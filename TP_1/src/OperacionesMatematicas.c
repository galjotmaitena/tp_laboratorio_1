/*
 * OperacionesMatematicas.c
 *
 *  Created on: 20 sept 2021
 *      Author: EXOSMART
 */

#include "OperacionesMatematicas.h"

void Suma(int numero1, int numero2, int* resultado){

	*resultado = numero1 + numero2;

}

void Resta(int numero1, int numero2, int* resultado){

	*resultado = numero1 - numero2;

}

void Multiplicacion(int numero1, int numero2, int* resultado){

	*resultado = numero1 * numero2;

}

void Division(float numero1, float numero2, float* resultado){

	*resultado = numero1 / numero2;

}

void Factorial (int numero, int* resultado){
 int factorial;

 factorial = 1;

 while(numero > 1){
 factorial = factorial * numero;
 numero --;
 }

 *resultado = factorial;

}

