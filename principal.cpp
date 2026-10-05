/* 1111111 */ // sustituir con los 7 dígitos de la cédula

/* Módulo principal de la tarea de EDA

Intérprete de comandos para probar los módulos.

Cada comando tiene un nombre el cual solicitara los distintos datos


El comando Fin termina el programa
Laboratorio de EDA 2026 UTU - LATU - Turno Nocturno 
Profesor Ing. Ferando Arrieta

*/
//*********************  DIRECTIVAS DE PRE-PROCESAMIENTO *************
#include "include/procesador.h"
#include "include/utils.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstddef>
#define MAX_PALABRA 64
#define MAX_LINEA 256
#define MAX_NOMBRE 25
#define MAX_PARAMETRO 25
#define MAX_NUMERO 4

enum _retorno {OK, ERROR, NO_IMPLEMENTADA};
typedef enum _retorno TipoRet;
typedef unsigned int Posicion;
typedef char* Cadena;

//*********************** FIRMAS DE FUNCIONES ********************************

//PRE Y POS CONDICIONES SE ENCUENTRAN EN LA LETRA DEL OBLIGATORIO
Procesador crearProcesador(Cadena nombre); 	
TipoRet borrarProcesador(Procesador &p);										
TipoRet borrarPalabra(Procesador &p);			
TipoRet insertarLinea(Procesador &p);
TipoRet insertarLineaEnPosicion(Procesador &p,Posicion PosisionLinea);
TipoRet borrarLinea(Procesador &p, Posicion posicionLinea);					
TipoRet borrarTodo(Procesador &p);
TipoRet borrarOcurrenciasPalabraEnTexto(Procesador &p, Cadena palabraABorrar);
TipoRet imprimirTexto(Procesador p);
TipoRet comprimirTexto(Procesador &p);
TipoRet insertarPalabra(Procesador &p, Posicion PosicionLinea, Posicion posicionPalabra, Cadena palabraIngresar);
TipoRet borrarPalabra(Procesador &p, Posicion posicionLinea, Posicion posicionPalabra);
TipoRet borrarOcurrenciasPalabraEnLinea(Procesador &p, Posicion posicionLinea, Cadena palabraABorrar);
TipoRet imprimirLinea(Procesador p, Posicion posicionLinea);
TipoRet ingresarPalabraDiccionario(Procesador &p, Cadena palabraAIngresar);
TipoRet borrarPalabraDiccionario(Procesador &p, Cadena palabraABorrar);
TipoRet imprimirDiccionario(Procesador p);
TipoRet imprimirTextoIncorrecto(Procesador p);
TipoRet imprimirUltimasPalabras(Procesador p);

								

