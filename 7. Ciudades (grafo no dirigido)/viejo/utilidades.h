#ifndef UTILIDADES_H
#define UTILIDADES_H

struct ARISTA{
    	int destino;
    	float distancia;           		// Distancia entre las ciudades
    	struct ARISTA *siguiente;		//Siguiente arista en la lista de adyacencia
};

typedef struct ARISTA arista;


struct VERTICE{
	int id;
    	char nombre[50];           			// Nombre de la ciudad
    	arista *adyacentes;				// Lista de ciudades conectadas a esta ciudad
    	struct VERTICE *siguiente;			// Puntero al siguiente nodo (ciudad)
};

typedef struct VERTICE vertice;


// Funciones
vertice *crearCiudad(int id, char *nombre);

void insertarCiudad(vertice **grafo, int id, char *nombre);
void conectarCiudades(vertice *grafo, int id1, int id2, float distancia);

vertice *buscarCiudad(vertice *grafo, int id);
void imprimirMapa(vertice *grafo);
#endif
