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



int main(){

	NODO *raiz = NULL;

	cargarJuego(&raiz);

    	jugar(raiz);
    	
    	return 1;
}