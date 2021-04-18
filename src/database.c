/**
 * @file database.c
 * @author @djose1164
 * @brief Implementacion/definicion del header database.h.
 * 
 * @version 1.0
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/database.h"
//#include "../include/users.h" Para proxima actualizacion.
#include <string.h>

const size_t MAX_USERS = 2;
static short counter;

// Variables globales.
sqlite3 *db;
sqlite3_stmt *res;
static bool temp = true;
const char *database_name = "test.db";

/**
 * @brief Habilita el suficiente espacion en memoria para los strings.
 * 
 * @param string El string que se va a guardar.
 * @return char* El return de la direccion de memoria.
 */

char *allocate_str(int len)
{
    char *str = malloc(sizeof(char) * (len + 1));
    if (!str)
    {
        fprintf(stderr, "Couldn't allocate the memory.\n");
        exit(-1);
    }

    return str;
}

static void check_error(int conn, sqlite3 *db)
{
    if (conn != SQLITE_OK)
    {
        fprintf(stderr, "Error: %s.\n"
                        "The program is gonna close.\n",
                sqlite3_errmsg(db));
        exit(-1);
    }
}

static int __init_database__(const char *database_name)
{
#ifndef CONNECTED
#define CONNECTED
    int conn = sqlite3_open(database_name, &db);
    check_error(conn, db);
    return 0;
#endif //CONNECTED

    // Error
    return -1;
}

static void __create_table__(const char *query)
{
    __init_database__(database_name);

    char *errmsg;
    int conn = sqlite3_exec(db, query, 0, 0, &errmsg);
    check_error(conn, db);
}

static int __validate__(const char *const username, const char *const password)
{
    char *errmsg;
    int conn;
    __init_database__(database_name);

    // Array de punteros a los datos a validar.2
    const char *to_validate[] = {
        username,
        password};

    // Array de punteros para la consulta. Solo cambiar si tenes conocimiento de SQL.
    char *queries = {
        "SELECT username, password, is_admin "
        "FROM users "
        "WHERE username = ? AND "
        "password = ?;"};

    // Prepara la coneccion.
    conn = sqlite3_prepare_v2(db, queries, -1, &res, NULL);
    if (conn == SQLITE_ERROR)
        return -1;
    check_error(conn, db);

    for (size_t i = 0; i <= (sizeof *queries) / (sizeof queries[0]); i++)
    {
        // Enlaza el valor (cambia ? por su debido valor).
        conn = sqlite3_bind_text(res, i + 1, to_validate[i], -1, NULL);
        check_error(conn, db);
    }

    int step;

    if ((step = sqlite3_step(res)) != SQLITE_ROW)
    {
        sqlite3_finalize(res);
        sqlite3_close(db);
        return not_found;
    }
    else
    {
        if (1 == sqlite3_column_int(res, 2))
        {
            sqlite3_finalize(res);
            sqlite3_close(db);
            return admin;
        }
        else
        {
            sqlite3_finalize(res);
            sqlite3_close(db);
            return guest;
        }
    }
    return -1;
}

int validate(const char *username, const char *password)
{
    return __validate__(username, password);
}

//! Agregar nuevos datos.

bool __insert_into__(struct users_to_insert *const users_to_insert,
                     struct products *const products)
{
    char *query;
    // Mensaje de error.
    char *errmsg;
    int conn;
    char **data;

