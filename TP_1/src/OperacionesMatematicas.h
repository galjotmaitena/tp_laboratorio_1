/*
 * OperacionesMatematicas.h
 *
 *  Created on: 20 sept 2021
 *      Author: EXOSMART
 */
#include <stdio.h>
#ifndef OPERACIONESMATEMATICAS_H_
#define OPERACIONESMATEMATICAS_H_

/// \fn void Suma(int, int, int*)
/// \brief Recive dos numeros enteros, los suma y devuelve el resultado por parametro
/// \param numero1 Es el primer operando, este se sumara con el segundo operando
/// \param numero2 Es el segundo operando, el cual sera sumado con el primero
/// \param resultado Es la direccion de memoria de la variable asignada en el main para guardar el resultado de la suma
void Suma(int numero1, int numero2, int* resultado);

/// \fn void Resta(int, int, int*)
/// \brief Recive dos numeros enteros, los resta y devuelve el resultado por parametro
/// \param numero1 Es el pimer operando, al cual se le restara el segundo operando
/// \param numero2 Es el segundo operando, el cual sera restado al primer operando
/// \param resultado Es la direccion de memoria de la variable asignada en el main para guardar el resultado de la resta
void Resta(int numero1, int numero2, int* resultado);

/// \fn void Division(int, int, float*)
/// \brief Recive dos numeros enteros, uno lo convierte a flotante y los divide, luego devuelve el resultado por parametro a una variable de tipo flotante
/// \param numero1 Es el primer operando, el dividendo, el numero que sera dividido
/// \param numero2 Es el segundo operando, el divisor, la cantidad en la que sera dividido el primer operando
/// \param resultado Es la direccion de memoria de la variable asignada en el main para guardar el resultado de la division
void Division(float numero1, float numero2, float* resultado);

/// \fn void Multiplicacion(int, int, int*)
/// \brief Recive dos numeros enteros, los multiplica y devuelve el resultado por parametro
/// \param numero1 Es el primer operando, que sera multiplicado por el segundo operando
/// \param numero2 Es el segundo operando, que sera multiplicado por el primer operando
/// \param resultado Es la direccion de memoria de la variable asignada en el main para guardar el resultado de la multiplicacion
void Multiplicacion(int numero1, int numero2, int* resultado);

/// \fn void Factorial(int, int*)
/// \brief Recive un numero entero, calcula su factorial y devuelve el resultado por parametro
/// \param numero Es el numero del que se calculara el factorial
/// \param resultado Es la direccion de memoria de la variable asignada en el main para guardar el resultado del factorial
void Factorial (int numero, int* resultado);

#endif /* OPERACIONESMATEMATICAS_H_ */
