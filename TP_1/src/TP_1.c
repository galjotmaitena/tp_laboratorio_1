/*
 ============================================================================
 1. Ingresar 1er operando (A=x)
 2. Ingresar 2do operando (B=y)
 3. Calcular todas las operaciones
 a) Calcular la suma (A+B)
 b) Calcular la resta (A-B)
 c) Calcular la division (A/B)
 d) Calcular la multiplicacion (A*B)
 e) Calcular el factorial (A!)
 4. Informar resultados
 a) “El resultado de A+B es: r”
 b) “El resultado de A-B es: r”
 c) “El resultado de A/B es: r” o “No es posible dividir por cero”
 d) “El resultado de A*B es: r”
 e) “El factorial de A es: r1 y El factorial de B es: r2”
 5. Salir
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define TAM 4

int Menu(char opciones[]);
void SeleccionDelMenu(int opcion, int* x, int* y);
void SeleccionOpcionCalcular(int opcion, int* x, int* y);

int Suma(int numero1, int numero2);
int Resta(int numero1, int numero2);
int Division(int numero1, int numero2);
int Multiplicacion(int numero1, int numero2);

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int primerOperando;
	int segundoOperando;

	do {
		opcion = Menu("1. Ingresar primer operando \n2. Ingresar segundo operando \n3. Calcular todas las operaciones \n4. Informar resultados \n5. Salir \n");

		SeleccionDelMenu(opcion, &primerOperando, &segundoOperando);

	} while (opcion != 5);

	printf("%d %d", primerOperando, segundoOperando);

	return EXIT_SUCCESS;
}

int Menu(char opciones[]) {
	int opcion;

	printf("%s", opciones);
	scanf("%d", &opcion);

	return opcion;
}

void SeleccionDelMenu(int opcion, int* x, int* y){
	int numero1;
	int numero2;
	int opcionCalcular;

	switch (opcion) {
			case 1:
				printf("\nUsted ha seleccionado la opcion 1. Ingresar primer operando");

				printf("\nIngrese primer operando");
				scanf("%d", &numero1);

				*x = numero1;

				break;
			case 2:
				printf("Usted ha seleccionado la opcion 2. Ingresar segundo operando\n");

				printf("Ingrese segundo operando");
				scanf("%d", &numero2);

				*y = numero2;

				break;
			case 3:
				printf("Usted ha seleccionado la opcion 3. Calcular todas las operaciones\n");

				opcionCalcular = Menu("1. Calcular la suma \n2. Calcular la resta \n3. Calcular la division \n4. Calcular la multiplicacion \n5. Calcular el factorial \n");

				SeleccionOpcionCalcular(opcionCalcular, &numero1, &numero2);

				break;
			case 4:
				printf("Usted ha seleccionado la opcion 4. Informar resultados\n");

/*				switch(opcionCalcular){
				case 1:
				    printf("El resultado de la suma es %d", resultadoSuma);
					break;
				case 2:
				    printf("El resultado de la resta es %d", resultadoResta);
					break;
				case 3:
				    printf("El resultado de la division es %d", resultadoDivision);
					break;
				case 4:
				   printf("El resultado de la multiplicacion es %d", resultadoMultiplicacion);
					break;
				}
*/
				break;
			case 5:
				printf("Usted ha seleccionado la opcion 5. Salir\n");
				break;
			default:
				printf("OPCION INVALIDA\n");
			}

}

void SeleccionOpcionCalcular(int opcion, int* x, int* y){
	int resultados[TAM] = {};

		switch (opcion) {
		case 1:
			printf("\nUsted ha seleccionado la opcion a. Calcular suma");

			resultados[1] = Suma(*x, *y);

			break;
		case 2:
			printf("Usted ha seleccionado la opcion b. Calcular resta\n");

			resultados[2] = Resta(*x, *y);

			break;
		case 3:
			printf("Usted ha seleccionado la opcion c. Calcular division\n");

			resultados[3] = Division(*x, *y);

			break;
		case 4:
			printf(
					"Usted ha seleccionado la opcion d. Calcular multiplicacion\n");

			resultados[4] = Multiplicacion(*x, *y);

			break;
		}

	printf("%d", resultados[4]);
}

int Suma(int numero1, int numero2){
	int resultado;

	resultado = numero1 + numero2;

	return resultado;
}

int Resta(int numero1, int numero2){
	int resultado;

	resultado = numero1 - numero2;

	return resultado;
}

int Multiplicacion(int numero1, int numero2){
	int resultado;

	resultado = numero1 * numero2;

	return resultado;
}

int Division(int numero1, int numero2){
	int resultado;

	resultado = numero1 / numero2;

	return resultado;
}


