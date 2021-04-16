#ifndef VENTA_H
#define VENTA_H

//Librerias a usar:
#include <stdio.h>
#include <string.h>

/**
 * @brief Estructura para llenar datos de la facturacion
 * 
 */
typedef struct IngresodeVentas
{
    char nombre_cliente[50];
    char empleado_en_turno[50];
    char nombre_producto[50];
    int Cantidad;
    float Precio;
    float Total;
    float TotalaPagar;

} facturas;

/**
 * @brief Rellena la factura, con todos los datos requeridos, los guarda
 *  calcula y devuelve el total a pagar por productos y de la ventaen general 
 * tambien resta productos del inventario.
 * @param precio 
 * @param total 
 * @param total_a_pagar 
 * @return float 
 */
float vender(float precio, float total, float total_a_pagar);

/**
 * Permite volver a llenar los datos en una nueva linea
 * solo si presiona el numero 1, si presiona el 0 entonces le da el total a pagar
 */
void agregar_mas_articulos();

/**
 * permite ver todas las Facturas realizadas de acuerdo al nombre del cliente
 */
void ver_ventas();

/**
 * Permite editar cualquier factura, con la clave y usuario del admin
 */
void editar_pedido_sudo();

/**
 * Permite editar cualquier factura, con la clave y usuario del admin 
 Introduciendo el nombre del cliente se elimina automaticamente la factura
 */
void eliminiar_pedido_sudo();

/**
 * @brief Esta funcion devolvera lo que se venda para llevarlo a contabilidad
 *  es decir, le dara una copia de las ventas a contabilidad (cantidad/precio)
 * @param precio 
 * @param cant 
 * @return float 
 */
float venta_return_contabilidad(float precio, int cant);

/**
 * @brief Da el total de todas las facturas/ventas realizadas al momento
 * 
 */
void caja_registradora(Facturas);

/**
 * Regresa al usuario a lo que es el menu de inicio de los modulos
 */
void salir();

#endif //VENTA_H
