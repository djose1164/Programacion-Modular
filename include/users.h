/**
 * @file users.h
 * @author @djose1164
 * @brief Declarion del header para la validacion del login.
 * @version 0.1
 * @date 2021-03-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef USERS_H
#define USERS_H

/**
 * @brief Constantes para el eturn de la funcion validate.
 * 
 */
enum return_user
{
    registered,
    invalid_user,
    invalid_password,
};

/**
 * @brief Struct con los datos del usario.
 * 
 */
struct User
{
    /* Nombre o nickname utilizado al registrarse. */
    char username[50];
    /* La contraseña utilizada al registrarse. */
    char password[50];
    /* 0 si esta struct esta vacia, 1 de lo contrario. */
    unsigned short full;
};

/* Si el usario esta registrado 0, de lo contrario 1 */
extern short valide_user;

/**
 * @brief Anade un nuevo usuario a nueva struct.
 * 
 * @param username Input del usuario para el usrname.
 * @param password Input del usuario para el passwrd.
 */
void add_user(const char *username, const char *password);

/**
 * @brief Usalo para validar al usario.
 * 
 * @param username Nickname utilizado al registrarse.
 * @param password Contrasena utilizado al registrarse.
 * @return Retorna 0 si esta registrado, 1 si el usuario es incorrecto, y 2 si la contrasena esta mal
 */
int validate_user(const char *username, const char *password);

/**
 * @brief Pone todas las struct a vacia.
 * 
 */
void __init_usersarr__();
#endif //USERS_H
