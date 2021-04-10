/*
    Contabilidad: Registro de ingreso o retiro de dinero mediante compra 
    o venta de producto y suma total actual.
*/

/* Librerias a usar */
#include "../include/contabilidad.h"
#include <stdio.h>
#include <string.h>

void crear_registro(struct cont_reg *cont_reg) /* Creador del registro */
{
    /* Archivo donde se guardara el registro de contabilidad */
    const char reg_contabilidad = {"contabilidad.txt"};
    FILE *Contabilidad = fopen(reg_contabilidad, "a+");

    if (Contabilidad == NULL) /*Verificador del archivo*/
    {
        printf("Error: Problema con el archivo\n");
        getchar();
    }

    /* Toma la informacion sobre ventas/compras */
    //reg_nom_ventas = informacion de ventas;
    //reg_cant_ventas = informacion de ventas;
    //reg_pre_ventas = informacion de ventas;
    //reg_nom_compras = informacion de compras;
    //reg_cant_compras = informacion de compras;
    //reg_pre_compras = informacion de compras;

    /* Escritor de ventas en el registro de contabilidad */
    fprintf(Contabilidad, "%s\n", cont_reg->reg_nom_ventas);
    fprintf(Contabilidad, "%f\n", cont_reg->reg_cant_ventas);
    fprintf(Contabilidad, "%d\n", cont_reg->reg_pre_ventas);
    /* Escritor de compras en el registro de contabilidad */
    fprintf(Contabilidad, "%s\n", cont_reg->reg_nom_compras);
    fprintf(Contabilidad, "%f\n", cont_reg->reg_cant_compras);
    fprintf(Contabilidad, "%d\n", cont_reg->reg_pre_compras);

    fclose(Contabilidad);
}

void registro_contabilidad(int registro_compras, int registro_ventas) /* Muestra el Registro de Ingresos
                                                                      y Compras realizadas */
{
    /* Lector del Registro */
    const char reg_contabilidad = {"contabilidad.txt"};
    FILE *Contabilidad = fopen(reg_contabilidad, "r");

    if (Contabilidad == NULL) /*Verificador del archivo*/
    {
        printf("Error: Problema con el archivo\n");
        getchar();
    }

    /* Muestra el Registro Completo */
    printf("Resgistro de Contabilidad: \n"
           "");

    fclose(Contabilidad);
}