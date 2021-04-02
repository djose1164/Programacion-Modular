/**
 * @file database.c
 * @author @djose1164
 * @brief Implementacion/definicion del header Database.h.
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "../include/database.h"
//#include "../include/users.h" Para proxima actualizacion.
#include <string.h>

// El limite de usario que podran register por ejecucion del programa.
#define MAX_USERS 50

// Variables globales.
sqlite3 *db;
sqlite3_stmt *res;
static short temp = 0, _temp = 0;

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

// Retorna connn si fue un exito la creacion de la db. Cierra el programa
// de lo contrario.
static int __init_database__(const char *database_name)
{
#ifndef CONNECTED
#define CONNECTED
    int conn = sqlite3_open(database_name, &db);
    check_error(conn, db);
    return 0;
#endif //CONNECTED
}

static bool __create_table__(const char *query)
{
    char *errmsg;
    int conn = sqlite3_exec(db, query, 0, 0, &errmsg);
    if (!conn)
    {
        return true;
    }
    else
    {
        fprintf(stderr, "Couldn't create the table: %s.", errmsg);
        return false;
    }
}

static int __validate__(const char *const username, const char *const password)
{
    char *errmsg;
    int conn;
    // int callback(void *data, int column_count, char **columns, char **columns_names);

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
        return not_found;
    else
    {
        if (1 == sqlite3_column_int(res, 2))
            return admin;
        else
            return guest;
    }
    return -1;
}

int validate(const char *username, const char *password)
{
    return __validate__(username, password);
}

void add_user(const char *username, const char *password, int is_admin)
{
    __init_database__("test.db");
    // Crea una query para luego ser usada para crear la database
    char *table_query = {"CREATE TABLE IF NOT EXISTS users("
                         "username TEXT, "
                         "password TEXT, "
                         "is_admin INT);"};
    bool status = __create_table__(table_query);
    int conn;
#if 0  // 0
    struct toValidate toValidate[MAX_USERS];
    // Pone todas las structs a vacia.
    for (size_t i = 0; i < MAX_USERS; i++)
    {
        toValidate[i].full = false;
    }
    // Toma una struct vacia y almacena los datos alli.
    for (size_t i = 0; i < MAX_USERS; i++)
    {
        if (!toValidate[i].full)
        {
            strcpy(toValidate[i].username, username);
            strcpy(toValidate[i].password, password);
        }
    }
#endif //0

    // Array de punteros a los datos.
    char *data[] = {(char *)username, (char *)password};

    // Mensaje de error.
    char *errmsg;

    if (status == false)
        exit(-1);

    char *query = {"INSERT INTO users(username, password, is_admin) VALUES(?, ?, ?);"};
    // Prepara la coneccion.
    conn = sqlite3_prepare_v2(db, query, -1, &res, NULL);
    check_error(conn, db);

    for (size_t i = 1; i <= 2; i++)
    {
        // Enlaza el valor (cambia ? por su debido valor).
        conn = sqlite3_bind_text(res, i, data[i - 1], -1, NULL);
        check_error(conn, db);
    }
    conn = sqlite3_bind_int(res, 3, is_admin);
    check_error(conn, db);

    int step = sqlite3_step(res);

    printf("User created successfully!\n");
}

/*
int callback(void *data, int column_count, char **columns, char **columns_names)
{
    for (int i = 0; i < column_count; i++)
    {
        if (strcmp(toValidate.username, columns[i]) == 0)
            return temp;
        else if (strcmp(toValidate.password, columns[i]) == 0)
            return _temp;
    }
    if (!temp && !_temp)
        return true;

    return false;
}*/