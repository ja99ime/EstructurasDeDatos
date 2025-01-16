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


//------------------------CARGAR JUEGO--------------------------------------------------------------------
void cargarJuego(NODO **raiz){
 	// Creamos la raiz del jeugo
    	insertarNODO(raiz, NULL, 
    	"Entrada a la Mansión",
        "Te encuentras a las puertas de la inhóspita mansión. A la izquierda, la puerta principal te espera, imponente,\n"
        "como un muro de hormigón. A la derecha, tienes la entrada al jardín. Las zarzas recubren la valla de piedra,\n"
        "pero con algo de esfuerzo, podrías sortearla.\n\n", FALSE, 0, 0, 0, 0);
    
    	// Izquierda de la primera escena (intento de abrir la puerta)
    	insertarNODO(raiz, *raiz, 
    	"Puerta Principal",
    	"Cuando posas tus dedos sobre la puerta, descubres que esta cerrada con llave. Vas a necesitar algo más que\n"
        "audacia para entrar en la mansión y hacerte con el tesoro. \n\n", FALSE, 0, 1, 0, 0);
        
        // Izquierda de la segunda escena II (entrada)
    	insertarNODO(raiz, (*raiz)->hijo_izq, 
    	"Hall de la mansion",
    	"Estás en el recibidor, un aroma a humedad embarga tu olfato mientras buscas con la mirada a tu alrededor. Cerca \n"
    	"del recibidor, ves un cuelga llaves. Además, dos nuevos camminos se abren ante tí. El de la izquierda parece llevar \n"
    	"a un amplio salón mientras que el de la derecha, te conduce a una vieja cocina.\n\n", FALSE, 1, 0, 0, 0);  

    	
    	// Izquierda de la tercera escena II (salon)
    	insertarNODO(raiz, ((*raiz)->hijo_izq)->hijo_izq, 
    	"Salón de la mansion",
    	"Has llegado al nucleo de la mansión. Largas cortinas doradas cubiertas de polvo y alfombras granate se ocupan de ocultar\n"
    	"las enmohecidas maderas que componen la casa. Sin embargo, el desolado lugar y los vanidosos muebles que antaño, pudieron \n"
    	"ser alarde de riqueza no son lo que llama  tu atención. Un lamento mudo parece provenir del piso superior y escucharlo te \n"
    	"hiela la sangre. A la izquierda, las escaleras que suben al tercer piso te tientan con malicia a subir sus escalones. Por \n"
    	"otro lado, un poco más a la derecha ves una puerta que parece conducir al sotano. \n\n", FALSE, 0, 0, 0, 0);  

    	// Izquierda de la cuarta escena II (escaleras)
    	insertarNODO(raiz, (((*raiz)->hijo_izq)->hijo_izq)->hijo_izq, 
    	"Tercer Piso de la mansión",
    	"Mientras subes las escaleras, oyes una voz gutural pronunciar las siguientes palabras: \n\n"
    	"Sube tantos como hijos tuve.\n\n"
    	"Baja tantos como años viví en la trena. \n\n"
    	"Sube tantos como amistades leales logre. \n\n"
    	"Baja tantos como enemigos tuve que matar.\n\n"
    	"Y finalmente, sube uno por quintal de oro que en la habitación del tesoro te espera.\n\n", FALSE, 0, 0, 1, 0);  
    	
    	// Izquierda de la quinta escena II (desenlace)
    	insertarNODO(raiz, ((((*raiz)->hijo_izq)->hijo_izq)->hijo_izq)->hijo_izq, 
    	"Tercer Piso de la mansión",
    	"Llegas al tercer piso, donde un pasillo vacio se presenta ante tí con una unica puerta al fonde del corredor. Tu corazón late\n" 
    	"con fuerza mientras te acercas a la puerta. Quizás el viaje merezca la pena si abres la puerta. \n\n", FALSE, 0, 1, 0, 0); 
    	
    	// Izquierda de la quinta escena II (final)
    	insertarNODO(raiz, (((((*raiz)->hijo_izq)->hijo_izq)->hijo_izq)->hijo_izq)->hijo_izq, 
    	"Sala del tesoro",
    	"Entras en la habitacion y al instante, el oro y las joyas iluminan la habitación. Ni siquiera eres capaz de concebir la riqueza \n"
    	"que acabas de conseguir. Ahora el tesoro de la mansión te pertenece y no habrá nadie que pueda arrebatarterlo."
    	"Te lanzas contra la montaña de monedas doradas mientras te embarga la emoción.\n\n" 
    	"[FINAL BUENO: Asquerosamente rico]", FALSE, 0, 0, 0, 1); 
    	
    	// Izquierda de la quinta escena II (FINAL E)
    	insertarNODO(raiz, ((((*raiz)->hijo_izq)->hijo_izq)->hijo_izq)->hijo_izq, 
    	"Eternidad",
    	"Tus pies empiezan a vacilar mientras tu mente se oscurece. Los escalones suben infinitamente hacia un vacio eterno, mientras,\n"
    	"hacia abajo, un abismo sombrío amenaza con tragarte. Tratas de huir de tu inminente destino, pero resulta imposible. Empiezas \n"
    	"a plantearte tus últimas decisiones mientras un chillido ensordecedor taladra tus timpanos\n." 
    	"Finalmente, tropiezas en un mal paso y caes a traves de las sombras. \n\n"
    	"[FINAL MALO: Un oscuro traspie]", TRUE, 0, 0, 0, 1); 
    	
    	
    	// Derecha de la cuarta escena II (salon)
    	insertarNODO(raiz, (((*raiz)->hijo_izq)->hijo_izq)->hijo_izq, 
    	"Sotano de la mansion",
    	"En el sotano, la oscuridad es casi total. Casi. Pues en lo más profundo de la estancia, una vela ilumina una trampilla cerrada. \n"
    	"Al acercate, descubres que tiene un cerrojo. Escuchas un bramido ronco venir de las profundidades.\n\n", TRUE, 0, 1, 0, 0);  

    	// Descenso(FINAL D)
    	insertarNODO(raiz, ((((*raiz)->hijo_izq)->hijo_izq)->hijo_izq)->hijo_der, 
    	"Profundidades",
    	"Bajaste por la trampilla y descendiste por una escalera de mano durante varios minutos. Al principio, parecía una buena idea,\n"
    	"pero cuando la poca luz que veía de arriba se desvaneció y el único camino se convirtió en continuar bajando, tu determinación\n"
    	"comenzó a vacilar. Con las manos temblorosas, bajaste las escalerillas hasta que algo toco tu pierna\n."
    	"Cientos de dedos huesudos te arrastraron a las tinieblas\n\n"
    	"[FINAL MALO: Descenso al abismo]", FALSE, 0, 0, 0, 1);  


        // Derecha de la tercera escena II (cocina)
    	insertarNODO(raiz, ((*raiz)->hijo_izq)->hijo_izq, 
    	"Cocina de la mansion",
    	"Entras atraido por un aroma peculiar. Cuando traspasas el marco de la puerta, te sorprende encontrarte con dos bandejas\n"
    	"de plata encima de una mesilla movil. Tienes mucha hambre... Quizás, por probar..\n\n", TRUE, 0, 0, 0, 0);  
    	
    	// Bandeja Izquierda (cocina)
    	insertarNODO(raiz, (((*raiz)->hijo_izq)->hijo_izq)->hijo_der, 
    	"Cocina de la mansion",
    	"Al destapar la bandeja, te encuentras un enorme chuletón de tenera. Antes de devoralo, te percatas de algo peculitar y decides\n"
    	"contener tu apetito. Escrito con sangre, ves el código: 31157 sobre la carne recien hecha.\n\n", FALSE, 0, 0, 0, 0);  
    	
    	// Bandeja Derecha (FINAL C)
    	insertarNODO(raiz, (((*raiz)->hijo_izq)->hijo_izq)->hijo_der, 
    	"Cocina de la mansion",
    	"Al destapar la bandeja, ves lo que parece una triste alcachofa. Tus ojos se entrecierran, incapaz de comprender el porque,\n"
    	"pero, por desgracia, ni siquiera tienes el tiempo de procesarlo. De la alcachofa, comienzan a brotar otros productos naturales,\n"
    	"aumentando de manera exponencial el tamaño de la aberrante amalgama vegetal y tomando tras unos segundos, la forma de un grotesco\n"
	"monstruo. Cuando finalmente reaccionas, es muy tarde. En sus ojos de olivas ves el vacío.\n"
	"Tu cuerpo se descompone en vegetales y hortalizas.\n\n"
    	"[FINAL MALO: El alcachofimonstruo]", TRUE, 0, 0, 0, 1);  


    	// Derecha de la primera escena (rodear la mansion)
    	insertarNODO(raiz, *raiz, 
    	"Jardín",
    	"Estás en el lugubre jardín. Mientras escuchas el canto sobrenatural de los pájaros, te das cuenta de que, a tu\n"
    	"izquierda, en uno de los arboles cercanos, hay un enorme nido en una de las ramas más altas. Por otro lado, al \n" 
    	"voltear tu cabeza hacia la derecha, ves un viejo cobertizo.\n\n", TRUE, 0, 0, 0, 0);
	
    	// Izquierda de la segunda escena (FINAL A)
    	insertarNODO(raiz, (*raiz)->hijo_der, 
    	"Nido de Cuervos",
    	"Una bandada de cuervos se percata de tus acciones y se abalanza contra tí. Lo que de lejos parecían ser pájaros \n"
    	"inofensivos, han resultado ser criaturas voraces y terriblemente agresivas. \n"
    	"Pierdes la visión entre plumas y picotazos.\n\n"
    	"[FINAL MALO: Comida de pajaros]", FALSE, 0, 0, 0, 1);  

	
    	// Derecha de la segunda escena (cobertizo)
    	insertarNODO(raiz, (*raiz)->hijo_der,
    	"Viejo cobertizo (Exterior)",
    	"La madera vieja y destartalada que constituye el cobertizo cruje con el viento. No sabes porqué, pero sientes un \n"
    	"peso desvanecerse de tu pecho. A la izquierda, tienes la ventana. Podrías intentar romperla y pasar a través de ella\n"
    	"aunque la puerta a tu derecha no parece cerrada. La decisión es tuya\n\n", TRUE, 0, 0, 0, 0); 
    	
    	// Izquierda de la tercera escena (FINAL B)
    	insertarNODO(raiz, ((*raiz)->hijo_der)->hijo_der,
    	"Viejo cobertizo (Exterior)",
    	"Romper la ventana no solo fue complicado, sino también, engorroso. Tras varios intentos de hacerla pedazos, el ruido \n"
    	"que provocastes ha atraido la atención de algunas de las criaturas que habitan el jardín. Asustado, decidiste saltar \n"
    	"hacia el interior con todas tus fuerzas, pero por desgracia, varios cristales perforaron tu estomago y rasgaron tus \n"
    	"brazos. Adolorido, ves una llave en el medio del salón, pero cuando tratas de alcanzarla, te derrumbas. Las profundas \n"
    	"laceraciones arden en tu piel y no parece que te quede mucho tiempo de vida\n\n"
    	"[FINAL MALO: El ataque de los Cristaloides]", FALSE, 0, 0, 0, 1); 
    	
    	// Derecha de la tercera escena (cobertizo  dentro)
    	insertarNODO(raiz, ((*raiz)->hijo_der)->hijo_der,
    	"Viejo cobertizo (Interior)",
    	"Abres la puerta sin mayor dificultad, encontrando multiples herramientas de trabajo y artilugios de autodefensa. Sin \n"
    	"embargo, eso le quitaría la gracia a invadir una terrorífica mansión, ¿verdad? \n\n", TRUE, 1, 0, 0, 0); 

}

