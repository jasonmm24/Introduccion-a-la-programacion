/**
 * @file Programa9.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-04-22
 * 
 * @copyrigth GPlv3
 * 
 */

#include <stdio.h>

void fibonacci(int num1, int num2, int total);

int main() {
    int num1, num2, total;
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    printf("Ingrese el numero de elementos: ");
    scanf("%d", &total);
    printf("%d %d ", num1, num2);
    fibonacci(num1, num2, total-2);
    return 0;
}

/// @brief Funcion que genera una secuencia de fibonacci
/// @param num1 el primer numero de la secuencia
/// @param num2 el segundo numero de la secuencia
/// @param total la cantidad de elementos a calcular
void fibonacci(int num1, int num2, int total) {
    if (total == 0) {
        return;
    }
    int next = num1 + num2;
    printf("%d ", next);
    fibonacci(num2, next, total-1);
}
