/*
 * ArrayEmployees.c
 *
 *  Created on: 10 oct 2021
 *      Author: EXOSMART
 */
#include "ArrayEmployees.h"

int initEmployees(Employee* list, int len)
{
	int i;
	int retorno;

	retorno = -1;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE;
			retorno = 0;
		}
	}

	return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno;
	int i;

	retorno = -1;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].salary = salary;
				list[i].sector = sector;
				list[i].isEmpty = FALSE;
				break;
			}

			retorno = 0;
		}
	}

	return retorno;
}

int IngresarUnEmpleado(Employee* lista, int tamanio, int* idContador)
{
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int retorno;

	retorno = -1;

	if(lista != NULL && tamanio > 0)
	{
		*idContador = *idContador + 1;
		if(IngresarCadena(nombre, "\nIngrese nombre del empleado: ", "\nIngreso invalido", 51, 2) == 1)
		{
			printf("\nNo se pudo ingresar el nombre");
		}

		if(IngresarCadena(apellido, "\nIngrese apellido del empleado: ", "\nIngreso invalido", 51, 2) == 1)
		{
			printf("\nNo se pudo ingresar el apellido");
		}

		if(IngresarFlotante("\nIngrese salario del empleado: ", "\nIngreso invalido", &salario, 2) == 1)
		{
			printf("\nNo se pudo ingresar el salario");
		}

		if(IngresarEntero("\nIngrese sector del empleado: ", "\nIngreso invalido", &sector, 2) == 1)
		{
			printf("\nNo se pudo ingresar el sector");
		}

		id = *idContador;

		addEmployee(lista, tamanio, id, nombre, apellido, salario, sector);

		retorno = 0;
	}

	return retorno;
}

int findEmployeeById(Employee* list, int len,int id)
{
	int retorno;
	int i;

	retorno = -1;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].id == id)
			{
				printf("\n*******************************************************************************");
				MostrarUnEmpleado(list[i]);
				printf("\n*******************************************************************************");

				retorno = i;
			}
		}
	}

	return retorno;
}

int removeEmployee(Employee* list, int len, int id)
{
	int retorno;
	int i;
	int index;

	retorno = -1;

	index = findEmployeeById(list, len, id);

	if(index == -1)
    {
		printf("No se encontro ningun empleado con ese id");
	}

	if(list != NULL && len > 0)
	{

		for(i = 0; i < len; i++)
		{
			if(index == i)
			{
				list[i].isEmpty = TRUE;
				retorno = 0;

				break;
			}
		}
	}

	return retorno;
}


int BajaDeUnEmpleado(Employee lista[], int tamanio)
{
	int retorno;
	int id;

	retorno = -1;

	if(lista != NULL && tamanio > 0)
	{
		if(printEmployees(lista, tamanio) == -1)
		{
			printf("No hay ningun empleado ingresado");
		}

		IngresarEntero("\nIngrese el id del empleado que desea dar de baja: ", "\nIngreso invalido", &id, 2);

		if(removeEmployee(lista, tamanio, id) == 0)
		{
			if(printEmployees(lista, tamanio) == -1)
			{
				printf("No hay ningun empleado ingresado");
			}

			retorno = 0;
		}
		else
		{
			printf("No se pudo dar de baja al empleado");
		}
	}

	return retorno;
}

int Modificar(Employee lista[], int tamanio)
{
	int retorno;
	int id;
	int opcion;
	int i;

	retorno = -1;

	if(lista != NULL && tamanio > 0)
	{
		if(printEmployees(lista, tamanio) == -1)
		{
			printf("No hay ningun empleado ingresado");
		}

		IngresarEntero("\nIngrese el id del empleado en el que quiere realizar una modificacion: ", "\nIngreso invalido", &id, 2);

		i = findEmployeeById(lista, tamanio, id);

		if(i == -1)
		{
			printf("No se encontro ningun empleado con ese id");
		}

		opcion = Menu("\n1. Modificar NOMBRE.\n2. Modificar APELLIDO.\n3. Modificar SALARIO.\n4. Modificar SECTOR.\n");

		switch(opcion)
		{
		case 1:
			if(ModificarNombre(lista, tamanio, i) == -1)
			{
				printf("No se pudo modificar el nombre");
			}
			break;
		case 2:
			if(ModificarApellido(lista, tamanio, i) == -1)
			{
				printf("No se pudo modificar el apellido");
			}
			break;
		case 3:
			if(ModificarSalario(lista, tamanio, i) == -1)
			{
				printf("No se pudo modificar el salario");
			}
			break;
		case 4:
			if(ModificarSector(lista, tamanio, i) == -1)
			{
				printf("No se pudo modificar el sector");
			}
			break;
		}

		retorno = 0;
	}

	return retorno;
}

int ModificarNombre(Employee lista[], int tamanio, int i)
{
	int retorno;
	char auxiliarNombre[51];

	retorno = -1;

	if(lista != NULL && tamanio > 0)
	{
		IngresarCadena(auxiliarNombre, "\nIngrese el nuevo nombre: ", "\nIngreso invalido", 51, 2);
		strcpy(lista[i].name, auxiliarNombre);

		retorno = 0;
	}

	return retorno;
}

