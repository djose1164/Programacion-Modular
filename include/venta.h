typedef struct IngresodeVentas //Estructura para llenar datos de la facturacion
{
    // La nomenclatura esta mal. Debe ser nombreProducto o nombre_producto.
    char Nombrecliente;
    char Empleadoenturno;
    char NombreProducto;
    int Cantidad;
    float Precio;
    float Total;
    float TotalaPagar;

}facturas; //vector de 100 para las facturas que quiera hacer