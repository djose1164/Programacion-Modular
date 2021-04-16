/**
 * @file Database.h
 * @brief Prototipos y declaraciones para el manejo de la base de datos.
 * 
 * IMPORTANT: No definar nada aca.
 * 
 * @author @djose1164
 */

#ifndef DATABASE_H
#define DATABASE_H

// Librerias necesarias.
#ifdef __WIN32
#include "../include/sqlite3.h"
#else
#include <sqlite3.h>
#endif //! __WIN32
#include <stdbool.h>
#include <stddef.h>
#include "../include/inventario.h"

/**Struct donde se almacenara los datos a guardar. Deberas pasar esto a su
 * debida funcion.
 */
struct users_to_insert
{
    // Nombre del usuario a guardar.
    char *username;
    // Password del usuario a guardar.
    char *password;
    // Su nivel de priveligio.
    int is_admin;
    // Esta llena?
    bool full;
};

enum return_validate
{
    admin,
    guest,
    not_found
};

// Variables para el manejo de la base de datos.
extern sqlite3 *db;
extern sqlite3_stmt *res;
extern const char *database_name;
static char *errmsg;
static int conn;
// El limite de usario que podran register por ejecucion del programa.
extern const size_t MAX_USERS;

//! *-*-*-*-*-*-*- Metodos internos, no deberian modificarse sin saber SQL.*-*-*-*-*-*-*- 
/**
 * @brief Verifica que no haya error en la query.
 * En caso de lo que haya informara de ello y acabara la
 * ejecucion del programa.
 * 
 * @param conn Resultado de la query.
 * @param db Database usada.
 */
static void check_error(int conn, sqlite3 *db);

/**
 * @brief Para uso interno.
 * 
 * TODO: Hacerlo mas abstracto.
 * 
 */
static int __validate__(const char *const username, const char *const password);

/**
 * @brief Crea una nueva database si no existe.
 * Ej: Si pasas como nombre test.db y test.db no esta en tu actual directorio (donde estas ejucutando,
 * el programa) creara una nueva database; en caso de que exista creara una conexion.
 * 
 * IMPORTANT: Para uso interno
 * 
 * @param database_name 
 * @return int 
 */
static int __init_database__(const char *database_name);

/**
 * @brief Crea una nueva tabla. Para ver como crear un tabla visita el siguiente link:
 * https://www.tutorialesprogramacionya.com/sqliteya/detalleconcepto.php?punto=67&codigo=67&inicio=60
 * El link fue escogido aleatoriamente. En caso de dudas ver YT o algo.
 * 
 * @param query Codigo SQL para crear la tabla.
 * @return true Si fue exitoso.
 * @return false Si fallo.
 */
static void __create_table__(const char *query);

/**
 * IMPORTANT: Para uso interno.
 * 
 * @brief Funcion abstracta para complementar a otras o ser su base.
 * 
 * @param table_name El nombre de la tabla.
 * @param columns_name El nombre de la columna a la cual deseas agregar datos.
 * @param rows La cantidad de datos por fila 
 * 
 */
bool __insert_into__(struct users_to_insert *const users_to_insert,
                     struct products *const products);
/**
 * @brief Recibe una query para ejecutar la consulta.
 * 
 * @param query Codigo SQL.
 */
bool __make_query__(const char *query);

/**
 * @brief Para uso interno.
 * 
 * @param len 
 * @return char* 
 */
static char *allocate_str(int len);

/**
 * @brief Devuelve el nombre del producto por su ID.
 * 
 * IMPORTANT: Solo get_column_value debe retornar esta funcion.
 * 
 * @param id ID del producto.
 * @return char* Devuelve un string si se pudo encontrar. NULL de lo contrario.
 */
static void *__get_name__(const unsigned id);

/**
 * @brief Devuelve el precio del producto.
 * 
 * @param id ID del producto.
 * @return int El precio del producto.
 */
static void *__get_price__(const unsigned id);

/**
 * @brief Devuelve la cantidad actual del producto en inventario.
 * 
 * @param id ID del producto.
 * @return int Cantidad disponible.
 */
static void *__get_quantity__(const unsigned id);

/**
 * @brief update devuelve esta funcion.
 * 
 * @param id ID del producto a modificar.
 * @param new_name El nuevo nombre que se le pondra al producto.
 * @return true La modificacion fue un exito.
 * @return false Fallo al modificar.
 */
static bool __update_name__(const unsigned id, const char *new_name);

/**
 * @brief update devuelve esta funcion.
 * 
 * @param id ID del producto a editar.
 * @param quantity Cantidad que sera sumanda o restada.
 * @return true La modificacion fue un exito.
 * @return false La modifiacion fallo.
 */
static bool __update_quantity__(const unsigned id, const int quantity);

/**
 * @brief update devuelve esta funcion.
 * 
 * @param id ID del producto a modificar.
 * @param new_price El nuevo precio del producto.
 * @return true La modificacion fue un exito.
 * @return false La modifiacion fallo. 
 */
static bool __update_price__(const unsigned id, const unsigned new_price);

//! *-*-*-*-*-*-*- Metodos externos, pueden usarse sin problemas.*-*-*-*-*-*-*- 
/**
 * @brief Anade a un nuevo usario a la database.
 * 
 * @param username Nombre del usuario.
 * @param password La contraseña.
 * @param is_admin True si lo es, false si es invitado.
 * @return int 
 */
void add_user(const char *username, const char *password, int is_admin);

/**
 * @brief Usalo para verificar el usario y la contraseña del usario.
 * 
 * @param username El username registrado.
 * @param password La contraseña regristrada.
 * @return int Retorna 0 si esta registrado. Retorna 1 si el username esta incorrecto
 *         Retorna -1 si el password esta incorrecto.
 */
extern int validate(const char *const username, const char *const password);

/**
 * @brief Busca un producto por su id y muestra toda su informacion.
 * 
 * @param id 
 * @return char* Devuelve la informacion recolectada.
 */
extern char *search_product_by_id(const int id);

/**
 * @brief Actualiza un valor. Ej: id = 10, new_value = 50, is_int = true;
 * Como new_value es un string, y queremos guardar un int debemos pasar is_int = true.
 * El producto con el id = 10 sele asiganara un nuevo valor (50).
 * 
 * IMPORTANT: Para uso interno.
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
bool update(const unsigned id, const char *new_name,
            const unsigned *new_sellPrice, const int *new_availableQuantity);

/**
 * @brief Devolvera el valor de una columna. El retorna debe ser casteado con el
 * tipo de dato q desea.
 * 
 * @param id Obtendra el valor deseado del producto q tenga este ID.
 * @param __request_value Pasarse una opcion del enum __request_value
 * @return void* Un objeto q puede ser casteado a cualquier data type.
 */
void *get_column_value(const unsigned id, const unsigned __request_value);

/** 
 * TODO: Si crees que faltan alguna funcion, anadale en forma de comentario. Y explicacion de lo q hace.
 * TODO: De igual forma, si crees q alguna funcion debe ser modifica, sugiere el cambio en modo de comentario.
 */

#endif // !DATABASE_H