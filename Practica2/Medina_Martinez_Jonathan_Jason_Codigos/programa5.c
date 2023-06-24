/**
 * @file programa5.c
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
    double cel = 0, far = 0;

    printf("\n\nConvertidor de grados celcius a farenheit\n\n");
    printf("Ingrese la temperatura en grados Celsius: ");
    scanf("%lf", &cel);
    getc(stdin);

    far = (cel * 9/5) + 32;

    printf("La temperatura en grados farenheit es: %.2lf\n\n", far);

    return 0;
}
