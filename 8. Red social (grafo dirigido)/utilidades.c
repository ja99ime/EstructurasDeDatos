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

//-------------------------------------------------CREAR usuario-------------------------------------------------------------------------------
usuario *crearUsuario(int id, char *nombre) {			
    	usuario *nuevo = (usuario *)malloc(sizeof(usuario));				// creamos un nuevo nodo auxiliar para devolverlo al final
    	if (nuevo == NULL) {								// si no se ha podido reservar memoria, se devuelve NULL
        	printf("[ERROR] Fallo al asignar memoria para el usuario.\n");
        	return NULL;
    	}
    	
    	nuevo->id = id;									// se le da el entero pasado como parametro al id
    	strncpy(nuevo->nombre, nombre, 49);						// se le da el string pasado como parametro al nombre
    	nuevo->nombre[49] = '\0';  							// se asegura la terminación del array de chars
    	nuevo->adyacentes = NULL;							// se pone lel vector siguiente a nulo
    	nuevo->siguiente = NULL;							// se pone la seguidor siguiente a nulo
    	return nuevo;									// Se devuelve el nodo ya creado
}

//-------------------------------------------------INSERTAR usuario-------------------------------------------------------------------------------
void insertarUsuario(usuario **grafo) {			
    	
    	int id;
	char nombre[50];
	printf("Ingrese el ID del usuario: ");
	scanf("%d", &id);
	while (getchar() != '\n'); 							// Limpiar el buffer

	printf("Ingrese el nombre del usuario: ");
	fgets(nombre, 50, stdin);
	nombre[strcspn(nombre, "\n")] = '\0'; 						// Eliminar el salto de línea
    	
    	usuario *nuevo = crearUsuario(id, nombre);					// de crea un nuevo nodo con la funcion crear ciudad
    	if (!nuevo) return;								// si el nodo no se crea correctamente, se retorna nulo

    	nuevo->siguiente = *grafo;							// se conecta al resto de valores, coenctandola al principio de la lista de vertices
    	*grafo = nuevo;									// se establece el inicio del grafo como el nuevo nodo
    	
    	printf("Usuario '%s' añadida con éxito.\n", nombre);
}

//-------------------------------------------------BUSCAR NODO CIUDAD------------------------------------------------------------------------------

usuario *buscarUsuario(usuario *grafo, int id) {
    	usuario *actual = grafo;					// creamos un nodo auxiliar
    	while (actual != NULL) {					// recorremos la lista de vestices del grafo hasta llegar al ultimo elemento
		if (actual->id == id) return actual;			// si el id es igual al entero recibido, se devuelve el nodo actual
		actual = actual->siguiente;				// SI no,se avanza al siguiente usuario
    	}	
    	return NULL; 							// Si no se encuentra, devolver NULL
}
//-------------------------------------------------CREAR seguidor-------------------------------------------------------------------------------
void crearSeguimiento(usuario *grafo) {
    	
    	int id1, id2;
	printf("Ingrese el ID del seguidor: ");
	scanf("%d", &id1);
	printf("Ingrese el ID del seguido: ");
	scanf("%d", &id2);
    	
    	usuario *usu1 = buscarUsuario(grafo, id1);				// se crean dos vertices auxiliares que serviran para conectar las ciudades
    	usuario *usu2 = buscarUsuario(grafo, id2);				// estos vertices se asignarán a los vertices correctos con la funcion buscar ciudad

    	if (!usu1 || !usu2) {
        	printf("Uno o ambos usuarios no existen.\n");			// si alguna de las dos ciudades no existen, se avisa al usuario y se sale de la funcion
        	return;
    	}

   
   	//usu 2 -> usu1
        /*seguidor *nuevaArista1 = (seguidor *)malloc(sizeof(seguidor));	    	
    	nuevaArista1->idSeguido = id2;						// se establece el destino de la ruta para la ciudad 1
    	strcpy(nuevaArista1->nombre, usu2->nombre); 				// Copiar el nombre de la ciudad destino
    	nuevaArista1->siguiente = usu1->adyacentes;				// se añade al inicio de la lista de adyacencias del usuario
    	usu1->adyacentes = nuevaArista1;					// por ultimo, se añade la nueva seguidor a la ciudad 1
	*/
	
	//usu 1 -> usu2
    	seguidor *nuevaArista2 = (seguidor *)malloc(sizeof(seguidor));		
    	nuevaArista2->idSeguido = id1;						// se establece el destino de la ruta para la ciudad 2
    	strcpy(nuevaArista2->nombre, usu1->nombre); 				// Copiar el nombre de la ciudad destino
    	nuevaArista2->siguiente = usu2->adyacentes;				// se añade al inicio de la lista de adyacencias del usuario
    	usu2->adyacentes = nuevaArista2;					// por ultimo, se añade la nueva seguidor a la ciudad 2
    	
    	printf("Ahora el usuario %d sigue al usuario %d. \n", id1, id2);
}
//-------------------------------------------------IMPRIMIR MAPA-------------------------------------------------------------------------------
void imprimirUsuarios(usuario *grafo) {
    	usuario *actual = grafo;							// creamos un nodo auxiliar
    	while (actual) {								// mientras haya un nodo actual
        	printf("Usuario %d (%s):\n", actual->id, actual->nombre);		// se imprime la ciudad junto a su ID
        	seguidor *ady = actual->adyacentes;					// creamos un nodo auxiliar para las aristas de cada usuario
        	while (ady) {											// mientras haya conexiones al usuario				
            		printf("  -> Usuario %s \n\n", ady->nombre);		// se imprime la conexión
            		ady = ady->siguiente;									// se avanza a la siguiente conexion
        	}
        	actual = actual->siguiente;									// se avanza a la siguiente ciudad
    	}
}