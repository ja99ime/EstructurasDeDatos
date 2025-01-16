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

//------------------------ARBOL VACIO--------------------------------------------------------------------
int arbolVacio(NODO *raiz){
	if (raiz == NULL)	return TRUE;
	return FALSE;
}

//------------------------COMPROBAR INSERCCION-----------------------------------------------------------
int comprobarInserccion(NODO *raiz, NODO *padre, int derecha){
	if (padre!=NULL && derecha == FALSE && padre->hijo_izq != NULL ){
		return FALSE;
	} else if (padre != NULL && derecha == TRUE && padre->hijo_der != NULL ){
		return FALSE;
	} else if (padre == NULL && raiz != NULL ){
		return FALSE;
	}
	return TRUE;
}
//------------------------CARGAR JUEGO--------------------------------------------------------------------
void cargarJuego(NODO **raiz){
 	// Creamos la raiz del jeugo
    	insertarNODO(raiz, NULL, 
        "Te encuentras a las puertas de una inhóspita mansión. Un susurro gélido recorre tu espalda en un\n"
        "instante, provocandote un ligero temblor. Tras asegurarte de que nadie te sigue, alzas la vista.\n" 
        "Has venido aquí con un proposito y debes cumplirlo. \n\n"
        "¿Qué haces? \n(1) Entrar\n(2) Rodear la mansión", 
        FALSE, 0);
    
    	// Izquierda de la primera escena (intento de abrir la puerta)
    	insertarNODO(raiz, *raiz, 
    	"Cuando posas tus dedos sobre la puerta, descubres que esta cerrada con llave. Vas a necesitar\n"
        "algo más que valentía para entrar a la mansión. \n\n", 
    	FALSE, 0); 
    	
    	// Derecha de la primera escena (rodear la mansion)
    	insertarNODO(raiz, *raiz, 
    	"Decides dar una vuelta alrededor de la mansión. Mientras escuchas el canto sobrenatural de los \n"
    	"pájaros, te das cuenta de que en uno de los arboles, hay un nido donde algo brilla con fuerza.\n\n"
        "¿Qué haces? \n(1) Sacudes del árbol.\n(2) Trepas el árbol \n(3) Te alejas", 
    	TRUE, 0);

    	// Izquierda de la segunda escena (FINAL A)
    	insertarNODO(raiz, (*raiz)->hijo_der, 
    	"Una bandada de cuervos se percata de tus violentas acciones y se abalanza contra tí. Lo que de lejos\n" 
    	"parecían ser pájaros inofensivos, han resultado ser criaturas voraces y terriblemente agresivas. \n"
    	"Al final, pierdes la visión entre picotazos y plumas\n\n"
    	"[FINAL MALO: Comida de pajaros]", 
    	FALSE, 1);  // Hijo derecho de B

    	// Derecha de la segunda escena (llave)
    	insertarNODO(raiz, (*raiz)->hijo_der,
    	"Armandote de valor, trepas el árbol y metes la mano en el nido. Los cuervos cercanos comienzan a graznar \n"
    	"cuando uno de tus dedos toca uno de los huevos, pálidos y fríos. Sin embargo, sus amenazas parecen atenuarse\n"
    	"cuando tomas el objeto brillante y bajas del árbol. En tu poder tienes una llave metálica, algo oxidada.\n" 
        "¿Qué haces? \n(1) Pruebas suerte en la mansion.\n(2) Pruebas suerte en el cobertizo del jardín", 
    	TRUE, 0); 
    	
    	// Izquierda de la tercera escena (Interior de la mansion)
    	insertarNODO(raiz, ((*raiz)->hijo_der)->hijo_der,
    	"No pierdes el tiempo y te acercas a la entrada de la mansión. Cuando metes la llave en la puerta descubres que\n"
    	"encaja a la perfección, pero lo que no esperabas era que, al girar el pomo, una corriente de aire frio te empujara \n"
    	"contra el suelo. Ante ti tienes un enorme recibidor que da al salón central. La alfombra roja te invita a recorrer\n"
    	"las entrañas de la mansión\n"
        "¿Qué haces? \n(1) Ir al piso superior.\n(2) Ir al sotano", 
    	FALSE, 0); 
    	
    	// Derecha de la tercera escena (FINAL B)
    	insertarNODO(raiz, ((*raiz)->hijo_der)->hijo_der,
    	"No tiene sentido que sea tan sencillo, ¿verdad? O por lo menos, eso pensabas antes de acercarte al cobertizo. \n"
    	"No solo la llave no encaja en la mohosa puerta de madera, sino que una entidad sobrenatural parece molestarse \n"
    	"con tus intentos de invadir su propiedad. En uno de los intentos por forzar la llave en la cerradura, la puerta\n" 
        "se abre y caes hacia delante. Un monstruo de gran boca te atrapa entre sus brazos y antes de darte cuenta, eres \n"
        "engullido vivo por él. Pasas tus últimos instantes siendo digerido por una terrible criatura.\n\n"
        "[FINAL MALO: Demasiado listo]", 
    	TRUE, 1); 
	
	// Izquierda de la cuarta escena (piso superior)
    	insertarNODO(raiz, (((*raiz)->hijo_der)->hijo_der)->hijo_izq,
    	"Te encaminas a las escaleras mientras un canto extraño resuena en el piso de arriba. Puede que no te hayas dado cuenta, \n"
    	"pero hay marcha atrás en esta decisión. Sea lo que sea que haya ahí arriba es el verdadero propósito de tu viaje. La voz,\n"
    	"al principio gentil, comienza a distorsionarse con cada paso y con ello, la pesada sensación de la muerte se agolpa en\n"
    	"tu corazón\n"
        "¿Qué haces? \n(1) Seguir subiendo.\n(2) Correr", 
    	FALSE, 0); 
    	
    	// DERECHA de la cuarta escena (sotano)
    	insertarNODO(raiz, (((*raiz)->hijo_der)->hijo_der)->hijo_izq,
    	"El tipico sotano oscuro, cerrado y sin salida. Que podría salir mal... Pues en juego de terror común, seguramente \n"
    	"todo, pero este no es el típico juego de terror. Riquezas, joyas y cientos de tesoros se encuentran frente a tí. \n"
    	"Parece imposible, pero te las apañas para guardar tanto como puedes en tus bolsillos y salir por patas de la mansión. \n"
    	"Tienes la recompensa, así que... ¿Por qué buscar mas?\n\n"
    	"[FINAL BUENO: Asquerosamente rico]", 
    	TRUE, 1); 
    	
    	// Izquierda de la quinta escena (aceptacion)
    	insertarNODO(raiz, ((((*raiz)->hijo_der)->hijo_der)->hijo_izq)->hijo_izq,
    	"Seguir subiendo, contra todo pronostico, parece sumirte en un profundo trance a pesar del estridente ruido. Tu cuerpo se\n" 
    	"relaja y tu instinto de supervivencia se anula, obligándote a detener tu tren de pensamientos. ¿Quién eres? ¿Qué estás \n"
    	"haciendo? ¿Cual es tu proposito? ¿Metas? ¿Objetivos? ¿Qué era la mansion para tí? ¿Una excusa? ¿Una huida? No importa, pues\n"
    	"tus pies solo siguen moviendose mientras subes los infinitos escalones. Es adictivo, como si con cada paso, tu cuerpo fuera\n"
    	"dejando una parte de tí en la mansión. Simplemente, sube. Ya eres parte de ella\n\n"
        "[FINAL VERDADERO: El inexorable ciclo de la existencia]", 
    	FALSE, 1); 
    	
    	// Derecha de la quinta escena (panico)
    	insertarNODO(raiz, ((((*raiz)->hijo_der)->hijo_der)->hijo_izq)->hijo_izq,
    	"Te presionas las sienes en un intento de estabilizarte, no merece la pena y debes escapar. Sin darle tiempo a la extraña voz\n"
    	"de emponzoñar tu mente, te das la vuelta y comienzas a bajar. Corres y corres hacia abajo en un descenso eterno. Tus ojos se\n"
    	"llenan de lagrimas mientras la desesperación se aferra a tu pecho y la estridente voz taladra tus timpanos. Ni siquiera sabes \n"
    	"cuanto tiempo llevas bajando, pero los escalones, no cesan. Finalmente, tropiezas.\n\n"
        "[FINAL MALO: Cobarde]", 
    	TRUE, 1); 
}

