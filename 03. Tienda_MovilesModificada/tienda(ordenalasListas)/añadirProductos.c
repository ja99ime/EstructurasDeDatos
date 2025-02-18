#include <stdio.h>
#include <string.h>
#include "utilidades.h"  // Asegúrate de tener utilidades.h en el mismo directorio

int main() {
    // Definición de los productos
    struct Movil productos[15] = {
        {1, "XiaomiMi11", "gamaMedia", "Usado", 499.99, "Xiaomi", "Mi11", "Blanco", 6.81, 128, 6},
        {2, "GalaxyS21", "gamaMedia", "Nuevo", 799.99, "Samsung", "GalaxyS21", "Azul", 6.20, 256, 8},
        {3, "iPhone12", "gamaAlta", "Nuevo", 899.99, "Apple", "iPhone12", "Negro", 6.10, 128, 4},
        {4, "OnePlus9", "gamaAlta", "Nuevo", 749.99, "OnePlus", "OnePlus9", "Verde", 6.55, 256, 12},
        {5, "HuaweiP40", "gamaAlta", "Usado", 599.99, "Huawei", "P40", "Gris", 6.10, 128, 8},
        {6, "GooglePixel6", "gamaAlta", "Nuevo", 899.00, "Google", "Pixel6", "Blanco", 6.40, 128, 8},
        {7, "XiaomiRedmiNote11", "gamaMedia", "Usado", 269.99, "Xiaomi", "RedmiNote11", "Negro", 6.43, 64, 4},
        {8, "SamsungA52", "gamaMedia", "Nuevo", 399.99, "Samsung", "A52", "Azul", 6.50, 128, 6},
        {9, "iPhone13", "gamaAlta", "Nuevo", 1099.99, "Apple", "iPhone13", "Azul", 6.10, 256, 6},
        {10, "MotorolaEdge20", "gamaMedia", "Nuevo", 499.99, "Motorola", "Edge20", "Blanco", 6.70, 128, 8},
        {11, "RealmeGT", "gamaAlta", "Usado", 649.99, "Realme", "GT", "Rojo", 6.43, 256, 12},
        {12, "NokiaX20", "gamaMedia", "Usado", 349.99, "Nokia", "X20", "Azul", 6.67, 128, 6},
        {13, "OppoFindX3", "gamaAlta", "Nuevo", 999.99, "Oppo", "FindX3", "Blanco", 6.70, 256, 12},
        {14, "SonyXperia10", "gamaMedia", "Usado", 399.99, "Sony", "Xperia10", "Negro", 6.00, 128, 4},
        {15, "LGV60", "gamaAlta", "Nuevo", 799.99, "LG", "V60", "Gris", 6.80, 128, 8}
    };

    // Guardamos los productos en el archivo binario
    guardarProductos(productos, 15);

    printf("Archivo binario creado exitosamente con los productos iniciales.\n");
    return 0;
}