/*
  Módulo de definición de 'PALABRA'.

  Los elementos de tipo 'Palabra' son punteros a una estructura (que debe
  definirse en Palabra.cpp).

  Laboratorio de EDA Turno Nocturno curso 2026.
  UTU-LATU
 */

#ifndef _PALABRA_H
#define _PALABRA_H


typedef struct _rep_palabra *Palabra;

/* Operaciones de Palabra */

//************************* CONSTRUCTORAS *********************

//Pre-Cond:	No tiene
//Pos-Cond:	Retorna una palabra vacia.
Palabra crearPalabraVacia();

//Pre-Cond:	posicion<=cantidadPalabras(palabra)+1
//Pos-Cond:	inserta la palabra de nombre "nomPalabra" en la Posicion "posicion"
void insertarPalabraPosicion(Palabra &palabra, unsigned int posicion, char *nomPalabra);


//*************************  SELECTORAS **********************

//Pre-Cond:esVaciaPalabra(palabra)retorna false
//Pos-Cond:retorna un puntero a un arreglo de char.
char *obtenerNombrePalabra(Palabra palabra);


//Pre-Cond:	esVaciaPalabra(palabra) retorna false
//Pos-Cond:	Retorna un puntero a la siguente Palabra de "palabra"
Palabra siguientePalabra(Palabra palabra);


//*************************   AGREGADO 23/09/2026   ************************
//Pre-Cond:	No tiene
//Pos-Cond:	Retorna la cantidad de palabras que hay en la Palabra "palabra"
int cantidadPalabras(Palabra palabra);


//*************************  PREDICADOS **********************8
//Pre-Cond:	No tiene
//Pos-Cond:	Retorna true si la Palabra palabra no tiene palabras
bool esVaciaPalabra(Palabra palabra);

//Pre-Cond:	No tiene
//Pos-Cond:	Retorna true si la palabra de nombre "nomPalabra" existe en la Palabra "palabra"
bool existePalabra(Palabra palabra, char *nomPalabra);


//*************************  DESTRUCTORAS  *************************

//Pre-Cond:	No tiene
//Pos-Cond:	Libera toda la memoria reservada por la Palabra "palabra"
void destruirPalabra(Palabra &palabra);


//Pre-Cond:	esVaciaPalabra(palabra) retorna false
//Pos-Cond: elimina la primer Palabra de la Palabra "palabra"
void eliminarPalabra(Palabra &palabra);

//Pre-Cond:	No tiene
//Pos-Cond:	Elimina todas las palabras de nombre nomPalabras de "palabra"
void eiminarTodasLasPalabras(Palabra &palabra, char *nomPalabra);


//Pre-Cond:	La Posicion "posicion" existe en palabra
//Pos-Cond:	Elimina toda la memoria reservada por la palabra de la Posicion "posicion"
void eliminarPalabraPosicion(Palabra &palabra, unsigned int posicion);


//libera toda la memoria del Arreglo "arreglo"
void eliminarArreglo(char *arreglo);

#endif
