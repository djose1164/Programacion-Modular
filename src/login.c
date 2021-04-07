#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdint.h>
#ifdef __WIN32
#include <windows.h> /* Windows dectetado. */
#elif __linux__
#include <unistd.h> /* Linux detectado. */
#endif				//__WIN32
#include "../include/database.h"
#include "../include/login.h"
#include "../include/inventario.h"
//#include"inventario.h"

#define MAX_LETTERS 50

// *-*-*-*-*-*-*-*-*-*-*-*- Login para el Menu *-*-*-*-*-*-*-*-*-*-*-*-

int login_menu()
{
	/**Este es el inicio, luego de entrar al sistema
	 * 
	 */
	unsigned options, tecla;
	// system("color 38"); //cambia el color, el numero cambia el fondo
	// y la letra cambia el color de letra
	// No funciona en Linux ^^^

	// Para que no se sienta la espera.
	printf("Empezando sistema de carga...\n");
	for (size_t i = 0; i <= 100; i++)
	{

		if (i % 25 == 0)
		{
			fflush(stdout);
			printf("Hackeando a la NASA %zu%% completado.\r", i); /* Ahora hace 
			esencia con el nombre, jajaja. */
		}
		else
			continue;

		if (i == 100)
		{
			fflush(stdout);
			system("cls||clear");
		}
#ifdef __WIN32
		Sleep(1000);
#else
		sleep(1);
#endif //__WIN32
	}
	system("cls||clear");

	printf("\n\t\t\aBienvenido(a) a el:\tColmado jackeando la NASA\n");
	printf("\n\tSeleccione el modulo al que desea acceder:  \n");
	printf("\n\t1- Inventario \n");
	printf("\t2- Compras    \n");
	printf("\t3- Ventas     \n");
	printf("\t4- Contabilidad\n");
	printf("\t5- tSalir \n"); // El usuario saldra cuando presione 5.
	scanf("%d", &options);

	// TODO: Mejorar con un for y un contador de intentos.
	do
	{
		printf("Heyyy, debes eligir una opcion correcta!!!\n");
		printf("\n\tSeleccione el modulo al que desea acceder:  \n");
		printf("\n\t1- Inventario \n");
		printf("\t2- Compras    \n");
		printf("\t3- Ventas     \n");
		printf("\t4- Contabilidad\n");
		printf("\t5- Salir \n"); // El usuario saldra cuando presione 5.

	} while (options < 0 || options > 5);

	switch (options)
	{
	case inventario:
		//inventario();
		break;
	case compras:
		//compras();
		break;
	case ventas:
		//ventas();
		break;
	case contabilidad:
		//contabilidad();
		break;
	case salir:
		system("cls||clear");
		printf("Hackear a la NASA dejo de ser un sueno.\n");
		return 0;
	default:
		printf("Parece que hay un bug. Envia un issue detallando el bug.\n");
		break;
	}
	//getch ();
	/**
	 * Si presiona la letra e, se borra todo en pantalla y se imprime despedida
	 */
	return -1; // Error
}

// *-*-*-*-*-*-*-*-*-*-*-*- Login para el Menu de user *-*-*-*-*-*-*-*-*-*-*-*-
/** IMPORTANT: Esta debe ser la primiera pantalla que el usario vea. */

int login_user()
{
	// TODO: Imprimir mas informacion.
	// Por ejemplo, en printf("(1) Registrarse.\n"
	//		   				  "(2) Logearse.\n");
	// Deberia mostromar mas informacion y encabezado.

	/**Almacena el nombre del usuario a registrar. */
	char username[MAX_LETTERS];
	/**Almacena el password del usuario a registrar. */
	char password[MAX_LETTERS];
	/**Es admin? Si lo es 1, si no lo es 0. */
	int is_admin;
	/**Donde se guardara la opcion eligida por el usuario. */
	unsigned temp = 0;

	do
	{ /**Mientras el usuario no entre una opcion valida el loop se repetira. */
		printf("(1) Registrarse.\n"
			   "(2) Logearse.\n"
			   "Opcion: ");
		scanf("%d", &temp);
		getchar();
		system("cls||clear");

		/**Imprime al usuario q coga una opcion correta. */
		if (temp < 0 || temp > 2)
			printf("Por favor elige una opcion correta.\n");
	} while (temp < 0 || temp > 2);

	/**Dependiendo del valor en temp, el usuario se logeara o registrara. */
	switch (temp)
	{
	case 1: // Registrarse.
		printf("Username: ");
		fgets(username, MAX_LETTERS, stdin);
		// Cambiar \n con \0
		username[strcspn(username, "\n")] = 0;

		printf("Password: ");
		fgets(password, MAX_LETTERS, stdin);
		password[strcspn(password, "\n")] = 0;

		printf("Es admin: ");
		scanf("%d", &is_admin);
		getchar();

		system("clear||cls");
		// Anade al usuario.
		add_user(username, password, is_admin);

		// Luego entra en un blucle hasta que presione la letra de salir.
		for (; login_menu();)
			;

		return 0;

	case 2: // Logearse.
		printf("Username: ");
		fgets(username, MAX_LETTERS, stdin);
		// Cambiar \n con \0
		username[strcspn(username, "\n")] = 0;

		printf("Password: ");
		fgets(password, MAX_LETTERS, stdin);
		password[strcspn(password, "\n")] = 0;

		if (!validate(username, password))
			return 0;
		else
			return 1;
	}

	return -1; // Error
}
