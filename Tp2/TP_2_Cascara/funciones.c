#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "getsValids.h"


static int buscarLugarLibre(EPersona *array,int size);
static int proximoId(void);

int abmPersona_init(EPersona*array, int size)
{
    int i;
    int retorno=-1;
    if(size>0&& array !=NULL)
    {
        for(i=0; i<size; i++)
        {
            array[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}

int abmPersona_alta(EPersona *array,int size)
{
    int retorno = -1;
    int i;
    char nombre[50];
    int edad;
    int dni;


    if(size > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,size);
        if(i >= 0)
        {
            if(!get_validLetras("\nIngrese un nombre: ","\nEso no es un nombre","El maximo es 50",nombre,50,3))
            {
                if(!get_validInt("\nIngrese su edad: ","\nEso no es una edad",&edad,0,120,3))
                {
                    if(!get_validInt("\nIngrese su Dni: ","\nEso no es un Cuil",&dni,1000000,99999999,3))
                    {
                        retorno = 0;
                        strcpy(array[i].nombre,nombre);
                        array[i].edad=edad;
                        array[i].dni=dni;
                        array[i].id = proximoId();
                        array[i].isEmpty = 0;
                        printf("El ID del cliente es: %d\n", array[i].id);
                    }
                }

            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


int abmPersona_buscarPorId(EPersona *array,int size, int id)
{
    int retorno = -1;
    int i;
    if(size > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<size;i++)
        {
            if(!array[i].isEmpty && array[i].id==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int abmPersona_baja(EPersona *array,int size, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = abmPersona_buscarPorId(array,size,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}


int abmPersona_mostrar(EPersona *array, int size)
{

    int retorno = -1;
    int i;
    if(array != NULL)
    {
        for(i=0;i<size;i++)
        {


        retorno = 0;

            if(!array[i].isEmpty)
                printf("[RELEASE] -ID: %d - Nombre: %s - DNI:  %d - Estado: %d - %d\n",array[i].id, array[i].nombre,array[i].dni,array[i].edad, array[i].isEmpty);
        }
    }
    return retorno;
}


int abmPersona_modificacion(EPersona* array, int size, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char nombre[50];
    int edad;
    int dni;

    indiceAModificar = abmPersona_buscarPorId(array, size, id);

   if(size > 0 && array != NULL)
    {
        if(indiceAModificar >= 0)
        {
          if(!get_validLetras("\nIngrese un nombre: ","\nEso no es un nombre","El maximo es 50",nombre,50,3))
            {
                if(!get_validInt("\nIngrese su edad: ","\nEso no es una edad",&edad,0,120,3))
                {
                    if(!get_validInt("\nIngrese su Dni: ","\nEso no es un Cuil",&dni,1000000,99999999,3))
                    {
                        retorno = 0;
                        strcpy(array[indiceAModificar].nombre,nombre);
                        array[indiceAModificar].edad=edad;
                        array[indiceAModificar].dni=dni;
                        array[indiceAModificar].isEmpty = 0;
                    }
                }

            }
            }
            else
            {
                retorno = -3;
            }
    }
    else
    {
        retorno = -2;
    }

    return retorno;
}

int abmPersona_ordenar(EPersona *array, int size)
{
    int retorno=-1;
     int i,j;
     EPersona temp[size];
    if(size >0 )
    {
         for(i=1;i<size;i++)
         {
            if (array[i].isEmpty)
                continue;

            temp[i] = array[i];
            j=i-1;
            while((stricmp(temp[i].nombre,array[j].nombre)<0) && j>=0)
            {
                array[j+1] = array[j];
                j--;
            }
            array[j+1]=temp[i];

         }
         retorno=0;
    }
    return retorno;
}

void grafico (EPersona *array, int size)
{

    int contador18oMenor=0;
    int contadorEntre19y35=0;
    int contadormayor35=0;
    int i;
    int j;
    int graficoEjeY;

    if(array!= NULL && size > 0)
    {

    for(i=0; i<size; i++)
    {
        if(!array[i].isEmpty)
        {

            if (array[i].edad <= 18)
            {
                contador18oMenor++;
            }
            else if (array[i].edad > 35)
            {
                contadormayor35++;
            }
            else if(array[i].edad > 18 && array[i].edad <= 35 )
            {
                contadorEntre19y35++;
            }
        }
    }

    if(contador18oMenor > contadorEntre19y35 && contador18oMenor > contadormayor35)
    {
        graficoEjeY = contador18oMenor;
    }
    else if(contadorEntre19y35 > contadormayor35)
    {
        graficoEjeY = contadorEntre19y35;
    }
    else
    {
        graficoEjeY = contadormayor35;
    }

    for (j = graficoEjeY; j > 0 ; j--)
    {
        if (contador18oMenor >= j)
        {
            printf("\t  *");
        }
        else
        {
            printf("\t   ");
        }
        if (contadorEntre19y35 >= j)
        {
            printf("\t  *");
        }
        else
        {
            printf("\t     ");
        }
        if (contadormayor35 >= j)
        {
            printf("\t  *\n");
        }
        else
        {
            printf("\t \n");
        }
    }
    printf("\t<18\t19-35\t>35\n");

    }

}

static int buscarLugarLibre(EPersona *array,int size)
{
    int retorno = -1;
    int i;
    if(size > 0 && array != NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


