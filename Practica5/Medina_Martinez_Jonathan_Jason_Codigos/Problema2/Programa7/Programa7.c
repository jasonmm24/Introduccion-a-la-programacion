/**
 * @file Programa7.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-04-22
 * 
 * @copyrigth GPlv3
 * 
 */

#include <stdio.h>

void hailstone(int n);

int main() {
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    hailstone(n);
    return 0;
}

/// @brief Funcion que genera la serie de hailstone a partir de un numero entero dado
/// @param n el numero dado
void hailstone(int n) {

    printf("%d ", n);

    if (n == 1) {

        return;

    } else if (n % 2 == 0) {

        hailstone(n / 2);

    } else {

        hailstone(3 * n + 1);

    }

}
