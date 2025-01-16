#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "utilidades.h"

#define TRUE 1
#define FALSE 0
#define TAM 1000

// ----------------------------------FUNCION GENERAR NUMEROS ALEATORIOS--------------------------------------------------
void genera(int lista[], int tamArray){
	// Creamos la semilla de la variable aleatoria
	srand(time(NULL));
	
	for(int i = 0; i < tamArray; i++){
		lista[i]= rand() % TAM;
	}
}


// ----------------------------------FUNCION MOSTRAR ARRAY---------------------------------------------------------------
void imprimirArray(int datos[], int tam) {
    printf("\nSe listará el conjunto de elementos...\n\n");
    for (int i = 0; i < tam; i++) {
        if (i == 0) {
            printf("%d", datos[i]);
        } else {
            printf("; %d", datos[i]);
        }
    }
    printf("\n");
}

// -------------------------------------FUNCION COMPROBAR ORDENACION-------------------------------------------------------
int esta_ordenado(int n, int *a){
	int i;
	for(i=0; i < n-1; i++){
		 if(a[i] > a[i+1]){
		 	return FALSE;
		}
	}
	return TRUE;
}


// ----------------------------------FUNCION ORDENACION BURBUJA----------------------------------------------------------
int burbuja(int datos[], int tam){
	struct timeval t0, t1;
	int i, j, aux;
	int cont = TRUE;
	
	//Se inicia el conteo
	gettimeofday(&t0, NULL);
	
	// Se ordena el array
	do{
		cont = FALSE;

		for(i=0; i<tam; i++){
			for(j=0; j < (tam - 1) - i; j++){
				if (datos[j]>datos[j+1]){
					aux = datos [j];
					datos[j]= datos [j + 1];
					datos[j+1] = aux;
					cont = TRUE;
				}
			}
		}
	}while(cont == TRUE);
	
	// Se termina el conteo
	gettimeofday(&t1, NULL);
	unsigned long t = (t1.tv_sec - t0.tv_sec) * 1000000 + t1.tv_usec - t0.tv_usec;
	printf("\nTiempo de Ordenación(Burbuja): %luµs \n", t);
	return 0;
}

// ----------------------------------FUNCION ORDENACION SELECCION--------------------------------------------------------
int seleccion(int datos[], int tam) {
	struct timeval t0, t1;
	// Se declaran variables
	
	int i, j;
	int min, posmin;

	// Se inicia el conteo
	gettimeofday(&t0, NULL);
    	
    	// Se inicia la ordenación de elementos
    	for (i = 0; i < tam - 1; i++) {
        	min = datos[i];
        	posmin = i;
        	for (j = i + 1; j < tam; j++) {
            		if (min > datos[j]) {
                		min = datos[j];
                		posmin = j;
            		}
        	}
        	// Se Intercambia
        	int aux = datos[posmin];
        	datos[posmin] = datos[i];
        	datos[i] = aux;
    	}

	// Se detiene el conteo
    	gettimeofday(&t1, NULL);
    	unsigned long t = (t1.tv_sec - t0.tv_sec) * 1000000 + t1.tv_usec - t0.tv_usec;
    	printf("\nTiempo de Ordenación (Seleccion): %luµs \n", t);
    	return 0;
}
// ----------------------------------FUNCION ORDENACION INSERCCION----------------------------------------------------
int insercion(int datos[], int tam) {
    	struct timeval t0, t1;
	// Se declaran variables
	int i, j, aux;	
	
	// Se inicia el conteo
	gettimeofday(&t0, NULL);
    	
    	// Se inicia la ordenación de elementos
    	for (i = 1; i < tam; i++) {
        	aux = datos[i];
        	j = i;
        
        	// El bucle while desplaza los elementos menores a la derecha	
        	while(aux < datos[j-1] && j>0){
    			datos[j] = datos[j-1];
                	j--;
            	}
            	datos[j] = aux;
        }

	// Se detiene el conteo
    	gettimeofday(&t1, NULL);
    	unsigned long t = (t1.tv_sec - t0.tv_sec) * 1000000 + t1.tv_usec - t0.tv_usec;
    	printf("\nTiempo de Ordenación (Insercion): %luµs \n", t);
    	return 0;
}

