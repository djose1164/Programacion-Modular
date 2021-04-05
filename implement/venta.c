#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"../include/venta.h"
//#include<main.h

void vender ()/*hace la factura y calcula el total de la venta, resta los productos del inventario,*/
{
  facturas Facturas [50];
    system("cls");

    printf("\t\t\t\t Modular Programming Ventas \n");
    printf("Rellene con los datos  pedidos\n");
    printf("Nombre cliente \tTotal \n");
    scanf("%c",&Facturas->Nombrecliente);
    printf("\tAtendido por:");
    scanf("%c",&Facturas->Empleadoenturno);
    printf("\tProducto");
    scanf("%c",&Facturas->NombreProducto);
    printf("\tCantidad");
    scanf("%d",&Facturas->Cantidad);
    printf("\t Precio");
    scanf("%f",&Facturas->Precio);
    printf("\tTotal ");
    scanf("%f",&Facturas->Total);
    printf("\n\n Total a Pagar");
    scanf("%f",&Facturas->TotalaPagar);

}
/*void agregar_mas_articulos (){
    int i,j;
    int agregar_articulos = 1;
    printf("Desea agregar mas articulos?")
    scanf("%d",agregar_articulos)

    switch (agregar_articulos)
    {
    case 1:
        void vender ();//como puedo llamar la funcion aqui para que se ejecute en este caso
        break;
    
    default:

        break;
    }
}
void ver_ventas (){

}
void editar_pedido_sudo (){

}
void eliminiar_pedido_sudo (){

}
void caja_registradora (){

}
void salir (){

}*/
