/*
  Módulo de definición de 'linea'.

  Los elementos de tipo 'linea' son punteros a una estructura (que debe definirse en linea.cpp).

  Laboratorio de EDA Turno Nocturno curso 2026.
  UTU-LATU
 */

#ifndef _LINEA_H
#define _LINEA_H

#include "palabra.h"

typedef struct _rep_linea *Linea;


//***********************  CONSTRUCTORAS ***************** */

//Pos-Cond: Retorna una Linea vacia
Linea crearLineaVacia();

//Pre-cond: No tiene
//Pos-Cond: Agrega una nueva linea al final de la Linea "linea"
void agregarLinea (Linea &linea);




//*********************** 	AGREGADO 23/09/2026 ******************************
//Pre-cond:    0<posicion<=cantidadPalabras+1
//Pos-Cond:   Agrega en la Linea "linea" una nueva Palabra en la Posición "posicionPalabra" 
void insertarPalabraEnPosicion(Linea &linea, unsigned int posicionPalabra, char* nomPalabra);




//************************ SELECTORAS ********************* */

//Pre-Cond: la Linea "numLinea" existe en Linea
//Pos-Cond: Retorna un puntero a la Linea que tiene como numero "numLinea"
Linea obtenerLinea(Linea &linea, int numLinea);


//Pre-Cond: No tiene
//Pos-Cond: Imprime todas las palabras de la Linea "numLinea"
void imprimirLinea(Linea linea, int numLinea);


//Pre-Cond: !esVaciaLinea(linea) retorna true
//Pos-Cond: retorna un puntero a la siguente Linea de "linea"
Linea siguienteLinea(Linea linea);


//Pre-Cond: No tiene
//Pos-Cond: Retorna un puntero Linea a la linea anterio de la Linea "linea"
Linea anteriorLinea(Linea linea);


//Pre-Cond:	No tiene
//Pos-Cond:	Retorna la cantidad de lineas que tiene la Linea "linea" 
int cantidadLineas(Linea linea);


//Pre-Cond: existe el numero de linea numLinea
//Pos-Cond: Retorna un puntero a la linea numLinea
Linea numeroLinea(Linea linea,int numLinea);


//Pre-Cond: No tiene
//Pos-Cond:	Retorna la cantidad de palabras que tiene la linea.
int cantidadDePalabraEnLinea(Linea linea);

//Pre-Cond: No tiene
//Pos-Cond:	Retorna la cantidad de ocurrencias de la Cadena palabra en la Linea "linea"
int cantidadOcurenciasPalabraEnLinea(Linea linea, char* palabra);


//Pre-Cond: No tiene
//Pos-Cond:	Retorna la Palabra que se encuentra al comienzo de la linea;
Palabra primerPalabraLinea(Linea linea);


//********************* PREDICADOS ************************* */

//Pre-Cond: No tiene
//Pos-Cond: Retorna true si la Linea "linea" no tiene lineas.
bool esVaciaLinea (Linea linea);

//Pre-Cond: No tiene 
//Pos-Cond: retorna true si en la Linea "linea" la linea numLinea existe. 
bool existeLinea (Linea linea, int numLinea);

//Pre-Cond: no tiene
//Pos-Cond: retorna true si la palabra de nombre "nomPalabra" existe en la estructura Linea "linea" 
bool existePalabraLinea(Linea linea, char* nomPalabra);


//****************  DESTRUCTORAS ***********************

//Pre-Cond: existeLinea(linea, numLinea) retorna true;
//Pos-Cond: Elimina la linea num linea renumerando todas las otras lineas debajo de ella.
void eliminarLinea (Linea &linea, int numLinea);

//Pre-Cond:	No tiene
//Pos-Cond: Elimina la Palabra llamada  de nombre "nomPalabra" de la Linea "linea" en todas las ocurrencias.
//			Retornando la cantidad de palabras eliminadas.
int eliminarPalabraLinea(Linea &linea, char* nomPalabra);



//***************************  AGREGADO 23/09/20026 ***************************
//Pre-Cond:	posicion<=cantidadDePalabraEnLinea
//Pos-Cond: Elimina la palabra de la Posición "posicionPalabra" que se encuentra en la Linea "linea"
void eliminarPalabraPosicion(Linea &linea, int posicionPalabra);


//Pre-Cond: No tiene
//Pos-Cond: Libera toda la memoria de la Linea "linea"       
void destruirLinea (Linea &linea);

#endif
