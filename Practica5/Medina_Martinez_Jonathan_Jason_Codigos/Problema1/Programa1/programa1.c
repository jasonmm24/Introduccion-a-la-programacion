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
#include "funciones.h"

int main()
{
	int n = 0;

	char text1[] = "Ingrese el valor de n";
	imprimir_texto(text1);
	scanf("%d",&n);
	
	int arr[n];
	generar_arreglo_aleatorio(arr, n);
	
	char text2[] = "Arreglo generado:";
	imprimir_texto(text2);
	imprimir_arreglo(arr, n);
	
	ordenar_arreglo(arr, n);
	char text3[] = "Arreglo ordenado de mayor a menor:";
	imprimir_texto(text3);
	
	imprimir_arreglo(arr, n);
	
	return 0;
}

