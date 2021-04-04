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

// TODO: Guardar los productos, Editar productos(sudo), Eliminar producto(sudo)
// TODO: y Reporte de inventario
/**
 * @brief Estructura para los productos a guardar en la database.
 * 
 */
struct inventario
{
  // Nombre del producto a guardar.
  const char *product_name;
  // Precio del producto.
  const int sell_price;
  // Cantidad del producto.
  const int quantity_available;
};

/**
 * @brief Crea una tabla si no existe, para guardar los productos en la database.
 * 
 * @param product Estructura que contiene los datos a guardar. Mirar los
 * comentarios hechos en la struct para mas info.
 * @return true El producto se ha guardado successfully.
 * @return false No se ha podido guardar.
 */
bool save_product(struct inventario *const product);

/**
 * @brief Edita la informacion de los productos guardados en la database.
 * 
 * @param product_id ID del producto a modificar.
 * @return true 
 * @return false 
 */
bool edit_product(const int product_id);

void report_inventory();

#endif //INVENTARIO_H