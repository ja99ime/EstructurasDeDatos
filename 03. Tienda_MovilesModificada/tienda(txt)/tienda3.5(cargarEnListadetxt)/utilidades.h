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
	
	struct NODO{
   		int codigo;
		struct Movil productos;
		struct NODO *siguiente;
};

typedef struct NODO nodo;


	int cargarProductosArray(struct Movil productos[], nodo **inicio);
	void mostrarLista(nodo *);
	
	void guardarProductos(struct Movil productos[], int numProductos);
	
	void leerProducto(struct Movil *movil);
	void buscarProducto(struct Movil *productos, int numProductos, char *nombreBusqueda);
	void realizarPedido(nodo *inicio);
	
	void mostrarProductos(struct Movil productos[], int numProductos); 
	void ordenarProductos(struct Movil productos[], int numProductos, int criterio);


#endif