    if (!products)
    {
        query = "INSERT INTO users(username, password, is_admin) "
                "VALUES(?, ?, ?);";

        // Cambiando estructura de datos.
        data = malloc(sizeof(char) * 2);
        *(data + 0) = malloc(sizeof(char) * (strlen(users_to_insert->username) + 1));
        *(data + 1) = malloc(sizeof(char) * (strlen(users_to_insert->password) + 1));

        strcpy(data[0], users_to_insert->username);
        strcpy(data[1], users_to_insert->password);

        /*
        printf("%s\n", data[0]);
        printf("%s\n", data[1]);
        */

        // Prepara la coneccion.
        conn = sqlite3_prepare_v2(db, query, -1, &res, NULL);
        check_error(conn, db);

        for (size_t i = 1; i <= 2; i++)
        {
            // Enlaza el valor (cambia ? por su debido valor).
            conn = sqlite3_bind_text(res, i, data[i - 1], -1, NULL);
            check_error(conn, db);
        }
        conn = sqlite3_bind_int(res, 3, users_to_insert->is_admin);
        check_error(conn, db);

        // Esta funcion es IMPORTANTISIMA. Cuanto tiempo perdi joder xD.
        int step = sqlite3_step(res);
        // La de arriba ^^^

        sqlite3_finalize(res);
        free(users_to_insert);
        free(data);
        return true;
    }
    else
    {
#ifndef CREATED_TABLE
#define CREATED_TABLE
        query = "CREATE TABLE IF NOT EXISTS products( "
                "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                "nombre TEXT, "
                "precio INT, "
                "cantidad INT);";

        __create_table__(query);
#endif //CREATED_TABLE

        query = "INSERT INTO products("
                "id, nombre, precio, cantidad) "
                "VALUES(NULL, ?, ?, ?);";

        // Cambiando estructura de datos.
        data = malloc(sizeof(char) * 1);
        for (size_t i = 0; i < 1; i++)
        {
            data[i] = malloc(sizeof(char) * 1);
        }
        strcpy(data[0], products->product_name);

        int int_data[] = {products->sell_price,
                          products->available_quantity};

        conn = sqlite3_prepare_v2(db, query, -1, &res, NULL);
        check_error(conn, db);

        conn = sqlite3_bind_text(res, 1, data[0], -1, NULL);
        check_error(conn, db);

        //Vinculacion de los datos.
        for (size_t i = 0; i < 2; i++)
        {
            conn = sqlite3_bind_int(res, i + 2, int_data[i]);
            check_error(conn, db);
        }

        conn = sqlite3_step(res);

        sqlite3_finalize(res);
        free(products);
        free(data);
        return conn == SQLITE_DONE;
    }

    sqlite3_finalize(res);
    free(data);
    return false;
}

//! Realizar una consulta.

bool __make_query__(const char *query)
{
    __init_database__(database_name);
    char *errmsg;

    int callback(void *data, int column_count, char **columns, char **columns_names);

    int conn = sqlite3_exec(db, query, callback, NULL, &errmsg);
    if (conn == SQLITE_ERROR)
        return false;
    check_error(conn, db);
    // Para la ultima linea de la tabla.
    printf("*--------*--------------------*----------*----------*\n");
    return true;
}

//! Anandir nuevo usuario a la database.

void add_user(const char *username, const char *password, int is_admin)
{
    /**
     **Solo establecera la coneccion con la database una vez por ejecucion del
     **programa.
    */

    // Crea una query para luego ser usada para crear la database
    char *table_query = {"CREATE TABLE IF NOT EXISTS users("
                         "username TEXT, "
                         "password TEXT, "
                         "is_admin INT);"};
    __create_table__(table_query);

    // Coloca memoria para la primera dimension del array.
    struct users_to_insert **users_to_insert = malloc(sizeof(struct users_to_insert) * MAX_USERS);
    if (!users_to_insert)
        exit(-1);
    // Pone todas las structs a vacia.
    for (size_t i = 0; i < MAX_USERS; i++)
    {
        // Coloca memoria para la segunda dimension del array.
        users_to_insert[i] = malloc(sizeof(users_to_insert[0]));
        if (!users_to_insert[i])
            exit(-1);
        users_to_insert[i]->full = false;
    }
    // Toma una struct vacia y almacena los datos alli.
    bool temp = true;
    for (size_t i = 0; i < MAX_USERS && temp; i++)
    {
        temp = true;
        if (!users_to_insert[i]->full)
        {
            users_to_insert[i]->full = true;
            // Alocacion de memoria
            users_to_insert[i]->username = allocate_str(strlen(username));
            users_to_insert[i]->password = allocate_str(strlen(password));
            // Copia el contenido a la nueva direccion de memoria.
            strcpy(users_to_insert[i]->username, username);
            strcpy(users_to_insert[i]->password, password);
            users_to_insert[i]->is_admin = is_admin;

            // Almacena los datos por caa cada estructura vacia.
            if (__insert_into__(users_to_insert[i], NULL))
                printf("User created successfully!\n");

            temp = false;
        }
    }
}

//!-*-*-*-*-*-* Actualizar los datos -*-*-*-*-*-*

