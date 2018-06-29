#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "getsValids.h"
#define CANTIDAD 20

int main()
{
    char seguir='s';
    int opcion=0;
    int id;

    EPersona Personas[CANTIDAD];
    abmPersona_init(Personas, CANTIDAD);
    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                abmPersona_alta(Personas, CANTIDAD);
                break;
            case 2:
                get_validInt("Ingrese el ID que quiera eliminar", "\nID INVALIDO\n",&id,0,CANTIDAD,2);
                abmPersona_baja(Personas,CANTIDAD,id);
                break;
            case 3:
                abmPersona_ordenar(Personas,CANTIDAD);
                abmPersona_mostrar(Personas,CANTIDAD);
                break;
            case 4:
                grafico(Personas,CANTIDAD);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
