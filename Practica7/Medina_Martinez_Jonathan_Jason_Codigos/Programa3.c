/**
 * @file Programa3.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-05-20
 * 
 * @copyrigth GPlv3
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    printf("Ingrese la cantidad de numeros a almacenar: ");
    scanf("%d", &n);
    
    int *arreglo = (int *)malloc(n * sizeof(int));
    
    if (arreglo == NULL) {
        printf("Error al asignar memoria.");
        return 1;
    }
    
    printf("Ingrese los numeros:\n");
    
    for (int i = 0; i < n; i++) {
        scanf("%d", arreglo + i);
    }
    
    printf("Contenido del arreglo:\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arreglo + i));
    }
    
    free(arreglo);
    
    return 0;
}
