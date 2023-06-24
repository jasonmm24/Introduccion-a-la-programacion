/**
 * @file programa6.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-03-05
 * 
 * @copyright GLP v3
 * 
 */

#include <stdio.h>

int main()
{
    double far = 0, cel = 0;

    printf("\n\nConvertidor de grados farenheit a celcius\n\n");
    printf("Ingrese la temperatura en grados farenheit: ");
    scanf("%lf", &far);
    getc(stdin);

    cel = (far - 32) / 1.8;

    printf("La temperatura en grados celcius es: %.2lf\n\n", cel);

    return 0;
}
