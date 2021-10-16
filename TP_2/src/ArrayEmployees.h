/*
 * ArrayEmployees.h
 *
 *  Created on: 10 oct 2021
 *      Author: EXOSMART
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include "Input.h"

#define TRUE 0
#define FALSE 1

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}Employee;


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len); //X

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
**/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/// \fn int IngresarUnEmpleado(Employee*, int, int*)
/// \brief Pide los datos de un empleado
/// \param lista Array de empleados
/// \param tamanio Tamanio del array
/// \param idContador Direccion de memoria donde se guardaran los id
/// \return retorna (-1) si la lista es NULL, o (0) si todo fue exitoso
int IngresarUnEmpleado(Employee* lista, int tamanio, int* idContador);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

/// \fn int BajaDeUnEmpleado(Employee[], int)
/// \brief
/// \param lista
/// \param tamanio
/// \return
int BajaDeUnEmpleado(Employee lista[], int tamanio);

int Modificar(Employee lista[], int tamanio);

int ModificarSector(Employee lista[], int tamanio, int i);

int ModificarSalario(Employee lista[], int tamanio, int i);

int ModificarApellido(Employee lista[], int tamanio, int i);

int ModificarNombre(Employee lista[], int tamanio, int i);

float CalcularPromedioDeLosSueldos(float totalSueldos, int cantidadDeEmpleados);

int TotalYPromedioDeLosSueldos(Employee lista[], int tamanio, float* totalSueldos, float* promedioSueldos);

int EmpleadosConSueldoMayorAlPromedio(Employee lista[], int tamanio, float sueldoPromedio, int* cantidadDeEmpleadosConMayorSueldo);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length);

void MostrarUnEmpleado(Employee unEmpleado);

int OrdenarPorSectorDown(Employee lista[], int tamanio);

int OrdenarPorSectorUp(Employee lista[], int tamanio);

#endif /* ARRAYEMPLOYEES_H_ */
