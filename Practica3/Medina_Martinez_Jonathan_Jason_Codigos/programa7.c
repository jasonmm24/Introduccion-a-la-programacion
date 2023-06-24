/**
 * @file programa7.c
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
    int n, i, num = 1, div = 1;
    float suma = 0;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        suma += (float)num / div;
        printf("%d/%d, ", num, div);
        div++;
    }
    printf("\nLa suma de los %d terminos es: %f\n", n, suma/n);
    return 0;
}

