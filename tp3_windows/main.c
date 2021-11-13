#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Input.h"

/****************************************************
 Galjot Maitena divB

    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);

    int option = 0;
    int flag;

    flag = 1;

	LinkedList *listaEmpleados = ll_newLinkedList();

	do
	{
		option = Menu("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
					  "\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
					  "\n3. Alta de empleado."
					  "\n4. Modificar datos de empleado"
					  "\n5. Baja de empleado."
					  "\n6. Listar empleados."
					  "\n7. Ordenar empleados."
					  "\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
					  "\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
					  "\n10. Salir");

		switch (option)
		{
		case 1:
			if(flag == 1)
			{
				if(controller_loadFromText("data.csv", listaEmpleados) == 1)
				{
					printf("\nNo se pudo cargar en texto.");
					flag = 0;
				}
			}
			else
			{
				printf("\nEl archivo ya fue cargado en modo binario");
			}

			break;
		case 2:
			if(flag == 1)
			{
				if(controller_loadFromBinary("data.bin", listaEmpleados) == 1)
				{
					printf("\nNo se pudo cargar en binario.");
					flag = 0;
				}
			}
			else
			{
				printf("\nEl archivo ya fue cargado en modo binario");
			}

			break;
		case 3:
			if(controller_addEmployee(listaEmpleados) == 1)
			{
				printf("\nNo se pudo agregar al empleado.");
			}

			break;
		case 4:
			if(controller_editEmployee(listaEmpleados) == 1)
			{
				printf("\nNo se pudo realizra la modificacion.");
			}

			break;
		case 5:
			if(controller_removeEmployee(listaEmpleados) == 1)
			{
				printf("\nNo se pudo dar de baja.");
			}

			break;
		case 6:
			if(controller_ListEmployee(listaEmpleados) == 1)
			{
				printf("\nNo se pudo listar.");
			}

			break;
		case 7:
			if(controller_sortEmployee(listaEmpleados) == 1)
			{
				printf("\nNo se pudo ordenar.");
			}

			break;
		case 8:
			if(controller_saveAsText("data.csv", listaEmpleados) == 1)
			{
				printf("\nNo se pudo guardar el archivo en texto.");
			}

			break;
		case 9:
			if(controller_saveAsBinary("data.bin", listaEmpleados) == 1)
			{
				printf("\nNo se pudo guardar el archivo en binario.");
			}

			break;
		case 10:
			printf("\nSALIR");
			break;
		default:
			printf("\nOpcion invalida");
			break;
		}
	} while (option != 10);

	return 0;

}

