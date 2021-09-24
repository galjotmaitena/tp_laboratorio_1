/*
 * Funciones.c
 *
 *  Created on: 17 sept 2021
 *      Author: EXOSMART
 */
#include "Funciones.h"
#include "OperacionesMatematicas.h"

int Menu(char opciones[]) {
	int opcion;

	printf("%s", opciones);
	scanf("%d", &opcion);

	return opcion;
}


int IngresarEntero(int* validacion){
	int numeroIngresado;
	int flag;

	flag = 0;

	if(flag == 0){
		printf("Ingrese un numero");
		scanf("%d", &numeroIngresado);

		flag = 1;
	}

	*validacion = flag;

	return numeroIngresado;
}

void MostrarResultados(int resultado1, int resultado2, int validacion3, int resultado3, int resultado4, int validacion5, int resultado5, int validacion6, int resultado6){

	printf("\nEl resultado de la SUMA es %d", resultado1);

	printf("\nEl resultado de la RESTA es %d", resultado2);

	if(validacion3 == 0)
	{
		printf("\nEl resultado de la DIVISION es %d", resultado3);
	}
	else
	{
		printf("\nNo se puede dividir un numero por 0");
	}

	printf("\nEl resultado de la MULTIPLICACION es %d", resultado4);


	if(validacion5 == 0)
	{
		printf("\nEl FACTORIAL del PRIMER OPERANDO es %d", resultado5);
	}
	else
	{
		printf("\nNo se puede sacar el factorial de un numero menor o igual a 0");
	}

	if(validacion5 == 0)
	{
		printf("\nEl FACTORIAL del SEGUNDO OPERANDO es %d\n", resultado6);
	}
	else
	{
		printf("\nNo se puede sacar el factorial de un numero menor o igual a 0\n");
	}
}

int ValidacionDivision(int numero){
	int respuesta;

	respuesta = 0;

	if(numero == 0){

		respuesta = 1;
	}

	return respuesta;
}

int ValidacionFactorial(int numero){
	int respuesta;

	respuesta = 0;

	if(numero <= 0){

		respuesta = 1;
	}

	return respuesta;
}