int ModificarApellido(Employee lista[], int tamanio, int i)
{
	int retorno;
	char auxiliarApellido[51];

	retorno = -1;

	if(lista != NULL && tamanio > 0)
	{
		IngresarCadena(auxiliarApellido, "\nIngrese el nuevo apellido: ", "\nIngreso invalido", 51, 2);
		strcpy(lista[i].lastName, auxiliarApellido);

		retorno = 0;
	}

	return retorno;
}

int ModificarSalario(Employee lista[], int tamanio, int i)
{
	int retorno;
	float auxiliarSalario;

	retorno = -1;

	if(lista != NULL && tamanio > 0)
	{
		IngresarFlotante("\nIngrese el nuevo salario: ", "\nIngreso invalido", &auxiliarSalario, 2);
		lista[i].salary = auxiliarSalario;

		retorno = 0;
	}

	return retorno;
}

int ModificarSector(Employee lista[], int tamanio, int i)
{
	int retorno;
	int auxiliarSector;

	retorno = -1;

	if(lista != NULL && tamanio > 0)
	{
		IngresarEntero("\nIngrese el nuevo sector: ", "\nIngreso invalido", &auxiliarSector, 2);
		lista[i].sector = auxiliarSector;

		retorno = 0;
	}

	return retorno;
}

int TotalYPromedioDeLosSueldos(Employee lista[], int tamanio, float* totalSueldos, float* promedioSueldos)
{
	int retorno;
	float acumuladorSueldos;
	int contadorEmpleados;
	int i;

	retorno = -1;
	acumuladorSueldos = 0;
	contadorEmpleados = 0;

	if(lista != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(lista[i].isEmpty == FALSE)
			{
				contadorEmpleados++;
				acumuladorSueldos += lista[i].salary;

				retorno = 0;
			}
		}
	}

	*totalSueldos = acumuladorSueldos;
	*promedioSueldos = CalcularPromedioDeLosSueldos(acumuladorSueldos, contadorEmpleados);

	return retorno;
}

float CalcularPromedioDeLosSueldos(float totalSueldos, int cantidadDeEmpleados)
{
	float promedio;

	promedio = totalSueldos / cantidadDeEmpleados;

	return promedio;
}

int EmpleadosConSueldoMayorAlPromedio(Employee lista[], int tamanio, float sueldoPromedio, int* cantidadDeEmpleadosConMayorSueldo)
{
	int retorno;
	int i;
	int contador;

	retorno = -1;
	contador = 0;

	if(lista != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(lista[i].salary > sueldoPromedio)
			{
				contador++;

				retorno = 0;
			}
		}
	}

	*cantidadDeEmpleadosConMayorSueldo = contador;

	return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
	int retorno;

	retorno = -1;

	if(list != NULL && len > 0)
	{
		if(order == 1)
		{
			if(OrdenarPorSectorUp(list, len) == 0)
			{
				printEmployees(list, len);
			}
			else
			{
				printf("No se pudo ordenar por sector");
			}
		}
		else
		{
			if(OrdenarPorSectorDown(list, len) == 0)
			{
				printEmployees(list, len);
			}
			else
			{
				printf("No se pudo ordenar por sector");
			}
		}
	}

	return retorno;
}

int OrdenarPorSectorUp(Employee lista[], int tamanio)
{
	int retorno;
	int i;
	int j;
	Employee auxiliar;

	retorno = -1;

	for(i = 0; i < tamanio - 1; i++)
	{
		for(j = i + 1; j < tamanio; j++)
		{
			if(lista[i].isEmpty == FALSE)
			{
				if(lista[i].sector > lista[j].sector)
				{
					auxiliar = lista[i];
					lista[i] = lista[j];
					lista[j] = auxiliar;

					retorno = 0;
				}
				else
				{
					if(lista[i].sector == lista[j].sector && strcmp(lista[i].lastName, lista[j].lastName) > 0)
					{
						auxiliar = lista[i];
						lista[i] = lista[j];
						lista[j] = auxiliar;
					}
				}
			}

		}
	}

	return retorno;
}

int OrdenarPorSectorDown(Employee lista[], int tamanio)
{
	int retorno;
	int i;
	int j;
	Employee auxiliar;

	retorno = -1;

	for(i = 0; i < tamanio - 1; i++)
	{
		for(j = i + 1; j < tamanio; j++)
		{
			if(lista[i].isEmpty == FALSE)
			{
				if(lista[i].sector < lista[j].sector)
				{
					auxiliar = lista[i];
					lista[i] = lista[j];
					lista[j] = auxiliar;

					retorno = 0;
				}
				else
				{
					if(lista[i].sector == lista[j].sector && strcmp(lista[i].lastName, lista[j].lastName) < 0)
					{
						auxiliar = lista[i];
						lista[i] = lista[j];
						lista[j] = auxiliar;

					}
			    }

			}
		}
	}

	return retorno;
}

int printEmployees(Employee* list, int length)
{
	int retorno;
	int i;

	retorno = -1;

	if(list != NULL && length > 0)
	{
		for(i = 0; i < length; i++)
		{
			MostrarUnEmpleado(list[i]);
		}

		retorno = 0;
	}

	return retorno;
}

void MostrarUnEmpleado(Employee unEmpleado)
{
	if(unEmpleado.isEmpty == FALSE)
	{
		printf("\n%-10d %-10s %-10s %.2f %5d\n", unEmpleado.id, unEmpleado.lastName, unEmpleado.name, unEmpleado.salary, unEmpleado.sector);
	}
}
