#ifndef UTILIDADES_H
#define UTILIDADES_H

// Primero struct
struct NODO_ARBOL{
	// datos
   	char dato[650];
   	int esFinal;  // 1 si es fin de partida	
   	// puntero
	struct NODO_ARBOL *hijo_izq;
	struct NODO_ARBOL *hijo_der;
	struct NODO_ARBOL *padre;
};

typedef struct NODO_ARBOL NODO;


// Funciones

int arbolVacio(NODO *);
int comprobarInserccion(NODO *, NODO *, int);
int insertarNODO(NODO **, NODO *, char[], int, int);

void eliminarHoja(NODO *nodo);
void eliminarArbol(NODO *raiz);

void buscarEImprimirNodo(NODO *raiz, char dato[]);
NODO* buscarNodo(NODO *raiz, char dato[]);
void buscarEImprimirNodoConPadres(NODO *raiz, char dato[]);
NODO* buscarNodoYPadres(NODO *raiz, char dato[], NODO **padres, int *numPadres);

void recorrerEnOrden(NODO *);
void recorrerEnPreorden(NODO *nodo);
void recorrerEnPostorden(NODO *nodo);

void cargarJuego(NODO **raiz);
void jugar(NODO *actual);
#endif
