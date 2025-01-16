#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#define TRUE 1
#define FALSE 0
#define MAX 20  
#define FILE_NAME "productos.txt"


int main(){

	char caracter = '\0', palabra = '\0';		// Variables para almacenar caracteres y trabajar con ellos.
	int sel, salir, eliminar, guardar;		// Variables para almacenar enteros y trabajar con ellos.
	int cont = 0;					// Esta variable servirá para delimitar el tamaño de palabra a cinco.
	int fin = 0;					// Esta variable servirá para finalizar la partida.
	int puntos = 0;					// Esta variable contará los puntos del usuario.

	// Se definen las pilas
	letras *consonante1 = NULL;
	letras *consonante2 = NULL;
	letras *consonante3 = NULL;
	letras *vocal1 = NULL;
	letras *vocal2 = NULL;
	
	// Se define la cola, con dos punteros: entrada y salida
	palabras *salida = NULL;
	palabras *entrada = NULL;
	
	// Se llenan las pilas
	apilar(&consonante1,'C');
	apilar(&consonante1,'F');
	apilar(&consonante1,'B');
	apilar(&consonante1,'R');
	apilar(&consonante1,'D');
	
	apilar(&vocal1,'U');
	apilar(&vocal1,'O');
	apilar(&vocal1,'I');
	apilar(&vocal1,'E');
	apilar(&vocal1,'A');
	
	apilar(&consonante2,'S');
	apilar(&consonante2,'D');
	apilar(&consonante2,'T');
	apilar(&consonante2,'P');
	apilar(&consonante2,'M');
	
	apilar(&vocal2,'A');
	apilar(&vocal2,'E');
	apilar(&vocal2,'I');
	apilar(&vocal2,'O');
	apilar(&vocal2,'U');

	apilar(&consonante3,'D');
	apilar(&consonante3,'R');
	apilar(&consonante3,'L');
	apilar(&consonante3,'S');
	apilar(&consonante3,'N');

	
	do {
		if(cont == 5){									// Si el valor de cont es 5. se ha formado una palabra.
			encolar(&entrada, &salida, ' ');					// Se añade un espacio para separar la palabra
			puntos++;								// Se suma un punto al usuario
			cont = 0;								// Se resetea la variable de cont a 0.
			printf("\n-------------------------------------------------\n");	// Mensaje para el usuario
			printf(" 	      Enhorabuena!  +1 punto");
			printf("\n-------------------------------------------------\n");
		}
		
		printf("\n-------------------------------------------------\n");		// Mensaje de inicio para el usuario
		printf("	JUEGO BUSCADOR DE PALABRUSCAS   ");
		printf("\n-------------------------------------------------\n");
		
		leerCincoTopes(consonante1, vocal1, consonante2, vocal2, consonante3, &fin, puntos);	// Esta función mostrará la "interfaz" del juego.
		
		if(fin == 1){									// Si fin es igual a 1, se acaba la partida y se 
			printf("\n-------------------------------------------------\n");	// muestran la palabras obtenidas
			printf("  PALABRA OBTENIDAS: ");
			recorrerCola(salida);							// Se recorre la cola.
			printf("\n-------------------------------------------------\n");
			break;									// Se sale del bucle y termina el programa
		}
		
		printf("\nUltima letra: "); leerCola2(entrada);  				// El usuario verá la ultima letra que escogio.
		
		printf("\n1) Obtener Letra.\n");  						// El usuario guardará una letra.
		printf("2) Eliminar Letra.\n\n");  						// El usuario podrá eliminar una letra.
		printf("3) SALIR\n");  								// Se cerrará el programa.

		if(scanf("%d", &sel) == 1) {  							// SE LEE UN VALOR POR TECLADO
		    	if(sel > 0 && sel < 4) {  						// SI LA OPCION ES VALIDA
		        
		        	// ---------------------------- OBTENER LETRA --------------------------------------------------
		        	if (sel == 1) {
		            		do {
						printf("¿Qué letra deseas guardar? [1 - 2 - 3 - 4 - 5]\n");
						if(scanf("%d", &guardar) == 1) {
		                    			if(guardar > 0 || guardar < 6) {
								if (guardar == 1){					// El usuario a obtenido la letra 1
									palabra = leerTope(consonante1);
									printf("LETRA %c OBTENIDA\n", palabra);
									desapilar(&consonante1);			// Se quita la letra de la pila
									encolar(&entrada, &salida, palabra);		// Se encola en el resultado
								}
								if (guardar == 2){
									palabra = leerTope(vocal1);			// El usuario a obtenido la letra 2
									printf("LETRA %c OBTENIDA\n", palabra);
									desapilar(&vocal1);				// Se quita la letra de la pila
									encolar(&entrada, &salida, palabra);		// Se encola en el resultado
								}
								if (guardar == 3){
									palabra = leerTope(consonante2);		// El usuario a obtenido la letra 3
									printf("LETRA %c OBTENIDA\n", palabra);
									desapilar(&consonante2);			// Se quita la letra de la pila
									encolar(&entrada, &salida, palabra);		// Se encola en el resultado
								}
								if (guardar == 4){
									palabra = leerTope(vocal2);			// El usuario a obtenido la letra 4
									printf("LETRA %c OBTENIDA\n", palabra);
									desapilar(&vocal2);				// Se quita la letra de la pila
									encolar(&entrada, &salida, palabra);		// Se encola en el resultado
								}
								if (guardar == 5){
									palabra = leerTope(consonante3);		// El usuario a obtenido la letra 5
									printf("LETRA %c OBTENIDA\n", palabra);
									desapilar(&consonante3);			// Se quita la letra de la pila
									encolar(&entrada, &salida, palabra);		// Se encola en el resultado
								}
								cont++;
		                    			} else {
		                        			printf("ERROR. OPCION NO VALIDA\n");  // SI LA OPCION NO ES VALIDA
		                    			}
		                		} else {
		                    			while(getchar() != '\n');
		                    			printf("ERROR. OPCION NO VALIDA\n");
		                		}
		            		} while (guardar<= 0 || guardar >= 6);  // El bucle se repite mientras la opción no sea válida
		        	}
		        	// ---------------------------- QUITAR LETRA ---------------------------------------------------
		        	/* Esta funcion ha sido creada para darle la posibilidad al usuario de avanzar una pila, pero sacrificar una letra
		        	 en el proceso. Creo que esto podría acelerar las partidas y a la vez, obtener mayor variedad de palabras. */
		        	if (sel == 2) {
		            		do {
						printf("¿Qué letra deseas eliminar? [1 - 2 - 3 - 4 - 5]\n");
						if(scanf("%d", &eliminar) == 1) {
		                    			if(eliminar > 0 && eliminar < 6) {
								printf("Se eliminará la letra en la posición %d\n", eliminar);
								if (eliminar == 1) desapilar(&consonante1);
								if (eliminar == 2) desapilar(&vocal1);
								if (eliminar == 3) desapilar(&consonante2);
								if (eliminar == 4) desapilar(&vocal2);
								if (eliminar == 5) desapilar(&consonante3);
		                    			} else {
		                        			printf("ERROR. OPCION NO VALIDA\n");  // SI LA OPCION NO ES VALIDA
		                    			}
		                		} else {
		                    			while(getchar() != '\n');
		                    			printf("ERROR. OPCION NO VALIDA\n");
		                		}
		            		} while (eliminar <= 0 || eliminar >= 6);  // El bucle se repite mientras la opción no sea válida
		        	}
		        	// ---------------------------- SALIR DEL PROGRAMA ---------------------------------------------
		        	if (sel == 3) {
		            		salir = TRUE;  // Cambiar salir a TRUE para terminar el bucle
		        	}
		    	} else {
		        	printf("ERROR. OPCION NO VALIDA\n");  // SI LA OPCION NO ES VALIDA
		    	}
        	} else {
		    	while(getchar() != '\n');
		    	printf("ERROR. OPCION NO VALIDA\n");
        	}
    	} while (salir == FALSE);  // El bucle se repite mientras salir no sea verdadero

    	return 0;
}