/**
 * @file inventario.h
 * @author @djose1164
 * @brief Modulo para la intereccion con la database.
 * @version 0.1
 * @date 2021-04-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <stddef.h>

// TODO: Guardar los productos, Editar productos(sudo), Eliminar producto(sudo)
// TODO: y Reporte de inventario
/**
 * @brief Estructura para los productos a guardar en la database.
 * 
 */
struct products
{
    char *product_name;
    int sell_price;
    int available_quantity;
    bool full;
};

// Consts
extern const size_t MAX_PRODUCTS;
/**
 * @brief 
 * 
 * @param product Estructura que contiene los datos a guardar. Mirar los
 * comentarios hechos en la struct para mas info.
 * @return true 
 * @return false 
 */

/**
 * @brief Crea una tabla si no existe, para guardar los productos en la database.
 * 
 * @param product_name 
 * @param sell_price 
 * @param available_quantity 
 * @return true El producto se ha guardado successfully.
 * @return false No se ha podido guardar.
 */
bool save_product(char const *product_name, unsigned int sell_price, 
                  unsigned int available_quantity);

/**
 * @brief Edita la informacion de los productos guardados en la database.
 * 
 * @param product_id ID del producto a modificar.
 * @return true Si el producto fue guardado sastifactoriamente.
 * @return false Si no se ha podido guardar el producto sastifactoriamente.
 */
bool edit_product(const int product_id);

/**
 * @brief Impre en pantalla el estado actual del inventario (database).
 * 
 */
void report_inventory();

#endif //INVENTARIO_H