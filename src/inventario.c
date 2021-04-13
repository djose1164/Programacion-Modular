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
#include "../include/login.h"
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

bool edit_product()
{
    char _temp[sizeof(int) + sizeof(unsigned)];
    unsigned temp = 0;
    char product_name[50];
    unsigned price = 0;
    int available_quantity = 0;
    unsigned id = 0;
    char c;
    bool flag;

    for (short i = 0; temp <= 0 || temp > 4; ++i)
    {
        fflush(stdout);
        system("cls||clear");

        if (i != 0)
            printf("\a\tPor favor elige una opcion correcta!\n\n");

        printf("\t\t\aHola! Estas actualmente en editar producto!\n\n"
               "\tQue quieres actualizar?\n\n"
               "1) Nombre del producto.\n"
               "2) Precio del producto.\n"
               "3) Cantidad del producto.\n"
               "Opcion: ");
        fgets(_temp, sizeof(_temp), stdin);
        sscanf(_temp, "%u", &temp);
    }

    fflush(stdout);
    system("cls||clear");

    printf("\t\aIngrese el id: ");
    fgets(_temp, sizeof(_temp), stdin);
    sscanf(_temp, "%u", &id);

    switch (temp)
    {
    case new_name:
        printf("\t\aIngrese el nuevo nombre del producto: ");
        fgets(product_name, sizeof(product_name) / sizeof(char), stdin);
        product_name[strcspn(product_name, "\n")] = 0;
        flag = update(id, product_name, NULL, NULL);
        break;
    case new_price:
        printf("\t\aIngrese el nuevo precio de venta: ");
        fgets(_temp, sizeof(_temp), stdin);
        sscanf(_temp, "%u", &price);
        flag = update(id, NULL, &price, NULL);
        break;
    case new_quantity:
        printf("\t\aIngrese la cantidad (positivo para suma, negativo para resta): ");
        fgets(_temp, sizeof(_temp), stdin);
        sscanf(_temp, "%d", &available_quantity);
        flag = update(id, NULL, NULL, &available_quantity);
        break;
    default:
        fprintf(stderr, "\aEsto luce como un bug in edit_product().\n");
        break;
    }

    fflush(stdout);
    system("cls||clear");

    if (flag)
    {

        printf("\t\t\aEl producto fue modificado exitosamente!\n\n"
               "\tPresiona 'i' para volver al inventario; cualquier otra tecla "
               "para salir.\n");
        while ((c = getchar()) != '\n')
            if (c == 'i')
                return true;
            else
                exit(0);
    }
    else
    {
        printf("\a\tEl producto que has intentado actualizar no existe.\n"
               "\tVerifica que hayas ingresado un id existe.\n"
               "Presione cualquier tecla para volver a menu Inventario...");
        getch();
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
    system_loading(1);

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
               "4) Volver al menu principal.\n"
               "5) Salir.\n"
               "\aOpcion: ");
        fgets(_temp, sizeof(_temp), stdin); // 4 bytes 8 bytes
        sscanf(_temp, "%hd", &temp);

        // Se comprueba a donde el usuario quiere ir.
        switch (temp)
        {
        case _save_product:
            // TODO: #16 Reparar bug: cuando se presiona s no pregunta para guardar otro producto.
            for (; ask_to_save();)
                ;
            return inventory_menu();

        case _edit_product:
            for (; edit_product();)
                ;
            return inventory_menu();

        case _report_inventory:
            report_inventory();
            for (size_t i = 0;; ++i)
            {
                if (i != 0)
                {
                    fflush(stdout);
                    system("cls||clear");
                    printf("\t\aElige una opcion valida!\n");
                }
                printf("\n\n\aPresiona 'i' para volver al menu de Inventario; "
                       "'p' para volver al menu principal.\n"
                       "Opcion: ");
                fgets(_temp, sizeof(_temp), stdin);
                sscanf(_temp, "%c", &c);
                if (c == 'i' || c == 'I')
                    return inventory_menu();
                else if (c == 'p' || c == 'P')
                {
                    return 0;
                }
            }
        case _menu_principal:
            return true;
        case _salir:
            exit(EXIT_SUCCESS);
        default:
            fprintf(stderr, "Has introducido una opcion incorrecta!\n"
                            "Si crees que es un bug manda una issue detallando el"
                            "error!\n");
            return false;
            break;
        }

        fflush(stdout);
        system("cls||clear");
    } while (temp <= 0 || temp > 4);

    return true;
}

bool edit_availableQuantity(const unsigned id, const int quantity)
{
    return update(id, NULL, NULL, &quantity);
}
