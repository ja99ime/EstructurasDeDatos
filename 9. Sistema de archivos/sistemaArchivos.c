#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "utilidades.h"

#define TRUE 1
#define FALSE 0
#define ERROR -1
#define MAX 20  



int main(){

  	NODO *raiz = NULL;  		// Raíz del árbol
    	NODO *actual = NULL;  		// Nodo actual (posición en el árbol)

    	// Inicializar el árbol con el nodo raíz "\"
   	NODO ini = {"HOME", 0, NULL, NULL, NULL};
    	raiz = (NODO *)malloc(sizeof(NODO));
    	if (!raiz) {
        	printf("[ERROR] No se pudo inicializar el árbol.\n");
        	return 1;
    	}
    	*raiz = ini;
    	actual = raiz;  // El nodo actual apunta a la raíz
	
	int sel, cod, salir = FALSE;
	char buscar[30];
	do {
		
		printf("\n-------------------------------------------------\n");		
		printf("	        SISTEMA DE ARCHIVOS  ");					// Mensaje de inicio para el usuario
		printf("\n-------------------------------------------------\n\n");

		printf("Estás en: ");  
		
		buscarEImprimirNodoConPadres(raiz, actual->nombre);
		verHijos(actual);

		printf("1) Listar arbol carpetas.\n");  					// Se listan las carpetas del directorio actual
		printf("2) Moverse a una de las carpetas del directorio.\n");  			// Se accede a una de las carpetas del directorio
		printf("3) Moverse a la carpeta anterior.\n\n");  				// Se va hacia atrás en el arbol del directorio
		printf("4) Crear Carpeta o Documento de Texto.\n");  						// Se crea una nueva Carpeta
		printf("5) Borrar Carpeta o Documento de Texto.\n");  						// Se borra una carpeta
		printf("6) Buscar Carpeta o Documento de Texto.\n\n"); 
		printf("0) Salir.\n");  							// Se sale del menu

		if(scanf("%d", &sel) == 1) {  							// SE LEE UN VALOR POR TECLADO
		    	if(sel >= 0 && sel < 7) {  						// SI LA OPCION ES VALIDA
		        
		        	// ---------------------------- LISTAR ARBOL DE CARPETAS ----------------------------------------------------
		        	if (sel == 1) {
		            		recorrerEnPreorden(raiz, 0);			
		        	}
		        	// ---------------------------- ACCEDER A UNA SUBCARPETA ----------------------------------------------------
		        	if (sel == 2) {
		        		
		        		NODO *carpeta = mover(actual);
		        		if (carpeta == NULL) printf("[ERROR] No se ha podido encontrar la carpeta %s", buscar);
		        		else {
		        			actual = carpeta;
		        		}
		        	}
		        	// ---------------------------- RETROCEDER A LA CARPETA ANTERIOR ----------------------------------------------------
		        	if (sel == 3) {
		            		if (actual->padre != NULL) actual = actual->padre;
    					else printf("[ERROR] Ya estás en la raiz");
		        	}
		        	// ---------------------------- CREAR NUEVA CARPETA ----------------------------------------------------
		        	if (sel == 4) {
		            		NODO carpeta = *leerNodo();
		            		if (arbolVacio)
		          		insercion(&raiz, actual, carpeta);
		        	}
		        	// ---------------------------- BORRAR CARPETA ----------------------------------------------------
		        	if (sel == 5) {
		            		printf("Introduce el nombre de la carpeta: ");	
    					scanf("%29s", buscar); 									
    					getchar(); 
		            		
		            		NODO *carpetaE = buscarNodo(actual, buscar);
		            		
		            		if (arbolVacio(carpetaE)){
		            			eliminarHoja(carpetaE);
		            		}else{
		            			eliminarArbol(&carpetaE); 
		            		}
		        	}
		        	
		        	// ---------------------------- BUSCAR CARPETA ----------------------------------------------------
		        	if (sel == 6) {
		            		printf("Introduce el nombre de la carpeta: ");	
    					scanf("%29s", buscar); 									
    					getchar(); 
		            		
		            		printf ("RUTA: ");
		            		buscarEImprimirNodoConPadres(raiz, buscar);
		        	}
		        	
		        	// ---------------------------- Salir -------------------------------------------------------
		        	if (sel == 0) {
		            		salir = TRUE;  			// Cambiar salir a TRUE para terminar el bucle
		        	}
		    	} else {
		        	printf("ERROR. OPCION NO VALIDA\n");  	// se imprime un mensaje si la opcion no es valida
		    	}
        	} else {
		    	while(getchar() != '\n');
		    	printf("ERROR. OPCION NO VALIDA\n");
        	}
    	} while (salir == FALSE);  					// El bucle se repite mientras salir no sea verdadero

    	return 0;
}