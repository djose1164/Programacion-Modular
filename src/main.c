/************************************************************/
/*           Programacion para mecatronicos                 */
/*  Nombres y matriculas: 								    */
/*     	Jose S. Daniel - 2020-10646						    */
/*     	Milvia Victorio - 2020-9598						    */
/*     	Engeers O.Rossis - 2020-10573 					    */
/*     	Robeert Avila - 2019-8215						    */
/*  Seccion: Miercoles                                      */
/*  Practica: Programacion modular.                         */
/*  Fecha: 17/4/2021                                        */
/************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/database.h"
#include "../include/inventario.h"
#include "../include/login.h"

typedef struct products Product;

int main(int argc, char *const argv[])
{
#ifdef __linux__
	printf("\033[100m"
		   "\033[34m"); // Cambia el color de la letra en linux.
						// Para mas info: https://opensource.com/article/19/9/linux-terminal-colors
#else
	system("color 8B"); //cambia el color, el numero cambia el fondo
						// y la letra cambia el color de letra
						// https://www.geeksforgeeks.org/how-to-print-colored-text-in-c/
#endif // __linux__
	system("cls||clear");
	/**
	 * TODO: Hacer algo.
	 */
	if (argv[1] ? !strcmp(argv[1], "1234") : 0)
		login_menu();
	else
		login_user();

	Product product = {
		.id = 1,
		.available_quantity = 20,
		.full = true,
		.sell_price = 100,
		.product_name = "Algo de comer",
	};

	printf("El programa esta en: %s\n", argv[0]);

#if 0  //COMMENTED
	add_user("djose1164", "1234", 1);
	int status = validate("djose1164", "1234");
	switch (status)
	{
	case admin:
		printf("Eres admin.\n");
		short temp = save_product("Lata de maiz", 35, 5);
		temp = save_product("Lata de maiz2", 35, 5);
		temp = save_product("Lata de maiz3", 35, 5);
		temp = save_product("Lata de maiz4", 35, 5);
		temp = save_product("Lata de maiz5", 35, 5);
		if (temp)
		{
			printf("The product have been saved successfully!\n");
			report_inventory();
			edit_product(product.id, product.product_name, product.sell_price, 
						 product.available_quantity);
			printf("\n*-*-*-*-*-After Update.*-*-*-*-*-\n");
			report_inventory();
		}
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
#endif //COMMENTED

	return 0;
}