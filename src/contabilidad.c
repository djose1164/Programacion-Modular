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
    return print_factura();
}

void dinero_total (int compra_total, int venta_total)
{
    int compra_total;
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
               "\t1) Registro de Deudas\n"
               "\t2) Registro de Ingresos\n"
               "\t3) Dinero Total\n"
               "\t4) Volver al Menu Principal\n");
        fgets(_temp, sizeof(_temp), stdin);
        sscanf(_temp, "%hd", &temp);
        flag = true;

    } while (temp < 0 || temp > 4);

    switch (temp)
    {
    case REG_DEU:
        registro_compras();
        getchar();
        break;

    case REG_ING:
        registro_ventas();
        getchar();
        break;

    case DT:
        printf("Vuelva mas Tarde");

        break;

    case BACK_MENU:

        printf("Vuelva mas Tarde");
        break;

    default:
        fprintf(stderr, "\n\aHaz elegido una opcion incorrecta\n");
        break;
    }

    return true;
}