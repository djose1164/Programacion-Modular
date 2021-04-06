#include <stdio.h>
#include <stdlib.h>
#include "../include/database.h"
#include "../include/inventario.h"
#include "../include/sqlite3.h"
#include <stdbool.h>
#include <string.h>

void add_user(const char *username, const char *password, int is_admin);
int main(int argc, char *const argv[])
{
	/**
	 * TODO: Hacer algo.
	 */
	if (argv[1] ? !strcmp(argv[1], "1234") : 0)
		printf("Welcome back, master.\n");

	printf("El programa esta en: %s\n", argv[0]);

	add_user("djose1164", "1234", 1);
	int status = validate("djose1164", "1234");
	switch (status)
	{
	case admin:
		printf("Eres admin.\n");
		short temp = save_product("Lata de maiz", 35, 5);
		if (temp)
			printf("The product have been saved successfully!\n");
		else
			printf("It looks like the product couldn't be saved. "
				   "Send an issue about this bug.\n");
		break;
	case guest:
		printf("Eres invitado.\n");
		break;
	case not_found:
		printf("Verifica que hayas ingresado los datos correctamente.\n");
		break;
	default:
		printf("Error! Put a issue well explained about this bug.\n");
		break;
	}
	/**Este es el inicio, luego de entrar al sistema
	 * 
	 */
	int options;
	system("color 0c"); //cambia el color, el numero cambia el fondo y la letra cambia el color de letra

	for (size_t i = 0; i <= 100; i++)
	{

		if (i % 25 == 0)
		{
			system("cls");
			printf("Cargando.... %d%c completado", i, 37);
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
	scanf("%d", &options);

	getchar();
}

/* switch (options)
	 {
	 case 1: Inventario(); break;
	 case 2: Compras(); break;
	 case 3: Ventas(); break;
	 case 4: Contabilidad(); break;
	 default : Salir();
	 }*/
//getch ();
