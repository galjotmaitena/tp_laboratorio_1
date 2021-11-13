#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Input.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* miArchivo;
	int retorno;

	retorno = 1;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		miArchivo = fopen(path, "r");

		if(miArchivo != NULL)
		{
			if(parser_EmployeeFromText(miArchivo, pArrayListEmployee) == 0)
			{
				fclose(miArchivo);
				retorno = 0;
			}
			else
			{
				fclose(miArchivo);
				printf("\nNo se pudo parsear correctamente.");
			}
		}

	}
    return retorno;
}


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
			if(parser_EmployeeFromBinary(miArchivo, pArrayListEmployee) == 0)
			{
				retorno = 0;
				fclose(miArchivo);
			}
			else
			{
				fclose(miArchivo);
				printf("\nNo se pudo parsear correctamente.");
			}
		}
	}

	return retorno;
}

//*********************************************************************************************************

int controller_getLastId(char* path, int* id)
{
    FILE* pLastId;
	int retorno;
	int funcionId;
	int auxiliarId;
	int r;

    retorno = -1;

    if(path != NULL && id != NULL)
    {
    	pLastId = fopen(path, "r");

    	if(pLastId != NULL)
    	{
    		do
    		{
    			r = fscanf(pLastId, "%d", &funcionId);

    			if(r == 1)
    			{
    				auxiliarId = funcionId;
    			    retorno = 0;
    			}
    		}while(!feof(pLastId));

    		*id = auxiliarId + 1;

    		fclose(pLastId);
    	}
    }

    return retorno;
}

int controller_saveLastId(char* path, int id)
{
    FILE* pLastId;
	int retorno;

    retorno = -1;

    if(path != NULL)
    {
    	pLastId = fopen(path, "w") ;

    	if(pLastId != NULL)
    	{
    			fprintf(pLastId, "%d", id);

    			retorno = 0;

    		fclose(pLastId);
    	}
    }

    return retorno;
}

//**********************************************************************************************

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* unEmpleado;
	int id;
	char nombre[128];
	char horasTrabajadas[50];
	char sueldo[50];
	char auxiliarId[50];
	int retorno;
	int respuesta;

	retorno = 1;
	unEmpleado = NULL;

	if(pArrayListEmployee != NULL)
	{
		respuesta = controller_getLastId("last_id.txt", &id);
		itoa(id, auxiliarId, 10);

		if(respuesta == 0)
		{
			printf("\n%s", auxiliarId);
			IngresarCadena(nombre, "\nIngrese el nombre del empleado: ", "Dato invalido", 128, 2);
			IngresarCadenaNumerica(horasTrabajadas, "\nIngrese las horas de trabajo: ", "Dato invalido", 50, 2);
			IngresarCadenaNumerica(sueldo, "\nIngrese el sueldo: ", "Dato invalido", 50, 2);

			unEmpleado = employee_newParametros(auxiliarId, nombre, horasTrabajadas, sueldo);

			if(ll_add(pArrayListEmployee, unEmpleado) == 0)
			{
				if(controller_saveLastId("last_id.txt", id) == 0)
				{
					retorno = 0;
				}
			}
		}
		else
		{
			employee_delete(unEmpleado);
		}
	}

    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* unEmpleado;
	int auxiliarId;
	int index;
	int len;
	int retorno;

	retorno = 1;
	unEmpleado = NULL;

	if(pArrayListEmployee != NULL)
	{
		if(ll_isEmpty(pArrayListEmployee) == 0)
		{
			controller_ListEmployee(pArrayListEmployee);

			IngresarEntero("\nIngrese el id del empleado en el que desea hacer una modificacion: ", "Ingreso invalido", &auxiliarId, 2);

			index = employee_GetById(pArrayListEmployee, auxiliarId);

			unEmpleado = (Employee*)ll_get(pArrayListEmployee, index);

			employee_ImprimirUnEmpleado(unEmpleado);

			if(Menu("\n¿Este es el empleado que desea modificar?\n1. SI\n2. NO") == 1)
			{
				len = ll_len(pArrayListEmployee);

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

				retorno = 0;
			}
		}

	}

	   return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* unEmpleado;
	int index;
	int auxiliarId;
	int retorno;

	retorno = 1;

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

				retorno = 0;
			}
		}
	}

    return retorno;
}

//*********************************************************************************************************


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

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	LinkedList* pListaOrdenada;
	int retorno;
	int ordenamiento;
	retorno = 1;

	if(pArrayListEmployee != NULL)
	{
		pListaOrdenada = ll_clone(pArrayListEmployee);
		ordenamiento = employee_AscendenteDescendente("\n0. Mayor a Menor\n1. Menor a Mayor\nIngrese la forma en la que quiere ordenar: ");

		if(ordenamiento == -1)
		{
			printf("\nERROR");
		}
		else
		{
			switch(Menu("\n1. Ordenar por nombre.\n2. Ordenar por horas trabajadas.\n3. Ordenar por sueldo."))
			{
			case 1:
				if(ll_sort(pListaOrdenada, employee_CompareByName, ordenamiento) == 0)
				{
					controller_ListEmployee(pListaOrdenada);
					printf("\nLista ordenada.");
				}
				else
				{
					printf("ERROR");
				}
				break;
			case 2:
				if(ll_sort(pListaOrdenada, employee_CompareByHours, ordenamiento) == 0)
				{
					controller_ListEmployee(pListaOrdenada);
					printf("\nLista ordenada.");
				}
				else
				{
					printf("ERROR");
				}
				break;
			case 3:
				if(ll_sort(pListaOrdenada, employee_CompareBySalary, ordenamiento) == 0)
				{
					controller_ListEmployee(pListaOrdenada);
					printf("\nLista ordenada.");
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

			retorno = 0;
		}

	}

    return retorno;
}

//*********************************************************************************************************


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* miArchivo;
	int retorno;

	retorno = 1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		miArchivo = fopen(path, "w");

		if(miArchivo != NULL)
		{
			if(parser_SaveAsText(miArchivo, pArrayListEmployee) == 0)
			{
				if(controller_saveAsBinary("data.bin", pArrayListEmployee) == 0)
				{
					printf("\nSe guardaron los datos exitosamente.");

					retorno = 0;
				}
			}

			fclose(miArchivo);
		}
	}

    return retorno;
}

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
			if(parser_SaveAsBinary(miArchivo, pArrayListEmployee) == 0)
			{
				if(controller_saveAsText("data.csv", pArrayListEmployee) == 0)
				{
					printf("\nSe guardaron los datos exitosamente.");

					retorno = 0;
				}
			}

			fclose(miArchivo);
		}
	}

	   return retorno;
}


