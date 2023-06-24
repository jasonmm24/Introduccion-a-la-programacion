/**
 * @file programa6.c
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
    int n, i = 1;
    int fac = 1;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    while (i <= n) {
        fac *= i;
        i++;
    }
    printf("El factorial de %d es: %d\n", n, fac);
    return 0;
}
