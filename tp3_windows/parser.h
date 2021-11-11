/*
 * parser.h
 *
 *  Created on: 8 nov 2021
 *      Author: EXOSMART
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_SaveAsText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_SaveAsBinary(FILE* pFile , LinkedList* pArrayListEmployee);


#endif /* PARSER_H_ */
