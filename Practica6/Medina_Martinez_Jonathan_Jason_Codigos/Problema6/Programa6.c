/**
 * @file Programa6.c
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
    char str[MAX];
    int frecuencia[26] = {0};
    int i = 0;

    printf("Ingresa una cadena de texto: ");
    fgets(str, MAX, stdin);

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            frecuencia[str[i] - 'a']++;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            frecuencia[str[i] - 'A']++;
        }
        i++;
    }

    printf("Frecuencia de las letras:\n");
    for (int j = 0; j < 26; j++) {
        if (frecuencia[j] > 0) {
            printf("%c   %d\n", 'a' + j, frecuencia[j]);
        }
    }

    return 0;
}
