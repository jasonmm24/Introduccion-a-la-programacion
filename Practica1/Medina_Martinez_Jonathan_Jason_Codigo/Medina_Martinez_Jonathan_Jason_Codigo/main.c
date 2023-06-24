/**
 * @file main.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief Practica 1
 * @version 0.1
 * @date 2023-02-26
 * 
 * @copyright GPL v3
 */

#include <stdio.h>

int main() {
    char nombre[50] = "0";
    int edad = 0;
    float estatura = 0;
    int anio = 0;

    // Pedir al usuario su nombre completo
    printf("Ingrese su nombre: ");
    scanf("%[^\n]", nombre);
    getc(stdin);

    // Pedir al usuario su edad
    printf("Ingrese su edad: ");
    scanf("%d", &edad);
    getc(stdin);

    // Pedir al usuario su estatura
    printf("Ingrese su estatura (en metros): ");
    scanf("%f", &estatura);
    getc(stdin);

    //Generar el anio de nacimiento
    anio = 2022 - edad;

    // Imprimir los datos del usuario
    printf("\n\n\n********************************\n");
    printf("Nombre: %s\n", nombre);
    printf("Edad: %d\n", edad);
    printf("Año de nacimiento: %d\n", anio);
    printf("Estatura: %.2f metros\n", estatura);
    printf("********************************\n");

    return 0;
}
