/**
* @file programa1.c
* @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
* @brief 
* @version 0.1
* @date 2023-03-23
* 
* @copyrigth GPlv3
* 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generar_arreglo_aleatorio(int arr[], int n);
void ordenar_arreglo(int arr[], int n);
void imprimir_arreglo(int arr[], int n);
void imprimir_texto(char text[]);

int main()
{
	int n = 0;

	char text1[] = "Ingrese el valor de n";
	imprimir_texto(text1);
	scanf("%d",&n);
	
	int arr[n];
	generar_arreglo_aleatorio(arr, n);
	
	char text2[] = "Arreglo ordenado de mayor a menor:";
	imprimir_texto(text2);
	imprimir_arreglo(arr, n);
	
	ordenar_arreglo(arr, n);
	char text3[] = "Arreglo generado:";
	imprimir_texto(text3);
	
	imprimir_arreglo(arr, n);
	
	return 0;
}

/// @brief Genera un arreglo aleatorio de una dimension dado
/// @param arr El arreglo generada
/// @param n La dimension del arreglo
void generar_arreglo_aleatorio(int arr[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (rand() % 500) + 1;
	}
}

/// @brief Ordena un arreglo de mayor a menor
/// @param arr El arreglo a ordenar
/// @param n La dimension del arreglo
void ordenar_arreglo(int arr[], int n) {
	int aux = 0, i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1 -i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				aux = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = aux;
			}
		}
	}
}

/// @brief Imprime un arreglo
/// @param arr El arreglo a imprimir
/// @param n La dimension del arreglo
void imprimir_arreglo(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}

/// @brief Imprime un texto
/// @param text el texto a imprimir
void imprimir_texto(char text[]) {
	printf("\n\n%s\n\n", text);
}