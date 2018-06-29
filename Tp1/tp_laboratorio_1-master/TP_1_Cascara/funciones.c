#include <stdio.h>
#include <stdlib.h>


int suma(float num1,float num2, float *resultadoOperacion)
{
    int retorno=-1;
    float resultado;
    if(num1&&num2)
    {
    retorno=0;
    resultado=num1+num2;
    *resultadoOperacion= resultado;
    }
    return retorno;
}

int resta(float num1,float num2, float *resultadoOperacion)
{
    int retorno=-1;
    float resultado;
    if(num1&&num2)
    {
    retorno=0;
    resultado= num1-num2;
    *resultadoOperacion= resultado;
    }
    return retorno;
}

int multiplicacion(float num1, float num2, float *resultadoOperacion)
{
    int retorno=-1;
    float resultado;
    if(num1&&num2)
    {
    retorno=0;
    resultado=num1*num2;
    *resultadoOperacion= resultado;
    }
    return retorno;
}

int division(float num1, float num2, float *resultadoOperacion)
{
    int retorno=-1;
    float resultado;

    if(num1&&num2)
    {
    retorno=0;
    resultado=num1/num2;
    *resultadoOperacion=resultado;
    }
    return retorno;
}
long factorial(float num1)
{
    float resultado;

    if(num1==1)
        return 1;


    resultado=(long)num1*factorial(num1-1);
    return resultado;
}

