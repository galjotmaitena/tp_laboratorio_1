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
/// \brief Pide el id del empleado que se desea dar de baja, para luego paserselo a la funcion que se encargara de realizar la baja
/// \param lista lista Array de empleados
/// \param tamanio Tamanio del array
/// \return retorna (-1) si la lista es NULL o el tamanio es invalido o si no se pudo realizar la baja, y (0) si se pudo realizar la baja
int BajaDeUnEmpleado(Employee lista[], int tamanio);

/// \fn int Modificar(Employee[], int)
/// \brief Muestra un menu de opciones, y a partir de la opcion elegida se realizara la modificacion solicitada
/// \param lista lista Array de empleados
/// \param tamanio Tamanio del array
/// \return retorna (-1) si la lista es NULL o el tamanio es invalido o si no se pudo realizar la modificacion, y (0) si se pudo realizar la modificacion
int Modificar(Employee lista[], int tamanio);

/// \fn int ModificarNombre(Employee[], int, int)
/// \brief Se encarga de modificar el nombre del empleado
/// \param lista lista Array de empleados
/// \param tamanio Tamanio del array
/// \param i La posicion del array en la que se debe realizar la modificacion
/// \return Retorna (-1) si la lista es NULL o el tamanio es invalido o si no se pudo modificar el nombre, y (0) si se pudo modificar el nombre
int ModificarNombre(Employee lista[], int tamanio, int i);

/// \fn int ModificarApellido(Employee[], int, int)
/// \brief Se encarga de modificar el apellido del empleado
/// \param lista lista Array de empleados
/// \param tamanio Tamanio del array
/// \param i La posicion del array en la que se debe realizar la modificacion
/// \return Retorna (-1) si la lista es NULL o el tamanio es invalido o si no se pudo modificar el apellido, y (0) si se pudo modificar el apellio
int ModificarApellido(Employee lista[], int tamanio, int i);

/// \fn int ModificarSalario(Employee[], int, int)
/// \brief Se encarga de modificar el salario del empleado
/// \param lista lista Array de empleados
/// \param tamanio Tamanio del array
/// \param i La posicion del array en la que se debe realizar la modificacion
/// \return Retorna (-1) si la lista es NULL o el tamanio es invalido o si no se pudo modificar el salario, y (0) si se pudo modificar el salario
int ModificarSalario(Employee lista[], int tamanio, int i);

/// \fn int ModificarSector(Employee[], int, int)
/// \brief Se encarga de modificar el sector del empleado
/// \param lista lista Array de empleados
/// \param tamanio Tamanio del array
/// \param i La posicion del array en la que se debe realizar la modificacion
/// \return retorna (-1) si la lista es NULL o el tamanio es invalido o si no se pudo modificar el sector, y (0) si se pudo modificar el sector
int ModificarSector(Employee lista[], int tamanio, int i);

/// \fn int TotalYPromedioDeLosSueldos(Employee[], int, float*, float*)
/// \brief Se encarga de calcular el total de los sueldos, y de devolverlo junto con el promedio de los sueldos que es calculado por otra funcion
/// \param lista lista Array de empleados
/// \param tamanio Tamanio del array
/// \param totalSueldos direccion de memoria donde se guardara el total de los sueldos
/// \param promedioSueldos direccion de memoria donde se guardara el promedio de los sueldos
/// \return retorna (-1) si la lista es NULL o el tamanio es invalido o si no se pudieron acumular los sueldos, y (0) si se pudieron acumular los sueldos
int TotalYPromedioDeLosSueldos(Employee lista[], int tamanio, float* totalSueldos, float* promedioSueldos);

/// \fn float CalcularPromedioDeLosSueldos(float, int)
/// \brief  Calcula el promedio de los sueldos
/// \param totalSueldos La suma total de los sueldos
/// \param cantidadDeEmpleados La cantidad de empleados
/// \return Retorna el promedio de los sueldos
float CalcularPromedioDeLosSueldos(float totalSueldos, int cantidadDeEmpleados);

/// \fn int EmpleadosConSueldoMayorAlPromedio(Employee[], int, float, int*)
/// \brief Cuenta a los empleados que superan el sueldo promedio
/// \param lista lista Array de empleados
/// \param tamanio Tamanio del array
/// \param sueldoPromedio El promedio de los sueldos
/// \param cantidadDeEmpleadosConMayorSueldo  direccion de memoria donde se guardara la cantidad de empleados de los cuales su sueldos superan el promedio de los sueldos
/// \return retorna (-1) si la lista es NULL o el tamanio es invalido o si no se encontro ningun empleado que superara el sueldo promedio, y (0) si se encontro algun empleado que superara el sueldo promedio
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

/// \fn int OrdenarPorSectorDown(Employee[], int)
/// \brief Ordena por sector de mayor a menor, y en caso de que encuentre a dos empleados con el mismo apellido ordena alfabeticamente de la Z a la A
/// \param lista lista Array de empleados
/// \param tamanio Tamanio del array
/// \return retorna retorna (-1) si la lista es NULL o el tamanio es invalido o si no se pudo ordenar la lista, y (0) si se pudo ordenar
int OrdenarPorSectorDown(Employee lista[], int tamanio);

/// \fn int OrdenarPorSectorDown(Employee[], int)
/// \brief Ordena por sector de menor a mayor, y en caso de que encuentre a dos empleados con el mismo apellido ordena alfabeticamente de la A a la Z
/// \param lista lista Array de empleados
/// \param tamanio Tamanio del array
/// \return retorna retorna (-1) si la lista es NULL o el tamanio es invalido o si no se pudo ordenar la lista, y (0) si se pudo ordenar
int OrdenarPorSectorUp(Employee lista[], int tamanio);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length);

/// \fn void MostrarUnEmpleado(Employee)
/// \brief Muestra los datos de un empleado
/// \param unEmpleado Empleado del que mostrara los datos
void MostrarUnEmpleado(Employee unEmpleado);

#endif /* ARRAYEMPLOYEES_H_ */
