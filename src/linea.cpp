/* 5600400 */ // sustituiir con los 7 dígitos de la cédula
#include "../include/linea.h"
#include <stdio.h>
#include "../include/palabra.h"

struct _rep_linea {
    Linea anterior;
    Linea siguiente;
    Palabra primera_palabra;
    int indice;
    int cant_palabras;
};


//***********************  CONSTRUCTORAS ***************** */

//Pos-Cond: Retorna una Linea vacia
Linea crearLineaVacia() {
    Linea nueva = new _rep_linea();
    nueva->anterior = NULL;
    nueva->siguiente = NULL;
    nueva->primera_palabra = NULL;
    nueva->indice = 1;
    nueva->cant_palabras = 0;
    return nueva;
}

//Pre-cond: No tiene
//Pos-Cond: Agrega una nueva linea al final de la Linea "linea"
void agregarLinea(Linea &linea) {
    Linea nueva = crearLineaVacia();
    if (linea == NULL) {
        linea = nueva;
        return;
    }

    Linea ultima = linea;
    while (siguienteLinea(ultima) != NULL) {
        ultima = siguienteLinea(ultima);
    }

    nueva->indice = ultima->indice + 1;
    nueva->anterior = ultima;
    ultima->siguiente = nueva;
}

void insertarLineaPosicion(Linea &linea, unsigned int posicionLinea) {
    Linea objetivo = obtenerLinea(linea, posicionLinea);
    Linea nueva = crearLineaVacia();
    nueva->indice = objetivo->indice;
    nueva->anterior = objetivo->anterior;
    nueva->siguiente = objetivo;
    if (objetivo->anterior != NULL)
        objetivo->anterior->siguiente = nueva;
    else
        linea = nueva; // era la cabeza
    objetivo->anterior = nueva;
    renumerarLineas(nueva);
}

void renumerarLineas(Linea &linea) {
    if (linea == NULL) return;
    for (Linea a = linea->siguiente; a != NULL; a = a->siguiente)
        a->indice++;
}

void insertarPalabraEnPosicion(Linea &linea, unsigned int posicionPalabra, char *nomPalabra) {
    if (linea == NULL) return;
    insertarPalabraPosicion(linea->primera_palabra, posicionPalabra, nomPalabra);
    linea->cant_palabras++;
}


//************************ SELECTORAS ********************* */

//Pre-Cond: la Linea "numLinea" existe en Linea
//Pos-Cond: Retorna un puntero a la Linea que tiene como numero "numLinea"
Linea obtenerLinea(Linea &linea, int numLinea) {
    Linea objetivo = linea;
    while (numLinea > objetivo->indice) objetivo = objetivo->siguiente;
    while (numLinea < objetivo->indice) objetivo = objetivo->anterior;
    return objetivo;
}


//Pre-Cond: No tiene
//Pos-Cond: Imprime todas las palabras de la Linea "numLinea"
void imprimirLinea(Linea linea, int numLinea) {
    Linea aImprimir = obtenerLinea(linea, numLinea);
    Palabra actual = aImprimir->primera_palabra;
    printf("%d:", numLinea);
    for (int i = 0; i < aImprimir->cant_palabras; ++i) {
        printf(" %s", obtenerNombrePalabra(actual));
        actual = siguientePalabra(actual);
    }
    printf("\n");
}


//Pre-Cond: !esVaciaLinea(linea) retorna true
//Pos-Cond: retorna un puntero a la siguente Linea de "linea"
Linea siguienteLinea(Linea linea) {
    return linea->siguiente;
}


//Pre-Cond: No tiene
//Pos-Cond: Retorna un puntero Linea a la linea anterio de la Linea "linea"
Linea anteriorLinea(Linea linea) {
    return linea->anterior;
}

//Pre-Cond:	No tiene
//Pos-Cond:	Retorna la cantidad de lineas que tiene la Linea "linea"
int cantidadLineas(Linea linea);


//Pre-Cond: existe el numero de linea numLinea
//Pos-Cond: Retorna un puntero a la linea numLinea
Linea numeroLinea(Linea linea, int numLinea);


//Pre-Cond: No tiene
//Pos-Cond:	Retorna la cantidad de palabras que tiene la linea.
int cantidadDePalabraEnLinea(Linea linea) {
    return linea->cant_palabras;
}

//Pre-Cond: No tiene
//Pos-Cond:	Retorna la cantidad de ocurrencias de la Cadena palabra en la Linea "linea"
int cantidadOcurenciasPalabraEnLinea(Linea linea, char *palabra);


//Pre-Cond: No tiene
//Pos-Cond:	Retorna la Palabra que se encuentra al comienzo de la linea;
Palabra primerPalabraLinea(Linea linea) {
    return linea->primera_palabra;
}


//********************* PREDICADOS ************************* */

//Pre-Cond: No tiene
//Pos-Cond: Retorna true si la Linea "linea" no tiene lineas.
bool esVaciaLinea(Linea linea) {
    return linea == NULL;
}

//Pre-Cond: No tiene
//Pos-Cond: retorna true si en la Linea "linea" la linea numLinea existe.
bool existeLinea(Linea linea, int numLinea) {
    // ineficiente y medio circular porque obtenerLinea asume que existe
    // (serviria que ella dependa de esta)
    Linea existente = obtenerLinea(linea, numLinea);
    return existente != NULL;
}

//Pre-Cond: no tiene
//Pos-Cond: retorna true si la palabra de nombre "nomPalabra" existe en la estructura Linea "linea"
bool existePalabraLinea(Linea linea, char *nomPalabra);


//****************  DESTRUCTORAS ***********************

//Pre-Cond: existeLinea(linea, numLinea) retorna true;
//Pos-Cond: Elimina la linea num linea renumerando todas las otras lineas debajo de ella.
void eliminarLinea(Linea &linea, int numLinea) {
    Linea borrar = obtenerLinea(linea, numLinea);
    Linea anterior = borrar->anterior;
    Linea siguiente = borrar->siguiente;

    if (anterior != NULL) // 'anterior' no es el primero
        anterior->siguiente = siguiente;
    else
        linea = siguiente;

    if (siguiente != NULL) // 'siguiente' no es el ultimo
        siguiente->anterior = anterior;

    // Borrado
    Palabra palabras = borrar->primera_palabra;
    destruirPalabra(palabras);
    delete borrar;

    // Renumerar
    for (Linea a = siguiente; a != NULL; a = a->siguiente)
        a->indice--;
}

//Pre-Cond:	No tiene
//Pos-Cond: Elimina la Palabra llamada  de nombre "nomPalabra" de la Linea "linea" en todas las ocurrencias.
//			Retornando la cantidad de palabras eliminadas.
int eliminarPalabraLinea(Linea &linea, char *nomPalabra);

void eliminarPalabraPosicion(Linea &linea, int posicionPalabra) {
    // posicionPalabra<=cantidadDePalabraEnLinea(linea)
    eliminarPalabraPosicion(linea->primera_palabra, posicionPalabra);
    linea->cant_palabras--;
}

//Pre-Cond: No tiene
//Pos-Cond: Libera toda la memoria de la Linea "linea"
void destruirLinea(Linea &linea) {
    if (linea == NULL) return;

    Linea inicio = obtenerLinea(linea, 1);
    while (inicio != NULL) {
        Linea borrar = inicio;
        inicio = inicio->siguiente;
        destruirPalabra(borrar->primera_palabra);
        delete borrar;
    }
    linea = NULL;
}
