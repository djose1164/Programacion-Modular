#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdint.h>
#ifdef __WIN32
#include <windows.h> /* Windows dectetado. */
#include <conio.h>
#elif __linux__
#include <unistd.h> /* Linux detectado. */
#include <sys/ioctl.h>
#include <termios.h>
#endif //__WIN32
#include "../include/database.h"
#include "../include/login.h"
#include "../include/inventario.h"
//#include"inventario.h"

#define MAX_LETTERS 50

const short time = 2;

#ifdef __linux__
static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo)
{
	tcgetattr(0, &old);			/* grab old terminal i/o settings */
	current = old;				/* make new settings same as old settings */
	current.c_lflag &= ~ICANON; /* disable buffered i/o */
	if (echo)
		current.c_lflag |= ECHO; /* set echo mode */

	else
		current.c_lflag &= ~ECHO; /* set no echo mode */

	tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void)
{
	tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo)
{
	char ch;
	initTermios(echo);
	ch = getchar();
	resetTermios();
	return ch;
}

/* Read 1 character without echo */
char getch(void)
{
	return getch_(0);
}
#endif // __linux__

char *get_password(char *const password)
{
	char c;
	for (size_t i = 0; (c = getch()) != EOF || (c = getch()) != '\n'; ++i)
	{
		if (c == '\n')
		{
			password[i] = '\0';
			break;
		}
		else
			password[i] = c;
	}
	return password;
}

// *-*-*-*-*-*-*-*-*-*-*-*- Login para el Menu *-*-*-*-*-*-*-*-*-*-*-*-

int login_menu()
{
	/**Este es el inicio, luego de entrar al sistema
	 * 
	 */
	unsigned options = 0;

	// Para que no se sienta la espera.
	printf("Empezando sistema de carga...\n");
	system_loading(time);

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

	fflush(stdout);
	system("cls||clear");
	switch (options)
	{
	case inventario:
		printf("\aUps! En construccion!\n"
			   "Presione cualquier tecla para finalizar la ejecucion...");
		getch();
		break;
	case compras:
		printf("\aUps! En construccion!\n"
			   "Presione cualquier tecla para finalizar la ejecucion...");
		getch();
		break;
	case ventas:
		printf("\aUps! En construccion!\n"
			   "Presione cualquier tecla para finalizar la ejecucion...");
		getch();
		break;
	case contabilidad:
		printf("\aUps! En construccion!\n"
			   "Presione cualquier tecla para finalizar la ejecucion...");
		getch();
		break;
	case salir:
		printf("Hackear a la NASA dejo de ser un sueno.\n");
		return 0;
	default:
		fprintf(stderr, "Verifica que hayas ingresado tus credenciales correctamente o "
						"envia un issue detallando el posible bug.\n");
		break;
	}
	putchar('\n');
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

	// Para que no se sienta la espera.
	printf("Empezando sistema de carga...\n");
	system_loading(time);
	do
	{ /**Mientras el usuario no entre una opcion valida el loop se repetira. */
		printf("\n\t\t\t\aHaz ingresado a la plataforma de Colmado Hackeando la NASA\n"
			   "\tSi ya estas registrado ingresa (2).\n"
			   "\tSi eres nuevo ingresa (1).\n"
			   "\t(1) Registrarse.\n"
			   "\t(2) Logearse.\n"
			   "\tOpcion: ");
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

		printf("\t\t\aHola! Aca podras registrarte. Por favor llena los siguientes campos.\n"
			   "Username: ");
		fgets(username, MAX_LETTERS, stdin);
		// Cambiar \n con \0
		username[strcspn(username, "\n")] = 0;

		printf("Password: ");
		strcpy(password, get_password(password));

		printf("\nEs admin: ");
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
					   "\t\aAsegurate de haber ingresado tus datos correctament. "
					   "Intentos restantes: %zu \n\n",
					   i);

			printf("\t\aUsername: ");
			fgets(username, MAX_LETTERS, stdin);
			// Cambiar \n con \0
			username[strcspn(username, "\n")] = 0;

			printf("\t\aPassword: ");
			strcpy(password, get_password(password));

			if (!validate(username, password))
			// TODO: mostrar el login menu y/o mostrar un mensaje de que se ha logeado.
			{
				// Quita el anterior mensaje para mostrar este printf y el sistema
				// de carga.
				system("cls||clear");
				printf("\n\t\t\aEfectivamente estas dentro!\n");

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

void system_loading(int time)
{
#ifdef __WIN32
	time += time * 1000
#endif //__WIN32

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
		};
#ifdef __WIN32
		Sleep(time);
#else
		sleep(time);
#endif //__WIN32
	}
}