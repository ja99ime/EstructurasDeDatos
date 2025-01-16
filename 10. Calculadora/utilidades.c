#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"

#define TRUE 1
#define FALSE 0
#define ERROR -1
#define MAX 20  

//------------------------ Verificar si el árbol está vacío -----------------------------------------
int arbolVacio(NODO *raiz) {
    return (raiz == NULL) ? TRUE : FALSE;  // Si la raíz es NULL, el árbol está vacío
}

//------------------------ Función para ingresar un dígito -----------------------------------------
void ingresarValor(NODO **raiz) {
    	NODO *nuevo = leerNodo();  		// Llamamos a leerNodo()
    	if (nuevo != NULL) {

       	 	insercion(raiz, *raiz, nuevo);  // Insertamos el nodo en el árbol
        	if (nuevo->esDigito) {
            		printf("Dígito ingresado: %d\n", nuevo->digito);  	// Si es un dígito
        	} else {
            		printf("Operando ingresado: %s\n", nuevo->operando);  	// Si es un operando
        	}
    	}
}

//------------------------ Leer un nodo desde la entrada del usuario ----------------------------
NODO *leerNodo() {
    	NODO *nuevo = (NODO *)malloc(sizeof(NODO));  				// se reserva memoria para el nodo
    	if (nuevo == NULL) {
        	printf("[ERROR FATAL] No se pudo reservar memoria para el nodo.\n");
        	return NULL;  // Si falla la asignación de memoria, retornamos NULL
    	}

    	int tipo;
    	char entrada[30];  						// char para leer el operando si es necesario

    	do {
        	printf("¿Qué tipo de nodo quieres crear?: \n");
        	printf("1) Operando\n");
        	printf("2) Dígito\n");
        	scanf("%d", &tipo);

        	if (tipo == 1) {
            		nuevo->esDigito = 0; 
            		printf("Introduce el operando (ejemplo '+', '-', '*', '/'): ");
            		getchar();  							// se limpia el buffer
            
            		scanf("%29s", nuevo->operando);  				// se lee el operando
        	} else if (tipo == 2) {
            		nuevo->esDigito = 1; 
            		printf("Introduce el dígito: ");
            		scanf("%d", &nuevo->digito);  					// se lee el dígito
        	} else {
            		printf("[ERROR] Ingrese 1 para operando o 2 para dígito.\n");
        	}
    	} while (tipo != 1 && tipo != 2);  				// se repite hasta obtener un valor válido

    	nuevo->hijo_izq = NULL;						// se inicializan los hijos como NULL
    	nuevo->hijo_der = NULL;
    	nuevo->padre = NULL;  						// se inicializa el padre como NULL

    	return nuevo;  							// se retorna el nodo creado
}
//------------------------ Comprobar si hay espacio para la inserción --------------------------------
int comprobarInserccion(NODO *padre) {
    	if (padre->hijo_izq != NULL && padre->hijo_der != NULL) {  					// si ambos hijos están ocupados...
		printf("[Error] No hay espacio en la carpeta para crear nuevas subcarpetas.\n");
		return FALSE;  										// no hay espacio para insertar
    	}
    	return TRUE;  								// Si hay espacio en alguno de los hijos se devuelve true
}

//------------------------ Crear un nuevo nodo basado en otro -------------------------------------
NODO *crearNodo(NODO *elemento) {
    	NODO *nuevo = (NODO *)malloc(sizeof(NODO));  			// se reserva memoria para el nuevo nodo
    	if (nuevo == NULL) {
        	printf("[ERROR FATAL] No se pudo reservar memoria para el nodo.\n");
        	return NULL;  								// si falla la asignación de memoria, se retorna NULL
    	}

    	if (elemento->esDigito) {
        	nuevo->digito = elemento->digito;			// Si es un dígito, copiamos el numero
    	} else {
        	strcpy(nuevo->operando, elemento->operando);  		// Si es un operando, copiamos el operando
   	}

    	nuevo->esDigito = elemento->esDigito;  	// se copia el tipo

    	nuevo->hijo_izq = NULL;			// los punteros se inicializan como NULL
    	nuevo->hijo_der = NULL;
    	nuevo->padre = NULL;

    	return nuevo;  				// se devuelve el nuevo nodo
}

