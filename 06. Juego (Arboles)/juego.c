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

	NODO *raiz = NULL;
	int sel, val, finalMalo, salir = FALSE;
    	int llaves=0;  		// Inventario de 10 llaves (0 = no recogida, 1 = recogida)
    	char elec[2];

	cargarJuego(&raiz);
	NODO *actual = raiz; 		// Inicializa actual con la raíz del árbol.
		
	do {
		
        	printf("\n-----------------------------------------------------------------------------------------------------------\n");
        	revisarEscenario(actual, llaves);
		
		
		if (actual->hayPuzzle) {
       			int win = puzzle(actual);
       			if (win)	actual = mover(actual, 1);
       			else		actual = mover(actual, 2);
        		printf("\n-----------------------------------------------------------------------------------------------------------\n\n");
       			revisarEscenario(actual, llaves);
    			finalMalo = 1;
		
		}

		if (actual->llaveRequerida) {
    			printf("\n¿Revisas tus bolsillos en busca de alguna llave? (s/n): ");
    			scanf(" %1s", elec);
    			if (strcmp(elec, "s") == 0) {
       			 	if(abrirPuerta(actual, &llaves)==1){
       			 		llaves--;
       			 		actual = mover(actual, 1);
       			 		printf("\n-----------------------------------------------------------------------------------------------------------\n\n");
       			 		revisarEscenario(actual, llaves);
       			 	}
    			}
		}

		if (actual->hayLlave) {
    			printf("\n¿Quieres recoger la llave? (s/n): ");
    			scanf(" %1s", elec);
    			if (strcmp(elec, "s") == 0) {
       			 	recogerLlave(actual, &llaves);
       			 	llaves++;
       			 	
    			}
		}

		if (actual->esFinal) {
    			printf("\n[GAME OVER]");
	    		exit(1);
		}
		
		if (finalMalo ==1){
			printf("\n-----------------------------------------------------------------------------------------------------------\n\n");
			printf("Parece que no tienes la llave. Intentas bajar las escaleras, pero es imposible. No hay nada que puedas hacer\n");
			printf("Estás atrapado en el tercer piso de la mansión. No hay tesoro así como tampoco salida. Solo tenías que coger\n");
			printf("la llave de la entrada, pero parece que la soberbia te ha jugado una mala pasada. Ahora tu espiritu pasará a\n");
			printf("formar parte de la mansión y no habrá nada que puedas hacer para remediarlo.\n\n");
			printf("[FINAL SECRETO: Salve al nuevo ente de la mansión]");
			printf("\n\n[GAME OVER]");
	    		exit(1);
		}
		
		printf("\n-----------------------------------------------------------------------------------------------------------\n");

		printf("1) Izquierda.\n");  						// El usuario guardará una letra.
		printf("2) Derecha.\n");  						// El usuario podrá eliminar una letra.
		printf("3) Volver.\n\n");  						// Se cerrará el programa.
		printf("0) Salir del Juego\n");  					// Se cerrará el programa.

		if(scanf("%d", &sel) == 1) {  							// SE LEE UN VALOR POR TECLADO
		    	if(sel >= 0 && sel < 4) {  						// SI LA OPCION ES VALIDA
		        
		        	// ---------------------------- VER PROXIMAS COMANDAS --------------------------------------
		        	if (sel == 1 || sel == 2 || sel == 3) {
		            		actual = mover(actual, sel);
		        	}
	
	
		        	// ---------------------------- Avanzar cola ------------------------------------------------
		        	if (sel == 0) {
		            		salir = TRUE;  						// Cambiar salir a TRUE para terminar el bucle
		        	}
		    	} else {
		        	printf("ERROR. OPCION NO VALIDA\n");  // SI LA OPCION NO ES VALIDA
		    	}
        	} else {
		    	while(getchar() != '\n');
		    	printf("ERROR. OPCION NO VALIDA\n");
        	}
    	} while (salir == FALSE);  // El bucle se repite mientras salir no sea verdadero

    	return 1;
}