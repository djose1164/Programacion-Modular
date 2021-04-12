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
    _menu_principal,
    _salir
};

enum __request_value
{
    get_productName,
    get_price,
    get_quantity
};

enum set_new_value
{
    new_name = 1,
    new_price,
    new_quantity
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
 * @brief Muestra un menu para actualizar un producto por su ID.
 * 
 * 
 * TODO: Abstracion para users.
 * 
 * @return true Se han asignado los nuevos valores succesfully!
 * @return false No se han podido asignar los nuevos valores.
 */
bool edit_product();

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

/**
 * @brief Muestra el menu de guardar producto.
 * 
 * @return true El usuario desea guardar otro producto.
 * @return false El usuario no desea guardar otro producto.
 */
bool ask_to_save();

/**
 * @brief Permite modificar la cantidad almacena de un producto por su ID. Ya sea
 * para restarle cantidad o sumarle. Si quieres anadir deberas pasar un numero
 * negativo; para sumar un positivo.
 * 
 * @param quantity La cantidad que sera sumada o restada.
 * @param id ID del producto a modificar.
 * @return true Se ha podido establecer la nueva cantidad.
 * @return false No se ha podido establecer la nueva cantidad.
 */
bool edit_availableQuantity(const unsigned id, const int quantity);

#endif //INVENTARIO_H