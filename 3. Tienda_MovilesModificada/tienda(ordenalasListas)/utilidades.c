#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "utilidades.h"

#define TRUE 1
#define FALSE 0
#define MAX 20  
#define FILE_NAME "productos.dat"



//-----------------------------LISTAS MANEJO ---------------------------------------------------------------------------------------------------------

// ---------------------------- COMPROBAR LISTA VACIA  -------------------------------------------------------------------------------------------
int listaVacia(nodo *inicio ){
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
	float total = 0;
	if (listaVacia(inicio) == TRUE){
		printf("\n[ERROR]No hay nada en la lista");
	} else{
		
		aux = inicio;
		
		printf("\nProductos en Lista: ");
		printf("\n--------------------\n");
		while (aux != NULL){
			printf("%d. ", aux->productos.codigo);
			printf("%s ", aux->productos.nombre);
			printf("%.2f ", aux->productos.precio);
			printf("\n");
			
			total = total + aux->productos.precio;
			aux = aux->siguiente;
		}	
		printf("\n");
		printf("\nTOTAL: %.2f", total);
	}	
}


// ---------------------------- INSERTAR NODO LISTA   --------------------------------------------------------------------------------------

nodo * insertarNodo(nodo **inicio, nodo *refe, struct Movil producto ){
	nodo *nuevo;
	nuevo = (nodo *) malloc(sizeof(nodo)); // malloc reseva un espacio de memoria donde se toma como tamaño el sizeof de nodo

	if( nuevo == NULL){  // Comprobamos que se ha hecho bien
		printf("\nNo se ha podido reservar espacio para el nuevo elemento de la lista");
		return NULL;
	}
	nuevo->productos = producto;
	if (listaVacia(*inicio) == TRUE){ // mi nuevo nodo, será el primero de la lista
		*inicio = nuevo;
		nuevo->siguiente = NULL;
	} else{ 
		nuevo->siguiente = refe->siguiente;
		refe->siguiente = nuevo;
	} 
	return nuevo;
}

// ---------------------------- ELIMINAR NODO LISTA   --------------------------------------------------------------------------------------
int eliminarNodoPorCodigo(nodo **inicio, int codigo) {
	if (listaVacia(*inicio) == TRUE){
		printf("\n[ERROR]No hay nada en la lista");  // Se comprueba s la lista esta vacía
		return 0;
	} 
	
    	nodo *aux = *inicio;
    	nodo *anterior = NULL;
    	
	// Si el nodo a eliminar es el primero de la lista
    	if (aux != NULL && aux->productos.codigo == codigo) {
		*inicio = aux->siguiente;
		free(aux);
		printf("\nProducto con código %d eliminado del carrito.\n", codigo);
		return 1;
    	}
	
	// Buscar el nodo a eliminar
    	while (aux != NULL && aux->productos.codigo != codigo) {
		anterior = aux;
		aux = aux->siguiente;
    	}

    	// Si el producto no fue encontrado
    	if (aux == NULL) {
        	printf("\n[ERROR]No se encontró un producto con el código %d.\n", codigo);
        	return 0;
    	}

    	// Eliminar el nodo
    	anterior->siguiente = aux->siguiente;
    	free(aux);
    	printf("\nProducto con código %d eliminado del carrito.\n", codigo);
    	return 1;
}
// ---------------------------- ORDENAR LISTAS   --------------------------------------------------------------------------------------
void ordenarListaBurbuja(nodo *inicio) {
    	nodo *aux;
    	nodo *siguiente;
    	int intercambio;

    	if (listaVacia(inicio) == TRUE) {
        	printf("\n[ERROR]No hay nada en la lista");
    	} else {
        	do {
            		aux = inicio;
            		intercambio = FALSE;
            
            		while (aux->siguiente != NULL) {
                		siguiente = aux->siguiente;
                
                		// Se comparan los codigos de los productos
                		if (aux->productos.codigo > siguiente->productos.codigo) {
                    			// Se ntercambian los nodos 
				    	struct Movil temp = aux->productos;
				    	aux->productos = siguiente->productos;
				    	siguiente->productos = temp;
                    
                    			intercambio = TRUE;
                		}
                		aux = aux->siguiente;
            		}
        	} while (intercambio == TRUE); // Se rpite hasta que no haya mas intercambios
        
        	mostrarLista(inicio);  // Se muestra la lista ordenada
    	}
}


