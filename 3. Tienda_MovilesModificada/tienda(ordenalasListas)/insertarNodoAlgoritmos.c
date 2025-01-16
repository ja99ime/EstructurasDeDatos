void burbuja(nodo **inicio) {
    	if (*inicio == NULL || (*inicio)->siguiente == NULL) {
        	return; // La lista está vacía o tiene solo un nodo
    	}

    	nodo *i, *j;
    	int swap;
    
    	do {
        	swap = 0;
        	i = *inicio;
        
        	while (i != NULL && i->siguiente != NULL) {
            		j = i->siguiente;
            
            		// Si el código de i es mayor que el código de j, los intercambiamos
            		if (i->productos.codigo > j->productos.codigo) {
                		// Intercambiar los productos entre los nodos
				struct Movil temp = i->productos;
				i->productos = j->productos;
				j->productos = temp;
				
                		swap = 1;
            		}
            
            		i = i->siguiente;
        	}
    	} while (swap); // Repetir hasta que no haya más intercambios
}