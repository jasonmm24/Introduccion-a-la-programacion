/**
 * @file Programa6.c
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

#define TAM 50

void burbuja(int arr[], int tam);

void imprimir(int arr[]);

int main() {

    int arr[TAM];

    srand(time(NULL));

    for (int i = 0; i < TAM; i++) {

        arr[i] = rand() % 100000 + 1;

    }

    printf("Arreglo generado:\n");

    imprimir(arr);

    burbuja(arr, TAM);

    printf("Arreglo ordenado:\n");

    imprimir(arr);

    return 0;
}

/// @brief Ordena un areglo en orden decendente
/// @param arr el arreglo
/// @param tam tamaño del arreglo
void burbuja(int arr[], int tam) {

    if (tam == 1) {

        return;

    }

    for (int i = 0; i < tam - 1; i++) {

        if (arr[i] < arr[i+1]) {

            int temp = arr[i];

            arr[i] = arr[i+1];

            arr[i+1] = temp;

        }

    }

    burbuja(arr, tam - 1);

}

/// @brief Imprime un arreglo en pantalla
/// @param arr El arreglo
void imprimir(int arr[]){

    for (int i = 0; i < TAM; i++) {

        printf("%d ", arr[i]);

    }

    printf("\n");

}