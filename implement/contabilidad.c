/*
    Contabilidad: Registro de ingreso o retiro de dinero mediante compra 
    o venta de producto y suma total actual.
*/

/* Librerias a usar */
#include "../include/contabilidad.h"
#include <stdio.h>
#include <string.h>

FILE *Contabilidad;
/* Archivo donde se guardara el registro de contabilidad */

void registro_contabilidad(int registro_compras, int registro_ventas) /* Muestra el Registro de Ingresos
                                                                      y Compras realizadas */
{
    Contabilidad = fopen("../output/registro_contabilidad.txt", "a+");
    printf("Resgistro de Contabilidad: \n"
           "");
    
}