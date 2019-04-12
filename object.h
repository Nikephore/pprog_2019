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

/*
*
* @brief: obtiene la descripcion de un objeto
* @params: recibe como parámetro de entrada un objeto
* @return: devuelve la id de dicho objeto
*
*/

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

/*
*
* @brief: establece la descripcion de un objeto
* @params1: el objeto del cual se quiere obtener la descripcion
* @params2: la descripcion del objeto
* @return: devuelve ERROR si no se ha liberado la memoria, u OK si lo ha hecho correctamente
*
*/
STATUS object_set_description(Object* obj, char* description);

/*
* @brief: establece una descricion alternativa
* @params1: recibe el objeto
* @params2: la descripcion alternativa
*/
STATUS object_set_alt_description(Object* obj, char* alt);
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

/*
*
* @brief: cambia el estado para indicar si un objeto se puede mover
* @params: recibe como parámetro de entrada el objeto
* @return: OK si se ha cambiado el estado y ERROR si ha habido algun error
*
*/
STATUS object_set_movable(Object* obj);

/*
*
* @brief: indica si se puede mover el objeto
* @params: recibe como parámetro de entrada el objeto
* @return: TRUE si se puede mover y FALSE si no se puede mover
*
*/
BOOL object_is_movable(Object* obj);

/*
*
* @brief: indica si un objeto se ha movido
* @params: recibe como parámetro de entrada el objeto
* @return: TRUE si se ha movido y FALSE si no se ha movido
*
*/
BOOL object_been_moved(Object* obj);

/*
* @brief: pone en el estado a TRUE de si un objeto ha sido movido
* @params: recibe como parámetro de entrada el objeto
* @return: OK si se ha cambiado, ERROR si ha pasado algo
*/
STATUS object_set_moved(Object* obj);
/*
*
* @brief: cambia el estado para indicar si un objeto está oculto
* @params: recibe como parámetro de entrada el objeto
* @return: OK si se ha cambiado el estado y ERROR ha habido algun error
*
*/
STATUS object_set_hidden(Object* obj);

/*
*
* @brief: indica si un objeto está oculto
* @params: recibe como parámetro de entrada el objeto
* @return: TRUE si está oculto y FALSE si no está oculto
*
*/
BOOL object_is_hidden(Object* obj);

/*
*
* @brief: cambia el estado para indicar si un objeto ilumina
* @params: recibe como parámetro de entrada el objeto
* @return: OK si se ha cambiado el estado y ERROR ha habido algun error
*
*/
STATUS object_set_illuminate(Object* obj);

/*
*
* @brief: indica si un objeto ilumina un espacio
* @params: recibe como parámetro de entrada el objeto
* @return: TRUE si ilumina un espacio y FALSE si no lo ilumina
*
*/
BOOL object_illuminate_space(Object* obj);

/*
*
* @brief: indica si un objeto puede abrir un link
* @params: recibe como parámetro de entrada el objeto
* @params1: recibe la id del link
* @return: TRUE si puede abrir ese link y FALSE si no lo abre
*
*/
BOOL object_open_link(Object* obj, Id link);

/*
*
* @brief: cambia el estado para indicar si un objeto está encendido
* @params: recibe como parámetro de entrada el objeto
* @return: OK si se ha cambiado el estado y ERROR ha habido algun error
*
*/
STATUS object_set_turnedon(Object* obj);

/*
*
* @brief: indica si un objeto que puede iluminar está encendido
* @params: recibe como parámetro de entrada el objeto
* @return: TRUE si puede iluminar y FALSE si no lo puede iluminar
*
*/
BOOL object_turned_on(Object* obj);

#endif