//*******************  PROGRAMA PRINCIPAL ******************************
int main() {

  char restoLinea[MAX_LINEA + 1];
  char palabra[MAX_PALABRA];
  char palabraABorrar[MAX_PALABRA];
  char sentencia[MAX_PALABRA];
  char sinParametro[MAX_PARAMETRO];
  char numeroLinea[MAX_NUMERO];
  char numeroPalabra[MAX_NUMERO];
  char nomProcesador [MAX_NOMBRE];
  unsigned int numeroLin=0;
  unsigned int numeroPal=0;
  int cont_comandos = 0;
  bool salir = false;

  
  printf("\n\n************ BIENVENIDOS AL PROCESADOR DE TEXTO *********\n\n");
  printf("Ingrese el nombre del Procesador a crear: ");
  scanf("%s",nomProcesador);
  Procesador p = crearProcesador(nomProcesador);
  printf("\n");
  while (!salir) {
        // mostrar el prompt
        cont_comandos++;
        printf("%d>", cont_comandos);	
        // leer el comando
        leerChars(sentencia);
        int largo=strlen(sentencia);
        for (int i=1;i<largo;i++){
            if ((sentencia[i]=='(') || (sentencia [i]==')'))
                sentencia[i]=',';
        }
        char* token = strtok(sentencia,",");
        char nombre_comando[MAX_PALABRA];
        strcpy(nombre_comando,token);
        int cont=0;
        while (token != NULL){
            if ((0==strcmp(nombre_comando, "BorrarProcesador") && (cont==0)))
                    strcpy(sinParametro,token); 
				
            else if (0==strcmp(nombre_comando, "InsertarLinea") && (cont==0))
                    strcpy(sinParametro,token);
				
            else if (0==strcmp(nombre_comando, "InsertarLineaEnPosicion") && (cont==2)){
                    strcpy(numeroLinea,token);
					sscanf(numeroLinea,"%u",&numeroLin);
			}

			else if (0==strcmp(nombre_comando, "BorrarLinea") && (cont==2)){
                    strcpy(numeroLinea,token);
					sscanf(numeroLinea,"%u",&numeroLin);	
			}							
				
            else if (0==strcmp(nombre_comando, "BorrarTodo") && (cont==0))
                    strcpy(sinParametro,token);
				
			else if (0==strcmp(nombre_comando, "BorrarOcurrenciasPalabraEnTexto") && (cont==2)){
                    strcpy(palabra,token);
			}
				
			else if (0==strcmp(nombre_comando, "ImprimirTexto") && (cont==0)){
                    strcpy(sinParametro,token);
			}
			
            else if (0==strcmp(nombre_comando, "ComprimirTexto") && (cont==0))
                    strcpy(sinParametro,token);
			
			//************************************************************
			else if (0==strcmp(nombre_comando, "InsertarPalabra") && (cont==2)){
                    strcpy(numeroLinea,token);	
					sscanf(numeroLinea,"%u",&numeroLin);
			}
			
			else if (0==strcmp(nombre_comando, "InsertarPalabra") && (cont==3)){
                    strcpy(numeroPalabra,token);	
					sscanf(numeroPalabra,"%u",&numeroPal);
			}
			
			else if (0==strcmp(nombre_comando, "InsertarPalabra") && (cont==4)){
                    strcpy(palabra,token);
			}
				
				
			//****************************************************************
            
			else if (0==strcmp(nombre_comando, "BorrarPalabra") && (cont==2)){
                    strcpy(numeroLinea,token);	
					sscanf(numeroLinea,"%u",&numeroLin);
			}
			
			else if (0==strcmp(nombre_comando, "BorrarPalabra") && (cont==3)){
                    strcpy(numeroPalabra,token);	
					sscanf(numeroPalabra,"%u",&numeroPal);
			}
				
			//****************************************************************	
            else if (0==strcmp(nombre_comando, "BorrarOcurrenciasPalabraEnLinea") && (cont==2)){
                    strcpy(numeroLinea,token);	
					sscanf(numeroLinea,"%u",&numeroLin);
			}
				
			else if (0==strcmp(nombre_comando, "BorrarOcurrenciasPalabraEnLinea") && (cont==3))
                    strcpy(palabra,token);
			//****************************************************************				
			
            else if (0==strcmp(nombre_comando, "ImprimirLinea") && (cont==2))
                    strcpy(numeroLinea,token);
				
			else if (0==strcmp(nombre_comando, "IngresarPalabraDiccionario") && (cont==2))
                    strcpy(palabra,token);
				
            else if (0==strcmp(nombre_comando, "BorrarPalabraDiccionario") && (cont==2))
                    strcpy(palabra,token);
				
			else if (0==strcmp(nombre_comando, "ImprimirDiccionario") && (cont==0))
                    strcpy(sinParametro,token);
				
			else if (0==strcmp(nombre_comando, "ImprimirTextoIncorrecto") && (cont==0))
                    strcpy(sinParametro,token);
				
			else if (0==strcmp(nombre_comando, "ImprimirUltimasPalabras") && (cont==0))
                    strcpy(sinParametro,token);
            token = strtok(NULL, ",");
            cont++;
        }
        // procesar el comando
		if (0 == strcmp(nombre_comando, "Fin")) {
				salir = true;
				printf("Fin.\n");
				// comentario
		}else if (0 == strcmp(nombre_comando, "BorrarProcesador")) {       
					TipoRet salida=borrarProcesador(p);
					if (salida == OK)
						printf("OK\n");
					else if (salida == NO_IMPLEMENTADA )
							printf("NO_IMPLEMENTADA\n");
					else if( salida == ERROR )
						printf("ERROR\n");
					
        }else if (0 == strcmp(nombre_comando, "InsertarLinea")) {
					TipoRet salida=insertarLinea(p);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
					else if( salida == ERROR )
						printf("ERROR\n");
						
        } else if (0 == strcmp(nombre_comando, "InsertarLineaEnPosicion")) {
                    TipoRet salida=insertarLineaEnPosicion(p,numeroLin);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
					else if( salida == ERROR )
						printf("ERROR\n");
						
        } else if (0 == strcmp(nombre_comando, "BorrarLinea")) {
					TipoRet salida=borrarLinea(p,numeroLin);
                     if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
					else if( salida == ERROR )
						printf("ERROR\n");
						
        } else if (0 == strcmp(nombre_comando, "BorrarTodo")) {
                    TipoRet salida=borrarTodo(p);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
					else if( salida == ERROR )
						printf("ERROR\n");
						
        } else if (0 == strcmp(nombre_comando, "BorrarOcurrenciasPalabraEnTexto")) {
    
                    TipoRet salida=borrarOcurrenciasPalabraEnTexto(p,palabra);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
					else if( salida == ERROR )
						printf("ERROR\n");
						
        } else if (0 == strcmp(nombre_comando, "ImprimirTexto")) {
                    TipoRet salida=imprimirTexto(p);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
					else if( salida == ERROR )
						printf("ERROR\n");
						
        } else if (0 == strcmp(nombre_comando, "ComprimirTexto")) {
                    TipoRet salida=comprimirTexto(p);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
					else if( salida == ERROR )
						printf("ERROR\n");
						
        } else if (0 == strcmp(nombre_comando, "InsertarPalabra")) {
                    
                    TipoRet salida=insertarPalabra(p,numeroLin,numeroPal,palabra);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
					else if( salida == ERROR )
						printf("ERROR\n");
				
        } else if (0 == strcmp(nombre_comando, "BorrarPalabra")) {
                    TipoRet salida=borrarPalabra(p,numeroLin,numeroPal);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
					else if( salida == ERROR )
						printf("ERROR\n");
 
		} else if (0 == strcmp(nombre_comando, "BorrarOcurrenciasPalabraEnLinea")) {
                    TipoRet salida=borrarOcurrenciasPalabraEnLinea(p,numeroLin,palabraABorrar);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
					else if( salida == ERROR )
						printf("ERROR\n");
        }
		  else if (0 == strcmp(nombre_comando, "ImprimirLinea")) {
                    TipoRet salida=imprimirLinea(p,numeroLin);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
					else if( salida == ERROR )
						printf("ERROR\n");
        }	
		  else if (0 == strcmp(nombre_comando, "IngresarPalabraDiccionario")) {
                    TipoRet salida=ingresarPalabraDiccionario(p,palabra);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
					else if( salida == ERROR )
						printf("ERROR\n");
		}			
		  else if (0 == strcmp(nombre_comando, "BorrarPalabraDiccionario")) {
                    TipoRet salida=borrarPalabraDiccionario(p,palabra);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
					else if( salida == ERROR )
						printf("ERROR\n");
		}			
		  else if (0 == strcmp(nombre_comando, "ImprimirDiccionario")) {
                    TipoRet salida=imprimirDiccionario(p);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
					else if( salida == ERROR )
						printf("ERROR\n");
		}			
		  else if (0 == strcmp(nombre_comando, "ImprimirTextoIncorrecto")) {
                    TipoRet salida=imprimirTextoIncorrecto(p);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
					else if( salida == ERROR )
						printf("ERROR\n");
		}			
		  else if (0 == strcmp(nombre_comando, "ImprimirUltimasPalabras")) {
                    TipoRet salida=imprimirUltimasPalabras(p);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
					else if( salida == ERROR )
						printf("ERROR\n");
		}					
		else 
			printf("Comando no reconocido.\n");
       
        // if
        fgets(restoLinea, MAX_LINEA + 1, stdin);
  } // while
  return 0;
} // main



 //************* FUNCIONES A IMPLEMENTAR POR LOS ESTUDIANTES ***********
   																								//Obligatorio 1 y 
   
