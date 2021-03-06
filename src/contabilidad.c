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
#include "../include/compra.h"
#include "../include/venta.h"

void registro_compras() /* Muestra el Registro de Compras realizadas */
{
    clear_screen();
    /* Muestra el Registro Compras */
    printf("Resgistro de Contabilidad de Compras: \n");
    return report_inventory();
    printf("\nPresione nuevamente para volver al menu");
}

void registro_ventas() /* Muestra el Registro de Ventas realizadas */
{
    clear_screen();
    /* Muestra el Registro de Ventas */
    printf("Resgistro de Contabilidad de Ventas: \n");
    return print_factura();
    printf("\nPresione nuevamente para volver al menu");
}

void modificar_compras () /* Modifica el Registro de Compras existentes */
{
    clear_screen();
    /* Modifica el Registro de Compras */
    return edit_product();
}

void modificar_ventas () /* Modifica el Registro de Ventas existentes */
{
    clear_screen();
    /* Modifica el Registro de Ventas */
    return edit_orders();
}

void dinero_total() /* Muestra el total del dinero */
{
    clear_screen();
    printf("El Dinero Total Obtenido es: %d\n", obtener_ventas_suma() - obtener_suplidor_suma());
    printf("\nPresione nuevamente para volver al menu");
}

bool contabilidad_menu() /* Menu de Opciones disponibles en el Modulo de Contabilidad */
{

    char _temp[sizeof(short) * 2];
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
               "\t3) Modificacion de Registro de Compras\n"
               "\t4) Modificacion de Registro de Ventas\n"
               "\t5) Dinero Total\n"
               "\t6) Volver al Menu Principal\n");
        fgets(_temp, sizeof(_temp), stdin);
        sscanf(_temp, "%hd", &temp);
        flag = true;

    } while (temp < 0 || temp > 6);

    switch (temp)
    {
    case REG_DEU:
        registro_compras();
        getchar();
        return contabilidad_menu();
        break;

    case REG_ING:
        registro_ventas();
        getchar();
        return contabilidad_menu();
        break;

    case MOD_DEU:
        modificar_compras();
        getchar();
        return contabilidad_menu();
        break;

    case MOD_ING:
        modificar_ventas();
        getchar();
        return contabilidad_menu();
        break;

    case DT:
        dinero_total();
        getchar();
        return contabilidad_menu();
        break;

    case BACK_MENU:

        return login_menu();
        break;

    default:
        fprintf(stderr, "\n\aHaz elegido una opcion incorrecta\n");
        break;
    }

    return true;
}