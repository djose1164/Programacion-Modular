#include <stdio.h>
#include "../include/users.h"

int main()
{
	__init_usersarr__();
	add_user("djose1164", "1234");
	short status = validate_user("djose1164", "124");

	if (!status)
		printf("Bienvenido!\n");
	else
		switch (status)
		{
		case invalid_user:
			printf("Tu nombre de usuario no fue encontrado.\n"
				   "Verica que te hallas registrado.\n");
			break;
		case invalid_password:
			printf("Tu contraseña es incorrecta.\n");
			break;
		default:
			printf("Parece que hay un bug.\n");
			break;
		}
	return (0);
}