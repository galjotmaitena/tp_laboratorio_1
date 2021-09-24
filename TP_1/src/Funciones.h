/*
 * Funciones.h
 *
 *  Created on: 17 sept 2021
 *      Author: EXOSMART
 */
#include <stdio.h>
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/// \fn int Menu(char[])
/// \brief Muestra un menu de opciones, el usuario debe elegir una de estas y la retorna.
/// \param opciones Es un mensaje que muestra todas las opciones posibles.
/// \return Retorna la opcion seleccionada por el usuario.
int Menu(char opciones[]);

/// \fn int IngresarEntero(int*)
/// \brief Pide un numero entero y lo retorna
/// \param validacion Va a devolver 1 o 0 por parametro, 1 para informar que se ingreso un entero y 0 para informar que no se ingreso ningun entero.
/// \return Retorna el numero entero ingresado por el usuario.
int IngresarEntero(int *validacion);

/// \fn void MostrarResultados(int, int, int, int, int, int, int, int, int)
/// \brief Muetra los resultados de cada operacion, y en caso de que no se haya podido realizar alguna de las operaciones informa el por que.
/// \param resultado1 Es el resultado de la SUMA, este se mostrara en un mensaje
/// \param resultado2 Es el resultado de la RESTA, este se mostrara en un mensaje
/// \param validacion3 En el caso de que el segundo operando haya sido un 0, validacion3 vale 1 y va a informar de que no se puede realizar una division por 0.
///                    Si el segundo operando es un numero distinto de 0, validacion3 vale 0 y se mostrara el resultado de la division guardado en resultado3.
/// \param resultado3 Es el resultado de la DIVISION, este se mostrara en un mensaje
/// \param resultado4 Es el resultado de la MULTIPLICACION, este se mostrara en un mensaje
/// \param validacion5 En el caso de que el primer operando sea menor o igual a 0 validacion5 vale 1, y va a informar que no se puede sacar el factorial de un numero menor o igual a 0.
///                    Si el primer operando es un numero mayor a 0, muestra el resultado del factorial de dicho numero.
/// \param resultado5 Es el resultado del FACTORIAL del PRIMER OPERANDO, este se mostrara en un mensaje
/// \param validacion6 En el caso de que el segundo operando sea menor o igual a 0 validacion5 vale 1, y va a informar que no se puede sacar el factorial de un numero menor o igual a 0.
///                    Si el segundo operando es un numero mayor a 0, muestra el resultado del factorial de dicho numero.
/// \param resultado6 Es el resultado del FACTORIAL del SEGUNDO OPERANDO, este se mostrara en un mensaje
void MostrarResultados(int resultado1, int resultado2, int validacion3, int resultado3, int resultado4, int validacion5, int resultado5, int validacion6, int resultado6);

/// \fn int ValidacionDivision(int)
/// \brief Valida que el segundo operando sea distinto de 0 para asi verificar si se puede resolver la division o no, de acuerdo a esto, retornara 1 o 0
/// \param numero Es el numero que se va a validar, el numero que se va a fijar si es igual o distinto de 0
/// \return Retorna 1 en caso de que el segundo operando sea igual a 0, o retorna 0 en caso de que el segundo operando sea distinto de 0
int ValidacionDivision(int numero);

/// \fn int ValidacionFactorial(int)
/// \brief Valida que el operando que recive sea mayor a 0, ya que de no ser asi no se puede sacar el factorial, retorna 1 o 0
/// \param numero Es el numero que se va a validar si es mayor a 0 o no
/// \return Retorna 1 en caso de que el operando sea manor a 0, o retorna 1 en caso de que el operando sea mayor a 0
int ValidacionFactorial(int numero);


#endif /* FUNCIONES_H_ */
