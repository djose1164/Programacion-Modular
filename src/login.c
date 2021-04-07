#include <stdio.h>
#include <stdlib.h>
//#include <stdint.h>
#ifdef __WIN32
#include <windows.h> /* Windows dectetado. */
#else
#include <unistd.h> /* Linux detectado. */
#endif				//__WIN32
#include "../include/database.h"
#include "../include/login.h"
//#include"inventario.h"

#define MAX_LETTERS 50

// *-*-*-*-*-*-*-*-*-*-*-*- Login para el Menu *-*-*-*-*-*-*-*-*-*-*-*-

int login_menu()
{
	/**Este es el inicio, luego de entrar al sistema
	 * 
	 */
	int options,tecla;
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
		Sleep(1);
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
	printf(" \tSalir \n"); // Salir deberia tener una clave para salir.

	if (kbhit() == 1){
             tecla = getch(); 
            if (tecla == 'e')
			system("cls||clear");/*Si pulsa la tecla 'e' se limpia la pantalla, 
			imprime un mensaje y sale del programa*/
			printf("\t\t\tHaz salido de Colmado jackeando la NASA");
			Sleep(1);
			getch();
            }

	/*switch (options)
	 {
	 case 1: Inventario(); break;
	 case 2: Compras(); break;
	 case 3: Ventas(); break;
	 case 4: Contabilidad(); break;
	 default : Salir();
	 }*/
	//getch ();

	return -1; // Error
}
// *-*-*-*-*-*-*-*-*-*-*-*- Login para el Menu de user *-*-*-*-*-*-*-*-*-*-*-*-

int login_user()
{
	/**Almacena el nombre del usuario a registrar. */
	char username[MAX_LETTERS];
	/**Almacena el password del usuario a registrar. */
	char password[MAX_LETTERS];
	/**Es admin? Si lo es 1, si no lo es 0. */
	int is_admin;

	printf("Username: ");
	// TODO: Si da error usar dynamic memory.
	fgets(username, MAX_LETTERS, stdin);

	printf("Password: ");
	fgets(password, MAX_LETTERS, stdin);

	printf("Es admin: ");
	scanf("%d", &is_admin);
	getchar();

	// Anade al usuario.
	add_user(username, password, is_admin);
	// Luego entra en un blucle hasta que presione la letra de salir.
	for (; login_menu();)
		; // Con el punto y coma aca, es mas leible.

	int temp = validate(username, password);
	if (!temp)
		printf("Estas dentro para hackear a la NASA.\n");
	else
		printf("Aun tas joven.");
	int login_menu();

	return -1; // Error
}