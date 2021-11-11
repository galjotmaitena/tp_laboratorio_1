/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
//constructor, crea la lista en memoria
LinkedList* ll_newLinkedList(void);
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

//agrega un empleado, le paso la lista y un puntero de cualquier tipo(el elemento que quiero agregar)
int ll_add(LinkedList* this, void* pElement);

//el valor de len se ajusta a la cantidad de elementos que tengo en la lista, funciona como el strlen
int ll_len(LinkedList* this);

//devuelve el empleado que este en el indice pasado por parametro
void* ll_get(LinkedList* this, int index);

//agrega un dato a la lista, a diferencia del add lo setea en un lugar especifico, cambia hacia a donde apunta el puntero
int ll_set(LinkedList* this, int index,void* pElement);

//mete en el medio de dos elementos, otro elemento
int ll_push(LinkedList* this, int index, void* pElement);

//elimina un elemento de la lista en un indice especificado, elimina el nodo de la lista
int ll_remove(LinkedList* this,int index);

//elimina el nodo de la lista, pero a diferencia del remove, devuelve el dato                                         BAJA
void* ll_pop(LinkedList* this,int index);

//limpia la lista, borra todos los elementos que haya en la lista, sigue existiendo en memoria
int ll_clear(LinkedList* this);

//borra la lista y la saca de memoria, es un destructor                                                              SALIR
int ll_deleteLinkedList(LinkedList* this);

//devuelve el indice en el que esta el dato                                                                          MODIFICAR
int ll_indexOf(LinkedList* this, void* pElement);

//dice si la lista esta vacia       1 = VACIA ----- 0 = CARGADA                                                                                 VALIDAR
int ll_isEmpty(LinkedList* this);

//le paso un x elemento y te dice si esta contenido ese dato en la lista
int ll_contains(LinkedList* this, void* pElement);

//si la lista 2 esta incluida en la lista 1
int ll_containsAll(LinkedList* this,LinkedList* this2);

//me devuelve una parte de la lista, devuelve una lista nueva
LinkedList* ll_subList(LinkedList* this,int from,int to);

//clona la lista, sirve para ordenar y no perder el orden original de la lista
LinkedList* ll_clone(LinkedList* this);

//ordena la lista, recibe un puntero a funcion
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
