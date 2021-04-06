#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/venta.h"
#include"../include/iniciologin.h"

void vender ()/*hace la factura y calcula el total de la venta, resta los productos del inventario,*/
{
  facturas Facturas [50];
    system("cls");

    printf("\t\t\t\t Modular Programming Ventas \n");
    printf("Rellene con los datos  pedidos\n");
    printf("Nombre cliente \n");
    scanf("%c",&Facturas->Nombrecliente);//ingresa nombre del cliente y debe guardarlo para verla mas tarde(no se donde la guardaria)
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
    Facturas->Total = Facturas->Precio * Facturas->Cantidad;
    printf("\n\n Total a Pagar");
    scanf("%f",&Facturas->TotalaPagar);
    Facturas->TotalaPagar = 

}
void agregar_mas_articulos (){//Da la opcion de agregar mas articulos a la factura con key1
    int i,j;
    int agregar_articulos = 1;
  
    printf("Desea agregar mas articulos?");
    scanf("%d",&agregar_articulos);

    switch (agregar_articulos)
    {
    case 1:
        void vender (Facturas);//como puedo llamar la funcion aqui para que se ejecute en este caso
        break;
    
    case 0:
        printf("%d",TotalaPagar);//Necesito imorimir el total a Pagar, me marca como que no existe esta estruct

        break;
    }
    system("cls");
    main();//debe volver a imprimir el menu de inicio sin registrar el user
}
void ver_ventas (){//permite ver todas las facturas realizadas de acuerdo al nombre del cliente
printf("Usted ha elegido ver ventas \n Ingrese el nombre del cliente: \n");
scanf("%s");//necesita buscar el nombre del cliente e imprimir esa factura

}
void editar_pedido_sudo (){ //permite editar cualquier factura, con la clave y usuario del admin

}
void eliminiar_pedido_sudo (){
/*permite editar cualquier factura, con la clave y usuario del admin
e introduciendo el nombre del cliente se elimina automaticamente*/

}
void caja_registradora (facturas){//Da el total de todas las facturas realizadas
caja_registradora = Facturas.TotalaPagar

}
void salir (){//me saca de la consola

}
