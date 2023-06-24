/**
 * @file funciones.h
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyrigth GPlv3
 * 
 */

#include <stdio.h>

/// @brief Crea una matriz 3x3 con los datos dados por el usuario
/// @param A La matriz generada
void matriz3x3(float A[3][3]){

    printf("Ingrese los elementos de la matriz A: \n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

}

/// @brief Crea un vector a partir de los datos dados por el usuario
/// @param B El vector generado
void vector(float B[3]){

    printf("Ingrese los elementos del vector B: \n");
    for(int i=0; i<3; i++) {
        printf("B[%d] = ", i);
        scanf("%f", &B[i]);
    }

}

/// @brief Saca la inversa de una matriz 3x3
/// @param A la matriz a invertir
/// @param invA La matriz invertida
/// @param detA El determinante de A solo se requiere inicializar en 0
void matrizinversa(float A[3][3], float invA[3][3]){

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

}

/// @brief Calcula los valores de x1, x2 y x3 y los almacena en un vector 
/// @param X El vector de resultados
/// @param invA la inversa de la matriz 3x3
/// @param B el vector B
void resultados(float X[3], float invA[3][3], float B[3]){

    X[0] = invA[0][0] * B[0] + invA[0][1] * B[1] + invA[0][2] * B[2];
    X[1] = invA[1][0] * B[0] + invA[1][1] * B[1] + invA[1][2] * B[2];
    X[2] = invA[2][0] * B[0] + invA[2][1] * B[1] + invA[2][2] * B[2];

}
