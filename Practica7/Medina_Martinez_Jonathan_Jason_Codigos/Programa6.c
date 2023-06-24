/**
 * @file Programa6.c
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
#include <time.h>

void generarNumerosAleatorios(int *arreglo, int n);

void ordenarArreglo(int *arreglo, int n);

void imprimirArreglo(int *arreglo, int n);

int main() {
    int n;
    int *arreglo;

    printf("Ingrese la cantidad de numeros a generar: ");
    scanf("%d", &n);

    arreglo = (int *)malloc(n * sizeof(int));

    if (arreglo == NULL) {
        printf("Error al asignar memoria.");
        return 1;
    }

    generarNumerosAleatorios(arreglo, n);

    printf("Arreglo generado:\n");
    imprimirArreglo(arreglo, n);

    ordenarArreglo(arreglo, n);

    printf("Arreglo ordenado:\n");
    imprimirArreglo(arreglo, n);

    free(arreglo);

    return 0;
}

/// @brief Genera numeros pseudoaleatorios y los almacena en un arreglo.
/// @param arreglo El arreglo donde se almacenaran los numeros generados.
/// @param n La cantidad de numeros a generar.
void generarNumerosAleatorios(int *arreglo, int n) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        arreglo[i] = rand() % 2001 - 1000;
    }
}

/// @brief Ordena un arreglo de menor a mayor.
/// @param arreglo El arreglo a ordenar.
/// @param n La longitud del arreglo.
void ordenarArreglo(int *arreglo, int n) {
    int *p, *q, temp;

    for (p = arreglo; p < arreglo + n - 1; p++) {
        for (q = p + 1; q < arreglo + n; q++) {
            if (*p > *q) {
                temp = *p;
                *p = *q;
                *q = temp;
            }
        }
    }
}

/// @brief Imprime los elementos de un arreglo.
/// @param arreglo El arreglo a imprimir.
/// @param n La longitud del arreglo.
void imprimirArreglo(int *arreglo, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}