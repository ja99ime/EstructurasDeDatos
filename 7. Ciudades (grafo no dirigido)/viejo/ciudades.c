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
				    	int id;
				    	char nombre[50];
				    	printf("Ingrese el ID de la ciudad: ");
				    	scanf("%d", &id);
				    	while (getchar() != '\n'); // Limpiar el buffer

				    	printf("Ingrese el nombre de la ciudad: ");
				    	fgets(nombre, 50, stdin);
				    	nombre[strcspn(nombre, "\n")] = '\0'; // Eliminar el salto de línea

				    	insertarCiudad(&mapa, id, nombre);
				    	printf("Ciudad '%s' añadida con éxito.\n", nombre);
                		}
                		// ---------------------------- OPC2 ----------------------------------------------------
                		if (sel == 2) {
				    	int id1, id2;
				    	float distancia;
				    	printf("Ingrese el ID de la primera ciudad: ");
				    	scanf("%d", &id1);
				    	printf("Ingrese el ID de la segunda ciudad: ");
				    	scanf("%d", &id2);
				    	printf("Ingrese la distancia entre las ciudades: ");
				    	scanf("%f", &distancia);

				    	conectarCiudades(mapa, id1, id2, distancia);
				    	printf("Ruta entre las ciudades %d y %d añadida con éxito.\n", id1, id2);
				}
				// ---------------------------- OPC3 ----------------------------------------------------
				if (sel == 3) {
				    	printf("Mapa de ciudades:\n");
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

