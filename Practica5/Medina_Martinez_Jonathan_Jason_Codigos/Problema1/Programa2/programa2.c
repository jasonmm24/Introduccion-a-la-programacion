/**
 * @file programa2.c
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
    int A[3][3], B[3][3], C[3][3];

    char text1[] = "Ingrese los elementos de la matriz A:";
    imprimir_texto(text1);
    pedir_elementos(A);

    char text2[] = "Ingrese los elementos de la matriz B:";
    imprimir_texto(text2);
    pedir_elementos(B);

    char text3[] = "La suma de A + B es:";
    imprimir_texto(text3);
    suma_matrices(A, B, C);
    imprimir_matriz(C);

    char text4[] = "La resta de A - B es:";
    imprimir_texto(text4);
    resta_matrices(A, B, C);
    imprimir_matriz(C);

    char text5[] = "La multiplicacion de A x B es:";
    imprimir_texto(text5);
    multiplicacion_matrices(A, B, C);
    imprimir_matriz(C);

    return 0;
}