//------------------------CARGAR JUEGO--------------------------------------------------------------------
void jugar(NODO *actual) {
    	int opcion;
    	while (actual != NULL) {
        	printf("\n-----------------------------------------------------------------------------------------------------------\n");
        	printf("\n%s\n", actual->dato);  // Mostrar el escenario actual
		printf("\n-----------------------------------------------------------------------------------------------------------\n");
        	if (actual->esFinal) {
        	   	printf("\n¡Has llegado a un final del juego!\n");
	            	printf("Gracias por jugar. Fin de la partida.\n");
            		break;
        	}		
		
        	if (actual->hijo_izq == NULL && actual->hijo_der == NULL) {
            		printf("\nNo tienes muchas opciones.\n");
              		printf("¿Vuelves sobre tus pasos? (1) Sí  (2) Me rindo! ");

            		scanf("%d", &opcion);

            		if (opcion == 1) {
                		actual = actual->padre;  // Volver al nodo padre
                		continue;
            		} else {
            			printf("\nTe rendiste ante la inmensa mansión y tu alma pasó a formar parte de su historia.\n");
                		break;  // Salir del juego
            		}
        	}

        	printf("\n¿Qué decides?\n");
        	scanf("%d", &opcion);
        
        	// Decisiones del jugador
        	if (opcion == 1 && actual->hijo_izq != NULL) {
            		actual = actual->hijo_izq;  // Moverse al hijo izquierdo
        	} else if (opcion == 2 && actual->hijo_der != NULL) {
            		actual = actual->hijo_der;  // Moverse al hijo derecho
        	} else if (opcion == 3) {
            		if (actual->padre != NULL) {
                		actual = actual->padre;  // Volver al nodo padre
            		} else {
                		printf("Ya no puedes volver atrás.\n");
            		}
       		} else if (opcion == 4) {
            		printf("Saliendo del juego...\n");
            		break;  // Salir del juego
        	} else {
            		printf("Opción no válida. Intenta de nuevo.\n");
        	}
    	}
}
//------------------------INSERTAR NODO--------------------------------------------------------------------
int insertarNODO(NODO **raiz, NODO *padre, char dato[], int derecha, int final){
	NODO  *nuevo;
	
	if (comprobarInserccion(*raiz, padre, derecha) == TRUE){ 	// se puede proceder a la insercion
		nuevo = (NODO *) malloc (sizeof(NODO));			// se crea el espacio de la memoria
		if (nuevo == NULL)	return FALSE;
		
		// Se establecen los valores del hijo
		strcpy(nuevo->dato, dato);				// copiamos el nuevo daro al valor de nuevo
		nuevo->esFinal = final;
		nuevo->hijo_izq = NULL;					// ponemos el hijo izquierdo como nulo
		nuevo->hijo_der = NULL;					// ponemos el hijoderecho como nulo
	
		if (arbolVacio(*raiz) == TRUE){				// SI ES EL PRIMER NODO
			*raiz = nuevo;					// nuevo se establece como raiz
			nuevo->padre = NULL;				// si el arbol esta vacio, el nuevo padre es nulo
		} else {						// SI E NODO NO ES EL PRIMERO
			if(derecha)	padre->hijo_der = nuevo;	
			else		padre->hijo_izq = nuevo;
			
			nuevo->padre = padre;
		}	
	} else{
		return FALSE;						// YA está ocupado
	}
	return TRUE;
}
//------------------------ELIMINAR NODO--------------------------------------------------------------------
void eliminarHoja(NODO *nodo) {
	if (nodo == NULL) return;

    	if (nodo->hijo_izq == NULL && nodo->hijo_der == NULL) {		// Verificamos si el nodo no tiene hijos
        	NODO *padre = nodo->padre;				// en dicho caso, localizamos a su nodo padre

        	if (padre != NULL) {					// Si existe un padre, desconectamos el nodo del árbol
            		if (padre->hijo_izq == nodo) {			// en caso de ser hijo izquierdo
                		padre->hijo_izq = NULL;			// se elimina su conexion con el padre
           		} else if (padre->hijo_der == nodo) {		// en caso de ser hijo derecho
           			padre->hijo_der = NULL;			// se elimina su conexion con el padre
            		}
        	}
        	
        	printf("\nEliminando nodo con dato: %s\n", nodo->dato);	
        	free(nodo);						// se libera la memoria del nodo
    	} else {
        	printf("[Error] El nodo no es una hoja.\n");
    	}
}
//------------------------ELIMINAR ARBOL------------------------------------------------------------------
void eliminarArbol(NODO *raiz) {
    	if (raiz == NULL)  return; 					// Si el árbol está vacío, no hacemos nada

    	(raiz->hijo_izq);						// se eliminan los subárboles primero con recursividad
    	eliminarArbol(raiz->hijo_der);

    	printf("\nEliminando nodo con dato: %s\n", raiz->dato);		// se imprime la eliminacion del nodo
    	free(raiz);							// se libera memoria
}

