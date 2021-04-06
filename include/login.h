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

#endif //LOGIN_H
