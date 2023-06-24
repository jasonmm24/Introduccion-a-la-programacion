/**
 * @file programa1.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-03-05
 * 
 * @copyright GLP v3
 * 
 */

#include <stdio.h>

#define PI 3.1416

int main()
{
    float perimetro = 0, area = 0, radio = 0;

    printf("Introduzca el radio: ");
    scanf("%f", &radio);
    getc(stdin);

    area = PI * radio * radio;

    perimetro = 2 * PI * radio;

    printf("\n\nEl area del circulo es: %f\n", area);
    printf("El Perimetro del circulo es: %f\n", perimetro);

    return 0;
}

