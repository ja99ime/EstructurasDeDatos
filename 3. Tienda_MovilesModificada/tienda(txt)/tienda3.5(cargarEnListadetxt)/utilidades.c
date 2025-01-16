#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "utilidades.h"

#define TRUE 1
#define FALSE 0
#define MAX 20  
#define FILE_NAME "productos.txt"
#define FILE_NAME2 "Nuevos.txt"

// ---------------------------- COMPROBAR LISTA VACIA  -------------------------------------------------------------------------------------------
int listaVacia(nodo *inicio){
	if(inicio == NULL){
//		printf("Lista Vacia");
		return TRUE;
	} else{
//		printf("Lista No Vacia");
		return FALSE;
	}
}


// ---------------------------- MOSTRAR LISTA   -------------------------------------------------------------------------------------------
void mostrarLista(nodo *inicio){
	nodo *aux;
	
	if (listaVacia(inicio) == TRUE){
		printf("\nNo hay nada en la lista");
	} else{
		
		aux = inicio;
		while (aux != NULL){
			printf("%s ", aux->productos.nombre);
			aux = aux->siguiente;
		}	
		printf("\n");
	}	
}


// ---------------------------- CARGAR PRODUCTOS DESDE TXT  -------------------------------------------------------------------------------------------
/*Esta función servirá para cargar los archivos que se hallen en productos.txt en el array de productos. Gracias a esto podremos
trabajar en todo momento con los productos de manera dinamica y podremos determinar el numero de elementos inciales al 
iniciar el programa en cada ejecución */

int cargarProductosArray(struct Movil productos[], nodo **inicio) {
	FILE *file = fopen(FILE_NAME, "r"); // Abrimos el archivo en modo lectura
	if (file == NULL) { // Nos aseguramos de que se abre. Si no, informamos al usuario
		printf("No se pudo abrir el archivo. Comenzando con un inventario vacío.\n");
		return 0;
	}

	int numProductos = 0; // El numero de productos se establece incialmente a 0 
	while (fscanf(file, "%s %s %s %f %s %s %s %f %d %d",
		productos[numProductos].nombre, productos[numProductos].descripcion, productos[numProductos].estado,
		&productos[numProductos].precio, productos[numProductos].marca, productos[numProductos].modelo, productos[numProductos].color,
		&productos[numProductos].pulgadas, &productos[numProductos].capacidad, &productos[numProductos].RAM) != EOF) { 
			// se lee cada valor uno por uno del fichero y se almacena en su lugar correspondiente dentro del array de struct producto
			// hasta llegar al final del fichero
			numProductos++; // Cada vez que se lee un prodcuto, se incrementa el numero de productos. 
			
			if (numProductos >= MAX) {
				printf("Alcanzado el límite de productos.\n"); // Si el numero de prodcutos ya está al máximo, se sale del bucle
			    	break;
			}
			
			// Para cada línea leída, insertamos el producto en la lista
        		nodo *nuevo = (nodo *)malloc(sizeof(nodo));
			if (nuevo == NULL) {
			    	printf("Error al reservar memoria para un nuevo nodo\n");
			    	fclose(file);
			    	return numProductos;  // Salimos de la función si hay un error
			}
			
			// Asignamos los datos leídos al nodo
			nuevo->codigo = numProductos;
			nuevo->productos = productos[numProductos -1];
			nuevo->siguiente = NULL;
			
			// Si la lista está vacía, el nuevo nodo será el primero
			if (*inicio == NULL) {
			    	*inicio = nuevo;
			} else {
			    	// Si la lista no está vacía, buscamos el final de la lista
			    	nodo *aux = *inicio;
			    	while (aux->siguiente != NULL) {
					aux = aux->siguiente;
			    	}
			    	// Insertamos el nuevo nodo al final de la lista
			    	aux->siguiente = nuevo;
			}	
		}

		fclose(file);	// Se cierra el fichero
		return numProductos; // Se devuelve el numero de productos.
}


// ------------------------------ GUARDAR NUEVOS PRODUCTOS EN TXT --------------------------------------------------------------------------------------
/*Esta función servirá para guardar los nuevos valores del array de prodcutos dentro de "productos.txt". Esta función nos permitirá tener actualizado 
en todo momento los valores del struct dentro del archivo, lo que nos permitirá trabajar de manera dinamica con el.*/

