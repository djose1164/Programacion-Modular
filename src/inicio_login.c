#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#ifdef __WIN32
#include <windows.h> /* Windows dectetado. */
#else
#include <unistdio.h> /* Linux detectado. */
#endif				  //__WIN32
#include "../include/database.h"
//#include"inventario.h"

/**
 * @brief Mientras retorne verdadera deberia ejecutarse.
 * 
 * @return true Mientras no se haya logeado deberia retornar true.
 * @return false Significa que se logeo o se registro. No se.
 */
bool login_menu()
{
/**Este es el inicio, luego de entrar al sistema
	 * 
	 */
	int options;
	// system("color 38"); //cambia el color, el numero cambia el fondo y la letra cambia el color de letra
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

	return true;
}

int main()
{
	bool status = login_menu();

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