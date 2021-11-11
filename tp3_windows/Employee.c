#include "Employee.h"
#include "Input.h"
#include "LinkedList.h"

Employee* employee_new()
{
	Employee* pEmpleado;

	pEmpleado = (Employee*)malloc(sizeof(Employee));

	if(pEmpleado == NULL)
	{
		exit(EXIT_FAILURE);
	}

	return pEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee *pEmpleado;

	pEmpleado = employee_new();

	if (pEmpleado != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		if(EsNumerico(idStr) == 0)
		{
			employee_setId(pEmpleado, atoi(idStr));
		}
		else
		{
			printf("\nERROR.");
		}

		if(sonSoloLetras(nombreStr) == 0)
		{
			employee_setNombre(pEmpleado, nombreStr);
		}
		else
		{
			//printf("\nERROR."); REVISAAAAAAAAAAAAAAAAAAR
		}

		if(EsNumerico(horasTrabajadasStr) == 0)
		{
			employee_setHorasTrabajadas(pEmpleado, atoi(horasTrabajadasStr));
		}
		else
		{
			printf("\nERROR.");
		}

		if(EsNumerico(sueldoStr) == 0)
		{
			employee_setSueldo(pEmpleado, atoi(sueldoStr));
		}
		else
		{
			printf("\nERROR.");
		}

	}

	return pEmpleado;
}
void employee_delete(Employee* this)
{
	if(this != NULL)
	{
	    free(this);
	}
}

//************************************************************************

int employee_setId(Employee* this,int id)
{
	int retorno;

	retorno = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
int employee_getId(Employee* this,int* id)
{
	int retorno;

	retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

//************************************************************************

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno;

	retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strncpy(this->nombre, nombre, 128);
		retorno = 0;
	}

	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno;

	retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre, 128);
		retorno = 0;
	}

	return retorno;
}

//************************************************************************

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno;

	retorno = -1;

	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno;

	retorno = -1;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

//************************************************************************

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno;

	retorno = -1;

	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}

	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno;

	retorno = -1;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}

	return retorno;
}

//************************************************************************

int employee_ImprimirUnEmpleado(Employee* this)
{
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	int retorno;

	retorno = -1;

	if(this != NULL)
	{
		if(employee_getId(this, &id) == 0 && employee_getNombre(this, nombre) == 0 &&
		   employee_getHorasTrabajadas(this, &horasTrabajadas) == 0 && employee_getSueldo(this, &sueldo) == 0)
		{
			printf("\n%d -- %s -- %d -- %d", this->id, this->nombre, this->horasTrabajadas, this->sueldo);

			retorno = 0;
		}
	}

	return retorno;
}

//************************************************************************

int employee_ModificarNombre(LinkedList* pArrayListEmployee, int tamanio, int index)
{
	Employee* unEmpleado;
	int retorno;
	char auxiliarNombre[128];
	int i;

	retorno = -1;

	if(pArrayListEmployee != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(i == index)
			{
				unEmpleado = (Employee*)ll_get(pArrayListEmployee, index);

				IngresarCadena(auxiliarNombre, "\nIngrese el nuevo nombre: ", "\nIngreso invalido", 128, 2);

				employee_setNombre(unEmpleado, auxiliarNombre);

				retorno = 0;

				break;
			}
		}
	}

	return retorno;
}

int employee_ModificarSueldo(LinkedList* pArrayListEmployee, int tamanio, int index)
{
	Employee* unEmpleado;
	int retorno;
	int auxiliarSueldo;
	int i;

	retorno = -1;

	if(pArrayListEmployee != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(i == index)
			{
				unEmpleado = (Employee*)ll_get(pArrayListEmployee, index);

				IngresarEntero("\nIngrese el nuevo sueldo: ", "\nIngreso invalido", &auxiliarSueldo, 2);

				employee_setSueldo(unEmpleado, auxiliarSueldo);

				retorno = 0;

				break;
			}
		}
	}

	return  retorno;
}

int employee_ModificarHorasTrabajadas(LinkedList* pArrayListEmployee, int tamanio, int index)
{
	Employee* unEmpleado;
	int retorno;
	int auxiliarHorasTrabajadas;
	int i;

	retorno = -1;

	if(pArrayListEmployee != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(i == index)
			{
				unEmpleado = (Employee*)ll_get(pArrayListEmployee, index);

				IngresarEntero("\nIngrese la nueva cantidad de horas: ", "\nIngreso invalido", &auxiliarHorasTrabajadas, 2);

				employee_setHorasTrabajadas(unEmpleado, auxiliarHorasTrabajadas);

				retorno = 0;

				break;
			}
		}
	}

	return retorno;
}

//************************************************************************

int employee_GetById(LinkedList* pArrayListEmployee,int id)
{
	Employee* auxiliarEmpleado;
	int retorno;
	int i;
	int len;
	int auxiliarId;

	retorno = -1;

	if(pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		for(i = 0; i < len; i++)
		{
			auxiliarEmpleado = (Employee*)ll_get(pArrayListEmployee, i);

			if(employee_getId(auxiliarEmpleado, &auxiliarId) == 0 && id == auxiliarId)
			{
				//MOSTRAR AL EMPLEADO
				//FUNCION CONFIRMAR
				retorno = i;
			}
		}
	}

	return retorno;
}

//************************************************************************

int employee_CompareByName(void* x, void* y)
{
	int compara;
	Employee* unEmpleado;
	Employee* otroEmpleado;

	if(x != NULL && y != NULL)
	{
		unEmpleado = (Employee*)x;//unboxing de la variable
		otroEmpleado = (Employee*)y;

		compara = strcmp(unEmpleado->nombre, otroEmpleado->nombre);
	}

	return compara;
}

int employee_CompareBySalary(void* x, void* y)
{
	int compara;
	Employee* unEmpleado;
	Employee* otroEmpleado;
	int unSueldo;
	int otroSueldo;

	compara = 0;

	if(x != NULL && y != NULL)
	{
		unEmpleado = (Employee*)x;//unboxing de la variable
		otroEmpleado = (Employee*)y;

		if(employee_getSueldo(unEmpleado, &unSueldo) > employee_getSueldo(otroEmpleado, &otroSueldo))
		{
			compara = 1;
		}
		else
		{
			if(employee_getSueldo(unEmpleado, &unSueldo) < employee_getSueldo(otroEmpleado, &otroSueldo))
			{
				compara = -1;
			}
		}
	}

	return compara;
}

int employee_CompareByHours(void* x, void* y)
{
	int compara;
	Employee* unEmpleado;
	Employee* otroEmpleado;
	int unaCantidadDeHoras;
	int otraCantidadDeHoras;

	compara = 0;

	if(x != NULL && y != NULL)
	{
		unEmpleado = (Employee*)x; //unboxing de la variable
		otroEmpleado = (Employee*)y;

		if(employee_getSueldo(unEmpleado, &unaCantidadDeHoras) > employee_getSueldo(otroEmpleado, &otraCantidadDeHoras))
		{
			compara = 1;
		}
		else
		{
			if(employee_getSueldo(unEmpleado, &unaCantidadDeHoras) < employee_getSueldo(otroEmpleado, &otraCantidadDeHoras))
			{
				compara = -1;
			}
		}
	}

	return compara;
}
