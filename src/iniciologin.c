#include <stdio.h>
#include<stdlib.h>
#include"database.h"
#include"inventario.h"


int main()
{
	/**Este es el inicio, luego de entrar al sistema
	 * 
	 */
	int options;
	system ("color 0c");//cambia el color, el numero cambia el fondo y la letra cambia el color de letra

	for (size_t i = 0; i <=100; i++)
	{
	
        if (i % 25 == 0)
		{
		system("cls");
		printf("Cargando.... %d%c completado",i,37);
		}
		else 
		     continue;
			sleep(1);
	}
	system("cls");

	 printf("\n\t\t\t\t\aBienvenido(a):\tColmado jackeando la NASA\n");
	 printf("\n\tSeleccione el modulo al que desea acceder:  \n");
	 printf("\n\t1- Inventario \n");
	 printf("\t2- Compras    \n");
	 printf("\t3- Ventas     \n");
	 printf("\t4- Contabilidad\n");
	 printf(" \tSalir \n");
	 scanf("%d",&options);

	 /*switch (options)
	 {
	 case 1: Inventario(); break;
	 case 2: Compras(); break;
	 case 3: Ventas(); break;
	 case 4: Contabilidad(); break;
	 default : Salir();
	 }*/
	//getch ();
	return 0;
}