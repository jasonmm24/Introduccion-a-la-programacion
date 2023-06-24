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

int main() {
    float A[3][3];
    float B[3];

    printf("Calculadora de sistemas de ecuaciones lineales 3x3\n\n");
    printf("Ejemplo de sistema de ecuaciones lineales 3x3:\n");
    printf("A[0][0]x + A[0][1]y + A[0][2]z = B[1]\n");
    printf("A[1][0]x + A[1][1]y + A[1][2]z = B[2]\n");
    printf("A[2][0]x + A[2][1]y + A[2][2]z = B[3]\n\n");

    printf("Ingrese los elementos de la matriz A: \n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    printf("Ingrese los elementos del vector B: \n");
    for(int i=0; i<3; i++) {
        printf("B[%d] = ", i);
        scanf("%f", &B[i]);
    }

    float invA[3][3];
    float detA = A[0][0] * (A[1][1] * A[2][2] - A[2][1] * A[1][2])
               - A[0][1] * (A[1][0] * A[2][2] - A[2][0] * A[1][2])
               + A[0][2] * (A[1][0] * A[2][1] - A[2][0] * A[1][1]);

    invA[0][0] = (A[1][1] * A[2][2] - A[2][1] * A[1][2]) / detA;
    invA[0][1] = (A[0][2] * A[2][1] - A[2][2] * A[0][1]) / detA;
    invA[0][2] = (A[0][1] * A[1][2] - A[1][1] * A[0][2]) / detA;

    invA[1][0] = (A[1][2] * A[2][0] - A[2][2] * A[1][0]) / detA;
    invA[1][1] = (A[0][0] * A[2][2] - A[2][0] * A[0][2]) / detA;
    invA[1][2] = (A[0][2] * A[1][0] - A[1][2] * A[0][0]) / detA;

    invA[2][0] = (A[1][0] * A[2][1] - A[2][0] * A[1][1]) / detA;
    invA[2][1] = (A[0][1] * A[2][0] - A[2][1] * A[0][0]) / detA;
    invA[2][2] = (A[0][0] * A[1][1] - A[1][0] * A[0][1]) / detA;

    float X[3];
    X[0] = invA[0][0] * B[0] + invA[0][1] * B[1] + invA[0][2] * B[2];
    X[1] = invA[1][0] * B[0] + invA[1][1] * B[1] + invA[1][2] * B[2];
    X[2] = invA[2][0] * B[0] + invA[2][1] * B[1] + invA[2][2] * B[2];

    printf("La solucion es: \n");
    printf("x = %f \n", X[0]);
    printf("y = %f \n", X[1]);
    printf("z = %f \n", X[2]);

    return 0;
}