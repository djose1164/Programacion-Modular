/**
 * @file users.c
 * @author @djose1164
 * @brief Implemetacion del header "users.h".
 * @version 0.1
 * @date 2021-03-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "../include/users_fichero.h"
#include <string.h>
#include <stdio.h>

// Numero maximo para el array.
#define MAX_USERS 50

struct User user[MAX_USERS];

void __init_usersarr__()
{
    for (size_t i = 0; i < MAX_USERS; i++)
    {
        user[i].full = 0;
    }
}

void __save_into_file__(const char *username, const char *password)
{
    const char *file_name = {"usarios.txt"};
    // Creacion del archivo en modo escritura.
    FILE *__fp = fopen(file_name, "w");

    // Escribe el username y el password dentro del fichero.
    fprintf(__fp, "%s\t", username);
    fprintf(__fp, "%s\n", password);

    // Cierra el fichero.
    fclose(__fp);
}

void add_user(const char *username, const char *password)
{
    for (size_t i = 0; i < MAX_USERS; ++i)
    {
        if (user[i].full == 0)
        {
            // Copia los usuarios y contraseñas a sus repectivas struct.
            strcpy(user[i].username, username);
            strcpy(user[i].password, password);

            // Guarda los datos de los usuarios.
            __save_into_file__(user[i].username, user[i].password);
        }
    }
}

int validate_user(const char *username, const char *password)
{
    for (size_t i = 0; i < MAX_USERS; i++)
    {
        if (!strcmp(username, user[i].username) &&
            !strcmp(password, user[i].password))
            return registered;
        else if (strcmp(username, user[i].username))
            return invalid_user;
        else if (strcmp(password, user[i].password))
            return invalid_password;
    }

    return -1;
}

int __validate_from_file__(const char *file_name, const char *username, const char *password)
{
    /**
     * @brief Definicion aca, pueden cambiar los parametros.
     * 
     */
}