#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "validations.h"

int getOption(int maxOption)
{
    int option;

    validations_getUnsignedInt(&option, "\n Introduzca una opcion: ", "\nError. Opcion inexistente\n", 1, sizeof(int),0, maxOption,4);

    return option;
}


int confirm(int menuOption)
{
    char option;
    int confirmed = 0;


    switch(menuOption)
    {
        case 2:
                validations_getChar(&option,"\nConfirma la baja? (s/n): ", "\nError. Caracter invalido.\nConfirma la baja? (s/n): ",4);

                if(option == 's' || option == 'S')
                {
                    confirmed = 1;
                    printf("\n Registro dado de baja exitosamente");
                    system("pause");
                }
                else
                {
                    printf("\n El registro no fue dado de baja.");
                    system("pause");
                }
                break;

        case 3:
                validations_getChar(&option,"\nConfirma la modificacion? (s/n): ", "\nError. Caracter invalido.\nConfirma la modificacion? (s/n): ",4);

                if(option == 's' || option == 'S')
                {
                    confirmed = 1;
                    printf("\n Registro modificado exitosamente \n");
                    system("pause");
                }
                else
                {
                    printf("\n El registro no fue modificado.");
                    system("pause");
                }
                break;
        case 10:
                validations_getChar(&option,"\n Esta seguro que desea salir? (s/n): ", "\nError. Caracter invalido.\n Esta seguro que desea salir? (s/n): ",2);

                if(option == 's' || option == 'S')
                {
                    confirmed = 1;
                }
                break;
    }
    return confirmed;
}
