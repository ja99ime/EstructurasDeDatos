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
	
	int sel, cod, salir = FALSE;
  	
  	do {
        	printf("\n-------------------------------------------------\n");        
        	printf("          CALCULADORA BINARIA\n"); 
	        printf("\n-------------------------------------------------\n\n");
	
        	recorrerEnOrden(raiz);

        	printf("\n1) Ingresar Valor.\n"); 	// Opción para ingresar un valor
        	printf("2) Resolver.\n"); 		// Opción para resolver
        	printf("3) Reiniciar Valores.\n\n"); 	// Opción para reiniciar calculadora
        	printf("0) Salir.\n"); 			// Opción para salir


		if(scanf("%d", &sel) == 1) {  						// SE LEE UN VALOR POR TECLADO
		    	if(sel >= 0 && sel <= 3) {  					// SI LA OPCION ES VALIDA
		        
		        	// ---------------------------- OPC1 ----------------------------------------------------
		        	if (sel == 1) {
		            		 ingresarValor(&raiz);			
		        	}
		        	// ---------------------------- OPC2 ----------------------------------------------------
		        	if (sel == 2) {
        	 			if (raiz != NULL) {
                    				int resultado = resolverOperacion(raiz);  // Resolver la operación en el árbol
                    				printf("\n--------------------------------------\n\n");
                    				printf("Resultado de la operación: %d\n", resultado);
                    				printf("\n---------------------------------------\n\n");
                    				eliminarArbol(&raiz);
                			} else {
                    				printf("El árbol está vacío, no hay operación que resolver.\n");
                			}
		        	}
		        	// ---------------------------- OPC3 ----------------------------------------------------
		        	if (sel == 3) {
 					eliminarArbol(&raiz);
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