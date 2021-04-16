#ifndef COMPRA_H
#define COMPRA_H
#include <stdlib.h>

enum opciones_conpras_menu
{
    COMPRAR_PRODUCTOS = 1,
    CREAR_PRODUCTOS ,
    ELIMINAR_EDITAR ,
    HISTORIAL_DEL_PRODUCTO,
    SALIR_COMPRA
};

/**
 * 
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
};


//variables constantes
const size_t MAX_COMPRAS;

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
bool conpras_menu();

/**
 * @brief mostrar los productos a comprar.
 * 
 * @return true se ha podido compro el producto.
 * @return false no se pudo comprar el productointente otra vez.
 */
bool compar_productos(); 

/**
 * @brief esta funcion me permitira crear los productos.  
 * 
 * @return true se ha creado el producto.
 * @return false no se ha podido crear. 
 */
bool crear_productos();

/**
 * @brief esta funcion me permitira editar y eliminar los prductos.
 * 
 * @return true si el producto se ha podido editar.
 * @return false si el producto no se pudo editar. 
 */
bool editar();

/**
 * @brief Aqui podre ver las busquedas realizadas.
 * 
 * @return true si se pudo se mostrara.
 * @return false de lo contrario no se mostrara.
 */
bool historial_de_produc();

/**
 * @brief que vueelve a la interfaz inicial del programa.
 * 
 * @return true si seleciona te redirecciona al inicio del programa.
 * @return false siendo los opuesto no se podra salir de la opcion de compras.
 */
bool salir();


#endif //COMPRA_H

