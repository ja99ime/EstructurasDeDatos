#ifndef UTILIDADES_H
#define UTILIDADES_H

	struct Movil{
	   	char nombre[30];
	   	char descripcion[50];
		char estado[10];
		float precio;
		char marca[30];
		char modelo[30];
		char color[30];
		float pulgadas;
		int capacidad;
		int RAM; 
	};
	int cargarProductos(struct Movil productos[]);
	void guardarProductos(struct Movil productos[], int numProductos);
	//void guardarProductosNuevos(struct Movil productos[], int numProductos);
	
	void leerProducto(struct Movil *movil);
	void buscarProducto(struct Movil *productos, int numProductos, char *nombreBusqueda);
	void comprarProducto(struct Movil productos[], int *numProductos, const char *nombreCompra);
	void mostrarProductos(struct Movil productos[], int numProductos); 
	void ordenarProductos(struct Movil productos[], int numProductos, int criterio);
	//void quickSort(struct Movil productos[], int iniArg, int finArg, int criterio);

#endif
