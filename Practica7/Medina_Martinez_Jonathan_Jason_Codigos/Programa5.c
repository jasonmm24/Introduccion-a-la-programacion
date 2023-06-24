/**
 * @file Programa5.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-05-20
 * 
 * @copyrigth GPlv3
 * 
 */

#include <stdio.h>

int contarVocalesConsonantes(char *cadena, int *vocales, int *consonantes);

int main() {
    char cadena[100];
    int vocales, consonantes, total;

    printf("Ingrese una cadena: ");
    fgets(cadena, sizeof(cadena), stdin);

    total = contarVocalesConsonantes(cadena, &vocales, &consonantes);

    printf("Cantidad de vocales: %d\n", vocales);
    printf("Cantidad de consonantes: %d\n", consonantes);
    printf("Total de caracteres: %d\n", total);

    return 0;
}

/// @brief Funcion que cuenta el numero de vocales y consonantes en una cadena de caracteres.
/// @param cadena La cadena de caracteres.
/// @param vocales Un puntero para almacenar el conteo de vocales.
/// @param consonantes Un puntero para almacenar el conteo de consonantes.
/// @return El total de caracteres (suma de vocales y consonantes).
int contarVocalesConsonantes(char *cadena, int *vocales, int *consonantes) {
    *vocales = 0;
    *consonantes = 0;

    while (*cadena != '\0') {
        if (*cadena == 'a' || *cadena == 'e' || *cadena == 'i' || *cadena == 'o' || *cadena == 'u' ||
            *cadena == 'A' || *cadena == 'E' || *cadena == 'I' || *cadena == 'O' || *cadena == 'U') {
            (*vocales)++;
        } else if ((*cadena >= 'a' && *cadena <= 'z') || (*cadena >= 'A' && *cadena <= 'Z')) {
            (*consonantes)++;
        }
        cadena++;
    }

    return (*vocales + *consonantes);
}