/**
 * @file Programa2.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyrigth GPlv3
 * 
 */

#include <stdio.h>

#define MAX 100

int main() {
    char cadena[MAX];
    int i, palabras = 0, letras = 0, numeros = 0, caracteres = 0;

    printf("Ingrese una cadena de texto: ");
    fgets(cadena, MAX, stdin);

    for (i = 0; cadena[i] != '\0'; i++) {
        if ((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z')) {
            letras++;
        } else if (cadena[i] >= '0' && cadena[i] <= '9') {
            numeros++;
        } else if (cadena[i] != ' ' && cadena[i] != '\n') {
            caracteres++;
        }

        if (cadena[i] == ' ') {
            palabras++;
        }
    }

    if (cadena[i - 1] != ' ') {
        palabras++;
    }

    printf("Total de palabras: %d\n", palabras);
    printf("Total de letras: %d\n", letras);
    printf("Total de numeros: %d\n", numeros);
    printf("Total de caracteres especiales: %d\n", caracteres);

    return 0;
}
