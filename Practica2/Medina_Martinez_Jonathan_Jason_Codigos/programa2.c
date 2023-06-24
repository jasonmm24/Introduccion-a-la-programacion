/**
 * @file programa2.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-03-05
 * 
 * @copyright GLP v3
 * 
 */

#include <stdio.h>
#include <math.h>
#define e 2.71828

int main() {
    double base = 0, exponente = 0, resultado = 0, raiz = 0;

    printf("\n\nIntrodusca la base de la raiz (UN NUMERO ENTERO): ");
    scanf("%lf", &base);
    getc(stdin);

    printf("\nIntrodusca el exponente de la raiz (UN NUMERO ENTERO): ");
    scanf("%lf", &exponente);
    getc(stdin);

    raiz = (1/exponente) * (log(base));
    resultado = round (pow(e, raiz));

    printf("\nLa raiz de base %.0lf exponente %.0lf es: %.3lf \n\n", base, exponente, resultado);
    getc(stdout);

    return 0;
}

