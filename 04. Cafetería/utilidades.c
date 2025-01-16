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
#define FILE_NAME "bebidas.dat"


// ---------------------------- CARGAR PRODUCTOS DESDE binario  --------------------------------------------------------------------------------------
/*Esta función servirá para cargar los archivos que se hallen en productos.dat en el array de productos. Gracias a esto podremos
trabajar tener un menu de bebida ya creado en cada carga del codigo. */

int cargarProductos(struct BEBIDAS carta[]) {
    	FILE *archivo = fopen(FILE_NAME, "rb"); // Abrimos el archivo en modo binario
    	if (archivo == NULL) {
        	perror("[ERROR]No se pudo abrir el archivo para lectura");
        	return 0; 
    	}
    
    	// Se leen los productos en el struct
    	int numProductos = 0;
    	while (fread(&carta[numProductos], sizeof(struct BEBIDAS), 1, archivo) == 1) {
        	numProductos++;
    	}
    
    	fclose(archivo);
    	return numProductos;
}


// ----------------------------- TAREAS CAFETERIA ----------------------------------------------------------------------------------------------------
void barraCafetería(calientes *tope, frias *salida){
	printf("-------------------------------\n");
	printf("Proximas comandas\n");
	printf("-------------------------------\n");
	
	printf("Próximo plato caliente: ");
 	if (pilaVacia(tope)) {
        	printf("Libre\n");
    	} else {
		printf("%s\n", leerTope(tope)); 
    	}
	
   	printf("Próximo plato frío: ");
    	if (colaVacia(salida)) {
        	printf("Libre\n");
    	} else {
        	leerColaSalida(salida);
    	}
}

// ----------------------------- VER MENú ----------------------------------------------------------------------------------------------------
void verMenú(struct BEBIDAS carta[], int numProductos){
	
	printf("\nProducto Fríos\n");
	printf("-------------------------------\n");
	for (int i = 0; i < numProductos; i++) {  // Se recorre el array de prodcutos, mostrando todos los valores de cada uno
		if (strcmp(carta[i].estado, "Caliente") == 0) {
			printf("%-2d %-7s		%.2f€  |\n", carta[i].codigo, carta[i].nombre, carta[i].precio);
		}
	}
	printf("\nProducto Calientes	       |\n");
	printf("-------------------------------\n");
	for (int i = 0; i < numProductos; i++) {  // Se recorre el array de prodcutos, mostrando todos los valores de cada uno
		if (strcmp(carta[i].estado, "Frio") == 0) {
			printf("%-2d %-7s		%.2f€  |\n", carta[i].codigo, carta[i].nombre, carta[i].precio);
		}
	}
	printf("-------------------------------\n");

}

// ----------------------------- PEDIDOS CAFETERIA ----------------------------------------------------------------------------------------------------
void hacerPedido(struct BEBIDAS carta[], int numProductos, frias **entrada, frias **salida, calientes **tope){
	
	int campo, valida;
	
	verMenú(carta, numProductos);
	do{
		printf("\n¿Que deseas pedir?:\n"); 													// Se preguntará al usuario que desea pedir			    	
		if(scanf("%d", &campo) == 1){
			for (int i = 0; i < numProductos; i++) {
                		if (carta[i].codigo == campo) {
                    		valida = TRUE; 												// La seleccion es válida
                    			if (strcmp(carta[i].estado, "Frio") == 0) {
						if (encolar(entrada, salida, &carta[i])) {								// Encolar bebida fría
                            				printf("La bebida '%s' ha sido añadida a la cola de bebidas frías.\n", carta[i].nombre);
                        			} else {
                            				printf("[ERROR] No se pudo añadir la bebida a la cola.\n");
                        			}
                    			} else if (strcmp(carta[i].estado, "Caliente") == 0) {
						if (apilar(tope, &carta[i])) {										// Apilar bebida caliente					
                            				printf("La bebida '%s' ha sido añadida a la pila de bebidas calientes.\n", carta[i].nombre);
                        			} else {
                            				printf("[ERROR] No se pudo añadir la bebida a la pila.\n");
                        			}
                    			}
                    			break;
                		}
            		}
            		if (!valida) {
                		printf("[ERROR] Código no válido. Por favor, intenta de nuevo.\n");
            		}
        	} else {
            		while (getchar() != '\n'); // Limpia el buffer de entrada
            		printf("[ERROR] Entrada no válida. Por favor, ingresa un número.\n");
        	}
    	} while (!valida); // Repite hasta que el usuario haga una selección válida
}
// ----------------------------- PILA VACIA --------------------------------------------------------
int pilaVacia(calientes *tope ){
	if(tope == NULL){
	//	printf("Lista Vacia");
		return TRUE;
	} else{
	//	printf("Lista No Vacia");
		return FALSE;
	}
}

