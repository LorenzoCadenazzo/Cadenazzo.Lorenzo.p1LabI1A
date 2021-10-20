#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"

void type_show(eType types[], int sizeTypes)
{
    printf("\n *** TIPOS ***\n");
    printf("        ID                    DESCRIPCION       \n");

    for(int i=0; i<sizeTypes; i++)
    {
        type_showOne(types[i]);
    }
}

void type_showOne(eType type)
{
    printf("\n       %d                  %10s\n", type.id, type.description);
}

int type_findOne(int id, eType types[], int sizeTypes)
{
    int ret = -1;

    for(int i=0; i<sizeTypes; i++)
    {
        if(types[i].id == id)
        {
            ret = i;
            break;
        }
    }

    return ret;
}
