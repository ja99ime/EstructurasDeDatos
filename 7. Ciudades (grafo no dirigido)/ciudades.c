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



int main() {
    	vertice *mapa = NULL; // Inicializamos el grafo como vacío
    	int sel = 0, salir = FALSE;

    	do {
		printf("\n-------------------------------------------------\n");
		printf("             MAPA DE CIUDADES           ");
		printf("\n-------------------------------------------------\n\n");

		printf("1) Añadir una nueva ciudad.\n");
		printf("2) Conectar dos ciudades con una ruta.\n");
		printf("3) Mostrar el mapa de ciudades.\n");
		printf("4) Salir.\n");

		if (scanf("%d", &sel) == 1) {
            		if (sel > 0 && sel < 5) {
                		// ---------------------------- OPC1 ----------------------------------------------------
                		if (sel == 1) {
				    	insertarCiudad(&mapa);
                		}
                		// ---------------------------- OPC2 ----------------------------------------------------
                		if (sel == 2) {
				    	conectarCiudades(mapa);
				}
				// ---------------------------- OPC3 ----------------------------------------------------
				if (sel == 3) {
				    	printf("Mapa de ciudades:\n\n");
				    	imprimirMapa(mapa);
				}

                		// ---------------------------- Salir ----------------------------------------------------
                		if (sel == 4) {
                    			salir = TRUE;
                    			printf("Saliendo del programa...\n");
                		}
            		} else {
                		printf("ERROR. OPCION NO VALIDA\n");
            		}
        	} else {
            		while (getchar() != '\n'); // Limpiar el buffer
            		printf("ERROR. OPCION NO VALIDA\n");
        	}
    	} while (salir == FALSE);

    	return 0;
}

