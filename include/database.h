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
#include "../include/sqlite3.h"
#include <stdbool.h>

struct toValidate
{
    char *username;
    char *password;
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
extern char *errmsg;
extern int conn;

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
 * @brief Para uso interno.
 * 
 * TODO: Hacerlo mas abstracto.
 * 
 */
static int __validate__(const char *const username, const char *const password);

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
static bool __create_table__(const char *query);

/**
 * @brief Se usara para insertar datos en la tabla productos.
 * Es decir, luego de haber creada la tabla se podra agregar 
 * productos a la misma atra ves de esta funcion
 * 
 * @param parametros Escribe: "@param x" y cambia la x por lo q creas necesario. Dentro
 * del comentario.
 * @return true Si se pudo insertar los datos.
 * @return false Error al insertar.
 */
static bool __insert_into__(void *parametros);

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
 * @param id Identificador exclusivo (no se puede repetir, y se genera automaticamente) para cada
 * producto.
 * @param new_value El nuevo valor que queramos pasarle al producto. 
 * @param is_int Pasarle true si new_value sera int, false de lo contrario.
 * @return true Se actualizo correctamente tu producto.
 * @return false Error encontrado mala suerte xd.
 */
extern bool update(const char *id, const char *new_value, bool is_int);

/**
 * @brief Verifica que no haya error en la query.
 * En caso de lo que haya informara de ello y acabara la
 * ejecucion del programa.
 * 
 * @param conn Resultado de la query.
 * @param db Database usada.
 */
void check_error(int conn, sqlite3 *db);

/** 
 * TODO: Si crees que faltan alguna funcion, anadale en forma de comentario. Y explicacion de lo q hace.
 * TODO: De igual forma, si crees q alguna funcion debe ser modifica, sugiere el cambio en modo de comentario.
 */

#endif // !DATABASE_H
