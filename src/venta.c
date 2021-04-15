#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/database.h"
#include "../include/venta.h"
#include "../include/inventario.h"
#include "../include/login.h"
#include <stdbool.h>

#if defined(__WIN32) //Windows detectado
#include <windows.h>
#elif defined(__linux__) //Linux detectado
#include <unistd.h>
#endif
#define MAX_FACTURAS 100
#define MAX_LETTERS 50
// Variables globales.
facturas Facturas[MAX_FACTURAS];
struct products;
//unsigned *cantidad;//Esta va a ingresar las cantidades de productos a vender
//TODO Preguntar si puedo en este caso usar la estructura
//TODO para que le pase cantidad a Facturas.cantidad y asi poder
//TODO pasarselo a venta_return_contabilidad.

void llenar_facturas()
{
    unsigned id, cantidad;
    report_inventory();
    printf("Ingrese el id del producto que desea comprar");
    scanf("%u", &id);
    getchar();
    printf("Ingrese la cantidad que desea comprar");
    scanf("%u", &cantidad);
    getchar();
    for (size_t i = 0; i < MAX_FACTURAS; i++)
    {
        if (!Facturas[i].full)
        {
            if (Facturas[i].Precio = get_price_by_id(id) == -1)
            {
                printf("No se pudo obtener el precio deseado");
                return;
            }
            Facturas[i].full = true;
            strcpy(Facturas[i].nombre_cliente, get_username());
            Facturas[i].id_producto_deseado = id;
            Facturas[i].Cantidad = cantidad;

            Facturas[i].Total = Facturas[i].Precio * Facturas[i].Cantidad;
            Facturas[i].TotalaPagar += Facturas[i].Total;
        }
    }
}
void inicializar_facturas()
{
    for (size_t i = 0; i < MAX_FACTURAS; i++)
    {
        Facturas[i].full = false;
    }
}

/**
 * @brief Regresa al usuario a lo que es el menu de inicio de los modulos
 * 
 * @return true El usuario ha salido del modulo y se va al menu inicial del programa
 * @return false No se ejecutara la funcion
 */
bool go_back()
{
    /*if (salir)
    {
        fflush(stdout);
        system("cls||clear");
        printf("Hackear a la NASA dejo de ser un sueno.\n");
        exit(0);
    }*/
    return false;
}

/**
 * @brief Da el total de todas las facturas/ventas realizadas al momento
 * 
 */
/*facturas cash_register(Facturas)
{
    printf("%d"); //Quiero imprimir todos los totales de las facturas para el reporte de caja
    return Facturas[50];
}*/

/**
 * @brief Esta funcion eliminara totalmente las ventas hechas 
 * Permite editar cualquier factura, con la clave y usuario del admin
 * Introduciendo el nombre del cliente se elimina automaticamente la factura
 */
/*void delete_orders(Facturas)
{
}*/

/**
 * @brief Permite editar cualquier factura, con la clave y usuario del admin
 * 
 * @param total_pagar 
 * @return int 
 */
int edit_orders(int total_pagar)
{
    int available_quantity = 0;
    unsigned id = 0;
    char c;
    bool flag;
    char _temp[sizeof(int) + sizeof(unsigned)];
    unsigned temp = 0;

    if (add_user) //ver si es admin o no, si es puede editar, sino sale error
    {
        printf("\n\aEstas ahora en el editor de pedidos\n"
               "\nSolo podras editar las cantidades de productos a vender\n"
               "\t\aIngrese la cantidad (positivo para suma, negativo para resta):");
        fgets(_temp, sizeof(_temp), stdin);
        sscanf(_temp, "%d", &available_quantity);
        flag = update(id, NULL, NULL, &available_quantity);
    }
    fflush(stdout);
    system("cls||clear");

    if (flag)
    {

        printf("\t\t\aHa modificado la cantidad del producto\n\n"
               "\tPresiona 'm' para volver al inventario  o  cualquier otra tecla "
               "\tpara salir.\n");
        while ((c = getchar()) != '\n')
            if (c == 'i')
                return true;
            else
                exit(0);
    }
    /* else
    {
        printf("\a\tEl producto que has intentado actualizar no existe.\n"
               "\tVerifica que hayas ingresado un id existe.\n"
               "Presione cualquier tecla para volver a menu Inventario...");
        getch();
    }*/
    return false;
}

/**
 * @brief Esta funcion devolvera lo que se venda para llevarlo a contabilidad
 *  es decir, le dara una copia de las ventas a contabilidad (cantidad/precio) 
 * @param precio 
 * @param cantidad 
 * @return int 
 */
/*unsigned venta_return_contabilidad() //TODO REVISAR
{
    return Facturas.Cantidad, Facturas.Precio;
}*/