void ordenarListaSelecDirecta(nodo *inicio) {
   	nodo *aux;
    	nodo *menor;
    	nodo *q;

    	int codigoMenor;

    	if (listaVacia(inicio) == TRUE) {
        	printf("\n[ERROR]No hay nada en la lista");
    	} else {
        	aux = inicio;
        
        	while (aux->siguiente != NULL) {
			menor = aux;
            		codigoMenor = menor->productos.codigo;

		    	q = aux->siguiente;
		    
		    	// Se busca el nodo con el valor mas pequeño
		    	while (q != NULL) {
		        	if (codigoMenor > q->productos.codigo) {
                    			codigoMenor = q->productos.codigo;
                    			menor = q;
                		}
		        	q = q->siguiente;
		    	}
		    
		    	// Si el nodo menor no es el actual, se intercambian
		    	if (menor != aux) {
		        	struct Movil temp = aux->productos;
                		aux->productos = menor->productos;
                		menor->productos = temp;
		    	}
		    
		    	aux = aux->siguiente;  // Se avanza al siguiente nodo
        	}
        
        mostrarLista(inicio);  // Muestra la lista ordenada
    	}
}


// ---------------------------- CARGAR PRODUCTOS DESDE TXT  --------------------------------------------------------------------------------------
/*Esta función servirá para cargar los archivos que se hallen en productos.dat en el array de productos. Gracias a esto podremos
trabajar en todo momento con los productos de manera dinamica y podremos determinar el numero de elementos inciales al 
iniciar el programa en cada ejecución */

int cargarProductos(struct Movil productos[]) {
    	FILE *archivo = fopen("productos.dat", "rb"); // Abre el archivo en modo binario de lectura
    	if (archivo == NULL) {
        	perror("[ERROR]No se pudo abrir el archivo para lectura");
        	return 0; // Retornamos 0 si no se pudo abrir el archivo
    	}
    
    	// Leemos los productos en el arreglo
    	int numProductos = 0;
    	while (fread(&productos[numProductos], sizeof(struct Movil), 1, archivo) == 1) {
        	numProductos++;
    	}
    
    	fclose(archivo);
    	return numProductos;
}

// ------------------------------ GUARDAR NUEVOS PRODUCTOS EN TXT --------------------------------------------------------------------------------------
/*Esta función servirá para guardar los nuevos valores del array de prodcutos dentro de "productos.tdat". Esta función nos permitirá tener actualizado 
en todo momento los valores del struct dentro del archivo, lo que nos permitirá trabajar de manera dinamica con el.*/

void guardarProductos(struct Movil productos[], int numProductos) {
    	FILE *archivo = fopen("productos.dat", "wb"); // Abre el archivo en modo binario de escritura
    	if (archivo == NULL) {
        	perror("[ERROR]No se pudo abrir el archivo para escritura");
        	return;
    	}
    
    	// Escribimos todos los productos en el archivo binario
    	fwrite(productos, sizeof(struct Movil), numProductos, archivo);
    
    	fclose(archivo);
}


// ---------------------------- FUNCIÓN DE REGISTRO DE PRODUCTOS ----------------------------------------------------------------------------------------
/*Esta función servirá para registrar un nuevo prodcuto en el struct de tipo moviles. */

