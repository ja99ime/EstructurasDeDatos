#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#define TRUE 1
#define FALSE 0
#define MAX 20  
#define FILE_NAME "productos.txt"

/*Se partirá de una tienda de moviles donde el numero máximod e registros a la vez será de 20, determinado esto por la constante MAX.
Además, el fichero a utilizar será "productos.txt" definido también por otra constante, está, llamada FILE_NAME*/

int main(){

	int sel;
	int salir = FALSE;
	struct Movil productos[MAX];	// Los productos serán manejados con un array de tipo struct Movil, declarado en "utilidades.h".
	
	nodo *pedido = NULL; 				// Se crea la lista para almacenar lo que se desea comprar
	nodo *insertado;				// Se crea un nodo para insertar valores que no sean el primero
	
	
	int numProductos = cargarProductos(productos);	 // El numero de productos será igual a los registros que haya en el fichero
	printf("Productos registrados en el sistema: %d\n", numProductos); // Se informa al usuario del numero de elementos que hay
	
	//guardarProductosNuevos(productos, numProductos);
	
	// A continuación, se le mostrará el menú al usuario.
	do{
	
		printf("Productos registrados en la lista de deseos: \n");
		// mostrarLista(pedido);
		printf("\n\n------------");
		printf("\n    Menu    ");
		printf("\n------------\n");
		printf("1) Registrar Productos.\n"); 		// El usuario registrará sus productos y estos, se guardarán en el fichero.
		printf("2) Buscar Productos.\n");		// El usuario podrá buscar un producto por nombre.
		printf("3) Realizar pedido\n");		// El usuario podra comprar un producto, eliminandolo de la lista.
		printf("4) Mostrar Productos Ordenados.\n");	// El usuario podrá ordenar los productos de manera ordenada por alguno de sus campos
		printf("5) SALIR\n");				// Se cerrará el programa.

		// SE LEE UN VALOR POR TECLADO
		if(scanf("%d", &sel) == 1){
		
			// SI LA OPCION ES VALIDA
			if(sel > 0 && sel < 6){
				printf("HA SELECCIONADO LA OPCION %d\n", sel);	// Se informa al usuario de la opción seleccionada.
				
				// ---------------------------- REGISTRO DE PRODUCTOS --------------------------------------------------
				if (sel == 1){
					if (numProductos < MAX) {   // Se comprueba que el numero de productos no exceda el máximo
                        			leerProducto(&productos[numProductos]); // Se lee el producto
                        			numProductos++; // Se aumenta el número de productos
                        			guardarProductos(productos, numProductos); // Se guarda el producto
                        		} else {
                        			printf("\nNo se pueden registrar más productos.\n"); // Si no se pueden ingresar más productos, se avisa al usuario.
                    			}

				}
				// ---------------------------- BÚSQUEDA DE PRODUCTOS ---------------------------------------------------
				 if (sel == 2) {
				    	char nombreBusqueda[30]; // Se define una variable para almacenar el nombre de busqueda
				    	printf("\nIngrese el nombre del producto a buscar: ");
				    	scanf("%s", nombreBusqueda);
				    	buscarProducto(productos, numProductos, nombreBusqueda); // Se llama una función para que busque el valor en el array
				 }
				// ---------------------------- COMPRAR PRODUCTOS (ELIMINAR) --------------------------------------------
				 if (sel == 3) {

				    	
				    	comprarProductos(productos, numProductos, &pedido); 		// Se llama una función para que inicie la compra
				 }
				 
				// ---------------------------- ORDENACIÓN DE PRODUCTOS --------------------------------------------------
				 if (sel == 4) {
				    	int campo; // Se definen nuevos valores para un segundo menú
				    	int salir2 = FALSE;
				    	do{
					    	printf("\nESCOGE el campo para ordenar:\n"); // Se desplegará un nuevo menú
					    	printf("1) Precio\n");		// El usuario ordenará los productos por Precio
					    	printf("2) Pulgadas\n");	// El usuario ordenará los productos por Pulgadas
					    	printf("3) Capacidad\n");	// El usuario ordenará los productos por Capacidad
					    	printf("4) RAM\n");		// El usuario ordenará los productos por RAM
					    	printf("5) Marca\n");		// El usuario ordenará los productos por Marca
					    	printf("6) CANCELAR\n");	// Retornamos al primer menú
					    	
					    	if(scanf("%d", &campo) == 1){
					    		// SI LA OPCION ES VALIDA
					    		if(campo > 0 && campo <= 6){
								printf("HA SELECCIONADO LA ORDENACIÓN %d\n", campo); // Se informa al usuario de su eleccion
							   	ordenarProductos(productos, numProductos, campo);    // Se llama a la función de ordenar
							   	printf("\nProductos ordenados correctamente.\n");    
							   	mostrarProductos(productos, numProductos);	     // Se llama a la función de mostrar
							if (campo == 6){					     // Se sale del menu de ordenación 
								salir2 = TRUE;
							}
					   		// SI LA OPCION NO ES VALIDA
					   		}else{
								printf("ERROR. OPCION NO VALIDA\n");
							}
						}else{
							while(getchar() != '\n');
								printf("ERROR. OPCION NO VALIDA\n");
						}
					} while (salir2 == FALSE); // El bucle se repite mientras salir2 no sea verdadero
				}
				
				// ---------------------------- SALIR DEL PROGRAMA --------------------------
				if (sel == 5){
					salir = TRUE;
				}
			
			// SI LA OPCION NO ES VALIDA
			}else{
				printf("ERROR. OPCION NO VALIDA\n");
			}
		}else{
			while(getchar() != '\n');
			printf("ERROR. OPCION NO VALIDA\n");
		}
	} while (salir == FALSE);  // El bucle se repite mientras salir no sea verdadero
	
	return 0;

}