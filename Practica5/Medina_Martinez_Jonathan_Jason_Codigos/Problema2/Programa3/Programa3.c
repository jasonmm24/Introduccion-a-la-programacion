/**
 * @file Programa3.c
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

#define ARR 20

#define MIN 50

#define MAX 500

void valor_maximo(int arr[], int n, int *maximo);

void valor_minimo(int arr[], int n, int *minimo);

int main() {

    int arr[ARR];

    int maximo = 0;
    int minimo = 0;

    srand(time(NULL));

    for (int i = 0; i < ARR; i++) {

        arr[i] = rand() % (MAX - MIN + 1) + MIN;

    }

    printf("Arreglo generado:\n");

    for (int i = 0; i < ARR; i++) {

        printf("%d ", arr[i]);

    }
    printf("\n");

    valor_maximo(arr, ARR, &maximo);

    valor_minimo(arr, ARR, &minimo);

    printf("Elemento mas grande: %d\n", maximo);

    printf("Elemento mas pequeno: %d\n", minimo);

    return 0;

}

/// @brief funcion que obtiene el valor maximo de un arreglo
/// @param arr el arreglo
/// @param n el lugar a evaluar
/// @param maximo el valor maximo
void valor_maximo(int arr[], int n, int *maximo) {

    if (n == 1) {

        *maximo = arr[0];

    } else {

        valor_maximo(arr, n - 1, maximo);

        if (arr[n - 1] > *maximo) {

            *maximo = arr[n - 1];

        }

    }

}

/// @brief funcion que obtiene el valor minimo de un arreglo
/// @param arr el arreglo
/// @param n el lugar a evaluar
/// @param minimo el valor minimo
void valor_minimo(int arr[], int n, int *minimo) {

    if (n == 1) {

        *minimo = arr[0];

    } else {

        valor_minimo(arr, n - 1, minimo);

        if (arr[n - 1] < *minimo) {

            *minimo = arr[n - 1];

        }

    }

}