// ----------------------------- LEER PILA  --------------------------------------------------------
char* leerTope(calientes *tope ){
	
	if (pilaVacia(tope)){
		return "Libre";
	} else{
		return tope->bebidas->nombre;
	}
}
// ----------------------------- APILAR  --------------------------------------------------------
int apilar(calientes **tope, struct BEBIDAS *bebida){
	calientes *nuevo;
	
	nuevo = (calientes *) malloc(sizeof(calientes));
	// NO ahce falta comproar pila vacia, pues no afecta al apilado.
	
	if (nuevo == NULL){
		return FALSE;
	}

	nuevo->bebidas = bebida;
	nuevo->siguiente = *tope;
	
	*tope = nuevo;
	
	return TRUE;
}
// ----------------------------- DESAPILAR --------------------------------------------------------
int desapilar(calientes **tope){
	calientes *aux;
	
	if (pilaVacia(*tope)){
		return FALSE;
	}
	printf("\n%s entregado al cliente.", (*tope)->bebidas->nombre);
	aux = *tope;
	*tope = (*tope)->siguiente;

	free(aux);
	
	return TRUE;
}

// ----------------------------- COLA VACIA --------------------------------------------------------
int colaVacia(frias *salida ){
	if(salida == NULL){
	//	printf("Lista Vacia");
		return TRUE;
	} else{
	//	printf("Lista No Vacia");
		return FALSE;
	}
}

// ----------------------------- LEER ELEMENTO QUE SALE COLA ----------------------------------------
void leerColaSalida(frias *salida ){
	if (colaVacia(salida)){
		printf("\n");
	} else{
		printf("%s\n", salida->bebidas->nombre);
	}	
}


// ----------------------------- ENCOLAR --------------------------------------------------------
int encolar(frias **entrada, frias **salida, struct BEBIDAS *bebida){
	frias *nuevo;
	nuevo = (frias *) malloc(sizeof(frias));
	if (nuevo == NULL){
		return FALSE;
	}
	nuevo->bebidas = bebida;
	nuevo->siguiente = NULL;
	
	if (colaVacia(*entrada)){
		*salida = nuevo;
	} else{
		(*entrada)->siguiente = nuevo;
	}	
	
	(*entrada) = nuevo;
	return TRUE;
}

// ----------------------------- DESENCOLAR --------------------------------------------------------
int desencolar(frias **entrada, frias **salida, char *valor){
	if (colaVacia(*salida)){
        	return FALSE; 				// Cola vacía, no se puede desencolar
    	}
	
	frias *aux = *salida;
    	strcpy(valor, aux->bebidas->nombre);				// El valor que estamos desencolando

    	*salida = (*salida)->siguiente; 		// El primer elemento ahora apunta al siguiente
    	if (*salida == NULL){
       		*entrada = NULL; 			// Si la cola se vacía, ponemos entrada a NULL
    	}
    	free(aux); 					// Liberamos la memoria del nodo desencolado
    	return TRUE;
}
