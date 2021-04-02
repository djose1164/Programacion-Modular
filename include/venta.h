typedef struct IngresodeVentas //Estructura para llenar datos de la facturacion
{
    char Nombrecliente[10];
    char Empleadoenturno[10];
    char NombreProducto[15];
    int Cantidad;
    float Precio;
    float Total;
    float TotalaPagar;

}facturas[100]; //vector de 100 para las facturas que quiera hacer