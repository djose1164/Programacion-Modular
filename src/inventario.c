/**
 * @file inventario.c
 * @author @djose1164
 * @brief 
 * @version 0.1
 * @date 2021-04-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/database.h"
#include "../include/inventario.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#if defined(__WIN32) // Windows fue dectatado.
#include <windows.h>
#elif defined(__linux__) // Linux fue dectado.
#include <unistd.h>
#endif

//const size_t MAX_PRODUCTS = 100;

bool save_product(char const *product_name, unsigned int sell_price,
                  unsigned int available_quantity)
{
#ifndef CREATED
#define CREATED

    char *sql = "Create Table If Not Exists products("
                "id Integer Primary Key AutoIncrement, "
                "nombre TEXT NOT NULL, "
                "precio INT NOT NULL, "
                "cantidad INT NOT NULL);";
    __create_table__(sql);
#endif //CREATED
    static size_t counter = 1;

    struct products **const product = malloc(sizeof(struct products) * counter);
    check_alloc((struct products *)product);
    for (size_t i = 0; i < counter; i++)
    {
        // Colocacion de memoria.
        product[i] = malloc(sizeof(struct products) * counter);
        check_alloc((struct products *)product[i]);
        // Dar memoria para los strings.
        product[i]->product_name = malloc(strlen(product_name) + 1);

        // Insertacion de datos.
        product[i]->id = i + 1;
        strcpy(product[i]->product_name, product_name);
        product[i]->sell_price = sell_price;
        product[i]->available_quantity = available_quantity;
        product[i]->full = true;

        // Guarda los datos recogidos por vuelta.
        return __insert_into__(NULL, product[i]);
    }

    // Error.
    return -1;
}

void report_inventory()
{
    __make_query__("SELECT * FROM products;");
}

bool edit_product(const unsigned id, const char *new_name,
                  const unsigned new_sellPrice, const unsigned new_availableQuantity)
{
    __update__(id, new_name, new_sellPrice, new_availableQuantity);
    return -1; // Error
}

bool inventory_menu()
{
    char _temp[sizeof(int) + sizeof(unsigned) ];
    short temp;
    bool flag = false;
    char product_name[50];
    unsigned price = 0;
    unsigned available_quantity = 0; 
    unsigned id = 0;

    fflush(stdout);
    system("cls||clear");
    /**El sistema de carga para entrar al modulo. */
    printf("Ingresando al modulo de inventario...\n");
    for (size_t i = 0; i <= 100; i++)
    {

        if (i % 25 == 0)
        {
            fflush(stdout);
            printf("Hackeando a la NASA %zu%% completado.\a\r", i); /* Ahora hace 
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
        Sleep(1000);
#else
        sleep(1);
#endif //__WIN32
    }

    do
    {
        if (flag)
            printf("Hey!! Mano q haces? Elige una opcion correcta!\n\n");
        /**Aca empieza el menu. */
        printf("\t\t\aBienvenido al menu de Inventario!\n\n"
               "\tPor favor elige una de las siguientes opciones:\n\n"
               "1) Guardar producto.\n"
               "2) Editar producto.\n"
               "3) Reporte de inventario.\n"
               "4) Salir.\n"
               "\aOpcion: "
               );
        fgets(_temp, sizeof(_temp), stdin); // 4 bytes 8 bytes
        sscanf(_temp, "%hd", &temp);

        fflush(stdout);
        system("cls||clear");

        flag = true;
    } while (temp <= 0 || temp > 4);

    switch (temp)
    {
    case _save_product:
        
        fflush(stdout);
        system("cls||clear");

        printf("\t\t\aHola! Estas actualmente en guardar producto!\n\n"
               "\a\tIngrese el nombre del producto a guardar: ");
        fgets(product_name, sizeof(product_name) / sizeof(char), stdin);
        product_name[strcspn(product_name, "\n")] = 0;

        printf("\t\aIngrese el precio de venta: ");
        //fflush(stdout);
        fgets(_temp, sizeof(_temp), stdin);
        sscanf(_temp, "%u", &price);

        printf("\t\aIngrese la cantidad: ");
        //fflush(stdout);
        fgets(_temp, sizeof(_temp), stdin);
        sscanf(_temp, "%u", &available_quantity);

        save_product(product_name, price, available_quantity);
        break;
    case _edit_product:
        printf("\t\t\aHola! Estas actualmente en editar producto!\n\n"
               "Escribe el ID del producto: ");
        fgets(_temp, sizeof(price), stdin);
        sscanf(_temp, "%u", &price); 

        printf("\t\aIngrese el nuevo nombre del producto: ");
        fgets(product_name, sizeof(product_name) / sizeof(char), stdin);
        product_name[strcspn(product_name, "\n")] = 0;

        printf("\t\aIngrese el nuevo precio de venta: ");
        fgets(_temp, sizeof(price), stdin);
        sscanf(_temp, "%u", &price);

        printf("\t\aIngrese la nueva cantidad: ");
        fgets(_temp, sizeof(available_quantity), stdin);
        sscanf(_temp, "%u", &available_quantity);
       
        edit_product(id, product_name, price, available_quantity);
        break;
    case _report_inventory:
        report_inventory();
        break;
    case _salir:
        return false;
    default:
        fprintf(stderr, "Has introducido una opcion incorrecta!\n"
                        "Si crees que es un bug manda una issue detallando el"
                        "error!\n");
        return false;
        break;
    }
    return true;
}
