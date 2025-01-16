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

//-------------------------------------------------CREAR VERTICE-------------------------------------------------------------------------------
vertice *crearCiudad(int id, char *nombre) {			
    	vertice *nuevo = (vertice *)malloc(sizeof(vertice));				// creamos un nuevo nodo auxiliar para devolverlo al final
    	if (nuevo == NULL) {								// si no se ha podido reservar memoria, se devuelve NULL
        	printf("[ERROR] Fallo al asignar memoria para la ciudad.\n");
        	return NULL;
    	}
    	
    	nuevo->id = id;									// se le da el entero pasado como parametro al id
    	strncpy(nuevo->nombre, nombre, 49);						// se le da el string pasado como parametro al nombre
    	nuevo->nombre[49] = '\0';  							// se asegura la terminación del array de chars
    	nuevo->adyacentes = NULL;							// se pone lel vector siguiente a nulo
    	nuevo->siguiente = NULL;							// se pone la arista siguiente a nulo
    	return nuevo;									// Se devuelve el nodo ya creado
}

//-------------------------------------------------INSERTAR VERTICE-------------------------------------------------------------------------------
void insertarCiudad(vertice **grafo) {			
    	
    	int id;
	char nombre[50];
	printf("Ingrese el ID de la ciudad: ");
	scanf("%d", &id);
	while (getchar() != '\n'); 							// Limpiar el buffer

	printf("Ingrese el nombre de la ciudad: ");
	fgets(nombre, 50, stdin);
	nombre[strcspn(nombre, "\n")] = '\0'; 						// Eliminar el salto de línea
    	
    	vertice *nuevo = crearCiudad(id, nombre);					// de crea un nuevo nodo con la funcion crear ciudad
    	if (!nuevo) return;								// si el nodo no se crea correctamente, se retorna nulo

    	nuevo->siguiente = *grafo;							// se conecta al resto de valores, coenctandola al principio de la lista de vertices
    	*grafo = nuevo;									// se establece el inicio del grafo como el nuevo nodo
    	
    	printf("Ciudad '%s' añadida con éxito.\n", nombre);
}

//-------------------------------------------------BUSCAR NODO CIUDAD------------------------------------------------------------------------------

vertice *buscarCiudad(vertice *grafo, int id) {
    	vertice *actual = grafo;					// creamos un nodo auxiliar
    	while (actual != NULL) {					// recorremos la lista de vestices del grafo hasta llegar al ultimo elemento
		if (actual->id == id) return actual;			// si el id es igual al entero recibido, se devuelve el nodo actual
		actual = actual->siguiente;				// SI no,se avanza al siguiente vertice
    	}	
    	return NULL; 							// Si no se encuentra, devolver NULL
}
//-------------------------------------------------CREAR ARISTA-------------------------------------------------------------------------------
void conectarCiudades(vertice *grafo) {
    	
    	int id1, id2;
	float distancia;
	printf("Ingrese el ID de la primera ciudad: ");
	scanf("%d", &id1);
	printf("Ingrese el ID de la segunda ciudad: ");
	scanf("%d", &id2);
	printf("Ingrese la distancia entre las ciudades: ");
	scanf("%f", &distancia);

    	
    	vertice *ciudad1 = buscarCiudad(grafo, id1);				// se crean dos vertices auxiliares que serviran para conectar las ciudades
    	vertice *ciudad2 = buscarCiudad(grafo, id2);				// estos vertices se asignarán a los vertices correctos con la funcion buscar ciudad

    	if (!ciudad1 || !ciudad2) {
        	printf("Una o ambas ciudades no existen.\n");			// si alguna de las dos ciudades no existen, se avisa al usuario y se sale de la funcion
        	return;
    	}

    	arista *nuevaArista1 = (arista *)malloc(sizeof(arista));	    	
    	nuevaArista1->destino = id2;						// se establece el destino de la ruta para la ciudad 1
    	strcpy(nuevaArista1->nombre, ciudad2->nombre); 				// Copiar el nombre de la ciudad destino
    	nuevaArista1->distancia = distancia;					// se establece la distancia con el valor pasado por parametros
    	nuevaArista1->siguiente = ciudad1->adyacentes;				// se añade al inicio de la lista de adyacencias del vertice
    	ciudad1->adyacentes = nuevaArista1;					// por ultimo, se añade la nueva arista a la ciudad 1

    	arista *nuevaArista2 = (arista *)malloc(sizeof(arista));		
    	nuevaArista2->destino = id1;						// se establece el destino de la ruta para la ciudad 2
    	strcpy(nuevaArista2->nombre, ciudad1->nombre); 				// Copiar el nombre de la ciudad destino
    	nuevaArista2->distancia = distancia;					// se establece la distancia con el valor pasado por parametros
    	nuevaArista2->siguiente = ciudad2->adyacentes;				// se añade al inicio de la lista de adyacencias del vertice
    	ciudad2->adyacentes = nuevaArista2;					// por ultimo, se añade la nueva arista a la ciudad 2
    	
    	printf("Ruta entre las ciudades %d y %d añadida con éxito.\n", id1, id2);
}
//-------------------------------------------------IMPRIMIR MAPA-------------------------------------------------------------------------------
void imprimirMapa(vertice *grafo) {
    	vertice *actual = grafo;							// creamos un nodo auxiliar
    	while (actual) {								// mientras haya un nodo actual
        	printf("Ciudad %d (%s):\n", actual->id, actual->nombre);		// se imprime la ciudad junto a su ID
        	arista *ady = actual->adyacentes;					// creamos un nodo auxiliar para las aristas de cada vertice
        	while (ady) {											// mientras haya conexiones al vertice				
            		printf("  -> Ciudad %s (Distancia: %.2f km)\n\n", ady->nombre, ady->distancia);		// se imprime la conexión
            		ady = ady->siguiente;									// se avanza a la siguiente conexion
        	}
        	actual = actual->siguiente;									// se avanza a la siguiente ciudad
    	}
}