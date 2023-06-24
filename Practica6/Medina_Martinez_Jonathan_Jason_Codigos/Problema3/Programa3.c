/**
 * @file Programa3.c
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
    int frecuencia[26] = {0};
    int repetida[26] = {0};
    int i, n = 0, m = -1;

    printf("Ingrese una cadena de texto: ");
    fgets(cadena, MAX, stdin);

    for (i = 0; cadena[i] != '\0'; i++) {
        if ((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z')) {
            if (cadena[i] >= 'a' && cadena[i] <= 'z') {
                frecuencia[cadena[i] - 'a']++;
            } else {
                repetida[cadena[i] - 'A']++;
            }
        }
    }

    for (i = 0; i < 26; i++) {
        if (frecuencia[i] + repetida[i] > n) {
            n = frecuencia[i] + repetida[i];
            m = i;
        }
    }

    if (m != -1) {
        printf("La letra que se repite mas veces es '%c', con %d repeticiones.\n", m + 'a', n);
    } else {
        printf("No se encontraron letras en la cadena ingresada.\n");
    }

    return 0;
}
