/**
 * @file programa3.c
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

int main()
{
    double x1 = 0, x2 = 0, y1 = 0, y2 = 0, suma = 0, difx = 0, dify = 0, resultado = 0;

    printf("\nIngrese la coordenada x del primer punto: ");
    scanf("%lf", &x1);
    getc(stdin);

    printf("\nIngrese la coordenada y del primer punto: ");
    scanf("%lf", &y1);
    getc(stdin);

    printf("\nIngrese la coordenada x del segundo punto: ");
    scanf("%lf", &x2);
    getc(stdin);

    printf("\nIngrese la coordenada y del segundo punto: ");
    scanf("%lf", &y2);
    getc(stdin);

    difx = x2 - x1;
    dify = y2 - y2;
    suma = (pow(difx, 2)) + (pow(dify, 2));
    resultado = pow(suma, 0.5);

    printf("\n\nLa distancia entre los puntos es: %lf\n", resultado);
    getc(stdout);

    return 0;
}

