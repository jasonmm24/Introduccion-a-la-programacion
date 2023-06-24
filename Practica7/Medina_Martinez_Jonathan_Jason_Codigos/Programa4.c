
/**
* @file Programa4.c
* @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
* @brief 
* @version 0.1
* @date 2023-05-20
* 
* @copyrigth GPlv3
* 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	
	printf("Ingrese la cantidad de numeros: ");
	scanf("%d", &n);
	
	int *numeros = (int *)malloc(n * sizeof(int));
	
	if (numeros == NULL) {
		
		printf("Error al asignar memoria.");
		
		return 1;
		
	}
	
	printf("Ingrese los numeros:\n");
	
	for (int i = 0; i < n; i++) {
		
		scanf("%d", numeros + i);
		
	}
	
	int maximo = *numeros;
	
	for (int i = 1; i < n; i++) {
		
		if (*(numeros + i) > maximo) {
			
			maximo = *(numeros + i);
			
		}
	
	}
	
	printf("El numero mas grande es: %d\n", maximo);
	
	free(numeros);
	
	return 0;
}