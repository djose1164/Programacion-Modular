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

#include <stdbool.h>
#include <stddef.h>

// TODO: Guardar los productos, Editar productos(sudo), Eliminar producto(sudo)
// TODO: y Reporte de inventario
/**
 * @brief Estructura para los productos a guardar en la database.
 * 
 */
struct products
{
    unsigned id;
    char *product_name;
    int sell_price;
    int available_quantity;
    bool full;
};

enum inventario_options
{
    _save_product = 1,
    _edit_product,
    _report_inventory,
    _salir
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
 * @brief Actualiza un valor. Ej: id = 10, new_value = 50, is_int = true;
 * Como new_value es un string, y queremos guardar un int debemos pasar is_int = true.
 * El producto con el id = 10 sele asiganara un nuevo valor (50).
 * 
 * IMPORTANT: Si no vas a actualizar algun parametro pasa Null. Ej. 5, NULL...
 * 
 * TODO: Abstracion para users.
 * 
 * @param id Identificador exclusivo (no se puede repetir, y se genera 
 * automaticamente) para cada producto. NO puede ser NULL.
 * @param new_name Nuevo nombre para el producto con el id suministrado.
 * @param new_sellPrice Nuevo sell_price para el producto con el id suministrado.
 * @param new_availableQuantity Nuevo available_quantity para el producto con el
 * id suministrado.
 * @return true Se han asignado los nuevos valores succesfully!
 * @return false No se han podido asignar los nuevos valores.
 */
bool edit_product(const unsigned id, const char *new_name,
                  const unsigned new_sellPrice, const unsigned new_availableQuantity);

/**
 * @brief Impre en pantalla el estado actual del inventario (database).
 * 
 */
void report_inventory();

/**
 * @brief Mostrara el menu de invetario. Permitiendo al usuario elegir entre las
 * opciones disponibles.
 * 
 * @return true El usuario no ha salido. Se ejectura.
 * @return false El usuario salio. Se parara.
 */
bool inventory_menu();

#endif //INVENTARIO_H