// ----------------------------------FUNCION ORDENACION SHELL--------------------------------------------------------
int shell(int datos[], int tam) {
    	struct timeval t0, t1;
	// Se declaran variables
	int i, j, aux;	
	int dist = tam;
	
	
	// Se inicia el conteo
	gettimeofday(&t0, NULL);
    	
    	// Se ajusta la distancia
    	while (dist!=1) {
    		dist = dist/2;
    	
    		// Se inicia la ordenación de elementos
    		for (i = dist; i < tam; i++) {
        		aux = datos[i];
        		j = i;
        
        		// El bucle while desplaza los elementos menores a la derecha	
        		while(aux < datos[j - dist] && j - dist >= 0){
    				datos[j] = datos[j - dist];
                		j = j - dist;
            		}
            		datos[j] = aux;
        	}
        	
        }
	// Se detiene el conteo
    	gettimeofday(&t1, NULL);
    	unsigned long t = (t1.tv_sec - t0.tv_sec) * 1000000 + t1.tv_usec - t0.tv_usec;
    	printf("\nTiempo de Ordenación (Shell): %luµs \n", t);
    	return 0;
}

// ----------------------------------FUNCION ORDENACION SACUDIDA----------------------------------------------------
int sacudida(int datos[], int tam) {
    	struct timeval t0, t1;
    	gettimeofday(&t0, NULL);

    	int i, temp;
    	int inicio = 0;
    	int fin = tam - 1;
    	int intercambio = 1;

    	while (intercambio) {
        	intercambio = 0;

        	// Recorrido de izquierda a derecha
        	for (i = inicio; i < fin; i++) {
            		if (datos[i] > datos[i + 1]) {
                	// Intercambiar
                	temp = datos[i];
                	datos[i] = datos[i + 1];
                	datos[i + 1] = temp;
                	intercambio = 1;
            		}
        	}
        	fin--; // Reducir el fin porque el último elemento está en su lugar

        	// Si no hubo intercambio, el arreglo ya está ordenado
        	if (!intercambio)
            		break;

        	intercambio = 0;

        	// Recorrido de derecha a izquierda
        	for (i = fin; i > inicio; i--) {
        		if (datos[i] < datos[i - 1]) {
                		// Intercambiar
                		temp = datos[i];
                		datos[i] = datos[i - 1];
                		datos[i - 1] = temp;
                		intercambio = 1;
            		}
        	}
        	inicio++; // Incrementar el inicio porque el primer elemento está en su lugar
    	}

    	gettimeofday(&t1, NULL);
    	unsigned long t = (t1.tv_sec - t0.tv_sec) * 1000000 + t1.tv_usec - t0.tv_usec;
    	printf("\nTiempo de Ordenación (Sacudida): %luµs \n", t);
    	return 0;
}

// ----------------------------------FUNCION ORDENACION QUICKSORT----------------------------------------------------
int quickSort(int datos[], int iniArg, int finArg){
	
	// Se declaran variables
	int ini, fin, aux;
	int pivote = (iniArg + finArg)/2;
		
	ini = iniArg;
	fin = finArg;
	
	while (ini<=fin){
		while(datos[ini] < datos[pivote]){
			ini++;
		}
		while(datos[fin] > datos[pivote]){
			fin--;
		}        	
		if (ini <=fin){
		     	aux = datos[ini];
        		datos[ini] = datos[fin];
        		datos[fin] = aux;

        		// Se vuelve hacia atrás para continuar comparando
        		ini++;
        		fin --;
        	}
	}
	if (iniArg < fin){
		quickSort(datos, iniArg, fin);
	}
	
	if (ini < finArg){
		quickSort(datos, ini, finArg);	
	}

    	return 0;

}