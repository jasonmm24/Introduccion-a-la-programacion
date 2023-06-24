/**
 * @file Programa5.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-04-22
 * 
 * @copyrigth GPlv3
 * 
 */

#include <stdio.h>

void suma(int n, int *sum);

int main() {

    int n = 0, sum = 0;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &n);
    suma(n, &sum);
    printf("La suma de los digitos de %d es %d.\n", n, sum);

    return 0;

}

/// @brief suma digito a digito un numero entero
/// @param n el numero entero
/// @param sum la suma
void suma(int n, int *sum) {

    if (n == 0) {

        return;

    } else {

        *sum += n % 10;

        suma(n / 10, sum);

    }

}