Procesador crearProcesador(Cadena nombre){	
		
		return NULL;
}

TipoRet borrarProcesador(Procesador &p){
			return NO_IMPLEMENTADA;
}

TipoRet insertarLinea(Procesador &p){
		
		 return NO_IMPLEMENTADA;
}

TipoRet insertarLineaEnPosicion(Procesador &p,Posicion PosisionLinea){
		return NO_IMPLEMENTADA;
}

TipoRet borrarLinea(Procesador &a, Posicion posicionLinea){
		return NO_IMPLEMENTADA;
}

TipoRet borrarTodo(Procesador &p){ 
		return NO_IMPLEMENTADA;
}

TipoRet borrarOcurrenciasPalabraEnTexto(Procesador &p, Cadena palabraABorrar){
		return NO_IMPLEMENTADA;
}

TipoRet comprimirTexto(Procesador &p){
		return NO_IMPLEMENTADA;
}

TipoRet insertarPalabra(Procesador &p, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraIngresar){
		return NO_IMPLEMENTADA;
}

TipoRet borrarPalabra(Procesador &p, Posicion posicionLinea, Posicion posicionPalabra){
		return NO_IMPLEMENTADA;
}

TipoRet borrarOcurrenciasPalabraEnLinea(Procesador &p, Posicion posicionLinea, Cadena palabraABorrar){
		return NO_IMPLEMENTADA;
}

TipoRet imprimirLinea(Procesador p, Posicion posicionLinea){
		return NO_IMPLEMENTADA;
}

TipoRet ingresarPalabraDiccionario(Procesador &p, Cadena palabraAIngresar){
		return NO_IMPLEMENTADA;
}

TipoRet imprimirTexto(Procesador p){
		return NO_IMPLEMENTADA;
}

TipoRet borrarPalabraDiccionario(Procesador &p, Cadena palabraABorrar){
		return NO_IMPLEMENTADA;
}
TipoRet imprimirDiccionario(Procesador p){
		return NO_IMPLEMENTADA;
}
TipoRet imprimirTextoIncorrecto(Procesador p){
		return NO_IMPLEMENTADA;
}

TipoRet imprimirUltimasPalabras(Procesador p){
		return NO_IMPLEMENTADA;	
}
   
