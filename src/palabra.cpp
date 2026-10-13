/* 5600400 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/palabra.h"
#include <string.h>

struct _rep_palabra {
    Palabra siguiente;
    char *valor;
};

/* Operaciones de Palabra */

//************************* CONSTRUCTORAS *********************

//Pre-Cond:	No tiene
//Pos-Cond:	Retorna una palabra vacia.
Palabra crearPalabraVacia() {
    return NULL;
}

//Pre-Cond:	posicion<=cantidadPalabras(palabra)+1
//Pos-Cond:	inserta la palabra de nombre "nomPalabra" en la Posicion "posicion"
void insertarPalabraPosicion(Palabra &palabra, unsigned int posicion, char *nomPalabra) {
    Palabra nueva = new _rep_palabra();
    nueva->valor = new char[strlen(nomPalabra) + 1];
    strcpy(nueva->valor, nomPalabra);
    nueva->siguiente = NULL;

    if (posicion <= 1) {
        nueva->siguiente = palabra; // NULL si estaba vacía
        palabra = nueva;
        return;
    }

    Palabra actual = palabra;
    // posicion >=2
    while (actual->siguiente != NULL) {
        if (posicion == 2) break;
        actual = actual->siguiente;
        posicion--;
    }

    nueva->siguiente = actual->siguiente;
    actual->siguiente = nueva;
}

//*************************  SELECTORAS **********************

//Pre-Cond:esVaciaPalabra(palabra)retorna false
//Pos-Cond:retorna un puntero a un arreglo de char.
char *obtenerNombrePalabra(Palabra palabra) {
    return palabra->valor;
}

//Pre-Cond:	esVaciaPalabra(palabra) retorna false
//Pos-Cond:	Retorna un puntero a la siguente Palabra de "palabra"
Palabra siguientePalabra(Palabra palabra) {
    return palabra->siguiente;
}

//*************************   AGREGADO 23/09/2026   ************************
//Pre-Cond:	No tiene
//Pos-Cond:	Retorna la cantidad de palabras que hay en la Palabra "palabra"
int cantidadPalabras(Palabra palabra) {
    if (esVaciaPalabra(palabra)) return 0;
    int cant = 1;
    while (palabra->siguiente != NULL) {
        palabra = palabra->siguiente;
        cant++;
    }
    return cant;
}

//*************************  PREDICADOS **********************8
//Pre-Cond:	No tiene
//Pos-Cond:	Retorna true si la Palabra palabra no tiene palabras
bool esVaciaPalabra(Palabra palabra) {
    return palabra == NULL;
}

//Pre-Cond:	No tiene
//Pos-Cond:	Retorna true si la palabra de nombre "nomPalabra" existe en la Palabra "palabra"
bool existePalabra(Palabra palabra, char *nomPalabra) {
    while (palabra != NULL) {
        if (strcasecmp(palabra->valor, nomPalabra) == 0) return true;
        palabra = siguientePalabra(palabra);
    }
    return false;
}

//*************************  DESTRUCTORAS  *************************

//Pre-Cond:	No tiene
//Pos-Cond:	Libera toda la memoria reservada por la Palabra "palabra"
void destruirPalabra(Palabra &palabra) {
    while (palabra != NULL) eliminarPalabra(palabra);
}

//Pre-Cond:	esVaciaPalabra(palabra) retorna false
//Pos-Cond: elimina la primer Palabra de la Palabra "palabra"
void eliminarPalabra(Palabra &palabra) {
    Palabra borrar = palabra;
    palabra = palabra->siguiente;
    eliminarArreglo(borrar->valor);
    delete borrar;
}

//Pre-Cond:	No tiene
//Pos-Cond:	Elimina todas las palabras de nombre nomPalabras de "palabra"
void eiminarTodasLasPalabras(Palabra &palabra, char *nomPalabra);

//Pre-Cond:	La Posicion "posicion" existe en palabra
//Pos-Cond:	Elimina toda la memoria reservada por la palabra de la Posicion "posicion"
void eliminarPalabraPosicion(Palabra &palabra, unsigned int posicion) {
    if (posicion == 1) {
        eliminarPalabra(palabra);
        return;
    }
    Palabra anterior = palabra;
    for (unsigned int i = 2; i < posicion; i++)
        anterior = anterior->siguiente;

    Palabra borrar = anterior->siguiente;
    anterior->siguiente = borrar->siguiente;
    eliminarArreglo(borrar->valor);
    delete borrar;
}

//libera toda la memoria del Arreglo "arreglo"
void eliminarArreglo(char *arreglo) {
    delete[] arreglo;
}
