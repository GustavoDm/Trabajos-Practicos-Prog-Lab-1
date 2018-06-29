#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    float x=0;
    float y=0;
    float resultado;
    long Q =x;
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (%.2f)\n", x);
        printf("2- Ingresar 2do operando (%.2f)\n", y);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese un numero por favor: ");
            scanf("%f", &x);
            system("cls");
            break;

        case 2:
            printf("Ingrese un numero por favor: ");
            scanf("%f", &y);
            system("cls");
            break;
        case 3:
            if((suma(x, y, &resultado))==0){
            printf("la suma es de un total de: %.2f\n", resultado);
            }
            else
            {
            printf("ERROR");
            }
            printf("desea continuar? s/n :");
            fflush(stdin);
            scanf("%c", &seguir);
            system("cls");
            break;
        case 4:
            if((resta(x, y, &resultado))==0){
            printf("la resta es de un total de: %.2f\n", resultado);
            }
            else
            {
            printf("ERROR");
            }
            printf("desea continuar? s/n :");
            fflush(stdin);
            scanf("%c", &seguir);
            system("cls");
            break;
        case 5:
            if(y==0)
            {
                printf("Error, no se puede dividir por cero\n");

            }
            else if ((division(x, y, &resultado))==0){
            printf("la division da un total de: %.2f\n", resultado);
            }
            else
            {
             printf("ERROR");
            }

                printf("desea continuar? s/n :");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
                break;

        case 6:
           if((multiplicacion(x, y, &resultado))==0){
            printf("la multiplicacion da un total de: %.2f\n", resultado);
            }
            else
            {
            printf("ERROR");
            }
            printf("desea continuar? s/n :");
            fflush(stdin);
            scanf("%c", &seguir);
            system("cls");
            break;
        case 7:
            if(x==1)
            printf("el factorial de A es: 1");
            else{
            factorial(Q);
            printf("el factorial de A es: %li\n", factorial(Q));
            }

            printf("desea continuar? s/n :");
            fflush(stdin);
            scanf("%c", &seguir);
            system("cls");
            break;
        case 8:

            if((suma(x, y, &resultado))==0){
            printf("la suma es de un total de: %.2f\n", resultado);
            }
              if((resta(x, y, &resultado))==0){
            printf("la resta es de un total de: %.2f\n", resultado);
            }
            if(y==0)
            {
                printf("Error, no se puede dividir por cero\n");

            }
            else if ((division(x, y, &resultado))==0){
            printf("la division da un total de: %.2f\n", resultado);
            }
             if((multiplicacion(x, y, &resultado))==0){
            printf("la multiplicacion da un total de: %.2f\n", resultado);
            }
           factorial(Q);
           printf("el factorial de A es: %li\n", factorial(Q));

            printf("desea continuar? s/n :");
            fflush(stdin);
            scanf("%c", &seguir);
            system("cls");
            break;
        case 9:
            seguir = 'n';
            break;
        }



    }
    return 0;
}
