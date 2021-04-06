#ifndef VENTA_H
#define VENTA_H

typedef struct IngresodeVentas //Estructura para llenar datos de la facturacion
{
    // La nomenclatura esta mal. Debe ser nombreProducto o nombre_producto.
    char Nombrecliente[50];
    char Empleadoenturno[50];
    char NombreProducto[50];
    int Cantidad;
    float Precio;
    float Total;
    float TotalaPagar;

} facturas; //vector de 100 para las facturas que quiera hacer

#endif //VENTA_H