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
#include <conio.h>
#elif defined(__linux__) //Linux detectado
#include <unistd.h>
#include "../include/getch.h"
#endif
#define MAX_FACTURAS 100
#define MAX_LETTERS 50
// Variables globales.
facturas Facturas[MAX_FACTURAS];
struct products;

//TODO Preguntar si puedo en este caso usar la estructura
//TODO para que le pase cantidad a Facturas.cantidad y asi poder
//TODO pasarselo a venta_return_contabilidad.

int obtener_ventas_suma()
{
    int sum = 0;
    for (size_t i = 0; i < MAX_FACTURAS; i++)
    {
        if (Facturas[i].full)
            sum += Facturas[i].Total;
    }

    return sum;
}

void llenar_facturas(unsigned id, unsigned cantidad)
{
    bool temp = true;

    for (size_t i = 0; i < MAX_FACTURAS && temp; i++)
    {
        if (!Facturas[i].full)
        {
            if ((Facturas[i].Precio = get_price_by_id(id)) == -1)
            {
                printf("No se pudo obtener el precio deseado");
                return;
            }
            Facturas[i].full = true;
            strcpy(Facturas[i].nombre_cliente, get_username());
            strcpy(Facturas[i].nombre_producto, get_name_by_id(id));
            Facturas[i].id_producto_deseado = id;
            Facturas[i].Cantidad = cantidad;

            Facturas[i].Total = Facturas[i].Precio * Facturas[i].Cantidad;
            Facturas[i].TotalaPagar += Facturas[i].Total;
            temp = false;
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
    if (GO_BACK_OUT_VENTAS)
    {
        clear_screen();

        login_menu();
    }
    return false;
}

/**
 * @brief Da el total de todas las facturas/ventas realizadas al momento
 * 
 */
void cash_register()
{
    char c;
    clear_screen();
    //Quiero imprimir todos los totales de las facturas para el reporte de caja
    printf("\t\t\t\aEstas en la Caja Registradora\n");

    if (Facturas[0].full)
    {
        printf("\t\t\aEl total generado ha sido de: %d.\n\n", obtener_ventas_suma());

        printf("Presione cualquier tecla para volver al menu principal...");
        getch();
    }
    else
    {
        printf("No se ha realizado ninguna venta el dia de hoy =( ");
        printf("Presione cualquier tecla para salir: ");
        getch();
    }
}

/**
 * @brief Esta funcion eliminara totalmente las ventas hechas 
 * Permite editar cualquier factura, con la clave y usuario del admin
 * Introduciendo el nombre del cliente se elimina automaticamente la factura
 */
void delete_orders()
{
    char str[50];
    clear_screen();
    getchar();
    printf("Cual de estas estas facturas desea eliminar.\n");
    print_factura();
    printf("\nIngre el nombre de usario: ");
    fgets(str, sizeof(str), stdin);

    for (size_t i = 0; i < MAX_FACTURAS; i++)
    {
        if (!strcmp(str, Facturas[i].nombre_cliente))
        {
            Facturas[i].eliminado = true;
        }
    }

    printf("Pedido elimando con exito!\n");
}

/**
 * @brief Permite editar cualquier factura, con la clave y usuario del admin
 * 
 * @return int 
 */
int edit_orders()
{
    int available_quantity = 0;
    unsigned id = 0;
    char c;
    bool flag;
    char _temp[sizeof(int) + sizeof(unsigned)];
    unsigned temp = 0;

    getchar();
    clear_screen();

    for (size_t i = 0; i < MAX_FACTURAS; i++)
    {
        if (1) //ver si es admin o no, si es puede editar, sino sale error
        {
            printf("\n\aEstas ahora en el editor de pedidos\n"
                   "\nSolo podras editar las cantidades de productos a vender\n"
                   "Ingrese el id del producto: ");
            scanf("%u", &id);
            getchar();

            printf("\n\t\aIngrese la cantidad (positivo para suma, negativo para resta):");
            fgets(_temp, sizeof(_temp), stdin);
            sscanf(_temp, "%d", &Facturas[i].Cantidad);

            //flag = edit_availableQuantity(id, Facturas[i].Cantidad);
            printf("Exito!");
            break;
        }
        else
        {
            printf("No puede acceder a esta opcion porque no es Admin");
            getchar();
        }
        clear_screen();
    }

    if (flag)
    {
        clear_screen();
        printf("\t\t\aHa modificado la cantidad del producto\n\n"
               "\tPresiona 'm' para volver al inventario  o  cualquier otra tecla "
               "\tpara salir.\n");
        while ((c = getchar()) != '\n' || (c = getchar()) != '\r')
            if (c == 'm')
                return true;
            else
                exit(0);
    }
    else
    {
        printf("\a\tEl producto que has intentado modificar no existe.\n"
               "\tVerifica que hayas ingresado un id existente.\n"
               "Presione cualquier tecla para volver a menu Inventario...");
        getch();
    }
    return false;
}

/**
 * @brief Imprime el encabezado del modulo ventas opcion 1
 * 
 */
void print_factura()
{
    printf("\t*************Bienvenido a Colmado Hackeando la NASA (VENTAS) *************\n\n"
           "%-20s%-20s%-20s%-20s%-20s%-20s\n",
           "Nombre cliente:", "Producto:", "Cantidad:", "Precio:", "Total:", "Total a pagar:");

    for (size_t i = 0; i < MAX_FACTURAS; i++)
    {
        if (Facturas[i].full)
            printf("%-20s%-20s%-20u%-20u%-20u\t%-20.2f\n",
                   Facturas[i].nombre_cliente, Facturas[i].nombre_producto,
                   Facturas[i].Cantidad, Facturas[i].Precio, Facturas[i].Total, Facturas[i].TotalaPagar);
    }
}

/**
 * @brief Pregunta si va a agregar articulos, sino da el total a pagar de la factura
 * 
 * @return int 
 */
bool sell_products()
{
    char c[10];
    char temp;
    int flag = 0;
    unsigned id, cantidad;

    clear_screen();

    printf("Estas en comprar producto.\n");
    report_inventory();
    putchar('\n');
    printf("Ingrese el id del producto que desea comprar:");
    scanf("%u", &id);
    getchar();
    printf("Ingrese la cantidad que desea comprar:");
    scanf("%u", &cantidad);
    getchar();

    llenar_facturas(id, cantidad);
    flag = -cantidad;
    edit_availableQuantity(id, flag);
    printf("Desea continuar? 's' para si, cualquier otra tecla para no.\n");
    fgets(c, sizeof(c), stdin);
    sscanf(c, "%c", &temp);

    if (temp == 's' || temp == 'S')
        return true;
    return false;
}

/**
 * @brief Menu de inicio para el modulo ventas
 * @return true si el usuario no salio y se imprime el menu
 * @return false el usuario salio y se para
 */
bool ventas_menu()
{

    char _temp[sizeof(short)];
    short temp = 0;

    int time = 1;
    /**Sistema de carga para ingresar al modulo */
    clear_screen();

    printf("Ingresando al Modulo Ventas...\n");
    system_loading(time);
    do
    {
        if (temp != 0)
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
    case SELL_PRODUCTS:
        /*void print_encabezado_factura();//ver si es necesario agregarla o si solo se puede llamar a 
                agregar_mas_articulos*/
        if (sell_products())
            return sell_products();
        else
            return ventas_menu();

    case SEE_ORDERS:
        clear_screen();
        print_factura();
        getchar();
        getchar();
        break;

    case EDIT_ORDERS:
        for (; edit_orders();)
            ;
        return ventas_menu();

        break;

    case DELETE_ORDERS:
        delete_orders();
        return false;
    case CASH_REGISTER:
        cash_register();
        getchar();
        break;

    case GO_BACK_OUT_VENTAS:

        go_back();
        return false;
        break;

    default:
        fprintf(stderr, "\n\aHaz elegido una opcion incorrecta\n");
        break;
    }

    return true;
}