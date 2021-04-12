#ifndef VENTA_H
#define VENTA_H

//Librerias a usar:
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/**
 * @brief Este modulo lo que hace es Vender, ver las ventas realizadas,
 *  editar pedidos(sudo), eliminar pedidos(sudo) y caja registradora.
 */
/**
 * @brief Estructura para llenar datos de la facturacion.
 * 
 */
typedef struct IngresodeVentas
{
    char nombre_cliente[50];
    char empleado_en_turno[50];
    char nombre_producto[50];
    unsigned Cantidad;
    unsigned Precio;
    unsigned Total;
    float TotalaPagar;

} facturas;


enum options_modulo_ventas
{
    _sell_products = 1,
    _see_orders,
    _edit_orders,
    _delete_orders,
    _cash_register,
    _salir 

};
/**
 * @brief Pregunta si va a agregar articulos,
 * solo si presiona el numero 1, si presiona el 0 entonces le da el total a pagar
 * @param total_pagar 
 * @return int 
 */
int sell_products(int total_pagar);

/**
 * @brief Esta funcion permite agregar otros articulos al usuario, los entra y los imprime 
 * cada vez que el usuario desee agregar algo mas 
 * 
 * @param total_pagar 
 * @return int 
 */
int agregar_mas_articulos(int *total_pagar);

/**
 * Permite ver todas las Facturas realizadas de acuerdo al nombre del cliente
 */
void see_orders();

/**
 * @brief Permite editar cualquier factura, con la clave y usuario del admin
 * 
 * @param total_pagar 
 * @return int 
 */
int edit_orders(int total_pagar);

/**
 * Permite editar cualquier factura, con la clave y usuario del admin 
 Introduciendo el nombre del cliente se elimina automaticamente la factura
 */
void delete_orders();

/**
 * @brief Esta funcion devolvera lo que se venda para llevarlo a contabilidad
 *  es decir, le dara una copia de las ventas a contabilidad (cantidad/precio)
 * @param precio 
 * @param cant 
 * @return int 
 */
unsigned venta_return_contabilidad(unsigned precio, unsigned cant);

/**
 * @brief Da el total de todas las facturas/ventas realizadas al momento
 * 
 */
void cash_register(Facturas);

/**
 * @brief Regresa al usuario a lo que es el menu de inicio de los modulos
 * 
 * @return true el usuario ha salido del modulo y se va al menu inicial del programa
 * @return false no se ejecutara la funcion
 */
bool salir();//TODO ver si esto funcionara o solo dejar el menu

/**
 * @brief 
 * 
 * @return true El usuario no salio y se imprime el menu
 * @return false El usuario salio, no se ejecutara
 */
bool ventas_menu();


/**
 * @brief Imprime el encabezado del modulo ventas opcion 1
 * 
 */
void print_encabezado_factura();

#endif //VENTA_H