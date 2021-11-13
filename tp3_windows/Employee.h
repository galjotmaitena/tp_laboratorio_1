#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

/// \fn int employee_ImprimirUnEmpleado(Employee*)
/// \brief Imprime los datos de un empleado
/// \param this El empleado que debe mostrar
/// \return Retorna 0 si se logro mostrarlo o -1 si no se logro
int employee_ImprimirUnEmpleado(Employee* this);

/// \fn int employee_ModificarNombre(LinkedList*, int, int)
/// \brief Modifica el nombre del empleado solicitado
/// \param pArrayListEmployee Lista en la que se buscara al empleado, por la posicion enviada por parametro
/// \param tamanio Tamanio de la lista a recorrer
/// \param index Posicion en la que se encuentra el empleado
/// \return Retorna 0 si se encontro y modifico al empleado o -1 si no se lo encontro
int employee_ModificarNombre(LinkedList* pArrayListEmployee, int tamanio, int index);
/// \fn int employee_ModificarSueldo(LinkedList*, int, int)
/// \brief Modifica el sueldo del empleado solicitado
/// \param pArrayListEmployee Lista en la que se buscara al empleado, por la posicion enviada por parametro
/// \param tamanio Tamanio de la lista a recorrer
/// \param index Posicion en la que se encuentra el empleado
/// \return Retorna 0 si se encontro y modifico al empleado o -1 si no se lo encontro
int employee_ModificarSueldo(LinkedList* pArrayListEmployee, int tamanio, int index);
/// \fn int employee_ModificarHorasTrabajadas(LinkedList*, int, int)
/// \brief Modifica las horas de trabajo del empleado solicitado
/// \param pArrayListEmployee Lista en la que se buscara al empleado, por la posicion enviada por parametro
/// \param tamanio Tamanio de la lista a recorrer
/// \param index Posicion en la que se encuentra el empleado
/// \return Retorna 0 si se encontro al empleado o -1 si no se lo encontro
int employee_ModificarHorasTrabajadas(LinkedList* pArrayListEmployee, int tamanio, int index);

/// \fn int employee_GetById(LinkedList*, int)
/// \brief Busca al empleado por el id pasado por parametro
/// \param pArrayListEmployee Lista a recorrer en busca del empleado
/// \param id Id que debe ser encontrado
/// \return Retorna la posicion en la que se encuentra el id
int employee_GetById(LinkedList* pArrayListEmployee,int id);

/// \fn int employee_CompareByName(void*, void*)
/// \brief Compara a las empleados por nombre
/// \param x Uno de los empleados a comparar
/// \param y El otro empleado a comparar
/// \return
int employee_CompareByName(void* x, void* y);
/// \fn int employee_CompareBySalary(void*, void*)
/// \brief Compara a las empleados por sueldo
/// \param x Uno de los empleados a comparar
/// \param y El otro empleado a comparar
/// \return
int employee_CompareBySalary(void* x, void* y);
/// \fn int employee_CompareByHours(void*, void*)
/// \brief Compara a las empleados por horas de trabajo
/// \param x Uno de los empleados a comparar
/// \param y El otro empleado a comparar
/// \return retorna
int employee_CompareByHours(void* x, void* y);

/// \fn int employee_AscendenteDescendente(char*)
/// \brief Muestra un mensaje, y devuelve la respuesta a dicho mensaje
/// \param mensaje Mensaje que sera mostrado
/// \return Retorna -1 si salio mal o la opcion indicada
int employee_AscendenteDescendente(char* mensaje);

#endif // employee_H_INCLUDED
