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
	unsigned options = 0;

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

	/**+-+-+-+-+-+-Empieza el menu+-+-+-+-+-+- */

	// TODO: #14 Mejorar con un for y un contador de intentos.
	for (size_t i = 3; i > 0 || (options < 0 || options > 5); --i)
	{
		system("cls||clear");

		if ((options <= 0 && i != 3) || options > 5)
			printf("Heyyy, debes eligir una opcion correcta!!!\n"
				   "Porque, pues te quedan %zu intentos.\n",
				   i);

		printf("\n\tSeleccione el modulo al que desea acceder:  \n"
			   "\n\t1- Inventario \n"
			   "\t2- Compras    \n"
			   "\t3- Ventas     \n"
			   "\t4- Contabilidad\n"
			   "\t5- Salir \n"); // El usuario saldra cuando presione 5.
		scanf(" %d", &options);
		getchar();

		if (options >= inventario && options <= salir)
			break;
	}

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
		fprintf(stderr, "Verifica que hayas ingresado tus credenciales correctamente o "
						"envia un issue detallando el posible bug.\n");
		break;
	}

	return 0;
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
		printf("\n\t\t\tHaz ingresado a la plataforma de Colmado Hacheando la NASA\n"
			   "Si eres nuevo ingresa (1).\n"
			   "Si ya estas registrado ingresa (2).\n"
			   "(1) Registrarse.\n"
			   "(2) Logearse.\n"
			   "Opcion: ");
		scanf(" %d", &temp);
		getchar();
		system("cls||clear");

		/**Imprime al usuario q coga una opcion correcta. */
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
		scanf(" %d", &is_admin);
		getchar();

		system("clear||cls");
		// Anade al usuario.
		add_user(username, password, is_admin);

		// Luego entra en un blucle hasta que presione la letra de salir.
		for (; login_menu();)
			;

		return 0;

	case 2: // Logearse.
		for (size_t i = 3; i > 0;)
		{
			// TODO: #13 falta un encabezado q le diga al usuario q hacer.
			printf("\t\t\aHola! Estas actualmenteen en el login. Ingresa tus "
				   "credenciales para poder ingresar al sistema!\n\n");

			if (i != 3 && i >= 1)
				printf("\t\t\aUps! Tus credenciales no aparecen en la base de datos.\n"
					   "\tAsegurate de haber ingresado tus datos correctament. "
					   "Intentos restantes: %zu \n\n",
					   i);

			printf("\t\aUsername: ");
			fgets(username, MAX_LETTERS, stdin);
			// Cambiar \n con \0
			username[strcspn(username, "\n")] = 0;

			printf("\t\aPassword: ");
			fgets(password, MAX_LETTERS, stdin);
			password[strcspn(password, "\n")] = 0;

			if (!validate(username, password))
			// TODO: mostrar el login menu y/o mostrar un mensaje de que se ha logeado.
			{
				// Quita el anterior mensaje para mostrar este printf y el sistema
				// de carga.
				system("cls||clear");
				printf("\nEfectivamente estas dentro!\n");
#if defined(__linux__) //__linux__
				sleep(2);
#elif defines(__WIN32)
				Sleep(2000);
#endif //__linux__
				for (; login_menu();)
					;
				return 0;
			}
			else
			{
				--i;
			}
			// Limpia la pantalla para la segunda vuelta.
			system("cls||clear");
		}
	}

	return -1; // Error
}
