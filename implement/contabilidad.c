/*
    Contabilidad: Registro de ingreso o retiro de dinero mediante compra 
    o venta de producto y suma total actual.
*/

/* Librerias a usar */
#include "../include/contabilidad.h"
#include <stdio.h>
#include <string.h>

void crear_registro(int reg_compras, int reg_ventas)/* Creador del registro */
{
    /* Archivo donde se guardara el registro de contabilidad */
    const char reg_contabilidad = {"contabilidad.txt"};
    FILE *Contabilidad = fopen(reg_contabilidad, "a+");

    fprintf(Contabilidad, "%d\n",reg_compras);
    fprintf(Contabilidad, "%d\n",reg_ventas);
}

void registro_contabilidad(struct cont_reg *cont_reg) /* Muestra el Registro de Ingresos
                                                                      y Compras realizadas */
{
    /* Lector del Registro */
    const char reg_contabilidad = {"contabilidad.txt"};
    FILE *Contabilidad = fopen(reg_contabilidad, "r");

    /* Muestra el Registro Completo */
    printf("Resgistro de Contabilidad: \n"
           "");
}