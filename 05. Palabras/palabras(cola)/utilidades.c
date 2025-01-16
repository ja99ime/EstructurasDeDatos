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
#define FILE_NAME "productos.txt"


// ----------------------------- INTERFAZ DEL JUEGO ----------------------------------------------------------------------------------------------------
void leerCincoTopes(letras *tope1, letras *tope2, letras *tope3, letras *tope4, letras *tope5, int *fin, int puntos){
	
	char valorTope1 = '\0';			// Se inicializa el primer tope
	char valorTope2 = '\0';			// Se inicializa el segundo tope
	char valorTope3 = '\0';			// Se inicializa el tercer tope
	char valorTope4 = '\0';			// Se inicializa el cuarto tope
	char valorTope5 = '\0';			// Se inicializa el quinto tope
	
	// Mientras todas las pilas tengan al menos un valor, el juego continuará
	if (pilaVacia(tope1) == FALSE && pilaVacia(tope2) == FALSE && pilaVacia(tope3) == FALSE && pilaVacia(tope4) == FALSE && pilaVacia(tope5) ==FALSE){
		
		valorTope1 = tope1->letra;	// Se le da el valor de la primera pila a tope1

		valorTope2 = tope2->letra;	// Se le da el valor de la segunda pila a tope2

		valorTope3 = tope3->letra;	// Se le da el valor de la tercera pila a tope3

		valorTope4 = tope4->letra;	// Se le da el valor de la cuarta pila a tope4

		valorTope5 = tope5->letra;	// Se le da el valor de la quinta pila a tope5
		
		// Se muestran los topes de la pila
		printf("	|  %c  |  %c  |  %c  |  %c  |  %c  |\n", valorTope1, valorTope2, valorTope3, valorTope4, valorTope5 );
	
	// Si una de las pilas se vacia, acaba la partida
	} else{
		printf("	|  -  |  F  |  I  |  N  |  -  |\n", valorTope1, valorTope2, valorTope3, valorTope4, valorTope5 );
		
		printf("\n\nPuntos Ganados: %d", puntos);	// Se indican los puntos del usuario
		*fin = 1;					// Se pone la variable fin a 1.
	}
}


// ----------------------------- PILA VACIA --------------------------------------------------------
int pilaVacia(letras *tope ){
	if(tope == NULL){
	//	printf("Lista Vacia");
		return TRUE;
	} else{
	//	printf("Lista No Vacia");
		return FALSE;
	}
}

// ----------------------------- LEER PILA  --------------------------------------------------------
char leerTope(letras *tope ){
	char valorTope = '\0';
	
	if (pilaVacia(tope) ==FALSE){
		valorTope= tope->letra;
	}
	return valorTope;
	
}

// ----------------------------- APILAR  --------------------------------------------------------
int apilar(letras **tope, char letraInsertada){
	letras *nuevo;
	
	nuevo = (letras *) malloc(sizeof(letras));
	// NO ahce falta comproar pila vacia, pues no afecta al apilado.
	
	if (nuevo == NULL){
		return FALSE;
	}

	nuevo->letra = letraInsertada;
	nuevo->siguiente = *tope;
	
	*tope = nuevo;
	
	return TRUE;
}
// ----------------------------- DESAPILAR --------------------------------------------------------
int desapilar(letras **tope){
	letras *aux;
	
	if (pilaVacia(*tope)){
		return FALSE;
	}
	
	//printf("\nEl dato que voy a sacar de la pila es %c", (*tope)->letra);	
	aux = *tope;
	*tope = (*tope)->siguiente;

	free(aux);
	
	return TRUE;
}

// ----------------------------- COLA VACIA --------------------------------------------------------
int colaVacia(palabras *salida ){
	if(salida == NULL){
	//	printf("Lista Vacia");
		return TRUE;
	} else{
	//	printf("Lista No Vacia");
		return FALSE;
	}
}

// ----------------------------- LEER ELEMENTO QUE SALE COLA ----------------------------------------
void leerCola(palabras *salida ){
	if (colaVacia(salida)){
		printf("\n");
	} else{
		printf("%c\n", salida->letra_palabra);
	}	
}

// ----------------------------- LEER ELEMENTO QUE ENTRA COLA ----------------------------------------
void leerCola2(palabras *entrada ){
	if (colaVacia(entrada)){
		printf("\n");
	} else{
		printf("%c\n", entrada->letra_palabra);
	}	
}

// ----------------------------- ENCOLAR --------------------------------------------------------
int encolar(palabras **entrada, palabras **salida, char caracter){
	palabras *nuevo;
	nuevo = (palabras *) malloc(sizeof(palabras));
	if (nuevo == NULL){
		return FALSE;
	}
	nuevo->letra_palabra = caracter;
	nuevo->siguiente = NULL;
	
	if (colaVacia(*entrada)){
		*salida = nuevo;
	} else{
		(*entrada)->siguiente = nuevo;
	}	
	
	(*entrada) = nuevo;
	return TRUE;
}

// ----------------------------- RECORRER COLA --------------------------------------------------------
void recorrerCola(palabras *inicio){
	palabras *aux;
	
	if (colaVacia(inicio) == TRUE){
		printf("\nNo hay nada en la COLA");
	} else{
		
		aux = inicio;
		while (aux != NULL){
			printf("%c", aux->letra_palabra);
			aux = aux->siguiente;
		}	
	}	
}
