/*
    Contabilidad: Registro de ingreso o retiro de dinero mediante compra 
    o venta de producto y suma total actual.
*/

/* Librerias a usar */
#include "../include/contabilidad.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../include/login.h"

void crear_registro(struct cont_reg *cont_reg) /* Creador del registro */
{
    /* Archivo donde se guardara el registro de contabilidad */
    const char *reg_contabilidad = {"contabilidad.txt"};
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
    const char *reg_contabilidad = {"contabilidad.txt"};
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

bool contabilidad_menu()
{

    char _temp[sizeof(short)];
    short temp;
    bool flag = false;
    int time = 1;
    /**Sistema de carga para ingresar al modulo */
    clear_screen();

    printf("Ingresando al Modulo de Contabilidad...\n");
    system_loading(time);
    do
    {
        if (flag)
            printf("Elige una opcion valida por favor\n");
        /* **Menu de Contabilidad **  */
        printf("\a\n\t\tBienvenido al Modulo de Contabilidad\n"
               "\t\t\tSeleccione la opcion que desea realizar: \n"
               "\t1) Registro\n"
               "\t2) Dinero Total\n"
               "\t3) Registro de Ingresos\n"
               "\t4) Registro de Deudas\n"
               "\t5) Volver al Menu Principal\n");
        fgets(_temp, sizeof(_temp), stdin);
        sscanf(_temp, "%hd", &temp);
        flag = true;

    } while (temp < 0 || temp > 5);

    switch (temp)
    {
    case _REG:
        printf("Vuelva mas Tarde");
        break;

    case _DT:
        printf("Vuelva mas Tarde");
        break;

    case _REG_ING:
        printf("Vuelva mas Tarde");

        break;

    case _REG_DEU:

        break;

    case _BACK_MENU:

        printf("Vuelva mas Tarde");
        break;

    default:
        fprintf(stderr, "\n\aHaz elegido una opcion incorrecta\n");
        break;
    }

    return true;
}