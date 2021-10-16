/*
 * Input.h
 *
 *  Created on: 4 oct 2021
 *      Author: EXOSMART
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#ifndef INPUT_H_
#define INPUT_H_

/// \fn int Menu(char[])
/// \brief Muestra un menu de opciones, del cual debemos seleccionar una y la retorna
/// \param opciones Las opciones que se mostraran
/// \return Retorna la opcion elegida
int Menu(char opciones[]);

/// \fn int IngresarCadena(char[], char[], char[], int, int)
/// \brief
/// \param cadena
/// \param mensaje
/// \param mensajeError
/// \param tamanio
/// \param reintentos
/// \return
int IngresarCadena(char cadena[], char mensaje[], char mensajeError[], int tamanio, int reintentos);
/// \fn int GetString(char[], int)
/// \brief
/// \param cadena
/// \param tamanio
/// \return
int GetString(char cadena[], int tamanio);

/// \fn int IngresarEntero(char[], char[], int*, int)
/// \brief
/// \param mensaje
/// \param mensajeError
/// \param resultado
/// \param reintentos
/// \return
int IngresarEntero(char mensaje[], char mensajeError[], int*resultado, int reintentos);
/// \fn int GetInt(int*)
/// \brief
/// \param resultado
/// \return
int GetInt(int* resultado);

/// \fn int IngresarFlotante(char[], char[], float*, int)
/// \brief
/// \param mensaje
/// \param mensajeError
/// \param resultado
/// \param reintentos
/// \return
int IngresarFlotante(char mensaje[], char mensajeError[], float*resultado, int reintentos);
/// \fn int GetFloat(float*)
/// \brief
/// \param resultado
/// \return
int GetFloat(float* resultado);

/// \fn int EsNumerico(char[])
/// \brief
/// \param cadena
/// \return
int EsNumerico(char cadena[]);
/// \fn int sonSoloLetras(char[])
/// \brief
/// \param cadena
/// \return
int sonSoloLetras(char cadena[]);

#endif /* INPUT_H_ */
