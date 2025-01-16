#ifndef UTILIDADES_H
#define UTILIDADES_H

// Primero struct
struct NODO_ARBOL{
   	char operando[30];
   	int digito;
   	int esDigito;
	struct NODO_ARBOL *hijo_izq;
	struct NODO_ARBOL *hijo_der;
	struct NODO_ARBOL *padre;
};

typedef struct NODO_ARBOL NODO;


// Funciones

int arbolVacio(NODO *);
int comprobarInserccion(NODO *);

NODO *leerNodo();
NODO *crearNodo(NODO *elemento);
int insercion(NODO **, NODO *, NODO *);

void eliminarArbol(NODO **raiz);

void recorrerEnOrden(NODO *);

void ingresarValor(NODO **raiz);
int resolverOperacion(NODO *nodo);
#endif
