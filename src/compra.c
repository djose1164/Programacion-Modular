#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/compra.h"
#include "../include/login.h"
#include "../include/inventario.h"

#define MAX_COMPRAS 15
struct compra comprar_producto[MAX_COMPRAS];
struct Proveedor suplir_producto[MAX_COMPRAS];

int obtener_suplidor_suma()
{
    int sum = 0;
    for (size_t i = 0; i < MAX_COMPRAS; i++)
    {
        if (suplir_producto[i].full)
            sum += suplir_producto[i].precio;
    }

    return sum;
}

void mostrar_productos_suplidor()
{
    clear_screen();
    printf("\t*************Bienvenido a Colmado Hackeando la NASA (VENTAS) *************\n\n"
           "%-20s%-20s%-20s%-20s\n",
           "ID:", "Producto:", "Cantidad:", "Precio:");

    for (size_t i = 0; i < MAX_COMPRAS; i++)
    {
        printf("%-20u%-20s%-20u%-20u\n",
               suplir_producto[i].id, suplir_producto[i].producto_nombre, suplir_producto[i].precio,
               suplir_producto[i].cantidad);
    }

    printf("En imprimir para compras");
    getchar();
}

bool crear_productos()
{
#ifndef INIT
#define INIT
    inicia_producto();
#endif //INIT

    bool _temp = true;
    char nombre[50];
    char temp[sizeof(unsigned) * 2];
    unsigned cantidad, precio;
    char c;

    getchar();

    clear_screen();
    printf("Nombre del producto: ");
    fgets(nombre, sizeof(nombre), stdin);

    printf("Precio del producto: ");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%u", &precio);

    printf("Cantidad del producto: ");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%u", &cantidad);

    for (size_t i = 0; i < MAX_COMPRAS && _temp; i++)
    {
        if (!suplir_producto[i].full)
        {
            suplir_producto[i].full = true;
            suplir_producto[i].id = i + 1;
            strcpy(suplir_producto->producto_nombre, nombre);
            suplir_producto[i].precio = precio;
            suplir_producto[i].cantidad = cantidad;
            _temp = false;
        }
    }

    clear_screen();
    printf("Deseas crear algun otro producto?\n"
           "Para si 's'; cualquier otro tecla para no...\n%d",
           suplir_producto[0].full);
    for (; (c = getchar()) != '\n' || (c = getchar()) != '\r';)
        if (c == 's' || c == 'S')
            return crear_productos();
        else
            return false;

    return false;
}

/**
 * @brief mostrar los productos a comprar.
 * 
 * @return true se ha podido compro el producto.
 * @return false no se pudo comprar el productointente otra vez.
 */
bool compar_productos()
{
    char temp[sizeof(unsigned) * 2];
    unsigned id;

    mostrar_productos_suplidor();
    putchar('\n');
    getchar();
    printf("Ingrese el id del producto que desea comprar: ");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%u", &id);

    for (size_t i = 0; i < MAX_COMPRAS; i++)
    {
        if (!comprar_producto[i].comprado)
        {
            for (size_t j = 0; j < MAX_COMPRAS; j++)
            {
                if (id == suplir_producto[j].id)
                {
                    comprar_producto[i].comprado = true;
                    strcpy(comprar_producto[i].nombre,
                           suplir_producto[j].producto_nombre);
                    comprar_producto[i].precio = suplir_producto[j].precio;
                    comprar_producto[i].cantidad = suplir_producto[j].cantidad;

                    // Anade el producto a la database.
                    return save_product(comprar_producto[i].nombre,
                                        comprar_producto[i].precio, comprar_producto[i].cantidad);
                }
            }
        }
    }

    printf("\nComprado con exito\n");
    return false;
}

void inicia_producto()
{
    for (size_t i = 0; i < MAX_COMPRAS; i++)
    {
        comprar_producto[i].comprado = false;
        comprar_producto[i].eliminado = false;
        suplir_producto[i].full = false;
    }
}

bool compras_menu()
{

    inicia_producto();
    char _temp[sizeof(short)];
    short temp;
    bool flag = false;
    int time = 1;

    /** el sistema de carga del modulo compras*/
    clear_screen();
    printf("ingresando al modulo de compras...\n");
    system_loading(time);

    do
    {
        if (flag)
            printf("Hey! Elige una opcion correta\n");
        /** aqui enpieza la impresion de mi menu*/
        printf("Bienvenido al menu de compras!\n"
               "por favor elige una delas siguientes opciones:\n"
               "1) Comprar productos\n"
               "2) crear produtos\n"
               "3) Eliminar/Editar\n"
               "4) Historial de producto\n"
               "5) Salir.\n");
        fgets(_temp, sizeof(_temp), stdin); // \n
        sscanf(_temp, "%hd", &temp);
        flag = true;
    } while (temp <= 0 || temp > 5);

    switch (temp)
    {
    case COMPRAR_PRODUCTOS:
        compar_productos();
        break;

    case CREAR_PRODUCTOS:
        (void)crear_productos();
        printf("Afuera de crear producto\n");
        getchar();
        break;

    case ELIMINAR_EDITAR:
        //editar();
        break;

    case HISTORIAL_DEL_PRODUCTO:
        //  historial_de_produc();
        break;

    case SALIR_COMPRA:
        //  salir();
        return false;
    default:
        fprintf(stderr, "Has introducido una funcion incorrecta!"
                        "Si crees que es un error mande un issue detallando"
                        "error\n");
        break;
    }

    fflush(stdout);
    system("cls||clear");

    flag = true;
    return true;
}
