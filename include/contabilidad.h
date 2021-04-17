/*
    Contabilidad: Estado de resultado, modificar cuentas(sudo) Devito, Credito, Banco, 
    Cuentas por cobrar, Cuentas por pagar,
*/

#ifndef CONTABILIDAD_H /*CONTABILIDAD_H*/
#define CONTABILIDAD_H
#include <stdbool.h>
/* Prototipos y Declaraciones */

/**
 * @brief Esta funcion mostrara la lista de los pagos realizadas
 * 
 */
void registro_compras ();

/**
 * @brief Esta funcion mostrara la lista de las ventas realizadas
 * 
 */
void registro_ventas ();

/**
 * @brief Esta funcion se encargara de llevar el total de dinero que posee
 * la tienda en base a las compras y ventas realizadas
 * 
 */
void dinero_total ();

/**
 * @brief Menu de Opciones de Contabilidad
 * 
 * @return true 
 * @return false 
 */
bool contabilidad_menu();

enum Opciones_Contabilidad_Menu{

    REG_DEU = 1,
    REG_ING,
    DT,
    BACK_MENU

};

#endif /*CONTABILIDAD_H*/