//------------------------ INSERTAR -------------------------------------------------------
int insercion(NODO **raiz, NODO *actual, NODO *elemento) {
	if (*raiz == NULL) {
        	*raiz = elemento;	// si el árbol esta vacio, el nuevo nodo se convierte en la raíz
        	return TRUE;
    	}

    	
    	if (actual->esDigito == 0) {		// si el nodo actual es un operando
        
        	if (actual->hijo_izq == NULL) {		// si tiene algún espacio disponible en los hijos
            		actual->hijo_izq = elemento;  	// se inserta como hijo izquierdo
            		elemento->padre = actual;      	// el padre del nuevo nodo es el actual operando
            		return TRUE;
        	} else if (actual->hijo_der == NULL) {
            		actual->hijo_der = elemento;  	// se inserta como hijo derecho
            		elemento->padre = actual;     	// el padre del nuevo nodo es el actual perando
            		return TRUE;
        	} else {
            
            		// Si ambos hijos están ocupados, la inserción recursiva debe continuar
            		if (actual->hijo_izq != NULL && actual->hijo_der != NULL) {
                		if (insercion(raiz, actual->hijo_izq, elemento)) { 	// primero se inserta en el subárbol izquierdo primero
                    			return TRUE;
                		}
                		
                		if (insercion(raiz, actual->hijo_der, elemento)) {	// si no, se intenta en el derecho
                    			return TRUE;
                		}
            		}
        	}
    	} else {
        	printf("[Error] No se puede insertar un hijo debajo de un nodo que es un dígito.\n");
        	return FALSE;	// si el nodo es un dígito, no se puede insertar debajo de él
    	}

    return FALSE; 		// Si no se pudo insertar, retornamos FALSE
}

//------------------------ Resolver operacion --------------------------------------------
int resolverOperacion(NODO *nodo) {
    	
    	if (nodo->esDigito == 1) {
        	return nodo->digito;	// si el nodo es un dígito, se devuelve su valor
    	}

    	// si el nodo es un operando, se resuelven recursivamente los hijos izquierdo y derecho
    	
    	int izquierdo = resolverOperacion(nodo->hijo_izq);
    	int derecho = resolverOperacion(nodo->hijo_der);

    	// tras esto, se aplica la operación del operando sobre los hijos
    	
    	if (nodo->operando[0] == '+') {
        	return izquierdo + derecho;
    	} else if (nodo->operando[0] == '-') {
        	return izquierdo - derecho;
    	} else if (nodo->operando[0] == '*') {
        	return izquierdo * derecho;
    	} else if (nodo->operando[0] == '/') {
        
        	
        	if (derecho == 0) {
            		printf("[ERROR] División por cero.\n");	// nos aseguramos de que no dividimos por cero
            		return 0;
        	}
       	 	return izquierdo / derecho;
    	
    	} else if (nodo->operando[0] == '%') {
        	return izquierdo % derecho;
    	} else {
        	printf("[ERROR] Operador no reconocido: %s\n", nodo->operando);
        	return 0;
    	}
}

//------------------------ELIMINAR ARBOL------------------------------------------------------------------
void eliminarArbol(NODO **raiz) {
    	if (*raiz == NULL)  return; 				// Si el árbol está vacío, no hacemos nada

    	eliminarArbol(&(*raiz)->hijo_izq);			// se eliminan los subárboles primero con recursividad
    	eliminarArbol(&(*raiz)->hijo_der);

    	free(*raiz);						// se libera memoria
	*raiz = NULL;
}

//------------------------ Recorrer el árbol en orden --------------------------------------------
void recorrerEnOrden(NODO *nodo) {
    	if (nodo != NULL) {
        	recorrerEnOrden(nodo->hijo_izq);	// primero se recorre el subárbol izquierdo

        	if (nodo->esDigito) {			// se muestra el contenido del nodo actual
        	    	printf("%d", nodo->digito);  	// Si es un dígito, mostrar el número
        	} else {
            		printf("%s", nodo->operando);  	// Si es un operando, mostrar el operando
        	}

        	recorrerEnOrden(nodo->hijo_der);	// al final, se recorre el subárbol derecho
    	}
}
