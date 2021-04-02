#include <stdio.h>
#include <stdlib.h>//system
#include<conio.h>
#include <string.h> //en esta lib se encuentra la funcion gets y strcmp

//mis credenciales
#define ADMIN "milvia"
#define CLAVEADMIN "mimi"
#define LONGITUD 50

int main()
{
    char usuario[LONGITUD + 1];
    /*variables que van a permitir el nombre de ususario y la contrasena que va a ingresar el usuario que quiere logearse
pongo mas uno para el caracter NULL*/
    char clave[LONGITUD + 1];
    int intento = 0;//veces que intenta entrar el usuario
    int ingresa = 0;// 0 = falso,, 1= verdadero, va a contar cuantas veces ingresa el user
    char caracter;
    int i = 0;//indice, indica la posicion donde ingresare el caracter 
    do
    {
        system("cls");
        printf("\n\t\t\tINICIO DE SESION\n");
        printf("\t\t\t***************\n");
        printf("\n\tUSUARIO:");
        gets(usuario);
        printf("\tCLAVE:");
        while (caracter = getch()) 
        {
            if(caracter == 13){
                clave[i] = '\0';// se guarda el caracter null, me indica el final de una cadena
                break;
            }else if (caracter == 8) {
                if(i > 0 ){
                       i--;
                printf("\b \b");//mueve el cursor hacia la izquierda
                }
             
            }else {
                if(i < LONGITUD){
                  printf("*");
           clave[i] = caracter;
           i++;
            }
            }
        }
        if (strcmp(ADMIN, usuario) == 0 && strcmp(CLAVEADMIN, clave) == 0)
        {
            ingresa = 1;
          
        }
        else
        {
            printf("\n\t Usuario y/o clave incorrectas\n");
            intento++;
            system("pause");
        }
    } while (intento < 3 && ingresa == 0);
    if(ingresa == 1){
        printf("\n\t Bienvenido al Sistema \n");
    }else{
        printf("\n\t Ha sobrepasado el numero de intentos maximos permitidos \n");

    }

    return 0;
}