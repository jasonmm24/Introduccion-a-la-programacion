/**
 * @file programa1.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-03-14
 * 
 * @copyright GLP v3
 * 
 */

#include <stdio.h>
#include <math.h>
#define PI 3.1416

int main()
{
    int opcion = 0;
    double area = 0, perimetro = 0, radio = 0, base = 0, altura = 0, lado = 0;

    do
    {
        printf("\nCALCULADORA DE AREAS Y PERIMETROS\n");
        printf("1. Circulo\n");
        printf("2. Cuadrado\n");
        printf("3. Rectangulo\n");
        printf("4. Salir\n");

        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        getc(stdin);

        switch (opcion){
            case 1:
                printf("Area y Perimetro del Circulo\n");
                printf("introdusca el radio del Circulo: ");
                scanf("%lf", &radio);
                getc(stdin);
                area = PI * (radio * radio);
                perimetro = PI * 2 * radio;
                printf("\nEl perimetro del Circulo es: %lf\n", perimetro);
                printf("El area del Circulo es: %lf\n", area);
            break;

            case 2:
                printf("Area y Perimetro del Cuadrado\n");
                printf("introdusca el lado del Cuadrado: ");
                scanf("%lf", &lado);
                getc(stdin);
                area = lado * lado;
                perimetro = 4 * lado;
                printf("\nEl perimetro del Cuadrado es: %lf\n", perimetro);
                printf("El area del Cuadrado es: %lf\n", area);
            break;

            case 3:
                printf("Area y Perimetro del Rectangulo\n");
                printf("introdusca la base del Rectangulo: ");
                scanf("%lf", &base);
                getc(stdin);
                printf("\nintrodusca la altura del Rectangulo: ");
                scanf("%lf", &altura);
                getc(stdin);
                area = base * altura;
                perimetro = (2 * base) + (2 * altura);
                printf("\nEl perimetro del Rectangulo es: %lf\n", perimetro);
                printf("El area del Rectangulo es: %lf\n", area);
            break;

            case 4:
                printf("\nHasta luego\n\n");
                return 0;
            break;

            default:
                printf("\nSeleccione una opcion valida\n");
        }
    } while (opcion > 0);

    return 0;
}

