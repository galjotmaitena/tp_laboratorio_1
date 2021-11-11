#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* unEmpleado;
	char id[50];
	char nombre[128];
	char horasTrabajadas[50];
	char sueldo[50];
	int r;
	int retorno;

	if(pArrayListEmployee != NULL)
	{
		if(pFile == NULL)
		{
			printf("El archivo no existe");
			exit(EXIT_FAILURE);
		}

		do
		{
			r = fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, nombre, horasTrabajadas, sueldo);

			if(r == 4)
			{
				unEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
				printf("\n%d -- %s -- %d -- %d", unEmpleado->id, unEmpleado->nombre, unEmpleado->horasTrabajadas, unEmpleado->sueldo);

				if(unEmpleado != NULL)
				{
					retorno = ll_add(pArrayListEmployee, unEmpleado);
					printf("\n%d", retorno);
				}
			}
			else
			{
				printf("ERROR");
				exit(EXIT_FAILURE);
			}
		}while(!feof(pFile));

		return 0;
	}
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* unEmpleado;
	int r;
	int retorno;

	retorno = 1;

	if(pArrayListEmployee != NULL)
	{
		if(pFile == NULL)
		{
			printf("El archivo no existe");
			exit(EXIT_FAILURE);
		}

		do
		{
			unEmpleado = employee_new();

			r = fread(unEmpleado, sizeof(Employee), 1, pFile);

			if(r == 1)
			{
				if(unEmpleado != NULL)
				{
					ll_add(pArrayListEmployee, unEmpleado);
					printf("\nempleado agregado");
					retorno = 0;
				}
			}
			else
			{
				printf("ERROR parser");
			}
		}while(!feof(pFile));


	}
	  return retorno;
}

//*********************************************************************************************************

int parser_SaveAsText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* unEmpleado;
	int auxiliarId;
	char auxiliarNombre[128];
	int auxiliarHorasDeTrabajo;
	int auxiliarSueldo;
	int retorno;
	int len;
	int i;

	retorno = 1;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		for(i = 0; i < len; i++)
		{
			unEmpleado = (Employee*)ll_get(pArrayListEmployee, i);

			if(employee_getId(unEmpleado, &auxiliarId) == 0 && employee_getNombre(unEmpleado, auxiliarNombre) == 0 &&
			employee_getHorasTrabajadas(unEmpleado, &auxiliarHorasDeTrabajo) == 0 && employee_getSueldo(unEmpleado, &auxiliarSueldo) == 0)
			{
				fprintf(pFile, "\n%d, %s, %d, %d", auxiliarId, auxiliarNombre, auxiliarHorasDeTrabajo, auxiliarSueldo);
			}
		}
	}
	return retorno;
}


int parser_SaveAsBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* unEmpleado;
	int retorno;
	int len;
	int i;

	retorno = 1;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		for(i = 0; i < len; i++)
		{
			unEmpleado = (Employee*)ll_get(pArrayListEmployee, i);

			if(fwrite(unEmpleado, sizeof(Employee), 1, pFile) == 1)
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

//*********************************************************************************************************

