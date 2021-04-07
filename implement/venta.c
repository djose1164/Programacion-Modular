#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/venta.h"
#include "../include/inventario.h"
#include "../include/login.h"
#include<stdbool.h>


// Variables globales.
facturas Facturas[50];
#define MAX_LETTERS 50
struct products;


void vender() /*rellena la factura y calcula el total de la venta, resta 
               los productos del inventario,*/
{

    system("cls");

    printf("\t\t\t\t Modular Programming Ventas \n");
    printf("Rellene con los datos  pedidos\n");
    printf("\nNombre cliente:");
    fgets(Facturas->nombre_cliente,MAX_LETTERS,stdin);
    printf("\tAtendido por:\n");
    fgets(Facturas->empleado_en_turno,MAX_LETTERS,stdin);
    printf("\n\tProducto");
    strcpy(Facturas->nombre_producto,);//,"Aca va lo que vas a guardar."
    printf("\tCantidad");
    strcpy( Facturas->Cantidad,product_name"Aca va lo que vas a guardar.");
    printf("\t Precio");//Precio no se de donde va a salir, creo que de inventario
    //TODO quiero hacer que el precio y el total aparezcan solos, dependiendo de la cantidad 
    //TODO y dependiendo del producto que este ingresando
    scanf("%f", &Facturas->Precio);
    printf("\tTotal ");
    scanf("%f", &Facturas->Total);
    for (size_t i = 0; i < count; i++)
    {
        /* code */
    }
    
}
void agregar_mas_articulos()
{ //Da la opcion de agregar mas articulos a la factura con key1
    int i, j;
    int agregar_articulos = 1;
    Facturas->Cantidad *= Facturas.//Quiero hacer que el total a pagar sea igual a Cantidad * Precio del producto

    printf("Desea agregar mas articulos?");
    fgets("%d", &agregar_articulos);

    switch (agregar_articulos)
    {
    case 1:
        void vender(Facturas); //como puedo llamar la funcion aqui para que se ejecute en este caso
        break;

    case 0:
        printf("%d", Facturas->TotalaPagar); //Necesito imprimir el total a Pagar, me marca como que no existe esta estruct

        break;
    }
    system("cls");
    login_menu(); //debe volver a imprimir el menu de inicio sin registrar el user
}
void ver_ventas()
{ //permite ver todas las Facturas realizadas de acuerdo al nombre del cliente
    printf("Usted ha elegido ver ventas \n Ingrese el nombre del cliente: \n");
    fgets(Facturas->nombre_cliente,MAX_LETTERS,stdin); //necesita buscar el nombre del cliente e imprimir esa factura
    printf()//TODO ?Como puedo hacer para presentar todas las facturas registradas??
}
void editar_pedido_sudo()
{

    
    //TODO: permite editar cualquier factura, con la clave y usuario del admin
}
void eliminiar_pedido_sudo()
{
    /*
TODO: permite editar cualquier factura, con la clave y usuario del admin 
TODO: Introduciendo el nombre del cliente se elimina automaticamente la factura
*/
}
void caja_registradora()
{ //Da el total de todas las Facturas realizadas
for (caja_registradora)
printf("\n\t\t\t******El total de las ventas que hizo ******\n");

}
void salir()
{
printf("*****Usted salio de Ventas *****");
Sleep(1);
system("cls");
login_menu();
     
 // TODO: Esta me permite salir del modulo ventas y volver al inicio_login
    
}
