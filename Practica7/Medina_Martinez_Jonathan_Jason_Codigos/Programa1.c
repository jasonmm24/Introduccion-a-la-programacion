/**
* @file Programa1.c
* @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
* @brief 
* @version 0.1
* @date 2023-05-19
* 
* @copyrigth GPlv3
* 
*/

#include <stdio.h>

void sumarNumeros(int num1, int num2, int *resultado);

int main() {
	int num1, num2, resultado;
	
	printf("Ingrese el primer numero: ");
	scanf("%d", &num1);
	
	printf("Ingrese el segundo numero: ");
	scanf("%d", &num2);
	
	sumarNumeros(num1, num2, &resultado);
	
	printf("La suma es: %d\n", resultado);
	
	return 0;
}

/// @brief Funcion que suma dos numeros utulizando punteros.
/// @param num1 El primer numero.
/// @param num2 El segundo numero.
/// @param resultado El resultado.
void sumarNumeros(int num1, int num2, int *resultado) {
	*resultado = num1 + num2;
}