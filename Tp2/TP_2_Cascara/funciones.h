#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int isEmpty;
    int dni;
    int id;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);


int abmPersona_init(EPersona*array, int size);
int abmPersona_alta(EPersona *array,int size);
int abmPersona_buscarPorId(EPersona *array,int size, int id);
int abmPersona_baja(EPersona *array,int size, int id);
int abmPersona_mostrar(EPersona *array, int size);
int abmPersona_modificacion(EPersona* array, int size, int id);
int abmPersona_ordenar(EPersona *array, int size);
void grafico (EPersona *array, int size);
#endif // FUNCIONES_H_INCLUDED
