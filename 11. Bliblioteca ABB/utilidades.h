#ifndef UTILIDADES_H
#define UTILIDADES_H

struct LIBRO{
   	char titulo[30];
   	char autor[30];
	int numPag;
};

struct NODO_ABB{
   	int id;
   	struct LIBRO libro;
	struct NODO_ABB *hijo_izq;
	struct NODO_ABB *hijo_der;
};

typedef struct NODO_ABB NODO;


// Funciones
NODO *leerNodo(int);


int insercion(NODO **, NODO *);
int busqueda(NODO **, int);   			// devuelve un entero 0 o 1
void busqueda2(NODO **raiz, int id);		// devuelve los valores del libro buscado

NODO *busquedaLugar(NODO **raiz, int);		// devuelve directamente el nodo padre
NODO *crearNodo(NODO *);

void eliminarArbol(NODO *raiz);
NODO *eliminarNodo(NODO *raiz, int id);
void eliminarSubarbol(NODO **raiz, int id);

void recorrerEnOrden(NODO *nodo);
void recorrerEnPreorden(NODO *nodo);

#endif
