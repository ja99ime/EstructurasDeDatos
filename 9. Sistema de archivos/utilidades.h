#ifndef UTILIDADES_H
#define UTILIDADES_H

// Primero struct
struct NODO_ARBOL{
	// datos
   	char nombre[30];
   	int esArchivo;
   	// puntero
	struct NODO_ARBOL *hijo_izq;
	struct NODO_ARBOL *hijo_der;
	struct NODO_ARBOL *padre;
};

typedef struct NODO_ARBOL NODO;


// Funciones

int arbolVacio(NODO *);
int comprobarInserccion(NODO *, NODO *);

NODO *leerNodo();
NODO *crearNodo(NODO *elemento);
int insercion(NODO **, NODO *, NODO );

NODO* buscarNodo(NODO *raiz, char dato[]);
NODO * mover(NODO *actual);


void eliminarHoja(NODO *nodo);
void eliminarArbol(NODO **raiz);

void verHijos(NODO *);
void buscarEImprimirNodoConPadres(NODO *raiz, char dato[]);
NODO* buscarNodoYPadres(NODO *raiz, char dato[], NODO **padres, int *numPadres);

void recorrerEnOrden(NODO *);
void recorrerEnPreorden(NODO *, int);

#endif
