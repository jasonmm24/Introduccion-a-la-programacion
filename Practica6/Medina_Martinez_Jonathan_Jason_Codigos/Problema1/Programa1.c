/**
 * @file Programa1.c
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
    char cadena[100];
    int n = 0;

    printf("Ingrese una cadena de texto: ");
    scanf("%s", cadena);

    while (cadena[n] != '\0') {
        n++;
    }

    printf("La longitud de la cadena es: %d", n);

    return 0;
}
