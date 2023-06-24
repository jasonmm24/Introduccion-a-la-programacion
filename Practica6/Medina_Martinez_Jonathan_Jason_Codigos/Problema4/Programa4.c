/**
 * @file Programa4.c
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
    char corta[MAX];
    char larga[MAX];
    int l = MAX;
    int m = 0;
    int n = 0;
    int i = 0;

    printf("Ingresa una cadena de texto: ");
    fgets(str, MAX, stdin);

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\n') {
            if (n < l) {
                l = n;
                sscanf(str + i - n, "%s", corta);
            }
            if (n > m) {
                m = n;
                sscanf(str + i - n, "%s", larga);
            }
            n = 0;
        } else {
            n++;
        }
        i++;
    }

    printf("La palabra mas corta es: %s\n", corta);
    printf("La palabra mas larga es: %s\n", larga);

    return 0;
}
