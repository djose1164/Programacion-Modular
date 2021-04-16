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
#include "../include/inventario.h"
#include "../include/venta.h"

void registro_compras() /* Muestra el Registro de Compras realizadas */
{
    /* Muestra el Registro Compras */
    printf("Resgistro de Contabilidad de Compras: \n");
    return report_inventory();
}

void registro_ventas() /* Muestra el Registro de Ventas realizadas */
{
    /* Muestra el Registro de Ventas */
    printf("Resgistro de Contabilidad de Ventas: \n");
    return print_();
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
        registro_contabilidad;
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