bool update(const unsigned id, const char *new_name,
            const unsigned *new_sellPrice, const int *new_availableQuantity)
{
    if (id <= 0)
        return false;

    if (new_name)
        return __update_name__(id, new_name);
    else if (new_sellPrice)
        return __update_price__(id, *new_sellPrice);
    else if (new_availableQuantity)
        return __update_quantity__(id, *new_availableQuantity);

    return false;
}

static bool __update_name__(const unsigned id, const char *new_name)
{
    int conn;
    char *errmsg;
    __init_database__(database_name);

    if (new_name == NULL)
        return false;

    char *sql = "UPDATE products "
                "SET nombre = ?"
                "WHERE id = ?;";

    conn = sqlite3_prepare_v2(db, sql, -1, &res, NULL);
    check_error(conn, db);

    conn = sqlite3_bind_text(res, 1, new_name, -1, NULL);
    check_error(conn, db);

    conn = sqlite3_bind_int(res, 2, id);
    check_error(conn, db);

    conn = sqlite3_step(res);
    sqlite3_finalize(res);
    return conn == SQLITE_DONE;
}

static bool __update_quantity__(const unsigned id, const int quantity)
{
    int conn;
    char *errmsg;
    __init_database__(database_name);

    char *sql = "UPDATE products "
                "SET cantidad = cantidad + ?"
                "WHERE id = ?;";

    conn = sqlite3_prepare_v2(db, sql, -1, &res, NULL);
    check_error(conn, db);

    sqlite3_bind_int(res, 1, quantity);
    check_error(conn, db);

    sqlite3_bind_int(res, 2, id);
    check_error(conn, db);

    conn = sqlite3_step(res);
    // if (conn ==)
    sqlite3_finalize(res);

    return conn == SQLITE_DONE;
}

static bool __update_price__(const unsigned id, const unsigned new_price)
{
    int conn;
    char *errmsg;
    __init_database__(database_name);

    char *sql = "UPDATE products "
                "SET precio = ? "
                "WHERE id = ?;";

    conn = sqlite3_prepare_v2(db, sql, -1, &res, NULL);
    check_error(conn, db);

    sqlite3_bind_int(res, 1, new_price);
    check_error(conn, db);

    sqlite3_bind_int(res, 2, id);
    check_error(conn, db);

    conn = sqlite3_step(res);
    sqlite3_finalize(res);
    return conn == SQLITE_DONE;
}

//! Obtener valores.

void *get_column_value(const unsigned id, const unsigned __request_value)
{
    __init_database__(database_name);
    if (id <= 0)
        return NULL;

    if (__request_value == NAME)
        return __get_name__(id);
    else if (__request_value == PRICE)
        return __get_price__(id);
    //else if (__request_value == QUANTITY)
    //    return __get_quantity__(id);
    else
        return (void *)-1;
}

static void *__get_name__(const unsigned id)
{
    int conn;
    char *str;
    char *sql = "SELECT nombre "
                "FROM products "
                "WHERE id = ?;";
    conn = sqlite3_prepare_v2(db, sql, -1, &res, NULL);
    check_error(conn, db);
    conn = sqlite3_bind_int(res, 1, id);
    check_error(conn, db);
    conn = sqlite3_step(res);

    str = conn == SQLITE_ROW ? (char *)sqlite3_column_text(res, 0) : NULL;
    void *temp = (void *)str;
    return temp;
}

static void *__get_price__(const unsigned id)
{
    int conn;
    static unsigned price;
    char *sql = "SELECT precio "
                "FROM products "
                "WHERE id = ?;";

    conn = sqlite3_prepare_v2(db, sql, -1, &res, NULL);
    check_error(conn, db);
    conn = sqlite3_bind_int(res, 1, id);
    check_error(conn, db);
    conn = sqlite3_step(res);

    price = conn == SQLITE_ROW ? sqlite3_column_int(res, 0) : -1;
    sqlite3_finalize(res);
    return (void *)&price;
}

int callback(void *data, int column_count, char **columns, char **columns_names)
{
    if (temp)
        printf("*--------*--------------------*----------*----------*\n"
               "|%-8s|%-20s|%-10s|%-10s|\n",
               columns_names[0], columns_names[1], columns_names[2],
               columns_names[3]);

    temp = false;

    fflush(stdout);
    printf("*--------*--------------------*----------*----------*\n"
           "|%-8s|%-20s|%-10s|%-10s|\n",
           columns[0], columns[1], columns[2], columns[3]);

    return 0;
}