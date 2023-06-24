/**
 * @file Programa4.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-04-22
 * 
 * @copyrigth GPlv3
 * 
 */

#include <stdio.h>

void contar(int n, int *suma);

int main() {

    int n = 0, suma = 0;

    printf("Ingrese un numero entero: ");
    scanf("%d", &n);

    contar(n, &suma);

    printf("El numero %d tiene %d digitos\n", n, suma);

    return 0;

}

/// @brief Funcion que cuenta los digitos de un numero entero
/// @param n El numero entero
/// @param suma variable para almacenar la cuenta
void contar(int n, int *suma) {

    if (n != 0) {

        (*suma)++;

        contar(n / 10, suma);

    }

}
