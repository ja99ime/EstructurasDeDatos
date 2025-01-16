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

//------------------------ARBOL VACIO--------------------------------------------------------------------
int arbolVacio(NODO *raiz){
	if (raiz == NULL)	return TRUE;
	return FALSE;
}

//------------------------MOVERSE A UNO DE LOS HIJOS -----------------------------------------------------------------
NODO * mover(NODO *actual) {
	
	if (actual == NULL) {
        	return NULL;  									// Si el nodo actual es NULL, no podemos movernos
    	}
    	
	char dato[30];
	printf("Introduce el nombre de la carpeta a la que quieres acceder: ");			// se intorcude el nombre de la carpeta a la que deseamos movernos
    	scanf("%29s", dato); 									
    	getchar(); 
	
    	if (actual->hijo_izq != NULL && strcmp(actual->hijo_izq->nombre, dato) == 0) {			// si el nombre de la carpeta es el hijo izquierdo
        	if (actual->hijo_izq->esArchivo == 1){							// y no es un archivo
        		printf("[ERROR] Esto no es una carpeta.\n");					
        	} else return actual->hijo_izq;  							// Retorna el hijo izquierdo para que sea el nodo actual
        	
    	} else if (actual->hijo_der != NULL && strcmp(actual->hijo_der->nombre, dato) == 0) {		// si el nombre de la carpeta es el hijo derecho
        	if (actual->hijo_der->esArchivo == 1){							// y no es un archivo
        		printf("[ERROR] Esto no es una carpeta.\n");
        	} else return actual->hijo_der;  							// Retorna el hijo derecho para que sea el nodo actual
    	}

        return NULL; 				
				
}

//------------------------VER HIJOS-----------------------------------------------------------------
void verHijos(NODO *nodo){
	if(nodo->hijo_izq != NULL){
		printf("%s", nodo->hijo_izq->nombre);
	}
	if(nodo->hijo_der != NULL){
		printf("\n%s", nodo->hijo_der->nombre);
	}
	printf("\n\n");
}

//------------------------BUSCAR RUTA NODO [1]-----------------------------------------------------------------
void buscarEImprimirNodoConPadres(NODO *raiz, char dato[]) {

    	NODO *padres[20];  	// array para almacenar los padres
    	int numPadres = 0;  	// numero de padres encontrados

    	NODO *encontrado = buscarNodoYPadres(raiz, dato, padres, &numPadres);
    	if (encontrado != NULL) {
        	
        	// se meustran los padres desde el nodo encontrado hasta la raíz
        	if (numPadres > 0) {
            		for (int i = numPadres - 1; i >= 0; i--) {
                		printf("%s\\", padres[i]->nombre);
            		}
            		 printf("%s\n", encontrado->nombre);  // se añade el nodo actual al final
        	} else {
            		printf("\n");
        	}
    	}
}
//------------------------BUSCAR RUTA NODO [2]-----------------------------------------------------------------
NODO* buscarNodoYPadres(NODO *raiz, char dato[], NODO **padres, int *numPadres) {
    	if (raiz == NULL) return NULL;  		// si el árbol está vacío o no se encuentra el nodo
    							
    	if (strcmp(raiz->nombre, dato) == 0) {		// Si el dato coincide con el del nodo actual, retornamos el nodo
        
        	NODO *padreActual = raiz->padre;	// Obtenemos los padres
        	int i = 0;
        
		while (padreActual != NULL) {			 // Recorremos hacia arriba, recopilando los padres hasta la raíz
		    	padres[i++] = padreActual;
		    	padreActual = padreActual->padre;
        	}
        
		*numPadres = i;  				// Actualizamos el número de padres encontrados
		return raiz;  					// se devuelve el nodo encontrado
	}

    	NODO *nodoIzq = buscarNodoYPadres(raiz->hijo_izq, dato, padres, numPadres); 	// se busca en el hijo izq
    	if (nodoIzq != NULL) {
        	return nodoIzq;  			// Si se encuentra en el subárbol izquierdo, se retorna dicho nodo
    	}

    	return buscarNodoYPadres(raiz->hijo_der, dato, padres, numPadres);		// se busca en el hijo der
}
//------------------------LEER NODO--------------------------------------------------------------------
NODO *leerNodo() {
    	NODO *nuevo = (NODO *)malloc(sizeof(NODO)); 						// se reserva memoria para el nodo
    	if (nuevo == NULL) {
        	printf("[ERROR FATAL] No se pudo reservar memoria para el nodo.\n");		// si no se puede, se informa al usuario
        	return NULL;									// se devuelve NUlo
    	}
	int tipo;

	do{
		printf("¿Que quieres crear?: \n");			
		printf("1) Archivo de texto (txt)\n");			// si el archivo es de texto, no se podrá acceder a el
		printf("2) Nueva Carpeta.\n");				// si el archivo es una carpeta, si se podrá acceder a el
		scanf("%d", &tipo);
		
		if (tipo == 1){
			nuevo->esArchivo = 1;
		
		} else if (tipo == 2){
			nuevo->esArchivo = 0;
		} else {
			printf("[ERROR] Ingrese uno o dos.\n");
		}
		
	}while(tipo != 1 && tipo !=2);					// se imprime hasta obtener el valor correcto
	
	
    	printf("Introduce el nombre (máx 30 caracteres): ");		// Leemos el nombre de la carpeta 
    	scanf("%29s", nuevo->nombre); 	
    	getchar(); 						// se consume el salto de línea sobrante	
								
    	nuevo->hijo_izq = NULL;					// inicializamos los hijos a NULL
    	nuevo->hijo_der = NULL;

    	return nuevo; // Retornar el nodo creado
}

