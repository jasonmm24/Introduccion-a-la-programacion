/**
 * @file programa8.c
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
    int n = 0, i = 1, num = 1, div = 1;
    float suma = 0;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    printf("Terminos de la serie armonica: ");
    while (i <= n) {
        suma += (float)num / div; 
        printf("%d/%d, ", (int)num, (int)div);
        div++; 
        i++; 
    }
    printf("\nLa suma de los %d terminos es: %.3f\n", n, suma);
    return 0;
}
