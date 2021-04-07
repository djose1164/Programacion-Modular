#ifndef VENTA_H
#define VENTA_H

//Librerias a usar:
#include <stdio.h>
#include <string.h>

typedef struct IngresodeVentas //Estructura para llenar datos de la facturacion
{
    // La nomenclatura esta mal. Debe ser nombreProducto o nombre_producto.
    char nombre_cliente[50];
    char empleado_en_turno[50];
    char nombre_producto[50];
    int Cantidad;
    float Precio;
    float Total;
    float TotalaPagar;

} facturas; //vector de 100 para las facturas que quiera hacer

/** Rellena la factura, con todos los datos requeridos, los guarda
calcula el total a pagar de la venta y resta productos del inventario*/
void vender();
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
 * Da el total de todas las facturas/ventas realizadas al momento
 */
void caja_registradora(Facturas);

/**
 * Regresa al usuario a lo que es el menu de inicio de los modulos
 */
void salir();

#endif //VENTA_H