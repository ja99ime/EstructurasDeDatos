#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "utilidades.h"


int main(){
	// ----------------------------------MEDICION DE TIEMPOS-----------------------------------------
    	static struct timeval t0, t1;
    	

	// ---------------------------CREACION DEL ARRAY ALEATORIO---------------------------------------
	// Creamos la semilla de la variable aleatoria
	srand(time(NULL));
	
	// Se da aleatoriamente una longitud al array
	int tamArray = rand() % 100;
	
	// Se crea el array
	int lista[tamArray];
	
	// Se llena el array de numeros aleatorios
	genera(lista, tamArray);

	// Se muestra el array
	imprimirArray(lista, tamArray);

	// Se informa al usuario.
	printf("\nEl array resultante tiene %d elementos.\n", tamArray);
	
	// ----------------------------------BURBUJA--------------------------------------------------
	printf("\nOrdenando por el metodo BURBUJA..\n");
	int burbu[tamArray];
	for (int i = 0; i < tamArray; i++) {
    		burbu[i] = lista[i];
		}
	burbuja(burbu, tamArray);
	
	// Se muestra el resultado
	imprimirArray(burbu, tamArray);
	
	// ----------------------------------SELECCION--------------------------------------------------
	printf("\nOrdenando por el metodo SELECCION...\n");
	int sele[tamArray];
	for (int i = 0; i < tamArray; i++) {
    		sele[i] = lista[i];
		}
	seleccion(sele, tamArray);
	
	// Se muestra el resultado
	imprimirArray(sele, tamArray);
	
	// ----------------------------------INSERCION--------------------------------------------------
	printf("\nOrdenando por el metodo INSERCION...\n");
	int inser[tamArray];
	for (int i = 0; i < tamArray; i++) {
    		inser[i] = lista[i];
		}
	insercion(inser, tamArray);
	
	// Se muestra el resultado
	imprimirArray(inser, tamArray);
	
	// ----------------------------------SHELL------------------------------------------------------
	printf("\nOrdenando por el metodo SHELL..\n");
	int shel[tamArray];
	for (int i = 0; i < tamArray; i++) {
    		shel[i] = lista[i];
		}
	shell(shel, tamArray);
	
	// Se muestra el resultado
	imprimirArray(shel, tamArray);
	
	// ----------------------------------SACUDIDA--------------------------------------------------
	printf("\nOrdenando por el metodo SACUDIDA...\n");
	int sacu[tamArray];
	for (int i = 0; i < tamArray; i++) {
    		sacu[i] = lista[i];
		}
	sacudida(sacu, tamArray);
	
	// Se muestra el resultado
	imprimirArray(sacu, tamArray);
	
		// ----------------------------------QuickSort--------------------------------------------------
	printf("\nOrdenando por el metodo QuickSort...\n");
	int quiso[tamArray];
	for (int i = 0; i < tamArray; i++) {
    		quiso[i] = lista[i];
		}
	gettimeofday(&t0, NULL);
	quickSort(quiso, 0, tamArray - 1);
	gettimeofday(&t1, NULL);
    	unsigned long t = (t1.tv_sec - t0.tv_sec) * 1000000 + t1.tv_usec - t0.tv_usec;
    	printf("\nTiempo de Ordenación (QuickSort): %luµs \n", t);
    	imprimirArray(quiso, tamArray);
}
