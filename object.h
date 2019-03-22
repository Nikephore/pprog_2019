/**
 * @brief Se encarga de las funciones y la gestion del objeto de nuestro juego
 *
 * @file object.h
 * @authors Álvaro Platón
 * @version 2.0
 * @date 05/03/2019
 * @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H

#define MAX_OBJECTS 20

#include "types.h"
/**
* @brief La estructura de un objeto
*
* Almacena las diferentes informaciones de un objeto
*/
typedef struct _Object Object;


/*
*
* @brief: reserva memoria dinámica suficiente para almacenar un objeto y guarda su Id
* @params: una id como parametro de entrada
* @return: la dirección del objeto creado
*
*/
Object * object_create(Id id);

/*
*
* @brief:obtener la Id del objeto
* @params: la dirección de memoria donde esta el objeto
* @return: devuelve la Id del objeto
*
*/
Id object_get_id(Object *obj);

/*
*
* @brief: accede al objeto y devuelve su nombre
* @params: recibe como parámetro de entrada un objeto
* @return: devuelve la cadena de caracteres del nombre del objeto
*
*/
char* object_get_name(Object *obj);

/*
*
* @brief: accede al objeto y devuelve su nombre
* @params: recibe como parámetro de entrada un objeto
* @return: devuelve la cadena de caracteres del nombre del objeto
*
*/
Id object_get_location(Object *obj);

char* object_get_description(Object *obj);
/*
*
* @brief: cambia la id de un objeto
* @params1: una dirección de memoria del objeto
* @params2: una nueva id a introducir
* @return: devuelve ERROR si no se ha cambiado correctamente, u OK si lo ha hecho
*
*/
STATUS object_set_id(Object *obj, Id id);

/*
*
* @brief: cambia el nombre del objeto
* @params1: introduce la direccion de un objeto
* @params2: una cadena de caracteres con un nombre a guardar
* @return: devuelve ERROR si no se ha liberado la memoria, u OK si lo ha hecho correctamente
*
*/
STATUS object_set_name(Object* obj, char *name);

/*
*
* @brief: cambia la localización del objeto
* @params1: introduce la direccion de un objeto
* @params2: una id con una localización a guardar
* @return: devuelve ERROR si no se ha liberado la memoria, u OK si lo ha hecho correctamente
*
*/
STATUS object_set_location(Object* obj, Id location);

STATUS object_set_description(Object* obj, char* description);
/*
*
* @brief: imprime la información del objeto por pantalla
* @params1: el objeto que se va a imprimir
* @return: devuelve ERROR si no se ha impreso correctamente, u OK si lo ha hecho correctamente
*
*/
STATUS object_print(Object * obj);

/*
*
* @brief: libera la memoria dinámica reservada del objeto que se ha recibido
* @params: recibe como parámetro de entrada el objeto a liberar
* @return:
*
*/
void object_destroy(Object* obj);

#endif
