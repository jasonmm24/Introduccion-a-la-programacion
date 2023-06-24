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

    float A[3][3] = {{2, -4, -3}, {1, 5, -5}, {4, 2, 67}};

    float B[3] = {15, 5, 20};

    float invA[3][3];

    float X[3];

    invertirMatrizA(A, invA);

    generarvectorx(X, invA, B);

    imprimirresultado(X);

    return 0;
}
