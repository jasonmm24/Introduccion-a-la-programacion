/**
 * @file Programa8.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-04-22
 * 
 * @copyrigth GPlv3
 * 
 */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double leibniz(int m, double acum);

int main() {
    int m = 0;

    printf("Ingrese el valor de m: ");
    scanf("%d", &m);

    double sum = leibniz(m, 0);

    if (sum < 0) {
        sum = sum * -1;
    }

    double picuartos = PI / 4;

    printf("\nLa suma de los primeros %d terminos de la serie de Leibniz es: %f\n", m, sum);
    printf("El valor de pi/4 es: %f\n", picuartos);
    return 0;
}

/// @brief calcula la suma de los resultados de la serie de Leibniz
/// @param m el numero de repeticiones
/// @param acum la suma
/// @return regresa el valor de acum
double leibniz(int m, double acum) {
    if (m == 0) {
        return acum;
    }
    double termino = (pow(-1, m)) / (2 * m + 1);
    return leibniz(m - 1, acum + termino);
}
