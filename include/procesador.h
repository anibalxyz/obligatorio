/*
  Módulo de definición del TAD 'PROCESADOR'.

  Los elementos de tipo 'PROCESADOR' son punteros a una estructura (que debe
  definirse en procesador.cpp).
  
  Laboratorio de EDA Turno Nocturno curso 2026.
  UTU-LATU
*/

#ifndef _PROCESADOR_H
#define _PROCESADOR_H

typedef char* Cadena;
typedef struct _rep_procesador *Procesador;


//***********************  CONSTRUCTORAS ***************** */

//Pre-Cond: No tiene
//Pos-Cond: Retorna un procesador vacio
Procesador crearProcesadorVacio(char *nomProcesador);

//Pre-Cond:	No tiene
//Pos-Cond:	inserta una nueva linea al final del procesador "p".
//			retorna true si la linea se inserto correctamente false en caso contrario
bool insertarLineaProcesador(Procesador &p);

//Pre-Cond:	posicionLinea >=0 && posicionLinea <= cantLineas(procesador)+1
//Pos-Cond:	inserta una nueva linea en la Posicion "posicionLinea" del Procesador "p".
bool insertarLineaEnPosicion(Procesador &p, int posicionLinea);

//************************ SELECTORAS *******************************
//Pre-Cond: No tiene
//Pos-Cond: Retorna un puntero a un arreglo con el nombre del Procesador "p"
char* obtenerNombreProcesador(Procesador p);


//Pre-Cond: No tiene
//Pos-Cond: Retorna la cantidad de lineas del Procesador "p"
int cantLineasProcesador(Procesador p);


//Pre-Cond:	posicionLinea >=0 && posicionLinea <= cantFilas(p)+1
//Pos-Cond:	elimina la linea de la Posicion "posicionLinea".
bool borrarLineaProcesador(Procesador &a, int posicionLinea);


//Pre-Cond:	
//Pos-Cond:	
void comprimirTextoProcesador(Procesador &p);


//Pre-Cond:	posicionLinea<=cantFilasProcesador (p);
//Pos-Cond: Inserta una nueva palabra de nombre: "nomPalabra" en la posicion "posicionLinea" y la posicion "posicionPalabra
bool insertarPalabraProcesador(Procesador &p, int posicionLinea, int posicionPalabra, Cadena palabraIngresar);


//Pre-Cond:	posicionLinea<=cantFilasProcesador (p);
//Pos-Cond: imprime todas las Palabras de la Posicion "posicionLinea"
bool imprimirLinea(Procesador p, int posicionLinea);

//Pre-Cond:
//Pos-Cond:
bool ingresarPalabraDiccionarioProcesador(Procesador &p, Cadena nomPalabra);

//Pre-Cond:
//Pos-Cond:
bool borrarPalabraDiccionarioProcesador(Procesador &p, Cadena palabraABorrar);

//Pre-Cond:
//Pos-Cond:
bool imprimirDiccionarioProcesador(Procesador p);

//Pre-Cond:
//Pos-Cond:
bool imprimirTextoIncorrectoProcesador(Procesador p);


//Pre-Cond:	el procesador 
//Pos-Cond:
bool imprimirUltimasPalabrasProcesador(Procesador p);

//************************* PREDICADOS  ****************************

//Pre-Cond: No tiene
//Pos-Cond:	Retorna true si el Procesador p no tiene lineas.
bool esVacioProcesador(Procesador p);

//************************* DESTRUCTORAS ***************************

//Pre-Cond: No tiene
//Pos-Cond: se eliminan todas las filas del Procesador "p";
void borrarTodasLasLineas(Procesador &p);

//Pre-Cond: No tiene
//Pos-Cond: se eliminan todas las Palabras de nombre "palabraABorrar" del Procesador "p";
void borrarOcurrenciasPalabraEnTextoProcesador(Procesador &p, Cadena palabraABorrar);

//Pre-Cond: No tiene
//Pos-Cond: se elimina toda la memoria reservada por el Procesador "p"
// 			retorna 1 si la funcion proceso bien o -1 en caso contrario
void borrarProcesadorCompleto (Procesador &p);

//Pre-Cond: No tiene
//Pos-Cond: 
bool borrarPalabraProcesador(Procesador &p, int posicionLinea, int posicionPalabra);

//Pre-Cond: No tiene
//Pos-Cond: 
bool borrarOcurrenciasPalabraEnLineaProcesador(Procesador &p, int posicionLinea, Cadena palabraABorrar);

#endif
