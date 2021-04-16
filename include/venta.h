#if 0 // COMMENTED
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
    char nombre_cliente[100];
    char nombre_producto[100];
    unsigned Cantidad;
    unsigned Precio;
    unsigned Total;
    float TotalaPagar;
    bool full;
    unsigned id_producto_deseado; //guarda el id que el user ingreso
    
} facturas;


enum options_modulo_ventas
{
    SELL_PRODUCTS = 1,
    SEE_ORDERS,
    EDIT_ORDERS,
    DELETE_ORDERS,
    CASH_REGISTER,
    GO_BACK_OUT_VENTAS

};

/**
 * @brief Se van a llenar las estructuras vacias con las funciones get_price...
 * 
 */
void llenar_facturas();

/**
 * @brief Esto va a inicializar las facturas para cuando se desee imprimirlas
 * 
 */
void inicializar_facturas();

/**
 * @brief Pregunta si va a agregar articulos,
 * solo si presiona el numero 1, si presiona el 0 entonces le da el total a pagar
 * @return int 
 */
bool sell_products();

/**
 * @brief Esta funcion permite agregar otros articulos al usuario, los entra y los imprime 
 * cada vez que el usuario desee agregar algo mas 
 * 
 * @return int 
 */
int agregar_mas_articulos();

/**
 * Permite ver todas las Facturas realizadas de acuerdo al nombre del cliente
 */
void see_orders();

/**
 * @brief Permite editar cualquier factura, con la clave y usuario del admin
 * 
 * @return int 
 */
int edit_orders();

/**
 * Permite editar cualquier factura, con la clave y usuario del admin 
 Introduciendo el nombre del cliente se elimina automaticamente la factura
 */
void delete_orders();

/**
 * @brief  Esta funcion devolvera lo que se venda para llevarlo a contabilidad
 *  es decir, le dara una copia de las ventas a contabilidad (cantidad/precio)
 * 
 * @return unsigned 
 */
unsigned venta_return_contabilidad();

/**
 * @brief Da el total de todas las facturas/ventas realizadas al momento
 * 
 */
void cash_register(facturas Facturas);

/**
 * @brief Regresa al usuario a lo que es el menu de inicio de los modulos
 * 
 * @return true el usuario ha salido del modulo y se va al menu inicial del programa
 * @return false no se ejecutara la funcion
 */
bool go_back();//TODO ver si esto funcionara o solo dejar el menu

/**
 * @brief 
 * 
 * @return true El usuario no salio y se imprime el menuj
 * @return false El usuario salio, no se ejecutara
 */
bool ventas_menu();


/**
 * @brief Imprime el encabezado del modulo ventas opcion 1
 * 
 */
void print_factura();

#endif //VENTA_H
#endif // COMMENTED