void guardarProductos(struct Movil productos[], int numProductos) {
    FILE *file = fopen(FILE_NAME, "w"); // Abrimos el fichero en modo escritura, borrando todo lo que tenga dentro
    if (file == NULL) {
        printf("Error al abrir el archivo.\n"); // Se comprueba si el archivo se a abierto correctamente
        return;
    }

    for (int i = 0; i < numProductos; i++) { // Uno a uno, se copian todos los valores del array de prodcutos en el fichero
        fprintf(file, "%s %s %s %.2f %s %s %s %.2f %d %d\n",
                productos[i].nombre, productos[i].descripcion, productos[i].estado,
                productos[i].precio, productos[i].marca, productos[i].modelo, productos[i].color,
                productos[i].pulgadas, productos[i].capacidad, productos[i].RAM);
    }

    fclose(file); // Se cierra el fichero
}


// ---------------------------- FUNCIÓN DE REGISTRO DE PRODUCTOS ----------------------------------------------------------------------------------------
/*Esta función servirá para registrar un nuevo prodcuto en el struct de tipo moviles. */

void leerProducto(struct Movil *movil){
        printf("\n-------------------: ");
        printf("\nRellene los datos: ");
        printf("\n-------------------: ");
        printf("\nNOMBRE: ");
        scanf("%29s", movil->nombre);			// Se lee el nombre con un maximo de 29 caracteres
        printf("\nDESCRIPCIÓN: ");
        scanf("%49s", movil->descripcion);		// Se lee la descripción con un maximo de 49 caracteres
        printf("\nPRECIO: ");
        scanf("%f", &movil->precio);			// Se lee el precio de tipo real
	
	do{
        	printf("\nESTADO[Nuevo o Usado]: ");	
        	scanf(" %9s", &movil->estado);		// Se lee el estado del producto. Solo podra ser "Nuevo" o "Usado".

		 if (strcmp(movil->estado, "Nuevo") != 0 && strcmp(movil->estado, "Usado") != 0) { // Se comprueba que el valor es correcto
           		 printf("\nEntrada no reconocida. Ingrese 'Nuevo' o 'Usado'.");
        	}
        	
	}while(strcmp(movil->estado, "Nuevo") != 0 && strcmp(movil->estado, "Usado") != 0); // Se preguntará este valor hasta que sea correcto

        printf("\nMARCA: ");
        scanf("%29s", movil->marca);			// Se lee la marca con un maximo de 29 caracteres
        printf("\nMODELO: ");
        scanf("%29s", movil->modelo);			// Se lee el modelo con un maximo de 29 caracteres
        printf("\nCOLOR: ");
        scanf("%29s", movil->color);			// Se lee el color con un maximo de 29 caracteres
        
	do{
        	printf("\nPULGADAS: ");
        	scanf("%f", &movil->pulgadas);		// Se lee las pulgadas hasta que sea un valor entre 3 y 10

		if (movil->pulgadas <3 || movil->pulgadas > 10){   // Se informa si el valor no es correcto
			printf("\nEl tamaño introducido no es valido");
		}
		
        }while(movil->pulgadas <0 || movil->pulgadas > 10);	// Se preguntará este valor hasta que sea correcto


	do{
        	printf("\nCAPACIDAD (GB): ");
        	scanf("%d", &movil->capacidad);		// Se lee la capacidad hasta que sea un valor entre 1 y 1000000

		if (movil->capacidad <0 || movil->capacidad > 100000){
			printf("\nEl tamaño introducido no es valido");   // Se informa si el valor no es correcto
		}
		
        }while(movil->capacidad <0 || movil->capacidad > 100000);	// Se preguntará este valor hasta que sea correcto
        
        do{
        	printf("\nRAM (GB): ");
        	scanf("%d", &movil->RAM);		// Se lee RAM hasta que sea un valor entre 1 y 500

		if (movil->RAM <0 || movil->RAM > 500){		
			printf("\nEl tamaño introducido no es valido");	// Se informa si el valor no es correcto
		}
        }while(movil->RAM <0 || movil->RAM > 500);	// Se preguntará este valor hasta que sea correcto
}

// ---------------------------- FUNCIÓN DE BUSQUEDA DE PRODUCTOS -----------------------------------------------------------------------------------------
/*Esta función servirá para buscar un prodcuto existente dentre el array de structs de tipo movil. */

