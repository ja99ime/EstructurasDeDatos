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

// ---------------------------- CARGAR PRODUCTOS DESDE TXT  -------------------------------------------------------------------------------------------
/*Esta función servirá para cargar los archivos que se hallen en productos.txt en el array de productos. Gracias a esto podremos
trabajar en todo momento con los productos de manera dinamica y podremos determinar el numero de elementos inciales al 
iniciar el programa en cada ejecución */

int cargarProductos(struct Movil productos[]) {
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
// -------------------------------Guardar productos de la lista (solo los moviles No usados. Por ESTADO)
//Esta funcion es una variante de la anterior, y nos permitirá guardar los productos que correspondan con un campo en especifico
// En este caso. Solo gaurdaremos los moviles que sean de Estado Nuevo


/*void guardarProductosNuevos(struct Movil productos[], int numProductos) {
    FILE *file = fopen(FILE_NAME2, "w"); // Abrimos el fichero en modo escritura, borrando todo lo que tenga dentro
    if (file == NULL) {
        printf("Error al abrir el archivo.\n"); // Se comprueba si el archivo se a abierto correctamente
        return;
    }

    for (int i = 0; i < numProductos; i++) { // Uno a uno, se copian todos los valores del array de prodcutos en el fichero
        if (strcmp(productos[i].estado, "Nuevo") == 0){
        	fprintf(file, "%s %s %s %.2f %s %s %s %.2f %d %d\n",
		        productos[i].nombre, productos[i].descripcion, productos[i].estado,
		        productos[i].precio, productos[i].marca, productos[i].modelo, productos[i].color,
		        productos[i].pulgadas, productos[i].capacidad, productos[i].RAM);
	    	}
	}
    fclose(file); // Se cierra el fichero
}*/


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
// ----------------------Busqueda Binaria--------------------------------------
/**Al igual que la de arriba, esta version de la función ofrece una busqueda, sin embargo, esta aplicara la busqueda binaria, tomando el struct de productos y
 disminuyendolo mitad a mitad para acotar la busqueda cada vez mas. Como es indispensable que los productos estén ordenados para que se busque, se implementará 
 la función de ordenación adecuada antes de ejecutar la busqueda/

/*ordenarProductos(productos, numProductos, 6); //Primero, se ordenan los productos por nombre
    	int ini = 0;  // inicio es el principio del array
    	int fin = numProductos - 1; // Final es el numero de productos
    	int encontrado = FALSE;  // Variable comprobante para determinar si se encuentra o no

   	while (ini <= fin) {
        	int centro = ini + (fin - ini) / 2;   // Variable centro, calculada en todo momento en funcion de inicio y fin
        	int cmp = strcmp(productos[centro].nombre, nombreBusqueda);  // Se guarda el valor correspndiente a centro y se compara con el nombre de busqueda

        	if (cmp == 0) { // Si el producto es encontrado, se muestran los datos
            		printf("\n---------------------\n");
            		printf("\nProducto encontrado:\n");
           		printf("\n---------------------\n");
            		printf("Nombre: %s\n", productos[centro].nombre);
            		printf("Descripción: %s\n", productos[centro].descripcion);
            		printf("Precio: %.2f\n", productos[centro].precio);
            		printf("Estado: %s\n", productos[centro].estado);
            		printf("Marca: %s\n", productos[centro].marca);
            		printf("Modelo: %s\n", productos[centro].modelo);
            		printf("Color: %s\n", productos[centro].color);
            		printf("Pulgadas: %.2f\n", productos[centro].pulgadas);
            		printf("Capacidad: %d GB\n", productos[centro].capacidad);
            		printf("RAM: %d GB\n", productos[centro].RAM);
            		encontrado = TRUE;
            		break;
        	} else if (cmp < 0) {
            		ini = centro + 1;  // se ajusta el inicio como el antiguo centro + 1
        	} else {
            		fin = centro - 1;  // se ajusta el fin como el nuevo centro - 1
        	} 
    	} // Se repite el bucle, acotando cada vez más el valor a buscar.

    	if (!encontrado) {  // si no se encuentra, se avisa al usuario
        	printf("\nProducto no encontrado.\n");
    	}*/
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
// ---------------------------- FUNCION COMPRAR PRODUCTOS ---------------------------------------------------------------------------------------------
/*Esta función servirá para eliminar uno de los prodcutos del array con el pretexto de realizar una compra es por ello que se simulara
en todo momento que se está realizando una adquisición del movil seleccionado por el nombre de compra pasado como parametro. */

void comprarProducto(struct Movil productos[], int *numProductos, const char *nombreCompra) {
    	int encontrado = FALSE;  // Se setea un comprobante como falso

    	// Buscar el producto
    	for (int i = 0; i < *numProductos; i++) {  // Se recorre el bucle en busca del registro a eliminar.
        	if (strcmp(productos[i].nombre, nombreCompra) == 0) {
		    	encontrado = TRUE;  // Si se encuentra el valor, se setea el comprobante como verdadero

		    	// Mostramos los detalles del producto
		    	printf("\nProducto encontrado:\n");
		    	printf("Nombre: %s\n", productos[i].nombre);
		    	printf("Descripción: %s\n", productos[i].descripcion);
		    	printf("Precio: %.2f\n", productos[i].precio);
		    	printf("Marca: %s\n", productos[i].marca);

		    	// Cnfirmacion de la compra
		    	char confirma; // Se crea un caracter para guardar un solo valor
		    	printf("\n¿Desea comprar este producto? (S/N): ");
		    	scanf(" %c", &confirma);

		    	if (confirma == 'S' || confirma == 's') { // Si el valor es una "s", se procedera con la eliminacion del producto
		        	for (int j = i; j < (*numProductos) - 1; j++) { // Para elimiar el valor, se desplazaran los valores hacia el resto
		            		productos[j] = productos[j + 1];
		        	}
		        	(*numProductos)--;  // Se descontará un producto del total

		        	// Actualizacion del archivo de productos
                		guardarProductos(productos, *numProductos);  // SE realizara una nueva escritura en el fichero para actualizarlo
				
		        	printf("\nCompra realizada con exito. Producto eliminado del sistema.\n");
		    	} else {
		        	printf("\nCompra cancelada\n"); // si el  valor del caracter no fue una s, se cancela la compra
            		}
            		break;  // Se rompe el bucle
        	}
    	}

    	if (!encontrado) {
        	printf("\nProducto no encontrado.\n"); // Si el producto no se ha encontrado, se advierte al usuario.
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
// ............................INSERCION (BARAJA).........................................
/*Esta funcion utiliza el metodo de inserción para ordenar los productos del array de moviles en funcion del valor seleccionado*/
/*void ordenarProductos(struct Movil productos[], int numProductos, int criterio) {
    	int i, j;
   	struct Movil aux; // struct auxiliar para el intercambio

    	// Recorremos cada elemento para insertarlo en su posición correcta
    	for (i = 1; i < numProductos; i++) {
        	aux = productos[i]; // Guardamos el elemento actual en la variable auxiliar
        	j = i;

        	// Utilizaremos un switch case para determinar la ordenación que usaremos.
        	int compara = 0;
        	while (j > 0) {
		    	switch (criterio) {
		        	case 1: // Ordenar por precio
		            		compara = (aux.precio < productos[j - 1].precio);
		            		break;
		       	 	case 2: // Ordenar por pulgadas
		            		compara = (aux.pulgadas < productos[j - 1].pulgadas);
		            		break;
		        	case 3: // Ordenar por capacidad
		            		compara = (aux.capacidad < productos[j - 1].capacidad);
		            		break;
		        	case 4: // Ordenar por RAM
		            		compara = (aux.RAM < productos[j - 1].RAM);
		            		break;
		        	case 5: // Ordenar por marca
		            		compara = (strcmp(aux.marca, productos[j - 1].marca) < 0);
		            		break;
		        	default:
		            		printf("Criterio de ordenación no válido.\n");
		            		return;
		    	}

		    	// Si el producto actual es menor que el anterior, se desplaza a la derecha
		    	if (compara) {
		        	productos[j] = productos[j - 1];
		       	 	j--;
		    	} else {
		        	break;
		    	}
		}
        	productos[j] = aux; // Insertamos elemento en su posición
    	}
}*/

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

//.....................SHELL..............................
/*Esta funcion utilizara el metodo de la SHELL para ordenar los productos del array de moviles, en funcion del valor seleccionado para ello.*/
/*void ordenarProductos(struct Movil productos[], int numProductos, int criterio) {
 
    	int dist = numProductos;
    	struct Movil temp;

    	// Ajusta la distancia en cada iteración
    	while (dist > 1) {
        	dist /= 2;
        
        	// Ordena los elementos a la distancia dada
        	for (int i = dist; i < numProductos; i++) {
            		temp = productos[i];
            		int j = i;

            		// Comparaciones y desplazamientos de elementos según el criterio seleccionado
            		while (j >= dist) {
                		int comparar = 0;
                		switch (criterio) {
                	    		case 1:  // Ordenar por precio
		                		comparar = (temp.precio < productos[j - dist].precio);
		                		break;
                    			case 2:  // Ordenar por pulgadas
						comparar = (temp.pulgadas < productos[j - dist].pulgadas);
						break;
                    			case 3:  // Ordenar por capacidad
						comparar = (temp.capacidad < productos[j - dist].capacidad);
						break;
                    			case 4:  // Ordenar por RAM
						comparar = (temp.RAM < productos[j - dist].RAM);
						break;
				    	case 5:  // Ordenar por marca
						comparar = (strcmp(temp.marca, productos[j - dist].marca) < 0);
						break;
                    			default:
						printf("Criterio de ordenación no válido.\n");
						return;
                			}

                		// Si el elemento actual es menor según el criterio, desplázalo
               			 if (comparar) {
				    	productos[j] = productos[j - dist];
				    	j -= dist;
                		} else {
                   	 		break;
                		}
            		}
            		productos[j] = temp;
        	}
	}
}
*/

// ....................QUICKSORT..........................
/*Esta funcion utilizara el metodo de quicksort para ordenar los productos del array de moviles, en funcion del valor seleccionado para ello.*/
/*void ordenarProductos(struct Movil productos[], int numProductos, int criterio) {
    	quickSort(productos, 0, numProductos - 1, criterio);
}

void quickSort(struct Movil productos[], int iniArg, int finArg, int criterio) {
    	int ini = iniArg;
    	int fin = finArg;
    	struct Movil aux;
    	struct Movil pivote = productos[(iniArg + finArg) / 2];

    	// Se realiza una comparación según el criterio
    	int comparar(struct Movil a, struct Movil b, int criterio) {
        	switch (criterio) {
            		case 1: return (a.precio > b.precio) - (a.precio < b.precio);
            		case 2: return (a.pulgadas > b.pulgadas) - (a.pulgadas < b.pulgadas);
		    	case 3: return (a.capacidad > b.capacidad) - (a.capacidad < b.capacidad);
		    	case 4: return (a.RAM > b.RAM) - (a.RAM < b.RAM);
		    	case 5: return strcmp(a.marca, b.marca);
		    	default: return 0; 
        	}
    	}

    	while (ini <= fin) {
		// Se cambian las condiciones de comparación usando la función comparar
		while (comparar(productos[ini], pivote, criterio) < 0) ini++;
		while (comparar(productos[fin], pivote, criterio) > 0) fin--;

        if (ini <= fin) {
            	// Se intercambian los elementos
            	aux = productos[ini];
            	productos[ini] = productos[fin];
            	productos[fin] = aux;

            	ini++;
            	fin--;
        	}
    	}

    	// Llamadas recursvas
    	if (iniArg < fin) quickSort(productos, iniArg, fin, criterio);
    	if (ini < finArg) quickSort(productos, ini, finArg, criterio);
}*/
