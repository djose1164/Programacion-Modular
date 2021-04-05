/**
 * @file main.c
 * @author @djose1164, @Engeers, @milv24, @robert1090
 * @brief Ejecucion del programa.
 * 
 * Mas detalles aca
 * 
 * Para iniciar seccion como root deberas pasar la contraseña: 1234, por la terminal
 * cuando vayas a ejucutar el programa. Ej: En Linux ./main 1234.
 * @version 0.1
 * @date 2021-04-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>
#include "../include/database.h"
#include "../include/inventario.h"

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

	return 0;
}