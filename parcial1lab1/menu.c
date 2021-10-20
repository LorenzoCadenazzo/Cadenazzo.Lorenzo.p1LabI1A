#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "extras.h"
#include "validations.h"


int menu_main()
{
    int option;

    printf("\n ***************  MENU  ***************");
    printf("\n                                   ");
    printf("\n 1.  ALTA DE BICI                ");
    printf("\n 2.  BAJA DE BICI                ");
    printf("\n 3.  MODIFICACION DE BICI        ");
    printf("\n 4.  LISTAR MOTOS                ");
    printf("\n 5.  LISTAR TIPOS                ");
    printf("\n 6.  LISTAR COLORES              ");
    printf("\n 7.  LISTAR SERVICIOS            ");
    printf("\n 8.  ALTA TRABAJO                ");
    printf("\n 9.  LISTAR TRABAJOS             ");
    printf("\n 10. SALIR                       ");

    option = getOption(10);

	return option;
}

int menu_biciModify()
{
    int option;

    printf("\n          Que desea modificar?");
    printf("\n");
    printf("\n 1. TIPO");
    printf("\n 2. RODADO");
    printf("\n 3. VOLVER");


    option = getOption(3);

    return option;
}
