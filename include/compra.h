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





#endif //COMPRA_H