//------------------------MOVERSE--------------------------------------------------------------------

NODO* mover(NODO *actual, int direccion) {

    	if (direccion == 1 && actual->hijo_izq != NULL && actual->llaveRequerida == 0) { 	// El pesonaje se mueve hacia la izquierda
        	return actual->hijo_izq;
        	
    	} else if (direccion == 2 && actual->hijo_der && actual->llaveRequerida == 0) {		// El pesonaje se mueve hacia la derecha
        	return actual->hijo_der;
        	
    	} else if (direccion == 3 && actual->padre != NULL) {					// El pesonaje retrocede
        	return actual->padre;
    	}
    	
    	printf("No puedes avanzar más.\n");
    	return actual;  							// Si no es posible moverse, quedarse en el nodo actual.
}

//------------------------REVISAR ESCENARIO----------------------------------------------------------------


void revisarEscenario(NODO *actual, int llaves) {
    	printf("%-90s Llaves: %d\n\n", actual->nombreEscenario, llaves);
   	 printf("%s\n", actual->descripcion);
    	if (actual->hayLlave) {
        	printf("¡Has encontrado una llave!\n");
    	}
}

//------------------------LLAVES----------------------------------------------------------------
void recogerLlave(NODO *actual, int *llaves) {
    	if (actual->hayLlave) {
        	printf("Has recogido una llave.\n");
        	actual->hayLlave = 0;
    	} else {
        	printf("No hay llaves aquí.\n");
    	}
}

