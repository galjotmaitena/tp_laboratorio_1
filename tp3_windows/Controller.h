//controlar la lectura del archivo, PATH direccion del archivo, carpeta en la que esta el archivo
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/// \fn int controller_getLastId(char*, int*)
/// \brief Lee un archivo de texto que contiene el ultimo id, y a este se le suma 1 para sacar el proximo id
/// \param path
/// \param id Posicion de memoria donde se guardara el id
/// \return retona 0 si se obtubo el id, o -1 si no se logro conseguirlo
int controller_getLastId(char* path, int* id);

/// \fn int controller_saveLastId(char*, int)
/// \brief Guarda el nuevo id si se pudo añadir exitosamente al empleado
/// \param path
/// \param id Id a guardar
/// \return retona 0 si se guardo el id, o -1 si no se logro guardarlo
int controller_saveLastId(char* path, int id);
