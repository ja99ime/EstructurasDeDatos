#ifndef UTILIDADES_H
#define UTILIDADES_H

// Structs

struct BEBIDAS{
	int codigo;
	char nombre[30];
	char estado[10];
	float precio;
};
	
struct BEBIDAS_FRIAS{
   	struct BEBIDAS *bebidas;
	struct BEBIDAS_FRIAS *siguiente;
};

struct BEBIDAS_CALIENTES{
   	struct BEBIDAS *bebidas;
	struct BEBIDAS_CALIENTES *siguiente;
};

typedef struct BEBIDAS_FRIAS frias;
typedef struct BEBIDAS_CALIENTES calientes;


// Funciones
int cargarProductos(struct BEBIDAS carta[]);


int pilaVacia(calientes * ); //Se pasa el puntero de inicio para ver si esta vacia
char * leerTope(calientes *tope );
int apilar(calientes **, struct BEBIDAS *bebida);
int desapilar(calientes **);

void barraCafetería(calientes *, frias *);
void verMenú(struct BEBIDAS carta[], int numProductos);
void hacerPedido(struct BEBIDAS carta[], int numProductos, frias **entrada, frias **salida, calientes **tope);

int colaVacia(frias * ); 
void leerColaSalida(frias * );
void leerColaEntrada(frias * );
int encolar(frias **, frias **, struct BEBIDAS *bebida);
int desencolar(frias **entrada, frias **salida, char *);
#endif
