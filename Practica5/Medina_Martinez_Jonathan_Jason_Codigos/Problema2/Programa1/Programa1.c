/**
 * @file Programa1.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyrigth GPlv3
 * 
 */


#include <stdio.h>


void imprimir(int m, int n);

int main() {

    int n = 0;

    printf("Ingresa un numero entero: ");

    scanf("%d", &n);

    printf("Los numeros en incrementos de 3 son: ");

    imprimir(1, n);

    printf("\n");

    return 0;

}


/// @brief Funcion que imprime una secuencia de numeros en incrementos de 3 desde uno hasta un numero dado
/// @param n El valor de final
/// @param m El inicio de la secuencia.
void imprimir(int m, int n) {

    if (m > n) {

        return;

    }

    printf("%d", m);

    if (m != n) {

        printf(", ");

    }

    imprimir(m + 3, n);

}
