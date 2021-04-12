/**
 * @file inventario.c
 * @author @djose1164
 * @brief 
 * @version 1.0
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
    return __update__(id, new_name, new_sellPrice, new_availableQuantity);
}

bool ask_to_edit()
{
    char _temp[sizeof(int) + sizeof(unsigned)];
    char product_name[50];
    unsigned price = 0;
    unsigned available_quantity = 0;
    unsigned id = 0;
    char c;

    fflush(stdout);
    system("cls||clear");

    printf("\t\t\aHola! Estas actualmente en editar producto!\n\n"
           "\tEscribe el ID del producto: ");
    fgets(_temp, sizeof(id), stdin);
    sscanf(_temp, "%u", &id);

    printf("\t\aIngrese el nuevo nombre del producto: ");
    fgets(product_name, sizeof(product_name) / sizeof(char), stdin);
    product_name[strcspn(product_name, "\n")] = 0;

    printf("\t\aIngrese el nuevo precio de venta: ");
    fgets(_temp, sizeof(price), stdin);
    sscanf(_temp, "%u", &price);

    printf("\t\aIngrese la nueva cantidad: ");
    fgets(_temp, sizeof(available_quantity), stdin);
    sscanf(_temp, "%u", &available_quantity);

    fflush(stdout);
    system("cls||clear");
    if (edit_product(id, product_name, price, available_quantity))
    {
        printf("\t\aEl producto se ha editado correctamente!\n"
               "Para editar otro producto escribe 's'; para volver al "
               "menu Inventario 'n'.\n"
               "Opcion: ");
        scanf("%c", &c);
        getchar();
        if (c == 'S' || c == 's')
            return true;
    }

    return false;
}

bool ask_to_save()
{
    char _temp[sizeof(int) + sizeof(unsigned)];
    char product_name[50];
    unsigned price = 0;
    unsigned available_quantity = 0;
    unsigned id = 0;
    char c;

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

    if (save_product(product_name, price, available_quantity))
    {
        fflush(stdout);
        system("cls||clear");
        printf("\t\t\aEl producto se ha guardado sastifactoriamente.\n\n"
               "\tPara ver todos tus productos guardados vuelve al menu de Inventario.\n\n");
    }
    else
        fprintf(stderr, "\a\tUps! Esto luce como un bug. Postea un issue!\n");

    printf("\tQuieres anadir algun otro producto?\n"
           "\tEscribe 's' para si, cualquier tecla para no (volveras al menu de Inventario).\n"
           "\t\aOpcion: ");
    scanf("%c", &c);
    getchar();
    if (c == 'S' || c == 's')
        return true;
    else
        return false;
}

bool inventory_menu()
{
    char _temp[sizeof(int) + sizeof(unsigned)];
    short temp = 0;
    char product_name[50];
    unsigned price = 0;
    unsigned available_quantity = 0;
    unsigned id = 0;
    char c;

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
        if (temp != 0)
            printf("Hey!! Mano q haces? Elige una opcion correcta!\n\n");
        /**Aca empieza el menu. */
        printf("\t\t\aBienvenido al menu de Inventario!\n\n"
               "\tPor favor elige una de las siguientes opciones:\n\n"
               "1) Guardar producto.\n"
               "2) Editar producto.\n"
               "3) Reporte de inventario.\n"
               "4) Salir.\n"
               "\aOpcion: ");
        fgets(_temp, sizeof(_temp), stdin); // 4 bytes 8 bytes
        sscanf(_temp, "%hd", &temp);

        switch (temp)
        {
        case _save_product:
            //add_product();
            break;
        case _edit_product:
            //edit_product();
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
            break;
        }

        fflush(stdout);
        system("cls||clear");
    } while (temp <= 0 || temp > 4);

    switch (temp)
    {
    case _save_product:
        // TODO: #16 Reparar bug: cuando se presiona s no pregunta para guardar otro producto.
        for (; ask_to_save();)
            ;
        return inventory_menu();

    case _edit_product:
        for (; ask_to_edit();)
            ;
        return inventory_menu();

    case _report_inventory:
        report_inventory();
        printf("\n\n\aPresiona 'i' para volver al menu de Inventario; "
               "'p' para volver al menu principal.\n"
               "Opcion: ");
        for (; (c = getchar());)
        {
            if (c == 'p' || c == 'P' && c != '\n')
                return 0; //return login_menu();
            else if (c == 'i' || c == 'I' && c != '\n')
                return inventory_menu();
        }
    case salir:
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
