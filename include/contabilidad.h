/*
    Contabilidad: Estado de resultado, modificar cuentas(sudo) Devito, Credito, Banco, 
    Cuentas por cobrar, Cuentas por pagar,
*/

#ifndef CONTABILIDAD_H /*CONTABILIDAD_H*/
#define CONTABILIDAD_H
/* Prototipos y Declaraciones */


/* Fichero a Usar */
const char reg_contabilidad;



/**
 * @brief Esta funcion se encargara de crear el registro de contabilidad
 * 
 * @param reg_contabilidad nombre del archivo txt donde se guardara el regsitro
 * @param reg_compras variable la cual se encargara de tomar del registro de compras
 * la informacion requerida
 * @param reg_ventas variable la cual se encargara de tomar del registro de ventas
 * la informacion requerida
 * @param reg_nom_ventas
 * 
 */
void crear_registro (int reg_compras, int reg_ventas);

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