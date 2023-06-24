/**
 * @file programa3.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-03-14
 * 
 * @copyright GLP v3
 * 
 */

#include <stdio.h>

int main() {
    int n, i;
    int a = 0, b = 1, temp;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    printf("Sucesion de Fibonacci hasta el termino es: %d\n", n);
    printf("%d, %d, ", a, b);
    for (i = 3; i <= n; i++) {
        temp = a + b;
        printf("%d, ", temp);
        a = b;
        b = temp;
    }
    printf("\n");
    return 0;
}