void buscarProducto(struct Movil *productos, int numProductos, char *nombreBusqueda) {
    	// -----------------------Busqueda Secuencial---------------------------
    	int encontrado = FALSE;  // Se establece un comprobante como falso
    
    	for (int i = 0; i < numProductos; i++) {  // Se busca crea un bucle para recorrer el array
        	if (strcmp(productos[i].nombre, nombreBusqueda) == 0) { // Si se encuentra el nombre, se devuelven los datos del producto
            		// SI SE ENCUENTRA EL PRODUCTO
            		printf("\n---------------------\n");
            		printf("\nProducto encontrado:\n");
            		printf("\n---------------------\n");
            		printf("Nombre: %s\n", productos[i].nombre);
            		printf("Descripción: %s\n", productos[i].descripcion);
            		printf("Precio: %.2f\n", productos[i].precio);
            		printf("Estado: %s\n", productos[i].estado);
            		printf("Marca: %s\n", productos[i].marca);
            		printf("Modelo: %s\n", productos[i].modelo);
            		printf("Color: %s\n", productos[i].color);
            		printf("Pulgadas: %.2f\n", productos[i].pulgadas);
            		printf("Capacidad: %d GB\n", productos[i].capacidad);
            		printf("RAM: %d GB\n", productos[i].RAM);
            		encontrado = TRUE;  // Se setea el valor de encontrado a verdadero
            		break;	// Si se ha encontrado el producto, no tiene sentido seguir recorriendo el bucle. Se sale del for.
        	}
    	}

    	if (!encontrado) {
        	printf("\nProducto no encontrado.\n");	// Si no se ha encontrado el prodcuto, se avisa al usuario
    	}
}


// ---------------------------- REALIZAR PEDIDO   -------------------------------------------------------------------------------------------
void realizarPedido(nodo *inicio){
	nodo *aux;
	nodo *compra = NULL;
	
	nodo *insertado2;
	char sino;
	
	if (listaVacia(inicio) == TRUE){
		printf("\nNo hay nada en la lista");
	} else{
		
		aux = inicio;
		while (aux != NULL){
			// Se presentan los datos del prodcuto
		        printf("\n---------------------\n");
            		printf("Producto %d:", aux->codigo);
            		printf("\n---------------------\n");	
            		printf("Nombre: %s\n", aux->productos.nombre);
            		printf("Descripción: %s\n", aux->productos.descripcion);
            		printf("Precio: %.2f\n", aux->productos.precio);
            		printf("Estado: %s\n", aux->productos.estado);
            		printf("Marca: %s\n", aux->productos.marca);
            		printf("Modelo: %s\n", aux->productos.modelo);
            		printf("Color: %s\n", aux->productos.color);
            		printf("Pulgadas: %.2f\n", aux->productos.pulgadas);
            		printf("Capacidad: %d GB\n", aux->productos.capacidad);
            		printf("RAM: %d GB\n", aux->productos.RAM);
            		
            		
            		do{
            			printf("¿Desea añadir este prodcuto al carrito? (s/n): \n"); 	// Se le pregunta al usuario si quiere el producto
        			scanf("%c ", &sino);	
        								// Se registra la respuesta
        		}while(sino != 's' && sino != 'n');
        				/*		
        		if (sino == 's'){
        			if (listaVacia(compra) == TRUE){ // mi nuevo nodo, será el primero de la lista
  					insertarNodo(&compra, compra, aux->productos);	
        		}else
        		insertarNodo(nodo **inicio, nodo *refe, int elemento )*/
            		// Se avanza al siguiente prodcuto de la lista
			aux = aux->siguiente;
		}	
		printf("\n");
	}	
}

// ---------------------------- FUNCIÓN DE MOSTRAR TODOS LOS PRODUCTOS ------------------------------------------------------------------------------------------
/*Esta función servirá para mostrar todos los productos existentes dentre el array de structs de tipo movil. */

void mostrarProductos(struct Movil productos[], int numProductos) {
    	if (numProductos == 0) {
		printf("\nNo hay productos registrados.\n"); // Si no hay productos, se avisará al usuario de ello.
		return;
	}

	for (int i = 0; i < numProductos; i++) {  // Se recorre el array de prodcutos, mostrando todos los valores de cada uno
		printf("\nProducto %d:\n", i + 1);
		printf("\n---------------------\n");
		printf("Nombre: %s\n", productos[i].nombre);
		printf("Descripción: %s\n", productos[i].descripcion);
		printf("Precio: %.2f\n", productos[i].precio);
		printf("Estado: %s\n", productos[i].estado);
		printf("Marca: %s\n", productos[i].marca);
		printf("Modelo: %s\n", productos[i].modelo);
		printf("Color: %s\n", productos[i].color);
		printf("Pulgadas: %.2f\n", productos[i].pulgadas);
		printf("Capacidad: %d GB\n", productos[i].capacidad);
		printf("RAM: %d GB\n", productos[i].RAM);
	}
}

