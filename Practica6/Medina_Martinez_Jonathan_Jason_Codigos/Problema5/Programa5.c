/**
 * @file Programa5.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyrigth GPlv3
 * 
 */

#include <stdio.h>

int main() {
    char c;

    printf("Ingresa un caracter: ");
    scanf("%c", &c);

    if (c >= 'a' && c <= 'z') {
        printf("El caracter ingresado es una letra minuscula.\n");
    } else if (c >= 'A' && c <= 'Z') {
        printf("El caracter ingresado es una letra mayuscula.\n");
    } else if (c >= '0' && c <= '9') {
        printf("El caracter ingresado es un numero.\n");
    } else {
        printf("El caracter ingresado es un caracter especial.\n");
    }

    return 0;
}
