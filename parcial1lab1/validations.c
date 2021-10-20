#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "validations.h"

int getString(char* message, char* messageError, int min, int max, int* tries, char* result)
{
    int ret = -1;
    char bufferString[max+10];

    if(result != NULL && message != NULL && messageError != NULL && min <= max && tries >= 0)
    {
        do
        {
            printf("%s", message);
            setbuf(stdin,NULL);
            fgets(bufferString,sizeof(bufferString),stdin);
            bufferString[strlen(bufferString)-1]='\0';

            if(strlen(bufferString) >= min && strlen(bufferString) <= max)    // tamaño (max) = cantidad de elementos (strlen) + 1(\0)
            {
                strncpy(result,bufferString,max);
                ret = 0;
                //printf("\nEntro al if de getString");
                break;
            }
            printf("%s", messageError);
            (*tries)--;

        }while((*tries) >= 0);
    }

    return ret;
}


int validations_getUnsignedInt(int* input, char* message, char* messageError, int minSize, int maxSize, int min, int max, int tries)
{
    int ret = -1;
    char bufferString[maxSize];
    int auxInt;

    if(input != NULL && message != NULL && messageError != NULL && minSize <= maxSize && min <= max && tries >= 0)
    {
        do
        {
            if(!getString(message,messageError,minSize,maxSize,&tries,bufferString)) //==0 sin errores !0
            {
                //printf("\nEntro al if de getString == 0");
                if(isValidNumber(bufferString) == 1)
                {
                    auxInt = atoi(bufferString);
                    if(auxInt >= min && auxInt <= max)
                    {
                        *input = auxInt;
                        ret = 0;
                        break;
                    }

                }
                printf("%s",messageError);
                tries--;
            }
        }
        while(tries >= 0);
        printf(".");
    }
    return ret;
}
int isValidNumber(char* string)
{
    int ret = 1;//true

    for(int i=0; string[i]!='\0'; i++)
    {
        if(string[i] < '0' || string[i] > '9')
        {
            ret = 0;//false
            break;
        }
    }
    return ret;
}

int validations_getChar(char* result, char* message, char* messageError, int tries)
{
    int ret = -1;
    char bufferChar[256];

    if(result != NULL && message != NULL && messageError != NULL && tries >= 0)
    {
        do
        {
            if(!getString(message,messageError,1,3,&tries,bufferChar))
            {
                if(isValidChar(bufferChar[0]) == 1)
                {
                    *result = bufferChar[0];
                    ret = 0;
                    break;
                }

                printf("%s",messageError);
                tries--;
            }
        }
        while(tries >= 0);
        showTriesOverMessage(tries);
    }
    return ret;
}

int isValidChar(char character)
{
    int ret = 1;

    if(character < 'A' || (character > 'Z' && character < 'a') || character > 'z')
    {
        ret = 0;
    }

    return ret;
}

int validations_getText(char* input, char* message, char* messageError, int minSize, int maxSize, int tries)
{
    int ret = -1;
    char bufferString[maxSize];

    if(input != NULL && message != NULL && messageError != NULL && minSize <= maxSize && tries >= 0)
    {
        do
        {
            if(!getString(message,messageError,minSize,maxSize,&tries,bufferString))
            {
                if(isValidText(bufferString, sizeof(bufferString)) == 1)
                {
                    strncpy(input,bufferString,maxSize);
                    ret = 0;
                    break;
                }
                printf("%s",messageError);
                tries--;
            }
        }
        while(tries >= 0);
        showTriesOverMessage(tries);
    }
    return ret;
}

int isValidText(char* string, int lenght)
{
    int ret = -1;

    if(string != NULL && lenght > 0)
    {
        ret = 1;
        for(int i=0; i<lenght && string[i] != '\0'; i++)
        {
            if((string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z') && (string[i] != ' '))
            {
                ret = 0;
                break;
            }
        }
    }
    return ret;
}
void showTriesOverMessage(int tries)
{
    if(tries == -1)
    {
            printf("\n\n\t\t(!) ERROR. NO HAY INTENTOS DISPONIBLES. LO INGRESADO NO SE CARGO CORRECTAMENTE (!)\n\n");
    }
}

int validations_getDate(int day, int month, int year, int minYear, int maxYear)
{
    int ret = 1;
    int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(year < minYear || year > maxYear)
    {
        ret = 0;
    }

    if (month < 1 || month > 12)
    {
        ret = 0;
    }

    if((month != 2) || (!isLeapYear (year)))	//si no es febrero o no es bisiesto
    {
        if (day < 1 || day > monthDays[month])
        {
            ret = 0;
        }
    }
    else if((month == 2) && (isLeapYear (year))) //si es febrero y es bisiesto
    {
        if (day < 1 || day > monthDays[2]+1) //pongo como dia maximo 28 + 1
        {
            ret = 0;
        }
    }

    return ret;
}
int isLeapYear(int year)
{
  int ret = 0;

    if((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
    {
      ret = 1;
    }
  return ret;
}
