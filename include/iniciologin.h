#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int main()
{
	int options;
    system ("color 0c");

	 printf("\n\t\tBienvenido(a):     Modular Programming\n");
	 printf("\nSeleccione el modulo al que desea acceder:  \n");
	 printf("\n1- Inventario \n");
	 printf("2- Compras    \n");
	 printf("3- Ventas     \n");
	 printf("4- Contabilidad\n");
	 printf(" Salir \n");
	 scanf("%d",&options);

	 switch (options)
	 {
	 case 1: Inventario(); break;
	 case 2: Compras(); break;
	 case 3: Ventas(); break;
	 case 4: Contabilidad(); break;
	 default :Salir();
	 }
	getch ();
} 