/*
    Compras:  Comprar producotos, Crear y comprar productos, Ver compras hechas, Eliminar 
    y editar compras(sudo)
*/

struct bought_product
{
    char name[50];
};

/**
 * @brief Para comprar productos a un suplidor.
 * 
 */
void buy_product(struct bought_product *const product)
{
    bool status = save_product(product);
    if (status)
        printf("Producto guardado.\n");
    else
        printf("El producto no se ha podido guardado.\n");

}
