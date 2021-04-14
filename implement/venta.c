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

// Variables globales.
facturas Facturas[50];
#define MAX_LETTERS 50
struct products;
//unsigned *cantidad;//Esta va a ingresar las cantidades de productos a vender 
                    //TODO Preguntar si puedo en este caso usar la estructura
                   //TODO para que le pase cantidad a Facturas.cantidad y asi poder 
                   //TODO pasarselo a venta_return_contabilidad.


/**
 * @brief Regresa al usuario a lo que es el menu de inicio de los modulos
 * 
 * @return true El usuario ha salido del modulo y se va al menu inicial del programa
 * @return false No se ejecutara la funcion
 */
bool salir()
{
    if (salir)
    {
        fflush(stdout);
		system("cls||clear");
		printf("Hackear a la NASA dejo de ser un sueno.\n");
		exit(0);
    }
    return false;
}

/**
 * @brief Da el total de todas las facturas/ventas realizadas al momento
 * 
 */
void cash_register(Facturas)
{
   printf("%d");//Quiero imprimir todos los totales de las facturas para el reporte de caja
    return facturas Facturas[50];
}

/**
 * @brief Esta funcion eliminara totalmente las ventas hechas 
 * Permite editar cualquier factura, con la clave y usuario del admin
 * Introduciendo el nombre del cliente se elimina automaticamente la factura
 */
void delete_orders(Facturas)
{

}

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
unsigned venta_return_contabilidad()//TODO REVISAR
{
    return Facturas->Cantidad, Facturas->Precio;
}

/**
 * @brief  Permite ver todas las Facturas realizadas de acuerdo al nombre del cliente logeado
 *  y como solo sera un cliente solo se vera una unica factura
 * 
 */
void see_orders()
{
   //TODO Chequear si se puede solo copiar lo que imprima sell_products
    
    system("cls || clear");
    printf("\a\n\tElegiste la opcion Ver ventas\n"
           "\n\t%s\n",Facturas); //Imprimira la factura que se haya hecho
    return Facturas;
}

/**
 * @brief Esta funcion permite agregar otros articulos al usuario, los entra y los imprime 
 * cada vez que el usuario desee agregar algo mas  
 * @param total_pagar 
 * @return int 
 */
int agregar_mas_articulos(int *total_pagar)
{
#ifndef IMPRESO
#define IMPRESO
    void print_encabezado_factura();
#endif IMPRESO // IMPRESO
    //TODO Revisar esto
    strcpy(Facturas->Precio,get_price_by_id);   

    /* Imprimira cada factura hecha por cada llamada. */
    printf("%s\t%s\t%s\t%s\t%s\t%s\n\n\n\n\n\n\n",
           get_username(),get_name_by_id,Facturas->Cantidad, get_price_by_id,
           edit_available_quantity(), get_price_by_id * Facturas->Cantidad);
           scanf("%u",&Facturas->Cantidad);//Ver si esta bien hacerlo con las estructuras o si debo crear variable
           getchar();
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
 * @param total_pagar 
 * @return int 
 */
int sell_products(int total_pagar)
{
    char temp[sizeof(unsigned)];
    unsigned _temp = 0;
    unsigned total_pagar = 0;
    unsigned id = 0;
  

     total_pagar = Facturas->Precio * Facturas->Cantidad;
    
    fflush(stdout);
    system("cls||clear");
    for (;;)
    {       
        agregar_mas_articulos(&total_pagar);
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
            ventas_menu();
    }
    printf("\t\t\tTotal a pagar: %u", total_pagar);

    return 0;
}

/**
 * @brief Menu de inicio para el modulo ventas
 * @return true si el usuario no salio y se imprime el menu
 * @return false el usuario salio y se para
 */
bool ventas_menu()
{

    char _temp[1];
    short temp;
    bool flag = false;
    /**Sistema de carga para ingresar al modulo */
    printf("Ingresando al Modulo Ventas...\n");
    for (size_t i = 0; i <= 100; i++)
    {

        if (i % 25 == 0)
        {
            fflush(stdout);
            printf("Hackeando a la NASA %zu%% completado.\r", i); /* Ahora hace 
			esencia con el nombre, jajaja. */
        }
        else
            continue;

        if (i == 100)
        {
            fflush(stdout);
            system("cls||clear");
        }
#ifdef __WIN32
        Sleep(1);
#else
        sleep(1);
#endif //__WIN32
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

            switch (temp)
            {
            case _sell_products:
                /*void print_encabezado_factura();//ver si es necesario agregarla o si solo se puede llamar a 
                agregar_mas_articulos*/
                int agregar_mas_articulos(int *total_pagar);

                break;

            case _see_orders:

                break;

            case _edit_orders:

                break;

            case _delete_orders:

                break;

            case _cash_register:

                break;

            case _salir:

                return false;

            default:
                fprintf(stderr, "\n\aHaz elegido una opcion incorrecta\n");
                break;
            }

            fflush(stdout);
            system("cls || clear");

            flag = true;

        } while (temp <= 0 || temp > 6);

        return true;
    }
