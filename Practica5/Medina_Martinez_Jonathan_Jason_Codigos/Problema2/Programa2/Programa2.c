/**
 * @file Programa2.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-04-22
 * 
 * @copyrigth GPlv3
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

void generar(int arr[], int n);

void imprimir(int arr[]);

int main() {

    int arr[MAX];

    srand(time(NULL));

    generar(arr, 0);

    imprimir(arr);

    return 0;

}

/// @brief Funcion que genera un arreglo de 20 elementos pseudoaleatorios de 10 a 100
/// @param arr el arreglo generado
/// @param n variable para almacenar la pocicion dentro del arreglo
void generar(int arr[], int n) {

    if (n < MAX) {

    arr[n] = rand() % 91 + 10;
    generar(arr, n + 1);

    }

}

/// @brief Programa que imprime un arreglo
/// @param arr el arreglo a imprimir
void imprimir(int arr[]) {

    printf("Los elementos del arreglo son:\n");

    for (int i = 0; i < MAX; i++) {

        printf("%d ", arr[i]);

    }

    printf("\n");

}
