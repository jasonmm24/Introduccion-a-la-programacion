/**
 * @file programa4.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-03-05
 * 
 * @copyright GLP v3
 * 
 */

#include <stdio.h>

int main()
{
    int numero = 0;
    printf("\n\nIngrese un numero: ");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        printf("\n\nComprobado con modulo: %d es un numero par\n\n", numero);
    } else {
        printf("\n\nComprobado con modulo: %d es un numero impar\n\n", numero);
    }

    (numero % 2 == 0 && printf("Comprobado con AND: %d es un numero par\n\n", numero)) || 
    (numero % 2 != 0 && printf("Comprobado con AND: %d es un numero impar\n\n", numero));

    printf("Comprobado con el operador ternario (? :) : %d es un numero %s\n\n", 
    numero, (numero % 2 == 0) ? "par" : "impar");

    return 0;
}
