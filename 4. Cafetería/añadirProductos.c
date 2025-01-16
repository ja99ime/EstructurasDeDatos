#include <stdio.h>
#include <string.h>

// Definición del struct BEBIDAS
struct BEBIDAS {
	int codigo;
    	char nombre[30];
    	char estado[10]; // Frío o caliente
    	float precio;
};

// Función para guardar las bebidas en un archivo binario
void guardarBebidas(struct BEBIDAS bebidas[], int cantidad) {
    FILE *archivo = fopen("bebidas.dat", "wb"); // Abre el archivo en modo binario de escritura
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    fwrite(bebidas, sizeof(struct BEBIDAS), cantidad, archivo); // Escribe las bebidas en el archivo
    fclose(archivo); // Cierra el archivo
    printf("Bebidas guardadas en el archivo binario exitosamente.\n");
}

int main() {
    // Definición de las bebidas
    struct BEBIDAS bebidas[10] = {
        {5, "CocaCola", "Frio", 1.50},
        {1, "Cafe", "Caliente", 2.00},
        {2, "Te", "Caliente", 1.80},
        {6, "Limonada", "Frio", 1.20},
        {7, "Cerveza", "Frio", 3.00},
        {8, "Agua", "Frio", 0.90},
        {3, "Chocolate", "Caliente", 2.50},
        {9, "Smoothie", "Frio", 4.00},
        {10, "Leche", "Frio", 1.10},
        {4, "Sopa", "Caliente", 2.80}
    };

    // Guardamos las bebidas en el archivo binario
    guardarBebidas(bebidas, 10);

    printf("Archivo binario creado exitosamente con las bebidas iniciales.\n");
    return 0;
}