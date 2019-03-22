/**
 * @brief Se encarga de las funciones y la gestion de un conjunto de objetos llamado set
 *
 * @file set.h
 * @authors Luis Nucifora
 * @version 2.0
 * @date 10/03/2019
 * @copyright GNU Public License
 */


#ifndef SET_H
#define SET_H

#include "types.h"

#define MAX_NUM_ID 15
/**
* @brief La estructura de un conjunto de objetos o set
*
* Almacena las diferentes informaciones de un conjunto de objetos o set
*/
typedef struct _Set Set;
/*
*
* @brief: reserva memoria dinámica suficiente para almacenar un set y guarda su Id
* @return: la dirección del set creado
*
*/
Set* set_create();
/*
*
* @brief: libera la memoria dinámica reservada del set que se ha recibido
* @params: recibe como parámetro de entrada el set a liberar
* @return: devuelve ERROR si no se ha liberado la memoria, u OK si lo ha hecho correctamente
*
*/
void set_destroy(Set *set);
/*
*
* @brief: añade un objeto a nuestro set
* @params1: recibe como parámetro de entrada el objeto a añadir al set
* @params2: recibe la id del objeto añadido
* @return: devuelve ERROR si no se ha liberado la memoria, u OK si lo ha hecho correctamente
*
*/
STATUS set_add_object(Set *set, Id id);
/*
*
* @brief: elimina un objeto de nuestro set
* @params1: recibe como parámetro de entrada el objeto a eliminar del set
* @params2: recibe la id del objeto eliminado
* @return: devuelve ERROR si no se ha liberado la memoria, u OK si lo ha hecho correctamente
*
*/
STATUS set_del_object(Set *set, Id id);
/*
*
* @brief: compara un objeto de nuestro set
* @params1: recibe como parámetro de entrada el objeto a comparar del set
* @params2: recibe la id del objeto comparado
* @return: devuelve ERROR si no se ha liberado la memoria, u OK si lo ha hecho correctamente
*
*/
STATUS set_compare(Set *set, Id id);
/*
*
* @brief: comprueba si nuestro set esta completo de objetos
* @params1: recibe como parámetro de entrada set a revisar
* @return: devuelve TRUE si es asi y FALSE si no
*/
BOOL set_full(Set *set);
/*
*
* @brief: comprueba si nuestro set esta vacio de objetos
* @params1: recibe como parámetro de entrada set a revisar
* @return: devuelve TRUE si es asi y FALSE si no
*/
BOOL set_empty(Set *set);
/*
*
* @brief: obtiene todos los id de los objetos de nuestro set
* @params1: recibe como parámetro de entrada set a revisar
* @return: devuelve esos ids
*/
Id *set_get_all(Set *set);
/*
*
* @brief: obtiene todos un id concreto de agun objeto de nuestro set
* @params1: recibe como parámetro de entrada set a revisar
* @return: devuelve dicho id
*/
Id set_get_id(Set *set, int num);
/*
*
* @brief: obtiene el numero toptal de ids de los objetos de nuestro set
* @params1: recibe como parámetro de entrada set a revisar
* @return: devuelve la cantidad de ids de nuestros objetos
*/
int set_get_num_id(Set *set);
/*
*
* @brief: obtiene el numero total de objetos de nuestro set
* @params1: recibe como parámetro de entrada set a revisar
* @return: devuelve la cantidad de objetos
*/
int set_search_object(Set *set, Id id);

/*
*
* @brief: imprime la información del set por pantalla
* @params1: el set que se va a imprimir
* @return: devuelve ERROR si no se ha impreso correctamente, u OK si lo ha hecho correctamente
*
*/
void set_print(Set *set);


#endif
