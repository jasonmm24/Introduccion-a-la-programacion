/**
 * @file programa3.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-03-24
 * 
 * @copyrigth GPlv3
 * 
 */

#include <stdio.h>
#include "funciones.h"

int main() {
    float A[3][3],  B[3], invA[3][3], X[3];

    printf("Calculadora de sistemas de ecuaciones lineales 3x3\n\n");
    printf("Ejemplo de sistema de ecuaciones lineales 3x3:\n");
    printf("A[0][0]x + A[0][1]y + A[0][2]z = B[1]\n");
    printf("A[1][0]x + A[1][1]y + A[1][2]z = B[2]\n");
    printf("A[2][0]x + A[2][1]y + A[2][2]z = B[3]\n\n");

    matriz3x3(A);

    vector(B);

    matrizinversa(A, invA);

    resultados(X, invA, B);

    printf("La solucion es: \n");
    printf("x = %f \n", X[0]);
    printf("y = %f \n", X[1]);
    printf("z = %f \n", X[2]);
    getc(stdin);

    return 0;
}