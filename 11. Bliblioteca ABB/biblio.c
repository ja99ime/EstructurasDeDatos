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



int main(){

	int sel, salir, cod; 	// variables para el menu
	NODO *raiz = NULL;	// inicializamos la raiz del arbol binario
	int id = 1;
	do {
		
		printf("\n-------------------------------------------------\n");		
		printf("		  BIBLIOTECA ");					// Mensaje de inicio para el usuario
		printf("\n-------------------------------------------------\n\n");

		printf("1) Mostrar Libros.\n");  						// se mostrará un recorrido en orden del arbol binario
		printf("2) Buscar Libros.\n");  						// se buscará la existencia de un determinado libro por id
		printf("3) Insertar Libros.\n");  						// se insertara un libro en el arbol
		printf("4) Eliminar Libros.\n\n");  						//  se elimina un libro
		printf("5) Salir.\n");  						// 

		if(scanf("%d", &sel) == 1) {  						// SE LEE UN VALOR POR TECLADO
		    	if(sel > 0 && sel < 6) {  						// SI LA OPCION ES VALIDA
		        
		        	// ---------------------------- MOSTRAR ----------------------------------------------------
		        	if (sel == 1) {
					recorrerEnOrden(raiz);
					recorrerEnPreorden(raiz);
		        	}
		        	// ---------------------------- BUSCAR ----------------------------------------------------
		        	if (sel == 2) {
					printf("Escribe el código: \n");
					scanf("%d", &cod);
					if (busqueda(&raiz, cod)){ 
						printf("Nodo con Libro %d encontrado.\n", cod);
						busqueda2(&raiz, cod);
    					}else printf("Nodo con Libro %d no encontrado.\n", cod);
					
					
		        	}
		        	// ---------------------------- INSERTAR ----------------------------------------------------
		        	if (sel == 3) {
		            		NODO *libro = leerNodo(id);
		            		if (insercion(&raiz, libro)) {
		            		 	id++;
                    				printf("Libro insertado correctamente.\n");
                			} else  printf("Error al insertar el libro.\n");	
		        	}
		        	// ---------------------------- ELIMINAR ----------------------------------------------------
		        	if (sel == 4) {
					printf("Escribe el código: \n");
					scanf("%d", &cod);
					if (busqueda(&raiz, cod)) {
					    	printf("Nodo con Libro %d encontrado.\n", cod);
					    	busqueda2(&raiz, cod);
					    	// Llamar a la función de eliminación del subárbol
					    	NODO **padre = &raiz;  // Puntero doble para manipular la raíz si el nodo es la raíz misma
					    	eliminarSubarbol(padre, cod);
					    	printf("Subarbol con raíz en Nodo %d eliminado.\n", cod);
					} else {
					    	printf("Nodo con Libro %d no encontrado.\n", cod);
					}
		        	}
		        	// ---------------------------- Salir -------------------------------------------------------
		        	if (sel == 5) {
		            		salir = TRUE;  			// Cambiar salir a TRUE para terminar el bucle
		        	}
		    	} else {
		        	printf("ERROR. OPCION NO VALIDA\n");  	// se imprime un mensaje si la opcion no es valida
		    	}
        	} else {
		    	while(getchar() != '\n');
		    	printf("ERROR. OPCION NO VALIDA\n");
        	}
    	} while (salir == FALSE);  					// El bucle se repite mientras salir no sea verdadero
    	return 0;
}

/*

    // Crear nodos para insertar
    NODO nodo1 = {"123456789", "Juan", "Perez", 8.5, NULL, NULL};
    NODO nodo2 = {"987654321", "Maria", "Lopez", 9.0, NULL, NULL};
    NODO nodo3 = {"456789123", "Carlos", "Gomez", 7.5, NULL, NULL};
    NODO nodo4 = {"654321987", "Ana", "Martinez", 9.5, NULL, NULL};

    // Insertar nodos en el árbol
    printf("\nInsertando nodos...\n");
    if (insercion(&raiz, &nodo1)) printf("Nodo con DNI %s insertado correctamente.\n", nodo1.dni);
    if (insercion(&raiz, &nodo2)) printf("Nodo con DNI %s insertado correctamente.\n", nodo2.dni);
    if (insercion(&raiz, &nodo3)) printf("Nodo con DNI %s insertado correctamente.\n", nodo3.dni);
    if (insercion(&raiz, &nodo4)) printf("Nodo con DNI %s insertado correctamente.\n", nodo4.dni);

    // Intentar insertar un nodo duplicado
    printf("\nIntentando insertar un nodo duplicado...\n");
    if (!insercion(&raiz, &nodo1)) printf("Nodo con DNI %s ya existe.\n", nodo1.dni);

    // Realizar búsquedas
    printf("\nRealizando búsquedas...\n");
    char dniBuscar1[10] = "123456789";
    char dniBuscar2[10] = "111111111";
    if (busqueda(&raiz, dniBuscar1)) printf("Nodo con DNI %s encontrado.\n", dniBuscar1);
    else printf("Nodo con DNI %s no encontrado.\n", dniBuscar1);

    if (busqueda(&raiz, dniBuscar2)) printf("Nodo con DNI %s encontrado.\n", dniBuscar2);
    else printf("Nodo con DNI %s no encontrado.\n", dniBuscar2);

    // Recorrer el árbol en diferentes órdenes
    printf("\nRecorrido en orden:\n");
    recorrerEnOrden(raiz);


    printf("\nPrograma finalizado.\n");
*/

