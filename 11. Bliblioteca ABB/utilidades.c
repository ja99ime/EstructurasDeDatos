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

// ---------------------------- LEER NODO ----------------------------------------------------
NODO *leerNodo(int id) {
    	NODO *nuevo = (NODO *)malloc(sizeof(NODO)); 						// se reserva memoria para el nodo
    	if (nuevo == NULL) {
        	printf("[ERROR FATAL] No se pudo reservar memoria para el nodo.\n");		// si no se puede, se informa al usuario
        	return NULL;									// se devuelve NUlo
    	}
	//nuevo->id = id;

	printf("Introduce el ID: ");
    	scanf("%d", &nuevo->id); 								// Leemos el numero paginas
    	getchar(); 		
	
    	printf("Introduce el TITULO (máx 30 caracteres): ");
    	scanf("%29s", nuevo->libro.titulo); 							// Leemos el titulo
    	getchar(); 										// se consume el salto de línea sobrante

    	printf("Introduce el AUTOR (máx 30 caracteres): ");
    	scanf("%29s", nuevo->libro.autor); 							// Leemos el autor
    	getchar(); 										// se consume el salto de línea sobrante

    	printf("Introduce el NUMERO PAGINAS: ");
    	scanf("%d", &nuevo->libro.numPag); 							// Leemos el numero paginas
    	getchar(); 										// se consume el salto de línea sobrante

    	// Inicializar los hijos
    	nuevo->hijo_izq = NULL;
    	nuevo->hijo_der = NULL;

    	return nuevo; // Retornar el nodo creado
}



// ---------------------------- BUSQUEDA ----------------------------------------------------
int busqueda(NODO **raiz, int id){
	NODO *p  = *raiz;							// se crea el nodo auxiliar p
	
	while(p!=NULL){								// mientras p no sea nulo...

		if (p->id == id)	return TRUE;				// Si se localiza en el arbol padre se devuelve verdad
		else{
			if (p->id > id) p = p->hijo_izq;			// si el resultado es menor a 0, va al arbol izquierdo
			else p = p->hijo_der;					// si el resultado es mayor a 0, va al arbol izquierdo
		}
	}
	return FALSE;								// si no se ha encontrado, se devuelve falso
}

void busqueda2(NODO **raiz, int id){
	NODO *p  = *raiz;							// se crea el nodo auxiliar p
	
	while(p!=NULL){								// mientras p no sea nulo...

		if (p->id == id){						// Si se localiza en el arbol padre se escirben los valores
			printf("ID: %d | Título: %s | Autor: %s | Páginas: %d\n",
               		p->id, p->libro.titulo, p->libro.autor, p->libro.numPag);
               		return;
		}				
		else{
			if (p->id > id) p = p->hijo_izq;			// si el resultado es menor a 0, va al arbol izquierdo
			else p = p->hijo_der;					// si el resultado es mayor a 0, va al arbol izquierdo
		}
	}							// si no se ha encontrado, se devuelve falso
}

// ---------------------------- CREAR NODO (INSERCION) ----------------------------------------------------
NODO *crearNodo(NODO *elemento) {			
    	NODO *nuevo = (NODO *)malloc(sizeof(NODO));				// se reserva espacio para el nodo nuevo
    	if (nuevo == NULL) {
		printf("[ERROR FATAL]\n");					// si no se hapodido reservar memoria, se informa al usuairo
		return NULL;							// se devuelve nulo
    	}
    	// Copiamos los datos del elemento al nuevo nodo (uso strcpy para chars)
    	nuevo->id = elemento->id;
    	strcpy(nuevo->libro.titulo, elemento->libro.titulo);
    	strcpy(nuevo->libro.autor, elemento->libro.autor);
    	nuevo->libro.numPag = elemento->libro.numPag;
    	nuevo->hijo_izq = NULL;							// los hijos se ponen a NULL
    	nuevo->hijo_der = NULL;
    	return nuevo;								// se devuelve el nodo nuevo
}
// ---------------------------- BUSQUEDA LUGAR (INSERCCION) ----------------------------------------------------
NODO *busquedaLugar(NODO **raiz, int id) {
    	NODO *padre = NULL;  							// se inicializa el nodo padre
    	NODO *actual = *raiz;  							// creamos un nodo para recorrer el arbol

    	while (actual != NULL) {
		if (actual->id == id) return NULL;				// Si se encuentra el nodo, devolver NULL (no se puede insertar)
     
        	padre = actual; 						// se actualiza el padre
        	if (actual->id > id) actual = actual->hijo_izq; 		// se va al subárbol izquierdo
            	else actual = actual->hijo_der; 				// se va al subárbol derecho
            				
    	}

    	return padre; // Devolver el nodo padre donde insertar el nuevo nodo
}

