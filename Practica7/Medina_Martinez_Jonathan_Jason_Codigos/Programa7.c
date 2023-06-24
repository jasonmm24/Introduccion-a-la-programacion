/**
 * @file Programa7.c
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

int calcularSuma(int *arreglo, int n);

int main() {
    int n;

    printf("Ingrese la cantidad de numeros: ");
    scanf("%d", &n);

    int *arreglo = (int *)malloc(n * sizeof(int));

    if (arreglo == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    printf("Ingrese los numeros:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arreglo[i]);
    }

    int suma = calcularSuma(arreglo, n);

    printf("La suma de los numeros es: %d\n", suma);

    free(arreglo);

    return 0;
}

/// @brief Calcula la suma de los elementos de un arreglo.
/// @param arreglo El arreglo de numeros.
/// @param n La longitud del arreglo.
/// @return La suma de los elementos del arreglo.
int calcularSuma(int *arreglo, int n) {
    int suma = 0;
    int *p = arreglo;

    for (int i = 0; i < n; i++) {
        suma += *p;
        p++;
    }

    return suma;
}