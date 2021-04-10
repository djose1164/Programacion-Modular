/*
    Contabilidad: Estado de resultado, modificar cuentas(sudo) Devito, Credito, Banco, 
    Cuentas por cobrar, Cuentas por pagar,
*/

#ifndef CONTABILIDAD_H /*CONTABILIDAD_H*/
#define CONTABILIDAD_H
/* Prototipos y Declaraciones */


/* Fichero a Usar */
const char reg_contabilidad;

struct cont_reg
{
    /* escribe el nombre de la venta en el registro */
    char reg_nom_ventas[50];
    /* escribe la cantidad de la venta en el registro */
    float reg_cant_ventas;
    /* escribe el ingreso de la venta en el registro */
    int reg_pre_ventas;
    /* escribe el nombre de la compra en el registro */
    char reg_nom_compras[50];
    /* escribre la cantidad de la compra en el registro */
    float reg_cant_compras;
    /* escribe el pago de la compra en el registro */
    int reg_pre_compras;
};

/**
 * @brief Esta funcion se encargara de escribir el registro de contabilidad 
 * en base a las compras y ventas realizadas
 * 
 * @param cont_reg 
 */
void crear_registro (struct cont_reg *cont_reg);

/**
 * @brief Esta funcion mostrara una lista de los ingresos y pagos realizadas
 * 
 * @param registro_compras llevara a cabo una lista de cuentas por pagar 
 * (Es decir, mencionar la cantidad de productos que se agrego y la cantidad que se pago por ello)
 * @param registro_ventas llevara a cabo una lista de las cuentas por cobrar
 * (Es decir, mencionar la cantidad de productos que se retiro y la cantidad de ingresos)
 */
void registro_contabilidad (int registro_compras, int registro_ventas);

/**
 * @brief Esta funcion se encargara de llevar el total de dinero que posee
 * la tienda en base a las compras y ventas realizadas
 * 
 * @param compra_total cantidad de dinero utilizado en inversiones
 * @param venta_total ingresos totales de ventas realizadas
 */
void dinero_total (int compra_total, int venta_total);

#endif /*CONTABILIDAD_H*/