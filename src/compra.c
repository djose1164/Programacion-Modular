#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/compra.h"

const size_t MAX_COMPRAS = 15;
    struct compra comprar_producto[MAX_COMPRAS];

/**
 * @brief mostrar los productos a comprar.
 * 
 * @return true se ha podido compro el producto.
 * @return false no se pudo comprar el productointente otra vez.
 */
bool compar_productos(){
    char nombre[50];
    unsigned precio;
    unsigned cantidad;

    clear_screen();
    for (size_t i = 0; i < MAX_COMPRAS; i++)
    {
        printf("Nombre del Producto\tPrecio\tCantidad\n");
        scanf("%s",&nombre);
        getchar();
        scanf("%u",&precio);
        getchar();
        scanf("%u",&cantidad);
    }
    
} 

void inicia_producto(struct compra *comprar_producto)
{
        for (size_t i = 0; i < MAX_COMPRAS; i++)
        {
        comprar_producto[i].comprado = false;
        }
}

bool compras_menu()
{   
    
    inicia_producto(&comprar_producto);
    char _temp[sizeof(short)];
    short temp;
    bool flag = false;
    int time = 2;
        /** el sistema de carga del modulo compras*/
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
    sscanf(_temp, "%hd",&temp);
    flag = true;
        } while (temp <= 0 || temp > 3);
        switch (temp)
        {
        case COMPRAR_PRODUCTOS:
        compar_productos();
            break;

        case CREAR_PRODUCTOS:
        crear_productos();
            break;

        case ELIMINAR_EDITAR:
        editar();
            break;

        case HISTORIAL_DEL_PRODUCTO:
        historial_de_produc();
            break;

        case SALIR_COMPRA:
        salir();
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
