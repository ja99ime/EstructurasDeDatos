#ifndef UTILIDADES_H
#define UTILIDADES_H

// Structs
struct LETRAS{
   	char letra;
	struct LETRAS *siguiente;
};

struct PALABRAS{
   	char letra_palabra;
	struct PALABRAS *siguiente;
};

typedef struct LETRAS letras;
typedef struct PALABRAS palabras;


// Funciones

int pilaVacia(letras * ); //Se pasa el puntero de inicio para ver si esta vacia
char leerTope(letras *tope );
int apilar(letras **, char);
int desapilar(letras **);

void leerCincoTopes(letras *tope1, letras *tope2, letras *tope3, letras *tope4, letras *tope5, int *fin, int puntos);

int colaVacia(palabras * ); 
void leerCola(palabras * );
void leerCola2(palabras * );
int encolar(palabras **, palabras **, char);
void recorrerCola(palabras *inicio);

#endif
