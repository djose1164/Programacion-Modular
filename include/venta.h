typedef struct IngresodeVentas //Estructura para llenar datos de la facturacion
{
    char nombre_cliente;
    char empleado_en_turno;
    char nombre_producto;
    int cantidad;
    float precio;
    float total;
    float total_a_Pagar;

}facturas[100]; //vector de 100 para las facturas que quiera hacer