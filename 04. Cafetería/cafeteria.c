#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#define TRUE 1
#define FALSE 0
#define MAX 20  
#define FILE_NAME "bebidas.dat"


int main(){

	int sel, salir, cod;
	char bebidaC[30];
	
	// Se definen los punteros para la pila y la cola
	frias *entrada = NULL;
	frias *salida = NULL;
	calientes *cima = NULL;

	struct BEBIDAS carta[MAX];
	int numProductos = cargarProductos(carta);
	printf("BEBIDAS: %d\n", numProductos);  

	
	do {
		
		printf("\n-------------------------------------------------\n");		// Mensaje de inicio para el usuario
		printf("	CAFETERIA BEBIDAS FRIAS Y CALIENTES   ");
		printf("\n-------------------------------------------------\n");

		printf("\n1) Revisar Barra.\n");  						// El usuario guardará una letra.
		printf("2) Realizar pedido.\n");  						// El usuario podrá eliminar una letra.
		printf("3) Hacer Pedido Caliente\n");  							// Se cerrará el programa.
		printf("4) Hacer Pedido Frío\n\n");  							// Se cerrará el programa.
		printf("5) Marcharse\n");  							// Se cerrará el programa.

		if(scanf("%d", &sel) == 1) {  							// SE LEE UN VALOR POR TECLADO
		    	if(sel > 0 && sel < 6) {  						// SI LA OPCION ES VALIDA
		        
		        	// ---------------------------- VER PROXIMAS COMANDAS --------------------------------------
		        	if (sel == 1) {
		            		barraCafetería(cima, salida);				// Esta función mostrará los proximos pedidos que realizará la barra
		        	}
		        	// ---------------------------- Ver Menú----------------------------------------------------
		        	if (sel == 2) {
					hacerPedido(carta, numProductos, &entrada, &salida, &cima);
		        	}
		        	// ---------------------------- Avanzar cola ---------------------------------------------
		        	if (sel == 3) {
		            		desapilar(&cima);
		        	}
		        	// ---------------------------- Avanzar cola ------------------------------------------------
		        	if (sel == 4) {
		            		if (desencolar(&entrada, &salida, bebidaC)) {
    						printf("\n%s entregado al cliente.\n", bebidaC);
					} else {
   						 printf("NO hay bebidas calientes en espera.\n");
					}
		            		
		        	}
		        	// ---------------------------- Salir -------------------------------------------------------
		        	if (sel == 5) {
		            		salir = TRUE;  // Cambiar salir a TRUE para terminar el bucle
		        	}
		    	} else {
		        	printf("ERROR. OPCION NO VALIDA\n");  // SI LA OPCION NO ES VALIDA
		    	}
        	} else {
		    	while(getchar() != '\n');
		    	printf("ERROR. OPCION NO VALIDA\n");
        	}
    	} while (salir == FALSE);  // El bucle se repite mientras salir no sea verdadero
    	return 0;
}