//------------------------COMPROBAR INSERCCION-----------------------------------------------------------
int comprobarInserccion(NODO *raiz, NODO *padre){
	if (padre->hijo_izq != NULL && padre->hijo_der != NULL) {	 // si nunguno de sus hijos esta vacio, no se puede crear una carpeta
		printf("[Error] No hay espacio en la carpeta para crear nuevas subcarpetas.\n");
		return FALSE;
	} 
	return TRUE; 

}

//------------------------ CREAR NODO --------------------------------------------------------------------
NODO *crearNodo(NODO *elemento) {			
    	NODO *nuevo = (NODO *)malloc(sizeof(NODO));		// se reserva espacio para el nodo nuevo
    	if (nuevo == NULL) {
		printf("[ERROR FATAL]\n");			// si no se hapodido reservar memoria, se informa al usuairo
		return NULL;					// se devuelve nulo
    	}
    	// Copiar los datos del elemento al nuevo nodo (uso strcpy para chars)
    	strcpy(nuevo->nombre, elemento->nombre);
    	nuevo->esArchivo = elemento->esArchivo;
    	nuevo->hijo_izq = NULL;				// los hijos se ponen a NULL
    	nuevo->hijo_der = NULL;
    	return nuevo;					// se devuelve el nodo nuevo
}

// ---------------------------- INSERCCION ----------------------------------------------------
int insercion(NODO **raiz, NODO *actual, NODO elemento) {
	
	if (comprobarInserccion(*raiz, actual) == TRUE){ 	// se comprueba si hay espacio en la carpeta
		NODO *nuevo = crearNodo(&elemento);		// si es el caso, se crea el nodo con el elemento pasado por parametro
		if (nuevo == NULL)	return FALSE;		// si hay fallo, se devuelve falso

	    	if (actual->hijo_izq == NULL){			// si hay hueco en el hijo izquierdo se inserta ahí
	    		actual->hijo_izq = nuevo;
	    	} else {					// si no, se intenta insertar en el derecho
	    		actual->hijo_der = nuevo;
	    	}
	    	nuevo->padre = actual;				// se pone el padre al nodo nuevo
	} else{
		return FALSE;					// Ya está ocupado
	}
	return TRUE;
}

