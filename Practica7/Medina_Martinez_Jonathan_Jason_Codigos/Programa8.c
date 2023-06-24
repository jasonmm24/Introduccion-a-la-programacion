/**
 * @file Programa8.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-05-21
 * 
 * @copyrigth GPlv3
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    char *texto = (char *)malloc(MAX_LENGTH * sizeof(char));

    if (texto == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    printf("Escriba un texto (presione punto para finalizar):\n");

    char *p = texto;
    char c;

    while ((c = getchar()) != '.') {
        *p = c;
        p++;

        if (p - texto >= MAX_LENGTH - 1) {
            printf("Tamanio maximo alcanzado. Se truncara el texto.\n");
            break;
        }
    }

    *p = '\0';

    printf("Texto ingresado:\n%s\n", texto);

    free(texto);

    return 0;
}