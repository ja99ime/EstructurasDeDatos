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
    	usuario *red = NULL; // Inicializamos el grafo como vacío
    	int sel = 0, salir = FALSE;

    	do {
		printf("\n-------------------------------------------------\n");
		printf("             RED SOCIAL          ");
		printf("\n-------------------------------------------------\n\n");

		printf("1) Añadir un nuevo Usuario.\n");
		printf("2) Crear seguimiento.\n");
		printf("3) Mostrar lista de usuarios.\n");
		printf("4) Salir.\n");

		if (scanf("%d", &sel) == 1) {
            		if (sel > 0 && sel < 5) {
                		// ---------------------------- OPC1 ----------------------------------------------------
                		if (sel == 1) {
				    	insertarUsuario(&red);
                		}
                		// ---------------------------- OPC2 ----------------------------------------------------
                		if (sel == 2) {
				    	crearSeguimiento(red);
				}
				// ---------------------------- OPC3 ----------------------------------------------------
				if (sel == 3) {
				    	printf("Seguidores:\n\n");
				    	imprimirUsuarios(red);
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

