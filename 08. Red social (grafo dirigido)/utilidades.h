#ifndef UTILIDADES_H
#define UTILIDADES_H

struct SEGUIDOR{
    	int idSeguido;
    	char nombre[50];           		// Nombre de la ciudad
    	struct SEGUIDOR *siguiente;		//Siguiente arista en la lista de adyacencia
};

typedef struct SEGUIDOR seguidor;


struct USUARIO{
	int id;
    	char nombre[50];           			// Nombre de la Usuario
    	seguidor *adyacentes;				// Lista de ciudades conectadas a esta ciudad
    	struct USUARIO *siguiente;			// Puntero al siguiente nodo (ciudad)
};

typedef struct USUARIO usuario;


// Funciones
usuario *crearUsuario(int, char *);

void insertarUsuario(usuario **);
void crearSeguimiento(usuario *);

usuario *buscarUsuario(usuario *, int);
void imprimirUsuarios(usuario *);
#endif