/**
 * @brief  Permite ver todas las Facturas realizadas de acuerdo al nombre del cliente logeado
 *  y como solo sera un cliente solo se vera una unica factura
 * 
 */
void see_orders(facturas Facturas)
{
    //TODO Chequear si se puede solo copiar lo que imprima sell_products

    system("cls || clear");
    printf("\a\n\tElegiste la opcion Ver ventas\n"
           "\n\t%s\n",
           Facturas); //Imprimira la factura que se haya hecho
}

/**
 * @brief Esta funcion permite agregar otros articulos al usuario, los entra y los imprime 
 * cada vez que el usuario desee agregar algo mas  
 * @param total_pagar 
 * @return int 
 */
int agregar_mas_articulos()
{
#ifndef IMPRESO
#define IMPRESO
    void print_encabezado_factura();
#endif // IMPRESO          \
               //TODO Revisar esto \
               //TODO llamar a reporte inventario

    /* Imprimira cada factura hecha por cada llamada. */
    /* for (size_t i = 0; i < MAX_FACTURAS; i++)
    {
        printf("%s\t%s\t%s\t%s\t%s\t%s\n\n\n\n\n\n\n",
               Facturas[i].nombre_cliente, Facturas[i].nombre_cliente, Facturas[i].Cantidad, Facturas[i].Precio,
               edit_availableQuantity(1, 5), Facturas[i].Total);
    }*/

    return 0;
}

/**
 * @brief Imprime el encabezado del modulo ventas opcion 1
 * 
 */
void print_encabezado_factura()
{
    printf("\t*************Bienvenido a Colmado Hackeando la NASA (VENTAS) *************\n"
           "\t\tIngrese los datos que se le piden:\n\n"
           "Nombre cliente:\tProducto:\t Cantidad:\tPrecio:\tTotal:\t\n");
}

/**
 * @brief Pregunta si va a agregar articulos, sino da el total a pagar de la factura
 * 
 * @return int 
 */
int sell_products()
{
    char temp[sizeof(unsigned)];
    unsigned _temp = 0;

    fflush(stdout);
    system("cls||clear");
    for (size_t i = 0; i < MAX_FACTURAS; i++)
    {
        agregar_mas_articulos();
        printf("\t\t\tDesea agregar algo mas: ");
        fgets(temp, sizeof(unsigned), stdin);
        sscanf(temp, "%u", &_temp);
        /* 
			scanf("%u", temp);
			getchar();
			*/
        if (!temp)
            break;
        else
        {
            printf("\t\t\tTotal a pagar: %u", Facturas[i].TotalaPagar);
            printf("Presiona cualquier tecla para volver al menu de ventas");
            getchar();
            ventas_menu();
        }
    }

    return 0;
}

/**
 * @brief Menu de inicio para el modulo ventas
 * @return true si el usuario no salio y se imprime el menu
 * @return false el usuario salio y se para
 */
bool ventas_menu()
{

    char _temp[sizeof(short)];
    short temp;
    bool flag = false;
    int time = 2;
    /**Sistema de carga para ingresar al modulo */
    fflush(stdout);
    system("cls||clear");
    printf("Ingresando al Modulo Ventas...\n");
    system_loading(time);
    do
    {
        if (flag)
            printf("Elige una opcion valida por favor\n");
        /** ******Menu de Ventas *****  */
        printf("\a\n\t\tBienvenido al Modulo Ventas\n"
               "\t\t\tSeleccione la opcion que desea realizar: \n"
               "\t1) Vender\n"
               "\t2) Ver Ventas realizadas\n"
               "\t3) Editar Pedidos\n"
               "\t4) Eliminar Pedidos\n"
               "\t5) Caja Registradora\n"
               "\t6) Volver al Menu Principal\n");
        fgets(_temp, sizeof(_temp), stdin);
        sscanf(_temp, "%hd", &temp);

    } while (temp < 0 || temp > 6);

    switch (temp)
    {
    case _SELL_PRODUCTS:
        /*void print_encabezado_factura();//ver si es necesario agregarla o si solo se puede llamar a 
                agregar_mas_articulos*/
        agregar_mas_articulos();

        break;

        /*case _SEE_ORDERS:
                for (; see_orders(Facturas);)
                    ;
                return ventas_menu();

                break;

            case _EDIT_ORDERS:
                for (; edit_orders();)
                    ;
                return ventas_menu();

                break;

            case _DELETE_ORDERS:

                break;

            case _CASH_REGISTER:

                break;*/

    case _GO_BACK_OUT_VENTAS:

        go_back();
        return false;
        break;

    default:
        fprintf(stderr, "\n\aHaz elegido una opcion incorrecta\n");
        break;
    }

    fflush(stdout);
    system("cls || clear");

    flag = true;

    return true;
}
