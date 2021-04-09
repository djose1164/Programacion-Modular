/**
 * @file database.c
 * @author @djose1164
 * @brief Implementacion/definicion del header database.h.
 * 
 * @version 1.0
 */
#include <stdio.h>
#include <stdlib.h>
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

void check_alloc(void *ptr)
{
    if (!ptr)
    {
        fprintf(stderr, "Couldn't allocate the memory.\n");
        exit(-1);
    }
}

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

void check_error(int conn, sqlite3 *db)
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

void __create_table__(const char *query)
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

    // Array de punteros a los datos a validar.
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
        //printf("Testing: %s\n", data[0]);
        conn = sqlite3_bind_text(res, 1, data[0], -1, NULL);
        check_error(conn, db);
        for (size_t i = 0; i < 2; i++)
        {
            conn = sqlite3_bind_int(res, i + 2, int_data[i]);
            check_error(conn, db);
        }

        int step = sqlite3_step(res);
        sqlite3_finalize(res);

        free(products);
        free(data);
        return true;
    }
    sqlite3_finalize(res);

    free(data);
    return false;

    free(data);
    sqlite3_finalize(res);

    // error
    return -1;
}

void __make_query__(const char *query)
{
    __init_database__(database_name);
    char *errmsg;
    int callback(void *data, int column_count, char **columns, char **columns_names);

    int conn = sqlite3_exec(db, query, callback, NULL, &errmsg);
    check_error(conn, db);
}

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

bool __update__(const int id, const char *new_name,
                const int new_sellPrice, const int new_availableQuantity)
{
    int conn;
    char *errmsg;
    char *sql;

    // Para imprimir los nombre de las columnas.
    temp = true;

    if (!id)
        return false;

    sql = "UPDATE products "
          "SET nombre = ?, "
          "precio = ?, "
          "cantidad = ? "
          "WHERE id = ?;";

    conn = sqlite3_prepare_v2(db, sql, -1, &res, NULL);
    check_error(conn, db);
    conn = sqlite3_bind_text(res, 1, new_name, -1, NULL);
    check_error(conn, db);
    conn = sqlite3_bind_int(res, 2, new_sellPrice);
    check_error(conn, db);
    conn = sqlite3_bind_int(res, 3, new_availableQuantity);
    check_error(conn, db);
    conn = sqlite3_bind_int(res, 4, id);
    check_error(conn, db);

    int step = sqlite3_step(res);
    sqlite3_finalize(res);
    return true;
}

int callback(void *data, int column_count, char **columns, char **columns_names)
{

    if(temp)
    {

       printf("*--------*--------------------*----------*----------*\n"
              "|%-8s|%-20s|%-10s|%-10s|\n", 
              columns_names[0], columns_names[1], columns_names[2], 
              columns_names[3]);
    } //   
    temp = false;

    
        fflush(stdout);
        printf("*--------*--------------------*----------*----------*\n"
               "|%-8s|%-20s|%-10s|%-10s|\n", 
               columns[0], columns[1], columns[2], columns[3]);
    

    return false;
}