void leerProducto(struct Movil *movil, int numele){

	movil->codigo = numele +1;
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
           		 printf("\n[ERROR]Entrada no reconocida. Ingrese 'Nuevo' o 'Usado'.");
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
			printf("\n[ERROR]El tamaño introducido no es valido");
		}
		
        }while(movil->pulgadas <0 || movil->pulgadas > 10);	// Se preguntará este valor hasta que sea correcto


	do{
        	printf("\nCAPACIDAD (GB): ");
        	scanf("%d", &movil->capacidad);		// Se lee la capacidad hasta que sea un valor entre 1 y 1000000

		if (movil->capacidad <0 || movil->capacidad > 100000){
			printf("\n[ERROR]El tamaño introducido no es valido");   // Se informa si el valor no es correcto
		}
		
        }while(movil->capacidad <0 || movil->capacidad > 100000);	// Se preguntará este valor hasta que sea correcto
        
        do{
        	printf("\nRAM (GB): ");
        	scanf("%d", &movil->RAM);		// Se lee RAM hasta que sea un valor entre 1 y 500

		if (movil->RAM <0 || movil->RAM > 500){		
			printf("\n[ERROR]El tamaño introducido no es valido");	// Se informa si el valor no es correcto
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
        	printf("\n[ERROR]Producto no encontrado.\n");	// Si no se ha encontrado el prodcuto, se avisa al usuario
    	}
}

// ---------------------------- FUNCIÓN DE MOSTRAR TODOS LOS PRODUCTOS ------------------------------------------------------------------------------------------
/*Esta función servirá para mostrar todos los productos existentes dentre el array de structs de tipo movil. */

void mostrarProductos(struct Movil productos[], int numProductos) {
    	if (numProductos == 0) {
		printf("\n[ERROR]No hay productos registrados.\n"); // Si no hay productos, se avisará al usuario de ello.
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

void comprarProductos(struct Movil productos[], int numProductos, nodo **pedido) {
    	if (numProductos == 0) {
		printf("\n[ERROR]No hay productos registrados.\n"); // Si no hay productos, se avisará al usuario de ello.
		return;
	}
	int codigoBorrado;
	char sino, sino2;
    	nodo *ultimoNodo = *pedido;
    	
    	struct Movil temp; // Temporal para el intercambio de productos
    	int i, j, ordenado;

    
	for (int i = 0; i < numProductos; i++) {  					// Se recorre el array de prodcutos, mostrando todos los valores de cada uno
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
		
		
		do{
            		printf("\n¿Desea añadir este prodcuto al carrito? (s/n): \n"); 	// Se le pregunta al usuario si quiere el producto
        		scanf(" %c", &sino);	
        										// Se registra la respuesta
        	}while(sino != 's' && sino != 'n');
        		
        	if (sino == 's'){
        		if (listaVacia(*pedido) == TRUE){ 				// mi nuevo nodo, será el primero de la lista
  				ultimoNodo = insertarNodo(pedido, NULL, productos[i]);	
        		}else{
        			ultimoNodo = insertarNodo(pedido, ultimoNodo, productos[i]);
        		}
        		 printf("\nProducto añadido al carrito.\n");
        	}
        }
        ordenarListaBurbuja(*pedido);
        mostrarLista(*pedido);
        do{
        	printf("\n¿Desea eliminar algun prodcuto de la lista? (s/n)\n");
        	scanf(" %c", &sino2);							// Se registra la respuesta
        }while(sino2 != 's' && sino2 != 'n');
        
        while (sino2 == 's') {
		printf("\nIngrese el código del producto que desea eliminar: ");
        	scanf("%d", &codigoBorrado);

        	if (eliminarNodoPorCodigo(pedido, codigoBorrado)) {
            		printf("\nProducto eliminado exitosamente.\n");
        	} else {
            		printf("\n[ERROR]No se encontró el producto con el código especificado.\n");
        	}

		printf("\nProductos actualizados en el carrito:\n");
		mostrarLista(*pedido);

		do{
			printf("\n¿Desea eliminar otro producto del carrito? (s/n): ");
			scanf(" %c", &sino2);
		}while (sino2 != 's' && sino2 != 'n');
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
                    			printf("[ERROR]Criterio de ordenación no válido.\n"); // Si no se seleccionó un criterio correcto, se informa al usuario
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