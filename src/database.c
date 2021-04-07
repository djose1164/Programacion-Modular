/**
 * @file database.c
 * @author @djose1164
 * @brief Implementacion/definicion del header database.h.
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "../include/database.h"
//#include "../include/users.h" Para proxima actualizacion.
#include <string.h>

const size_t MAX_USERS = 50;

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

static int __init_database__(const char *database_name)
{
    int conn = sqlite3_open(database_name, &db);
    check_error(conn, db);
    return 0;
}

static void __create_table__(const char *query)
{
    char *errmsg;

    int conn = sqlite3_exec(db, query, 0, 0, &errmsg);
    if (conn != SQLITE_OK)
        fprintf(stderr, "Couldn't create the table: %s.", errmsg);
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

bool __insert_into__(const char *table_name, const char *columns_name[],
                     struct to_insert *const rows)
{
    int conn;

    char *query = {
        "INSERT INTO users(username, password, is_admin) "
        "VALUES(?, ?, ?);"};

    // Mensaje de error.
    char *errmsg;

    // Cambiando estructura de datos.
    char *data[] = {rows->username, rows->password};

    // Prepara la coneccion.
    conn = sqlite3_prepare_v2(db, query, -1, &res, NULL);
    check_error(conn, db);

    for (size_t i = 1; i <= 2; i++)
    {
        // Enlaza el valor (cambia ? por su debido valor).
        conn = sqlite3_bind_text(res, i, data[i - 1], -1, NULL);
        check_error(conn, db);
    }
    conn = sqlite3_bind_int(res, 3, rows->is_admin);
    check_error(conn, db);

    int step = sqlite3_step(res);

    return true;
}

void add_user(const char *username, const char *password, int is_admin)
{
    /**
     **Solo establecera la coneccion con la database una vez por ejecucion del
     **programa.
    */
#ifndef CONNECTED
#define CONNECTED
    __init_database__("test.db");

    // Crea una query para luego ser usada para crear la database
    char *table_query = {"CREATE TABLE IF NOT EXISTS users("
                         "username TEXT, "
                         "password TEXT, "
                         "is_admin INT);"};
    __create_table__(table_query);
#endif //CONNECTED

    int conn;

    struct to_insert to_insert[MAX_USERS];
    // Pone todas las structs a vacia.
    for (size_t i = 0; i < MAX_USERS; i++)
    {
        to_insert[i].full = false;
    }
    // Toma una struct vacia y almacena los datos alli.
    bool temp = true;
    for (size_t i = 0; i < MAX_USERS && temp; i++)
    {
        temp = true;
        if (!to_insert[i].full)
        {
            to_insert[i].full = true;
            strcpy(to_insert[i].username, username);
            strcpy(to_insert[i].password, password);
            to_insert[i].is_admin = is_admin;

            // Almacena los datos por caa cada estructura vacia.
            char *columns_name[] = {"username", "password", "is_admin"};
            if (__insert_into__("users", (const char **)columns_name, &to_insert[i]))
                printf("User created successfully!\n");

            temp = false;
        }
    }
}

/*
int callback(void *data, int column_count, char **columns, char **columns_names)
{
    for (int i = 0; i < column_count; i++)
    {
        if (strcmp(to_insert.username, columns[i]) == 0)
            return temp;
        else if (strcmp(to_insert.password, columns[i]) == 0)
            return _temp;
    }
    if (!temp && !_temp)
        return true;

    return false;
}*/