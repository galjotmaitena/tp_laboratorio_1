/*
 ============================================================================
Galjot Maitena (1B)
 ============================================================================
 */

#include <stdlib.h>
#include "Funciones.h"
#include "OperacionesMatematicas.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int primerOperando;
	int flag1;
	int segundoOperando;
	int flag2;

	int resultadoSuma;
	int resultadoResta;
	float resultadoDivision;
	int resultadoMultiplicacion;
	int resultadoFactorial1;
	int resultadoFactorial2;

	int validacionDivision;
	int validacionFactorial1;
	int validacionFactorial2;

	int flag;

	flag = 0;

	flag1 = 0;
	flag2 = 0;

	do {
		opcion = Menu("1. Ingresar primer operando \n2. Ingresar segundo operando \n3. Calcular todas las operaciones \n4. Informar resultados \n5. Salir \n");

		switch(opcion){
		case 1:

			primerOperando = IngresarEntero(&flag1);

			break;
		case 2:

			segundoOperando = IngresarEntero(&flag2);

			break;
		case 3:

			if(flag1 != 0 && flag2 != 0)
			{
				Suma(primerOperando, segundoOperando, &resultadoSuma);

				Resta(primerOperando, segundoOperando, &resultadoResta);

					validacionDivision = ValidacionDivision(segundoOperando);

				Division((float)primerOperando, (float)segundoOperando, &resultadoDivision);

				Multiplicacion(primerOperando, segundoOperando, &resultadoMultiplicacion);

					validacionFactorial1 = ValidacionFactorial(primerOperando);

				Factorial (primerOperando, &resultadoFactorial1);

					validacionFactorial2 = ValidacionFactorial(segundoOperando);

				Factorial (segundoOperando, &resultadoFactorial2);

					flag = 1;
			}
			else
			{
				printf("\nUsted no ha ingresado algun operando");
				printf("\nComplete las opciones 1 y 2 para poder resolver los calculos");
			}

			break;
		case 4:

			if(flag == 1)
			{
				MostrarResultados(resultadoSuma, resultadoResta, validacionDivision, resultadoDivision, resultadoMultiplicacion, validacionFactorial1, resultadoFactorial1, validacionFactorial2, resultadoFactorial2);
			}
			else
			{
				printf("\nNo hay resultados, debe seleccionar la opcion 3 para que se realicen las operaciones\n");
			}

			break;
		case 5:

			printf("Usted ha seleccionado la opcion SALIR");

			break;
		default:

			printf("Usted ha seleccionado una opcion invalida");

		}

	} while (opcion != 5);

	return EXIT_SUCCESS;
}
