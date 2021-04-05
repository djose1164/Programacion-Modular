#include <stdio.h>

int main()
{
	int options;
	system ("color 0c");//cambia el color, el numero cambia el fondo y la letra cambia el color de letra

	 printf("\n\t\t\t\tBienvenido(a):     Modular Programming\n");
	 printf("\n\tSeleccione el modulo al que desea acceder:  \n");
	 printf("\n\t1- Inventario \n");
	 printf("\t2- Compras    \n");
	 printf("\t3- Ventas     \n");
	 printf("\t4- Contabilidad\n");
	 printf(" \tSalir \n");
	 scanf("%d",&options);

	 switch (options)
	 {
	 case 1: Inventario(); break;
	 case 2: Compras(); break;
	 case 3: Ventas(); break;
	 case 4: Contabilidad(); break;
	 default : Salir();
	 }
	getch ();
	return 0;
}