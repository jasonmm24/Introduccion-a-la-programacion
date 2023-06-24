/**
 * @file Programa10.c
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

double aureo(int e1, int e2, double rac, double phi);

int main() {
    double phi = (1 + sqrt(5)) / 2;
    int e1, e2;

    printf("Ingrese el Primer digito: ");
    scanf("%d", &e1);

    printf("Ingrese el Segundo digito: ");
    scanf("%d", &e2);

    printf("%d, %d, ", e1, e2);

    double rac = fabs((double)e2 / (double)e1);
    double result = aureo(e1, e2, rac, phi);

    printf("\nEl valor de Phi es: %f", phi);

    printf("\nEl valor de %d / %d es: %f", e2, e1, result);

    return 0;
}

/// @brief funcion que calcula el numero aure
/// @param e1 el primer valor
/// @param e2 el segundo valor
/// @param rac almacen
/// @param phi el valor de phi
double aureo(int e1, int e2, double rac, double phi) {
    int e3 = e1 + e2;

    printf("%d, ", e3);

    double new_rac = fabs((double)e3 / (double)e2);

    if (fabs(rac - new_rac) < 0.001) {
        return new_rac;
    } else {
        return aureo(e2, e3, new_rac, phi);
    }
}