//------------------------BUSCAR NODO [1] ---------------------------------------------------------------
void buscarEImprimirNodo(NODO *raiz, char dato[]) {
    	printf("\n\nBuscando el nodo con valor '%s'...\n", dato);
    
    	NODO *encontrado = buscarNodo(raiz, dato);
    	if (encontrado != NULL) {
        	printf("Nodo encontrado: %s\n", encontrado->dato);
        	if (encontrado->padre) {
            		printf("Padre: %s\n", encontrado->padre->dato);
        	} else {
            		printf("El nodo no tiene padre (es la raíz).\n");
        	}
    	} else {
        	printf("Nodo con valor '%s' no encontrado.\n", dato);
    	}
}

//------------------------BUSCAR NODO  [2] -----------------------------------------------------------------
NODO* buscarNodo(NODO *raiz, char dato[]) {
    	if (raiz == NULL)  return NULL; 		// Si el árbol está vacío o no se encuentra el nodo, se devuelve nulo

    if (strcmp(raiz->dato, dato) == 0) {		// Si el dato coincide con el del nodo raiz, se devuelve el mismo nodo
        return raiz;
    }

    NODO *nodoIzq = buscarNodo(raiz->hijo_izq, dato);	// se busca recursivamente en el hijo izquierdo
    if (nodoIzq != NULL) {
        return nodoIzq; 				// Si se encuentra en el subárbol izquierdo, retornar
    }
				
    return buscarNodo(raiz->hijo_der, dato);		// se busca recursivamente en el hijo derecho
}