// ---------------------------- INSERCCION ----------------------------------------------------
int insercion(NODO **raiz, NODO *elemento) {
    	NODO *padre = busquedaLugar(raiz, elemento->id);			// Buscamos directamente la posicion en la que debe ir el nodo padre

    	if (padre == NULL && *raiz != NULL) {
        	// Si padre es NULL pero el arbol no está vacío, el nodo ya existe
        	printf("Elemento ya encontrado en el sistema: ID %s\n", elemento->id);
        	return FALSE;
    	}

    	NODO *nuevo = crearNodo(elemento);					// en caso contrario, creaomos un nuevo nodo
    	if (nuevo == NULL) return FALSE;

    	if (padre == NULL) {					       		// si el arbol esta vacío, el nuevo nodo es la raíz
        	*raiz = nuevo;
    	} else if (elemento->id < padre->id) {		// si no se compara el valor obtenido de la comparacion de cadenas
        	padre->hijo_izq = nuevo; 				// si es menor a cero se inserta en el hijo izquierdo
    	} else  padre->hijo_der = nuevo; 				// si es mayor a cero se inserta en el hijo derecho


    return TRUE;
}
// ---------------------------- ELIMINACION ----------------------------------------------------
void eliminarArbol(NODO *raiz) {
    	if (raiz == NULL) {
        	return; // Si el árbol está vacío, no hacemos nada
    	}

    	// Recursivamente eliminar los subárboles
    	eliminarArbol(raiz->hijo_izq);
    	eliminarArbol(raiz->hijo_der);

    	// Eliminar el nodo actual
    	printf("Eliminando nodo con ID: %d\n", raiz->id);
    	free(raiz);
}

void eliminarSubarbol(NODO **raiz, int id) {
    	if (*raiz == NULL) return; // Si el árbol está vacío, no hacemos nada

    	// Buscar el nodo a eliminar
    	if (id < (*raiz)->id) {
        	eliminarSubarbol(&((*raiz)->hijo_izq), id);
    	} else if (id > (*raiz)->id) {
        	eliminarSubarbol(&((*raiz)->hijo_der), id);
    	} else {
		// Nodo encontrado, eliminar subárbol
		printf("Eliminando el subárbol con raíz en ID: %d\n", (*raiz)->id);
		eliminarArbol(*raiz);  // Eliminar todo el subárbol desde este nodo
		*raiz = NULL;          // Actualizar el puntero del padre
    	}
}
/* PORSIACASO
NODO *eliminarNodo(NODO *raiz, int id) {
    	if (raiz == NULL)  return raiz;


    	// Buscar el nodo a eliminar
    	if (id < raiz->id) {
        	raiz->hijo_izq = eliminarNodo(raiz->hijo_izq, id);
    	} else if (id > raiz->id) {
        	raiz->hijo_der = eliminarNodo(raiz->hijo_der, id);
    	} else {
        	// Nodo sin hijos
        	if (raiz->hijo_izq == NULL && raiz->hijo_der == NULL) {
            		free(raiz);
            		return NULL;
        	}

        	// Nodo con un hijo
        	if (raiz->hijo_izq == NULL) {
            		NODO *temp = raiz->hijo_der;
            		free(raiz);
            		return temp;
        	} else if (raiz->hijo_der == NULL) {
            		NODO *temp = raiz->hijo_izq;
            		free(raiz);
            		return temp;
        	}

        	// Nodo con dos hijos
        	NODO *temp = raiz->hijo_der;
        		while (temp->hijo_izq != NULL) {
            		temp = temp->hijo_izq; // Buscar el sucesor en inorden
        	}

        	// Copiar los datos del sucesor al nodo actual
        	raiz->id = temp->id;
        	strcpy(raiz->libro.titulo, temp->libro.titulo);
        	strcpy(raiz->libro.autor, temp->libro.autor);
        	raiz->libro.numPag = temp->libro.numPag;

        	// Eliminar el sucesor
        	raiz->hijo_der = eliminarNodo(raiz->hijo_der, temp->id);
    	}
    	return raiz;
}*/
// ---------------------------- RECORRER ARBOL ----------------------------------------------------
void recorrerEnOrden(NODO *nodo) {
    if (nodo != NULL) {
        recorrerEnOrden(nodo->hijo_izq);
        printf("ID: %d | Título: %s | Autor: %s | Páginas: %d\n",
               nodo->id, nodo->libro.titulo, nodo->libro.autor, nodo->libro.numPag);
        recorrerEnOrden(nodo->hijo_der);
    }
}

void recorrerEnPreorden(NODO *nodo) {
    if (nodo != NULL) {
    	printf("ID: %d | Título: %s | Autor: %s | Páginas: %d\n",
        	nodo->id, nodo->libro.titulo, nodo->libro.autor, nodo->libro.numPag);
        recorrerEnPreorden(nodo->hijo_izq);
        recorrerEnPreorden(nodo->hijo_der);
    }
}