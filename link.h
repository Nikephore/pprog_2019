/**
 * @brief Se encarga de las funciones y la gestion de los links
 *
 * @file link.h
 * @authors Victor Perea
 * @version 1.1
 * @date 15/03/2019
 * @copyright GNU Public License
 */

#ifndef LINK_H
#define LINK_H

#include "types.h"
#define NUM_IDS 2
#define MAX_LINKS 31

/**
* @brief La estructura de un link
*
* Almacena las diferentes informaciones de un link
*/
typedef struct _Link Link;

/*
*
* @brief: reserva memoria dinámica suficiente para almacenar un link, guarda su Id
* y tambien los Id de los espacios que une
* @params: la id del link como parametro de entrada
* @params1: una id de uno de los espacios como parametro de entrada
* @params2: una id del otro espacio como parametro de entrada
* @return: la dirección del link creado
*
*/
Link* link_create();

/*
*
* @brief: libera la memoria dinámica reservada del link que se ha recibido
* @params: recibe como parámetro de entrada el link a liberar
* @return:
*
*/
STATUS link_destroy(Link* link);

/*
*
* @brief: cambia la id de un link
* @params1: una dirección de memoria del link
* @params2: una nueva id a introducir
* @return: devuelve ERROR si no se ha cambiado correctamente, u OK si lo ha hecho
*
*/
STATUS link_set_id(Link* link, Id id);

/*
*
* @brief:obtener la Id del link
* @params: la dirección de memoria donde esta el link
* @return:devuelve la Id del link
*
*/
Id link_get_id(Link* link);

/*
*
* @brief: cambia el nombre del link
* @params1: introduce la direccion de un link
* @params2: una cadena de caracteres con un nombre a guardar
* @return: devuelve ERROR si no se ha cambiado el nombre, u OK si lo ha hecho correctamente
*
*/
STATUS link_set_name(Link* link, const char* name);

/*
*
* @brief: accede al link y devuelve su nombre
* @params: recibe como parámetro de entrada un link
* @return: devuelve la cadena de caracteres del nombre del link
*
*/
const char* link_get_name(Link* link);

/*
*
* @brief: accede al link y devuelve un id de un espacio
* @params: recibe como parámetro de entrada un link
* @return: devuelve el id del primer espacio
*
*/
Id link_get_space1_id(Link* link);

/*
*
* @brief: accede al link y devuelve un id de un espacio
* @params: recibe como parámetro de entrada un link
* @return: devuelve el id del segundo espacio
*
*/
Id link_get_space2_id(Link* link);
/*
*
* @brief: accede al link y cambia el estado del link
* @params: recibe como parámetro de entrada un link
* @return: Devuelve OK si ha cambiado el estado del link y error si no lo ha cambiado
*
*/
STATUS link_change_state(Link* link);

/**
*@brief imprime el link por pantalla
*@param1 link que se quiere imprimir
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS link_print(Link* link);

#endif
