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

//const size_t MAX_PRODUCTS = 100;

bool save_product(char const *product_name, unsigned int sell_price,
                  unsigned int available_quantity)
{
#ifndef CREATED
#define CREATED

    char *sql = "Create Table If Not Exists products("
                "id Integer Primary Key AutoIncrement, "
                "product_name TEXT NOT NULL, "
                "sell_price INT NOT NULL, "
                "available_quantity INT NOT NULL);";
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
        strcpy(product[i]->product_name, product_name);
        product[i]->sell_price = sell_price;
        product[i]->available_quantity = available_quantity;

        // Guarda los datos recogidos por vuelta.
        return __insert_into__(NULL, product[i]);
            
    }

    // Error.
    return -1;
}
