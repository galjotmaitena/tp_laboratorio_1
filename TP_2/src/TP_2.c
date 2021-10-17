/*
 ============================================================================
Galjot Maitena 1B
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include "ArrayEmployees.h"

#define TRUE 0
#define FALSE 1
#define TAM 1000

int main(void) {
	setbuf(stdout, NULL);

	Employee listaEmpleados[TAM];
	int opcion;
	int flag;
	int id;
	float totalSueldos;
	float promedioSueldos;
	int cantidadEmpleadosConMayorSueldo;

	flag = 0;
	id = 1000;

	if(initEmployees(listaEmpleados, TAM) == -1)
	{
		printf("Hubo un error con la inicializacion de los empleados");
	}

	do
	{
		opcion = Menu("\nIngrese una opcion: \n1. ALTA\n2. MODIFICAR\n3. BAJA\n4. INFORME\n5. SALIR");

		switch(opcion)
		{
		case 1:
			printf("\nALTA");

			if(IngresarUnEmpleado(listaEmpleados, TAM, &id) == -1)
			{
				printf("\nNo se pudo realizar la carga");
			}

			flag = 1;
			break;

		case 2:
			if(flag == 1)
			{
				printf("\nMODIFICAR");

				if(Modificar(listaEmpleados, TAM) == -1)
				{
					printf("\nNo se pudo realizar la modificacion");
				}
			}
			else
			{
				printf("\nDebe pasar por la opcion 1");
			}
			break;

		case 3:
			if(flag == 1)
			{
				printf("\nBAJA");

				if(BajaDeUnEmpleado(listaEmpleados, TAM) == -1)
				{
					printf("\nNo se pudo dar de baja al empleado");
				}
			}
			else
			{
				printf("\nDebe pasar por la opcion 1");
			}
			break;

		case 4:
			if(flag == 1)
			{
				printf("\nINFORME");

				switch(Menu("\n1. Empleados ordenados alfabeticamente por apellido y sector.\n2. Total y promedio de los salarios."))
				{
				case 1:
					switch(Menu("\n0. DOWN (mayor a menor)\n1. UP (menor a mayor)\n2. SALIR"))
					{
					case 0:
						sortEmployees(listaEmpleados, TAM, 0);
						break;
					case 1:
						sortEmployees(listaEmpleados, TAM, 1);
						break;
					case 2:
						printf("\nSALIR");
						break;
					default:
						printf("\nOpcion invalida");
					}
					break;
				case 2:
					if(TotalYPromedioDeLosSueldos(listaEmpleados, TAM, &totalSueldos, &promedioSueldos) == 0)
					{
						printf("\nEl total de los sueldos es %.2f", totalSueldos);
						printf("\nEl promedio de los sueldos es %.2f", promedioSueldos);
					}
					else
					{
						printf("\nNo se pudieron calcular los datos");
					}

					if(EmpleadosConSueldoMayorAlPromedio(listaEmpleados, TAM, promedioSueldos, &cantidadEmpleadosConMayorSueldo) == 0)
					{
						printf("\nHay %d empleados que tienen un sueldo mayor al promedio\n", cantidadEmpleadosConMayorSueldo);
					}
					else
					{
						printf("\nNo se encontro ningun empleado que supere el sueldo promedio");
					}
					break;
				}
			}
			else
			{
				printf("\nDebe pasar por la opcion 1");
			}
			break;

		case 5:
		    printf("\nSALIR");
		    break;

		default:
			printf("\nUsted ingreso una opcion invalida");
		}
	}while(opcion != 5);

	return EXIT_SUCCESS;
}
