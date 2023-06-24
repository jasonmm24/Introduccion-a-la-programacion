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

void pedir_elementos(int matriz[3][3]);
void suma_matrices(int matrizA[3][3], int matrizB[3][3], int matrizC[3][3]);
void resta_matrices(int matrizA[3][3], int matrizB[3][3], int matrizC[3][3]);
void multiplicacion_matrices(int matrizA[3][3], int matrizB[3][3], int matrizC[3][3]);
void imprimir_matriz(int matrizC[3][3]);
void imprimir_texto(char text[]);

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

/// @brief Pide los elementos de la matriz
/// @param matriz La matriz en la que se guardan los elementos
void pedir_elementos(int matriz[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

/// @brief Suma 2 matrices
/// @param matrizA Una de las matrices a sumar
/// @param matrizB Una de las matrices a sumar
/// @param matrizC La matriz resultante de la suma
void suma_matrices(int matrizA[3][3], int matrizB[3][3], int matrizC[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}

/// @brief Resta 2 matrices
/// @param matrizA Una de las matrices a restar
/// @param matrizB Una de las matrices a restar
/// @param matrizC La matriz resultante de la resta
void resta_matrices(int matrizA[3][3], int matrizB[3][3], int matrizC[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrizC[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }
}

/// @brief Multiplica 2 matrices
/// @param matrizA Una de las matrices a multiplicar
/// @param matrizB Una de las matrices a multiplicar
/// @param matrizC La matriz resultante de la multiplicacion
void multiplicacion_matrices(int matrizA[3][3], int matrizB[3][3], int matrizC[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrizC[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

/// @brief Imprime una matriz
/// @param matrizC 
void imprimir_matriz(int matrizC[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%4d ", matrizC[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/// @brief Imprime un texto
/// @param text el texto a imprimir
void imprimir_texto(char text[]) {
    printf("\n\n%s\n\n", text);
}