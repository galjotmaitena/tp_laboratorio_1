#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Input.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* miArchivo;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		miArchivo = fopen(path, "r");

		if(miArchivo != NULL)
		{
			if(parser_EmployeeFromText(miArchivo, pArrayListEmployee) == 1)
			{
				printf("ERROR");
				fclose(miArchivo);

				return 1;
			}
			else
			{
				fclose(miArchivo);
				return 0;
			}
		}

	}
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* miArchivo;
	int len;
	int i;
	Employee* unEmpleado;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		if(controller_loadFromText(path, pArrayListEmployee) == 1)
		{
			printf("\nERROR");
		}
		else
		{
			printf("\nLoad from text exitoso");
		}

		len = ll_len(pArrayListEmployee);

					printf("\n**************************   %d    **********************************", len);

		miArchivo = fopen("data.bin", "wb");

		printf("\nCONTROLLER");
		if(miArchivo != NULL)
		{
			printf("\narchivo abierto");

			len = ll_len(pArrayListEmployee);

			printf("\n**************************   %d    **********************************", len);

			for(i = 0; i < len; i++)
			{
				unEmpleado = (Employee*)ll_get(pArrayListEmployee, i);

				fwrite(unEmpleado, sizeof(Employee*), 1, miArchivo);
			}

			fclose(miArchivo);

			miArchivo = fopen("data.bin", "rb");

			if(parser_EmployeeFromBinary(miArchivo, pArrayListEmployee) == 1)
			{
				printf("ERROR controller");
				fclose(miArchivo);

				return 1;
			}
			else
			{
				printf("\narchivo parseado");
				fclose(miArchivo);

				len = ll_len(pArrayListEmployee);

							printf("\n**************************   %d    **********************************", len);

				return 0;
			}
		}
		else
		{
			printf("\narchivo NULL");
		}
	}

    return 1;
}*/

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* miArchivo;
	int retorno;

	retorno = 1;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		miArchivo = fopen(path, "rb");

		if(miArchivo != NULL)
		{
			if(parser_EmployeeFromBinary(miArchivo, pArrayListEmployee) == 1)
			{
				printf("\nERROR.");
				fclose(miArchivo);
			}
			else
			{
				fclose(miArchivo);
				retorno = 0;
			}
		}
	}

	return retorno;
}



//*********************************************************************************************************

/*
int controller_getLastId(LinkedList* pArrayListEmployee)
{
	FILE* miArchivo;
	FILE* lastId;
	Employee* unEmpleado;
	int retorno;
	int i;
	int len;
	int id;

	retorno = -1;

	if(pArrayListEmployee != NULL)
	{
		miArchivo = fopen("data.csv", "r");

		if(miArchivo != NULL)
		{
			if(parser_EmployeeFromText(miArchivo, pArrayListEmployee) == 1)
			{
				printf("ERROR");
				fclose(miArchivo);
			}
			else
			{
				fclose(miArchivo);

				len = ll_len(pArrayListEmployee);

				for(i = 0; i < len; i++)
				{
					unEmpleado = ll_get(pArrayListEmployee, i);

					if(employee_getId(unEmpleado, &id) == -1)
					{
						printf("ERROR");
					}
					else
					{
						lastId = fopen("lastID.dat", "wb");

						fwrite(id, sizeof(int), len, lastId);

						fclose(lastId);
					}
				}

				lastId = fopen("lastID.dat", "rb");


			}
		}
	}

	return retorno;
}*/
/*
int controller_getLastId(LinkedList* pArrayListEmployee)
{
	int retorno;
	int id;

	id = 1000;

	retorno = -1;

	if(pArrayListEmployee != NULL)
	{

	}

	return retorno;
}

int controller_escribirId(LinkedList* pArrayListEmployee)
{
	FILE* miArchivo;
	int retorno;

	retorno = -1;

	if(pArrayListEmployee != NULL)
	{
		miArchivo = fopen("ultimoId.csv", "w");

		if(miArchivo != NULL)
		{
			fprintf(miArchivo, "1000");

			fclose(miArchivo);
		}
	}

	return retorno;
}*/
//*******************MODIFICAAAAAAAAAAAAAAAAR
int controller_getLastId(LinkedList* pArrayListEmployee){
    int index = 0, id, maxId = 0, len;
    Employee* auxEmp;

    if(pArrayListEmployee == NULL){
        return EXIT_FAILURE;
    }
    len = ll_len(pArrayListEmployee);
    do{
        auxEmp = (Employee*) ll_get(pArrayListEmployee, index);
        if(employee_getId(auxEmp, &id)){
            return EXIT_FAILURE;
        }
        if(maxId < id){
            maxId = id;
        }
        index++;
    }while(index < len);

    return maxId + 1;
}
//**********************************************************************************************
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* unEmpleado;
	char id[50];
	char nombre[128];
	char horasTrabajadas[50];
	char sueldo[50];
	int auxiliarId;

	unEmpleado = NULL;

	if(pArrayListEmployee != NULL)
	{
		auxiliarId = controller_getLastId(pArrayListEmployee);
		itoa(auxiliarId, id, 50);

		IngresarCadena(nombre, "\nIngrese el nombre del empleado: ", "Dato invalido", 128, 2);
		IngresarCadenaNumerica(horasTrabajadas, "\nIngrese las horas de trabajo: ", "Dato invalido", 50, 2);
		IngresarCadenaNumerica(sueldo, "\nIngrese el sueldo: ", "Dato invalido", 50, 2);

		unEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

		ll_add(pArrayListEmployee, unEmpleado);

		return 0;
	}

    return 1;
}



