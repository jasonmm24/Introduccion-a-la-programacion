/**
 * @file programa9v2.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.2
 * @date 2023-03-14
 * 
 * @copyright GLP v3
 * 
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define e 2.71828182846

int main()
{
    int n = 0, m = 0; 
    float p1 = 0, p2 = 0, res = 0, expo = 0, ln = 0, lnn = 0, p3 = 0;

    do
    {
        printf("\n\nIntroduzca un numero entero positivo: ");
    scanf("%d", &n);
    getc(stdin);
    if (n <= 0)
    {
        printf("\nERROR Introduzca un valor valido");
        getc(stdin);
    }
    } while (n <= 0);

    do
    {
        printf("\n\nIntroduzca el exponente de la raiz (Numero entero positivo): ");
    scanf("%d", &m);
    getc(stdin);
    if (m <= 0)
    {
        printf("\nERROR Introduzca un valor valido");
        getc(stdin);
    }
    } while (m <= 0);

    for (int k = 0; k <= 5000; k++)
    {
        p1 = (1.0 / (2.0 * k + 1.0));
        p2 = ((n - 1.0) / (n + 1.0));
        ln = p1 * pow(p2, (2.0 * k + 1.0));
        p3 += ln;
    }

    lnn = 2 * p3;

    expo = ((1.0 / m) * lnn);
    res = pow(e, expo);

    printf("la raiz enecima de %d es: %lf", n, res);
    getc(stdout);

    return 0;
}