//------------------------BUSCAR NODO [2] -----------------------------------------------------------------
NODO* buscarNodo(NODO *raiz, char dato[]) {
    	if (raiz == NULL)  return NULL; 		// Si el árbol está vacío o no se encuentra el nodo, se devuelve nulo

    	if (strcmp(raiz->nombre, dato) == 0) {		// Si el dato coincide con el del nodo raiz, se devuelve el mismo nodo
        	return raiz;
    	}

    	NODO *nodoIzq = buscarNodo(raiz->hijo_izq, dato);	// se busca recursivamente en el hijo izquierdo
    	if (nodoIzq != NULL) {
        	return nodoIzq; 				// Si se encuentra en el subárbol izquierdo, retornar
    	}
				
    	return buscarNodo(raiz->hijo_der, dato);		// se busca recursivamente en el hijo derecho
}

//------------------------ELIMINAR NODO--------------------------------------------------------------------
void eliminarHoja(NODO **nodo) {
	if (*nodo == NULL) return;

    	if ((*nodo)->hijo_izq == NULL && (*nodo)->hijo_der == NULL) {		// Verificamos si el nodo no tiene hijos
        	NODO *padre = (*nodo)->padre;				// en dicho caso, localizamos a su nodo padre

        	if (padre != NULL) {					// Si existe un padre, desconectamos el nodo del árbol
            		if (padre->hijo_izq == (*nodo)) {			// en caso de ser hijo izquierdo
                		padre->hijo_izq = NULL;			// se elimina su conexion con el padre
           		} else if (padre->hijo_der == (*nodo)) {		// en caso de ser hijo derecho
           			padre->hijo_der = NULL;			// se elimina su conexion con el padre
            		}
        	}
        	
        	printf("\nEliminando carpeta: %s\n", (*nodo)->nombre);	
        	free(*nodo);						// se libera la memoria del nodo
    		*nodo = NULL;
    	} else {
        	printf("[Error] El nodo no es una hoja.\n");
    	}
}
//------------------------ELIMINAR ARBOL------------------------------------------------------------------
void eliminarArbol(NODO **raiz) {
    	if (*raiz == NULL)  return; 					// Si el árbol está vacío, no hacemos nada

    	eliminarArbol(&(*raiz)->hijo_izq);						// se eliminan los subárboles primero con recursividad
    	eliminarArbol(&(*raiz)->hijo_der);

    	printf("\nEliminando carpeta: %s\n", (*raiz)->nombre);		// se imprime la eliminacion del nodo
    	free(*raiz);						// se libera memoria
	*raiz = NULL;
}


//------------------------RECORRER EN ORDEN-----------------------------------------------------------------
void recorrerEnOrden(NODO *nodo){
	if(nodo != NULL){
		recorrerEnOrden(nodo->hijo_izq);
		printf("\n%s", nodo->nombre);
		recorrerEnOrden(nodo->hijo_der);
	}
}

//------------------------RECORRER EN PREORDEN (con tabs por nivel)-----------------------------------------------------------------
void recorrerEnPreorden(NODO *nodo, int nivel) {
    if (nodo != NULL) {
        for (int i = 0; i < nivel; i++) {		
            printf("  ");  				// se imprime una tabulación por cada nivel
        }

        printf("%s\n", nodo->nombre);			// se imprime el nombre del nodo
        
        // se recorren los hijos  con recursividad (izquierda y derecha)
        recorrerEnPreorden(nodo->hijo_izq, nivel + 1);  // Aumentamos el nivel para los hijos
        recorrerEnPreorden(nodo->hijo_der, nivel + 1);  // Aumentamos el nivel para los hijos
    }
}
//------------------------RECORRER EN POSTORDEN---------------------------------------------------------------------
void recorrerEnPostorden(NODO *nodo){
	if(nodo != NULL){
		recorrerEnPostorden(nodo->hijo_izq);
		recorrerEnPostorden(nodo->hijo_der);
		printf("\n%s", nodo->nombre);
	}
}

