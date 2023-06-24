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

    float A[3][3] = {{2, -4, -3}, {1, 5, -5}, {4, 2, 67}};
    float B[3] = {15, 5, 20};

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
