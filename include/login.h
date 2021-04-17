/**
 * @file login.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef LOGIN_H //LOGIN_H
#define LOGIN_H

enum menu_option
{
    INVENTARIO = 1,
    COMPRAS,
    VENTAS,
    CONTABILIDAD,
    SALIR
};

/**
 * @brief struct donde se guardara el actual usuario. Si se loguea se cargaron los 
 * datos q coincidan en la database.
 * 
 */
struct actual_user
{
    /**Almacena el nombre del usuario a registrar. */
    char username[50];
    /**Almacena el password del usuario a registrar. */
    char password[50];
    bool is_admin;
};

/**
 * @brief Muestra el login principal donde se podra elegir la opcion para ingre-
 * sar a otro modulo
 * 
 * @return int Mientras sea 1 se ejectura, y si es 0 se parara.
 */
int login_menu();

/**
 * @brief Muestra las opciones para logearse o registrarse. 
 * 
 * IMPORTANT: Cuando el usuario se registre se le dara acceso inmediato al sis-
 * tema.
 * 
 * @return int Mientras sea 1 se ejectura, y si es 0 se parara.
 */
int login_user();

/**
 * @brief Obtiene la contraseña escrita por el usuario. Desactivando el ECHO
 * para que no sea vea la misma.
 * 
 * @param password Donde se guardara la contraseña.
 * @return char* Devuelve la contraseña del usuario.
 */
void set_password(char *const password);

/**
 * @brief Mostrara en pantalla q el sistema esta cargando.
 * 
 * @param time El tiempo q durara el copilador parado.
 */
void system_loading(int time);

/**
 * @brief Devuelve el usario actual que esta ejecutando el programa.
 * 
 * @return char* La direccion de memoria donde se encutra el nombre.
 */
char *get_username();

/**
 * @brief Limpia la pantalla.
 * 
 */
void clear_screen();

#endif //LOGIN_H