/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* unEmpleado;
	int auxiliarId;
	int index;
	int len;

	unEmpleado = NULL;

	if(pArrayListEmployee != NULL)
	{
		if(ll_isEmpty(pArrayListEmployee) == 0)
		{
			controller_ListEmployee(pArrayListEmployee);

			IngresarEntero("\nIngrese el id del empleado en el que desea hacer una modificacion: ", "Ingreso invalido", &auxiliarId, 2);

			index = employee_GetById(pArrayListEmployee, auxiliarId);
			//index = ll_indexOf(pArrayListEmployee, id);

			unEmpleado = (Employee*)ll_get(pArrayListEmployee, index);

			employee_ImprimirUnEmpleado(unEmpleado);

			len = ll_len(pArrayListEmployee);

			if(Menu("\n¿Este es el empleado que desea modificar?\n1. SI\n2. NO") == 1)
			{
				switch(Menu("\n1. Modificar nombre.\n2. Modificar horas trabajadas.\n3. Modificar sueldo."))
				{
				case 1:
					if(employee_ModificarNombre(pArrayListEmployee, len, index) == -1)
					{
						printf("\nERROR.");
					}
					break;
				case 2:
					if(employee_ModificarHorasTrabajadas(pArrayListEmployee, len, index) == -1)
					{
						printf("\nERROR.");
					}
					break;
				case 3:
					if(employee_ModificarSueldo(pArrayListEmployee, len, index) == -1)
					{
						printf("\nERROR.");
					}
					break;
				case 4:
					printf("\nSALIR");
					break;
				default:
					printf("\nOpcion invalida");
					break;
				}

				return 0;
			}
		}

	}

	   return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* unEmpleado;
	int index;
	int auxiliarId;

	if(pArrayListEmployee != NULL)
	{
		if(ll_isEmpty(pArrayListEmployee) == 0)
		{
			controller_ListEmployee(pArrayListEmployee);

			IngresarEntero("\nIngrese el id del empleado que desea dar de baja: ", "Ingreso invalido", &auxiliarId, 2);

			index = employee_GetById(pArrayListEmployee, auxiliarId);

			unEmpleado = (Employee*)ll_get(pArrayListEmployee, index);

			employee_ImprimirUnEmpleado(unEmpleado);

			if(Menu("\n¿Este es el empleado que desea dar de baja?\n1. SI\n2. NO") == 1)
			{
				ll_remove(pArrayListEmployee, index);
				employee_delete(unEmpleado);
				printf("\nEmpleado eliminado exitosamente.");

				return 0;
			}
		}
	}

    return 1;
}

//*********************************************************************************************************

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	int len;
	Employee* auxiliarEmpleado;
	int retorno;

	retorno = 1;

	auxiliarEmpleado = NULL;

	if(pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		printf("\n******************************** %d ******************************", len);

		for(i = 0; i < len; i++)
		{
			auxiliarEmpleado = (Employee*)ll_get(pArrayListEmployee, i);

			if(auxiliarEmpleado != NULL)
			{
				employee_ImprimirUnEmpleado(auxiliarEmpleado);
				retorno = 0;
			}
		}
	}
    return retorno;
}

//*********************************************************************************************************

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;

	retorno = 1;

	if(pArrayListEmployee != NULL)
	{
		switch(Menu("\n1. Ordenar por nombre.\n2. Ordenar por horas trabajadas.\n3. Ordenar por sueldo."))
		{
		case 1:
			if(ll_sort(pArrayListEmployee, employee_CompareByName, 1) == 0)
			{
				printf("\nLista ordenada.");
				controller_ListEmployee(pArrayListEmployee);
			}
			else
			{
				printf("ERROR");
			}
			break;
		case 2:
			if(ll_sort(pArrayListEmployee, employee_CompareByHours, 1) == 0)
			{
				printf("\nLista ordenada.");
				controller_ListEmployee(pArrayListEmployee);
			}
			else
			{
				printf("ERROR");
			}
			break;
		case 3:
			if(ll_sort(pArrayListEmployee, employee_CompareBySalary, 1) == 0)
			{
				printf("\nLista ordenada.");
				controller_ListEmployee(pArrayListEmployee);
			}
			else
			{
				printf("ERROR");
			}
			break;
		case 4:
			printf("\nSALIR");
			break;
		default:
			printf("\nOpcion invalida");
			break;
		}
	}

    return retorno;
}

//*********************************************************************************************************

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* miArchivo;
	int len;
	int i;
	Employee* unEmpleado;
	int retorno;

	retorno = 1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		miArchivo = fopen(path, "w");

		if(miArchivo != NULL)
		{
			if(parser_SaveAsText(miArchivo, pArrayListEmployee) == 0)
			{
				printf("\nSe guardaron los datos exitosamente.");

				retorno = 0;
			}

			fclose(miArchivo);
		}
	}

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* miArchivo;
	int retorno;

	retorno = 1;


	if(path != NULL && pArrayListEmployee != NULL)
	{
		miArchivo = fopen(path, "wb");

		if(miArchivo != NULL)
		{
			if(parser_SaveFromBinary(miArchivo, pArrayListEmployee) == 0)
			{
				printf("\nSe guardaron los datos exitosamente.");

				retorno = 0;
			}

			fclose(miArchivo);
		}
	}

	   return retorno;
}


