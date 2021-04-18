#ifndef COMPRA_H
#define COMPRA_H
#include <stdbool.h>

enum opciones_compras_menu
{
    COMPRAR_PRODUCTOS = 1,
    CREAR_PRODUCTOS,
    ELIMINAR_EDITAR,
    HISTORIAL_DEL_PRODUCTO,
    SALIR_COMPRA
};

struct Proveedor
{
    unsigned id;
    char producto_nombre[50];
    unsigned cantidad;
    unsigned precio;
    bool full;
};

/**
 * @brief estructuras de comprar producto
 * me servira para organizar la opcion de compras 
 * 
 */
struct compra
{
    char nombre[50];
    unsigned precio;
    unsigned cantidad;
    bool comprado;
    bool eliminado;
};

/*
    Compras:  Comprar productos, Crear y comprar productos, Ver compras hechas, Eliminar 
    y editar compras(sudo)
/*variables globales*/
/**
 * @brief mostrara el menu de compras y opciones al usuario y podra elegir  
 * 
 * @return true el uusuario no ha salido. se ejecutara.
 * @return false el usurio salio. se parara.
 */
bool compras_menu();

/**
 * @brief mostrar los productos a comprar.
 * 
 * @return true se ha podido compro el producto.
 * @return false no se pudo comprar el productointente otra vez.
 */
bool comprar_productos();

/**
 * @brief esta funcion me permitira crear los productos.  
 * 
 * @return true se ha creado el producto.
 * @return false no se ha podido crear. 
 */
bool crear_productos();


/**
 * @brief que vueelve a la interfaz inicial del programa.
 * 
 * @return true si seleciona te redirecciona al inicio del programa.
 * @return false siendo los opuesto no se podra salir de la opcion de compras.
 */
void salir();

/**
 * @brief una vez que se compre algo se tiene que guardar nombre del producto ,cantidad ,precio
 * 
 * @return true si se guarda
 * @return false si no se guarda
 */
bool compra_historial();

void mostrar_productos_suplidor();//me servira para ver los productos del la funcion.

void llenar_productos_suplidor();//esta de aca me servira para llenar el lugar con nombre etc...de producto. 

/**
 * @brief Devuelve el suplidor.
 * 
 * @return struct Proveedor Una copia de la struct.
 */
int obtener_suplidor_suma();

void inicia_producto();//inicializacion

#endif //COMPRA_H
