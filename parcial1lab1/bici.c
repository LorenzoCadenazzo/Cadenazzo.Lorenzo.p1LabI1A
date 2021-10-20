#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "bici.h"
#include "validations.h"
#include "menu.h"
#include "extras.h"

#define EMPTY 0
#define TAKEN 1

void bici_hardcode(eBici bicicleta[], int bicicletaToHardcode)
{
    int ids[] = {1000,1001,1002,1003,1004};
    char brands[][20] = {"Venzo", "Jordan", "Olmo", "Vairo", "Raleigh"};
    int idsType[] = {1000,1001,1002,1003,1004};
    int idsColor[] = {5000,5001,5002,5003,5004};
    int rodado[] = {20,24,26,27,28};

    for(int i=0; i<bicicletaToHardcode; i++)
    {
        bicicleta[i].id = ids[i];
        strcpy(bicicleta[i].brand, brands[i]);
        bicicleta[i].idType = idsType[i];
        bicicleta[i].idColor = idsColor[i];
        bicicleta[i].rodado =  rodado[i];
        bicicleta[i].state = TAKEN;
    }
}

void bici_initializate(eBici bicicleta[], int sizeBicicleta)
{
    for(int i=0; i<sizeBicicleta; i++)
    {
        bicicleta[i].state = EMPTY;
    }
}
int bici_findFreeSpace(eBici bicicleta[], int sizeBicicleta)
{
    int ret = -1;

    for(int i=0; i<sizeBicicleta; i++)
    {
        if(bicicleta[i].state == EMPTY)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

int bici_findOne(int id, eBici bicicleta[], int sizeBicicleta)
{
    int ret = -1;

    for(int i=0; i<sizeBicicleta; i++)
    {
        if(bicicleta[i].id == id && bicicleta[i].state == TAKEN)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

int bici_load(int id, eBici bicicleta[], int sizeBicicleta, eType types[], int sizeTypes, eColor colors[], int sizeColor)
{
    eBici auxBici;
    int index = bici_findFreeSpace(bicicleta, sizeBicicleta);
    int ok = 0;

    system("cls");
    printf("\n\t*** ALTA ***\n\n");

    if(index == -1)
    {
        printf("\n\n\t\t>>> Sistema completo <<<\n\n\n");
        system("pause");
    }
    else
    {

        auxBici.id = id;

        validations_getText(auxBici.brand,"\n\tIngrese la marca: ", "\n Error. Caracteres invalidos.\n", 2, 20, 4);

        type_show(types, sizeTypes);
        validations_getUnsignedInt(&auxBici.idType,"\n\tIngrese ID del tipo: ", "\n Error. Ingrese un valor numerico entero. Rango: 1000-1003\n",1,1003,1000,1003,4);

        validations_getUnsignedInt(&auxBici.rodado,"\n Ingrese el rodado: ", "\n Error. Ingrese un valor numerico entero como 20, 24, 28.\n",1, 20, 24, 28, 4);

        auxBici.state = TAKEN;

        bicicleta[index] = auxBici;

        printf("\n Carga exitosa!. \n");
        system("cls");
        ok = 1;

    }
    return ok;
}

void bici_delate(eBici bicicleta[], int sizeBicicleta, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    int id;
    int index;

    system("cls");
    printf("\n\t*** BAJA ************************************************************************************\n\n");

    bici_show(bicicleta, sizeBicicleta, types, sizeTypes, colors, sizeColors);

    validations_getUnsignedInt(&id,"\nIngrese ID: ", "\n Error. Ingrese un valor numerico entero\n",0,999999,0,999999,4);

    index = bici_findOne(id, bicicleta, sizeBicicleta);

    if(index == -1)
    {
        printf("\n No se encuentran bicis con el ID: %d \n", id);
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n La bici que se dara de baja es:");
        printf("\n     ID              MARCA              TIPO       COLOR        RODADO          ");
        bici_showOne(bicicleta[index], types, sizeTypes, colors, sizeColors);

        if(confirm(2))
        {
            bicicleta[index].state = EMPTY;
        }
    }
}

void bici_modify(eBici bicicleta[], int sizeBicicleta, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    int id;
    int index;
    int newRodado;
    int newIDColor;

    system("cls");
    printf("\n    ******** MODIFICACION ******** \n");

    bici_show(bicicleta, sizeBicicleta, types, sizeTypes, colors, sizeColors);

    validations_getUnsignedInt(&id,"\n\tIngrese ID: ", "\n Error. Ingrese un valor numerico entero\n",0,999999,0,999999,4);

    index = bici_findOne(id, bicicleta, sizeBicicleta);

    if(index == -1)
    {
        printf("\n No se encuentra registrada una bicicleta con el ID: %d", id);
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n La bicicleta que se modificara es:");
        printf("\n      ID              MARCA              TIPO       COLOR        RODADO            ");
        bici_showOne(bicicleta[index], types, sizeTypes, colors, sizeColors);

        switch(menu_biciModify())
        {
        case 1:
            color_show(colors, sizeColors);
            validations_getUnsignedInt(&newIDColor,"\nIngrese ID del color: ", "\nError. Ingrese un valor numerico entero.\n",1,100000,10000,100000,4);
            if(confirm(3))
            {
                bicicleta[index].idColor = newIDColor;
            }
            break;
        case 2:
            validations_getUnsignedInt(&newRodado,"\nIngrese la rodado: ", "\n Error. Ingrese un valor numerico entero como 20, 24, 28.\n",1, 20, 24, 28, 4);
            if(confirm(3))
            {
                bicicleta[index].rodado = newRodado;
            }
            break;
        }

        printf("\n     ID              MARCA              TIPO       COLOR        RODADO          ");

        bici_showOne(bicicleta[index], types, sizeTypes, colors, sizeColors);


        system("pause");
    }
}

void bici_show(eBici bicicleta[], int sizeBicicleta, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    int flag = 0;

    printf("\n\t\t     ID              MARCA              TIPO       COLOR        RODADO               ");
    bici_sort(bicicleta, sizeBicicleta, types, sizeTypes, colors, sizeColors);
    for(int i=0; i<sizeBicicleta; i++)
    {
        if(bicicleta[i].state == TAKEN)
        {
            bici_showOne(bicicleta[i], types, sizeTypes, colors, sizeColors);
            flag = 1;
        }
    }
    printf("\n");
    if(flag == 0)
    {
        printf("\n No hay nada para mostrar.");
    }
}

void bici_showOne(eBici x, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    char typeDescription[20];
    char colorName[20];

    bici_loadTypeDescription(typeDescription, x.idType, types, sizeTypes);
    bici_loadColorName(colorName, x.idColor, colors, sizeColors);


    printf("\n    %5d  %15s   %15s  %10s         %5d         ", x.id, x.brand, typeDescription, colorName, x.rodado);
}

void bici_sort(eBici bicicleta[], int sizeBicicleta, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    eBici auxBici;

    for(int i=0; i<sizeBicicleta-1; i++)
    {
        for(int j=i+1; i<sizeBicicleta; i++)
        {
            if(bicicleta[i].idType > bicicleta[j].idType)
            {
                auxBici = bicicleta[i];
                bicicleta[i] = bicicleta[j];
                bicicleta[j] = auxBici;
            }
            else if(bicicleta[i].idType == bicicleta[j].idType && bicicleta[i].id > bicicleta[j].id)
            {
                auxBici = bicicleta[i];
                bicicleta[i] = bicicleta[j];
                bicicleta[j] = auxBici;
            }
        }
    }
}

int bici_loadTypeDescription(char description[], int id, eType types[], int sizeTypes)
{
    int ok = 0;

    for(int i=0; i<sizeTypes; i++)
    {
        if(types[i].id == id)
        {
            strcpy(description, types[i].description);
            ok = 1;
        }
    }

    return ok;
}

int bici_loadColorName(char colorName[], int id, eColor colors[], int sizeColors)
{
    int ok = 0;

    for(int i=0; i<sizeColors; i++)
    {
        if(colors[i].id == id)
        {
            strcpy(colorName, colors[i].colorName);
            ok = 1;
        }
    }

    return ok;
}

