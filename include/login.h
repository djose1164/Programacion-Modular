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
    inventario = 1,
    compras,
    ventas, 
    contabilidad,
    salir
    
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
char *get_password(char *const password);

/**
 * @brief Mostrara en pantalla q el sistema esta cargando.
 * 
 * @param time El tiempo q durara el copilador parado.
 */
void system_loading(int time);

#endif //LOGIN_H
