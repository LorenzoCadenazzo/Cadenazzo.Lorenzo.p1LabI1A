#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "work.h"

#include "validations.h"
#include "menu.h"
#include "extras.h"

#define EMPTY 0
#define TAKEN 1


void work_hardcode(eWork works[], int worksToHardcode)
{
    int idsBici[] = {1000,1001,1002,1003,1004,1005,1006,1007};
    int idsService[] = {20000,20001,20002,20003,20004,20005,20006,20007};
    int idsWork[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int days[] = {21,1,2,6,8,19,21,29};
    int months[] = {12,3,5,7,2,2,12,9};
    int years[] = {2010,2010,2013,2019,2008,2016,2017,2016};

    for(int i=0; i<worksToHardcode; i++)
    {
        works[i].id = idsWork[i];
        works[i].idBici = idsBici[i];
        works[i].idService = idsService[i];
        works[i].date.day = days[i];
        works[i].date.month = months[i];
        works[i].date.year = years[i];
        works[i].state = TAKEN;
    }
}
void work_initializate(eWork works[], int sizeWorks)
{
    for(int i=0; i<sizeWorks; i++)
    {
        works[i].state = EMPTY;
    }
}
int work_findFreeSpace(eWork works[], int sizeWorks)
{
    int ret = -1;

    for(int i=0; i<sizeWorks; i++)
    {
        if(works[i].state == EMPTY)
        {
            ret = i;
            break;
        }
    }

    return ret;
}
int work_findOne(int id, eWork works[], int sizeWorks)
{
    int ret = -1;

    for(int i=0; i<sizeWorks; i++)
    {
        if(works[i].id == id && works[i].state == TAKEN)
        {
            ret = i;
            break;
        }
    }

    return ret;
}


int work_load(int id, eWork works[], int sizeWorks, eBici bicicleta[], int sizeBicicleta, eType types[], int sizeTypes, eColor colors[], int sizeColors, eService services[], int sizeServices)
{
    eWork auxWork;
    int index = work_findFreeSpace(works, sizeWorks);
    int ok = 0;
    int biciExists;
    int serviceExists;

    system("cls");
    printf("\n\t*** ALTA ************************************************************************************\n\n");

    if(index == -1)
    {
        printf("\n\n\t\t>>> Sistema completo <<<\n\n\n");
        system("pause");
    }
    else
    {
        bici_show(bicicleta, sizeBicicleta, types, sizeTypes, colors, sizeColors);
        validations_getUnsignedInt(&auxWork.idBici,"\n\tIngrese ID de la bici: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",0,999999,0,999999,4);
        biciExists = bici_findOne(auxWork.idBici, bicicleta, sizeBicicleta);
        if(biciExists == -1)
        {
            printf("\n\n\t\t>>> No existe una bici con el ID ingresado <<<\n\n\n");
            system("pause");
        }
        else
        {
            services_show(services, sizeServices);
            validations_getUnsignedInt(&auxWork.idService,"\n\tIngrese ID del servicio: ", "\n\t(!) Error. Ingrese un valor numerico entero. Rango 20000-20003\n",1,20003,20000,20003,4);
            serviceExists = service_findOne(auxWork.idService, services, sizeServices);

            if(serviceExists == -1)
            {
                printf("\n\n\t\t>>> No existe un servicio con el ID ingresado <<<\n\n\n");
                system("pause");
            }
            else
            {
                // Tambien pido fecha validada para que figure correctamente después del alta
                validations_getUnsignedInt(&auxWork.date.day,"\n\tIngrese dia: ", "\n\t(!) Error. Ingrese un valor numerico entero. Dia inexistente.\n",1,31,1,31,4);
                validations_getUnsignedInt(&auxWork.date.month,"\n\tIngrese mes: ", "\n\t(!) Error. Ingrese un valor numerico entero. Mes inexistente.\n",1,12,1,12,4);
                validations_getUnsignedInt(&auxWork.date.year,"\n\tIngrese año: ", "\n\t(!) Error. Ingrese un valor numerico entero. El anio debe ser entre 1990 y 2020.\n",1,2020,1,2020,4);

                while(validations_getDate(auxWork.date.day, auxWork.date.month, auxWork.date.year, 1990, 2020)==0)
                {
                    printf("\n\t(!) Error. Fecha no valida. \n");
                    validations_getUnsignedInt(&auxWork.date.day,"\n\n\tIngrese dia: ", "\n\t(!) Error. Ingrese un valor numerico entero. Dia inexistente.\n",1,31,1,31,4);
                    validations_getUnsignedInt(&auxWork.date.month,"\n\tIngrese mes: ", "\n\t(!) Error. Ingrese un valor numerico entero. Mes inexistente.\n",1,12,1,12,4);
                    validations_getUnsignedInt(&auxWork.date.year,"\n\tIngrese año: ", "\n\t(!) Error. Ingrese un valor numerico entero entre 1990 y 2020.\n",1,2020,1,2020,4);
                }

                auxWork.id = id;
                auxWork.state = TAKEN;

                works[index] = auxWork;

                printf("\n\n\t\t>>> Cargado exitosamente <<<\n\n\n");
                system("pause");

                ok = 1;
            }
        }
    }

    return ok;
}
void work_show(eWork works[], int sizeWorks, eBici bicicleta[], int sizeBicicleta, eService services[], int sizeServices)
{
    int flag = 0;

    printf("\n\t\t ________________________________________________________________________\n");
    printf("\n\t\t     ID              MARCA           SERVICIO            FECHA          ");
    printf("\n\t\t ________________________________________________________________________\n");

    for(int i=0; i<sizeWorks; i++)
    {
        if(works[i].state == TAKEN)
        {
            work_showOne(works[i], bicicleta, sizeBicicleta, services, sizeServices);
            flag = 1;
        }
    }
    printf("\n");
    if(flag == 0)
    {
        printf("\n\t\t>>> No hay elementos para mostrar <<<\n\n\n");
    }
}
void work_showOne(eWork x, eBici bicicleta[], int sizeBicicleta, eService services[], int sizeServices)
{
    char serviceDescription[20];
    char biciName[20];

    work_loadServiceDescription(serviceDescription, x.idService, services, sizeServices);
    work_loadBiciName(biciName, x.idBici, bicicleta, sizeBicicleta);

    printf("\n\t\t     %d     %15s         %10s           %2d / %2d / %4d   \n", x.id, biciName, serviceDescription, x.date.day, x.date.month, x.date.year);
}




int work_loadBiciName(char biciName[], int id, eBici bicicleta[], int sizeBicicleta)
{
    int ok = 0;

    for(int i=0; i<sizeBicicleta; i++)
    {
        if(bicicleta[i].id == id)
        {
            strcpy(biciName, bicicleta[i].brand);
            ok = 1;
        }
    }

    return ok;
}
int work_loadServiceDescription(char serviceDescription[], int id, eService services[], int sizeServices)
{
    int ok = 0;

    for(int i=0; i<sizeServices; i++)
    {
        if(services[i].id == id)
        {
            strcpy(serviceDescription, services[i].description);
            ok = 1;
        }
    }

    return ok;
}
