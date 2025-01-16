#ifndef UTILIDADES_H
#define UTILIDADES_H

// Primero struct
struct NODO_ARBOL{

	char nombreEscenario[100];  	// Nombre del escenario (e.g., "Entrada del bosque")
   	char descripcion[750];
   	int hayLlave;  			// 1 si hay llave	
   	int hayPuzzle;  		// 1 si  hay cofre
   	int llaveRequerida;         	// Indica si una llave específica es requerida para acceder (0 = no, otro número = ID de la llave)
   	int esFinal;  			// 1 si es fin de partida	
   	
	struct NODO_ARBOL *hijo_izq;
	struct NODO_ARBOL *hijo_der;
	struct NODO_ARBOL *padre;
};

typedef struct NODO_ARBOL NODO;


// Funciones

int arbolVacio(NODO *);
int comprobarInserccion(NODO *, NODO *, int);
int insertarNODO(NODO **, NODO *, char[], char[], int, int, int, int, int);

void eliminarHoja(NODO *nodo);
void eliminarArbol(NODO *raiz);

void cargarJuego(NODO **raiz);
NODO* mover(NODO *actual, int direccion);
void revisarEscenario(NODO *actual, int );
void recogerLlave(NODO *actual, int *llaves);
int puzzle(NODO *actual);
int abrirPuerta(NODO *actual, int *llaves);

#endif