//------------------------BUSCAR RUTA NODO [1]-----------------------------------------------------------------
void buscarEImprimirNodoConPadres(NODO *raiz, char dato[]) {
    	printf("\n\nBuscando el nodo con valor '%s' y obteniendo sus padres...\n", dato);

    	NODO *padres[20];  // Array para almacenar los padres (puedes cambiar el tamaño si lo necesitas)
    	int numPadres = 0;  // Número de padres encontrados

    	NODO *encontrado = buscarNodoYPadres(raiz, dato, padres, &numPadres);
    	if (encontrado != NULL) {
        	printf("Mostrando ruta para el nodo encontrado: %s\n", encontrado->dato);

        	// Mostrar los padres desde el nodo encontrado hasta la raíz
        	if (numPadres > 0) {
            		printf("/");
            		for (int i = numPadres - 1; i >= 0; i--) {
                		printf("%s/", padres[i]->dato);
            		}
            		 printf("%s/\n", encontrado->dato);  // Añadimos el nodo actual al final
        	} else {
            		printf("El nodo no tiene padres (es la raíz).\n");
        	}
    	}
}

//------------------------BUSCAR RUTA NODO [2]-----------------------------------------------------------------
NODO* buscarNodoYPadres(NODO *raiz, char dato[], NODO **padres, int *numPadres) {
    	if (raiz == NULL) return NULL;  		// si el árbol está vacío o no se encuentra el nodo
    							
    	if (strcmp(raiz->dato, dato) == 0) {		// Si el dato coincide con el del nodo actual, retornamos el nodo
        
        	NODO *padreActual = raiz->padre;	// Obtenemos los padres
        	int i = 0;
        
		while (padreActual != NULL) {			 // Recorremos hacia arriba, recopilando los padres hasta la raíz
		    	padres[i++] = padreActual;
		    	padreActual = padreActual->padre;
        	}
        
		*numPadres = i;  				// Actualizamos el número de padres encontrados
		return raiz;  					// se devuelve el nodo encontrado
	}

    	// Buscar recursivamente en el hijo izquierdo
    	NODO *nodoIzq = buscarNodoYPadres(raiz->hijo_izq, dato, padres, numPadres);
    	if (nodoIzq != NULL) {
        	return nodoIzq;  // Si se encuentra en el subárbol izquierdo, retornar
    	}

    	// Buscar recursivamente en el hijo derecho
    	return buscarNodoYPadres(raiz->hijo_der, dato, padres, numPadres);
}
//------------------------RECORRER EN ORDEN-----------------------------------------------------------------
void recorrerEnOrden(NODO *nodo){
	if(nodo != NULL){
		recorrerEnOrden(nodo->hijo_izq);
		printf("\nSe accede al nodo con el dato %s", nodo->dato);
		recorrerEnOrden(nodo->hijo_der);
	}
}

//------------------------RECORRER EN PREORDEN---------------------------------------------------------------------
void recorrerEnPreorden(NODO *nodo){
	if(nodo != NULL){
		printf("\nSe accede al nodo con el dato %s", nodo->dato);
		recorrerEnPreorden(nodo->hijo_izq);
		recorrerEnPreorden(nodo->hijo_der);
	}
}
//------------------------RECORRER EN POSTORDEN---------------------------------------------------------------------
void recorrerEnPostorden(NODO *nodo){
	if(nodo != NULL){
		recorrerEnPostorden(nodo->hijo_izq);
		recorrerEnPostorden(nodo->hijo_der);
		printf("\nSe accede al nodo con el dato %s", nodo->dato);
	}
}