//------------------------PUERTAS---------------------------------------------------------------
int abrirPuerta(NODO *actual, int *llaves) {
    	if (actual->llaveRequerida) {
        	if (*llaves!=0) {
            		printf("¡Has abierto la puerta!\n");
            		actual->llaveRequerida = 0;  // Puerta abierto
            		return 1;
       		} else {
            		printf("No tienes la llave necesaria para abrir este cofre.\n");
            		return 0;
        	}
    	} else {
       	 	printf("No hay cofres aquí.\n");
    	}
}

//------------------------COFRES----------------------------------------------------------------
int puzzle(NODO *actual) {
    	int num;
    	if (actual->hayPuzzle) {
		printf("\n¿Cuantos subes?: ");
    		scanf(" %d", &num);
    		if (num!=3)	return FALSE;
    		printf("\n¿Cuantos bajas?: ");
    		scanf(" %d", &num);
    		if (num!=1)	return FALSE;
    		printf("\n¿Cuantos subes?: ");
    		scanf(" %d", &num);
    		if (num!=1)	return FALSE;
    		printf("\n¿Cuantos bajas?: ");
    		scanf(" %d", &num);
    		if (num!=5)	return FALSE;
    		printf("\n¿Cuantos subes?: ");
    		scanf(" %d", &num);
    		if (num!=7)	return FALSE;

    		return TRUE;
    		
    	} else {
       	 	printf("No hay cofres aquí.\n");
       	 	return FALSE;
    	}
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

//------------------------INSERTAR NODO--------------------------------------------------------------------
int insertarNODO(NODO **raiz, NODO *padre, char dato1[], char dato2[], int derecha, int llav, int cerr, int puzz, int final){
	NODO  *nuevo;
	
	if (comprobarInserccion(*raiz, padre, derecha) == TRUE){ 	// se puede proceder a la insercion
		nuevo = (NODO *) malloc (sizeof(NODO));			// se crea el espacio de la memoria
		if (nuevo == NULL)	return FALSE;
		
		// Se establecen los valores del hijo
		strcpy(nuevo->nombreEscenario, dato1);			// copiamos el nuevo daro al valor de nuevo
		strcpy(nuevo->descripcion, dato2);
		nuevo->hayPuzzle = puzz;
		nuevo->hayLlave = llav;
		nuevo->llaveRequerida = cerr;
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
        	
        	printf("\nEliminando nodo con dato: %s\n", nodo->nombreEscenario);	
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

    	printf("\nEliminando nodo con dato: %s\n", raiz->nombreEscenario);	// se imprime la eliminacion del nodo
    	free(raiz);								// se libera memoria
}