// ---------------------------- FUNCIÓN DE ORDENAR LOS PRODUCTOS ----------------------------------------------------------------------------------------
/*Esta funcion utilizara el metodo de la burbuja para ordenar los productos del array de moviles, en funcion del valor seleccionado para ello.*/
//............................BURBUJA................................
void ordenarProductos(struct Movil productos[], int numProductos, int criterio) {
	struct Movil temp; // Creamos un elemento temporal para guardar los datos de los productos.
	int i, j;

    	// se comparará según el criterio seleccionado
    	for (i = 0; i < numProductos - 1; i++) {
        	for (j = i + 1; j < numProductos; j++) {
            		int swap = 0; // Crearemos una variable para indicar  el intercambio

            		// Utilizaremos un switch case para determinar la ordenación que usaremos.
            		switch (criterio) {
                		case 1: // Ordenar por precio
                    			if (productos[i].precio > productos[j].precio) {
                        			swap = 1;
                    			}
                    			break;
				case 2: // Ordenar por pulgadas
				    	if (productos[i].pulgadas > productos[j].pulgadas) {
				        	swap = 1;
				    	}
				    	break;
                		case 3: // Ordenar por capacidad
                    			if (productos[i].capacidad > productos[j].capacidad) {
                        			swap = 1;
                    			}
                    			break;
                		case 4: // Ordenar por RAM
                    			if (productos[i].RAM > productos[j].RAM) {
                        			swap = 1;
                    			}
                    			break;
                		case 5: // Ordenar por marca
                    			if (strcmp(productos[i].marca, productos[j].marca) > 0) { // strcmp para comparar valores alfabeticos
                        			swap = 1;
                    			}
                    			break;
                    		case 6: // Ordenar por nombre. !!!Esta opcion no está habilitada para el menú de ordenar. Solo accesible para la busqueda binaria
    					if (strcmp(productos[i].nombre, productos[j].nombre) > 0) { 
        					swap = 1;
    					}
    					break;
                		default:
                    			printf("Criterio de ordenación no válido.\n"); // Si no se seleccionó un criterio correcto, se informa al usuario
                    			return;
            		}
            		
            		// Si el valor de swap esta activo, se inicia el intercambio con el struct de movil temporal
            		if (swap) { 
				temp = productos[i]; // se guarda el producto i en la variable temporal
				productos[i] = productos[j]; // se pasa el producto j al espacio del producto i
				productos[j] = temp; // se pasa el valor de temp (producto i) al espacio del producto j
            		}
        	}
    	}
}

// ............................SELECCION......................................... 
/*Esta funcion utiliza el metodo de selección para ordenar los productos del array de moviles en funcion del valor seleccionado*/
/*
void ordenarProductos(struct Movil productos[], int numProductos, int criterio) {
    	struct Movil temp; // Estructura temporal para realizar el intercambio
    	int i, j, posMin;  // `posMin` almacena la posición mínima en cada iteración

    	for (i = 0; i < numProductos - 1; i++) {
        	posMin = i;
        
        	// Se realiza la selección del elemento minimo segun el criterio
        	for (j = i + 1; j < numProductos; j++) {
		    	int comparar = 0;

		    	// Se compara según el criterio selecionado
		    	switch (criterio) {
		        	case 1: // Ordenar por precio
		            		comparar = (productos[j].precio < productos[posMin].precio);
		            		break;
		        	case 2: // Ordenar por pulgadas
		            		comparar = (productos[j].pulgadas < productos[posMin].pulgadas);
		            		break;
		        	case 3: // Ordenar por capacidad
		            		comparar = (productos[j].capacidad < productos[posMin].capacidad);
		            		break;
		        	case 4: // Ordenar por RAM
		            		comparar = (productos[j].RAM < productos[posMin].RAM);
		            		break;
		        	case 5: // Ordenar por marca
		            		comparar = (strcmp(productos[j].marca, productos[posMin].marca) < 0);
		            		break;
		        	default:
		            		printf("Criterio de ordenación no válido.\n");
		            	return;
		    	}

		    	// Si comparar es verdadero, se actualiza posmin
		    	if (comparar) {
		        	posMin = j;
		    	}
        	}

        	// Si posmin cambia, se realiza el intercambio
        	if (posMin != i) {
            		temp = productos[i];
            		productos[i] = productos[posMin];
            		productos[posMin] = temp;
        	}
   	}
}*/

