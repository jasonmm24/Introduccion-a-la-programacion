/**
 * @file programa7.c
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
    int n = 0, fi = 0;

    printf("\n\nIntroduzca el numero de la sucecion a buscar: (mayor que 1)");
    scanf("%d", &n);
    getc(stdin);

    fi = (1/(sqrt(5)))*(((pow(((1+(sqrt(5)))/2), n)))-((pow(((1-(sqrt(5)))/2), n))));

    printf("\n\nEl numero de la sucesion es: %d", fi);
    getc(stdout);

    return 0;
}

