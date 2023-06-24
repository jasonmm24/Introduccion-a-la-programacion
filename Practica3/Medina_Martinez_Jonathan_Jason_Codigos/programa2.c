/**
 * @file programa2.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-03-14
 * 
 * @copyright GLP v3
 * 
 */

#include <stdio.h>

int main() {
    int num, i, j, count = 1;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    for (i = 1; i <= num; i++) {
        for (j = 1; j <= i; j++) {
            if (count % 2 == 0) {
                printf("1 ");
            }
            else {
                printf("0 ");
            }
            count++;
        }
        printf("\n");
    }
    return 0;
}

