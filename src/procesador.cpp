/* 5600400 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/palabra.h"
#include "../include/linea.h"
#include "../include/procesador.h"

#include <string.h>

#ifndef MAX_CANT_PALABRAS_X_LINEA
#define MAX_CANT_PALABRAS_X_LINEA 3
#endif

typedef char *Cadena;

struct _rep_procesador {
    Linea inicio;
    Linea final;
    Cadena nombre;
    int cant_lineas;
};

// Pre-Cond: cantidadDePalabraEnLinea(linea) >= 1
// Pos-Cond: retorna el contenido de la ultima palabra de 'linea'
static char *copiarUltimaPalabra(Linea linea) {
    int ultimaPos = cantidadDePalabraEnLinea(linea);
    Palabra ultimaPalabra = primerPalabraLinea(linea);
    for (int i = 1; i < ultimaPos; i++)
        ultimaPalabra = siguientePalabra(ultimaPalabra);
    char *contenido = obtenerNombrePalabra(ultimaPalabra);
    char *res = new char[strlen(contenido) + 1];
    strcpy(res, contenido);
    return res;
}

//***********************  CONSTRUCTORAS ***************** */
Procesador crearProcesadorVacio(char *nomProcesador) {
    Procesador procesador = new _rep_procesador();
    procesador->inicio = nullptr;
    procesador->final = nullptr;
    procesador->nombre = new char[strlen(nomProcesador) + 1];
    strcpy(procesador->nombre, nomProcesador);
    procesador->cant_lineas = 0;
    return procesador;
}

bool insertarLineaProcesador(Procesador &p) {
    if (p == nullptr) return false;
    if (p->inicio == nullptr) {
        agregarLinea(p->inicio);
        p->final = p->inicio;
    } else {
        agregarLinea(p->final);
        p->final = siguienteLinea(p->final);
    }
    p->cant_lineas++;
    return true;
}

bool insertarLineaEnPosicion(Procesador &p, int posicionLinea) {
    if (p == nullptr) return false;
    if (1 > posicionLinea || posicionLinea > p->cant_lineas + 1) return false;
    if (posicionLinea == p->cant_lineas + 1) return insertarLineaProcesador(p);
    insertarLineaPosicion(p->inicio, posicionLinea);
    p->cant_lineas++;
    return true;
}

bool insertarPalabraProcesador(Procesador &p, int posicionLinea, int posicionPalabra, Cadena palabraIngresar) {
    if (p == nullptr || p->inicio == nullptr || posicionLinea < 1) return false;

    Linea lineaEditada = obtenerLinea(p->inicio, posicionLinea);

    bool posPalabraEsValida = 1 <= posicionPalabra && posicionPalabra <= cantidadDePalabraEnLinea(lineaEditada) + 1;
    if (!posPalabraEsValida) return false;
    insertarPalabraEnPosicion(lineaEditada, posicionPalabra, palabraIngresar);

    Linea actual = lineaEditada;
    int overflowPosition = MAX_CANT_PALABRAS_X_LINEA + 1;
    while (cantidadDePalabraEnLinea(actual) >= overflowPosition) {
        char *overflow = copiarUltimaPalabra(actual);
        eliminarPalabraPosicion(actual, overflowPosition);
        if (siguienteLinea(actual) == nullptr) insertarLineaProcesador(p);
        actual = siguienteLinea(actual);
        insertarPalabraEnPosicion(actual, 1, overflow);
        delete[] overflow;
    }

    return true;
}

//************************ SELECTORAS ********************* */

Linea obtenerPrimeraLinea(Procesador p) {
    return p->inicio;
}

int cantLineasProcesador(Procesador p) {
    if (p == nullptr) return 0;
    return p->cant_lineas;
}

bool imprimirLinea(Procesador p, int posicionLinea) {
    if (p == nullptr) return false;
    if (posicionLinea < 1 || posicionLinea > p->cant_lineas) return false;
    imprimirLinea(p->inicio, posicionLinea);
    return true;
}

//********************* PREDICADOS ************************* */

bool esVacioProcesador(Procesador p) {
    return cantLineasProcesador(p) == 0;
}


//****************  DESTRUCTORAS ***********************
bool borrarPalabraProcesador(Procesador &p, int posicionLinea, int posicionPalabra) {
    bool posicionLineaEsValida = 1 <= posicionLinea && posicionLinea <= cantLineasProcesador(p);
    if (esVacioProcesador(p) || !posicionLineaEsValida) return false;

    Linea lineaAEditar = obtenerLinea(p->inicio, posicionLinea);
    bool posicionPalabraEsValida = 1 <= posicionPalabra && posicionPalabra <= cantidadDePalabraEnLinea(lineaAEditar);
    if (!posicionPalabraEsValida) return false;

    eliminarPalabraPosicion(lineaAEditar, posicionPalabra);
    return true;
}

bool borrarLineaProcesador(Procesador &a, int posicionLinea) {
    if (a == nullptr || posicionLinea < 1 || posicionLinea > a->cant_lineas) return false;

    if (posicionLinea == a->cant_lineas)
        a->final = anteriorLinea(a->final);

    eliminarLinea(a->inicio, posicionLinea);

    a->cant_lineas--;
    return true;
}

void borrarTodasLasLineas(Procesador &p) {
    if (p == nullptr || p->cant_lineas < 1) return;
    destruirLinea(p->inicio);
    p->final = nullptr;
    p->cant_lineas = 0;
}

void borrarProcesadorCompleto(Procesador &p) {
    if (p == nullptr) return;
    borrarTodasLasLineas(p);
    delete[] p->nombre;
    delete p;
}
