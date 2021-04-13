#include <sqlite3.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../include/database.h"
#if defined(_win32) //windows fue detectado.
#include <windows.h>
#elif defined(_linux_) //linux fue detectado.
#include <unistd.h>
#endif
const size_t MAX_COMPRAS = 15;
void inicia_producto(struct compra *comprar_producto)
{
        for (size_t i = 0; i < MAX_COMPRAS; i++)
        {
        comprar_producto->comprado = false;
        }
}

bool compras_menu()
{   
    
    struct compra comprar_producto[MAX_COMPRAS];
    inicia_producto(&comprar_producto);
    char _temp[1];
    short temp;
    bool flag = true;
        /** el sistema de carga del modulo compras*/
        printf("ingresando al modulo de compras...\n");
    for (size_t i = 0; i <= 100; i++)

    {
        if (i % 25 == 0)
        {
            fflush(stdout);
            printf("Hackeando la NASA completado\a\r", i); //carga con relacion altema
        }
        else
            continue;
        if (i == 100)
        {
            fflush(stdout);
            system("cls ||clear");
        }
#ifdef _win32
        sleep(1000);
#else
        sleep(1);
#endif //win32
    }

    do
    {
        if (flag)
        printf("Hey! Elige una opcion correta\n");
        /** aqui enpieza mi menu*/
    printf("Bienvenido al menu de compras!\n"
           "por favor elige una delas siguientes opciones:\n"
           "1) Comprar productos\n"
           "2) crear produtos\n"
           "3) Eliminar/Editar\n"
           "4) compras realizadas\n"
           "5) Historial de producto\n"
           "6) Salir.\n");
    fgets(_temp, sizeof(_temp), stdin); // \n
    sscanf(_temp "%hd",&temp);
        switch (_temp)
        {
        case 1 _comprar_producto:
            /* code */
            break;
        case 2 crear_productos:
            /* code */
            break;
        case 3 Eliminar_ / Editar:
            /* code */
            break;
        case 4 compras_Realizadas:
            /* code */
            break;
        case 5 Historial_de_producto:
            /* code */
            break;
        case 6 Salir:
            /* code */
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
    } while {temp <= 0 || temp > 3};
    return true;
}
