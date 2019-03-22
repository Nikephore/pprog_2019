/**
 * @brief Se encarga de las funciones y la gestion del jugador de nuestro juego
 *
 * @file player.h
 * @authors Luis Nucifora
 * @version 2.0
 * @date 03/03/2019
 * @copyright GNU Public License
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "object.h"
/**
* @brief La estructura de un jugador
*
* Almacena las diferentes informaciones de un jugador
*/
typedef struct _Player Player;


/**
* @brief inicializa un jugador
* @param1
* @return devuelve la direccion del jugador o NULL si hubo algun error
*/
Player * player_create();

/**
*@brief libera el jugador que se ha pasado como argumento
*@param1 p. Jugador a liberar
*@return devuelve OK si se pudo liberar y ERROR si hubo algun problema
*/
STATUS player_destroy(Player * p);

/**
*@brief obtiene la id de un jugador
*@param1 p. El jugador del que queremos obtener la id
*@return devuelve la id del jugador o NO_ID si hubo algun error
*/
Id player_get_id(Player * p);

/*
*@brief obtiene la localizacion de un jugador
*@param1 p. El jugador del que queremos obtener la localizacion
*@return devuelve la localizacion del jugador o NULL si hubo algun ERROR
*/
Id player_get_location(Player * p);


/**
*@brief obtiene el nombre de un jugador
*@param1 p. El jugador del que queremos obtener el nombre
*@return devuelve el nombre del jugador.
*/
char* player_get_name(Player * p);

/**
*@brief cambia la id de un jugador
*@param1 p. El jugador del que queremos cambiar la Id
*@param2 id. Id para sutituir la id actual del jugador
*@return devuelve OK si se pudo cambiar la id o ERROR si algo fallo
*/
STATUS player_set_id(Player * p, Id id);


/**
*@brief cambia la localizacion de un jugador
*@param1 p. El jugador del que queremos cambiar la localizacion
*@param2 loc. localizacion para sutituir la localizacion actual del jugador
*@return devuelve OK si se pudo cambiar la localizacion o ERROR si algo fallo
*/
STATUS player_set_location(Player * p, Id loc);


/**
*@brief cambia el objeto de un jugador
*@param1 p. Jugador del que queremos cambiar el objeto
*@param2 obj. Objeto para sutituir el objeto actual del jugador
*@return devuelve OK si se pudo cambiar el nombre o ERROR si algo fallo
*/
STATUS player_set_object(Player * p, Id obj);

/*
*@brief imprime el jugador en una direccion especifica
*@param1 f. La direccion en la que se quiere imprimir el jugador
*@param2 p. El jugador que se quiere imprimir
*@return  devuelve OK si se pudo cambiar o ERROR si fallo algo
*/
STATUS player_print(Player * p);

/*
*@brief Añade elemento al inventario.
*@param1 player. El jugador donde se quiere añadir.
*@param2 id. Id del elemento a añadir.
*@return  devuelve OK si se pudo cambiar o ERROR si fallo algo
*/
STATUS player_add_element(Player* player, Id id);

/*
*@brief Elimina elemento del inventario.
*@param1 player. El jugador donde se quiere eliminar.
*@param2 id. Id del elemento a eliminar.
*@return  devuelve OK si se pudo cambiar o ERROR si fallo algo.
*/
STATUS player_delete_element(Player *player, Id id);

/*
*@brief comprueba si existe un elemento en el inventario.
*@param1 player. El jugador donde se quiere comprobar.
*@param2 id. Id del elemento a comprobar.
*@return  devuelve OK si se pudo cambiar o ERROR si fallo algo.
*/
STATUS player_check_element(Player* player, Id id);

/*
*@brief devuelve el inventario.
*@param1 player. El jugador donde se quiere devolver el inventario..
*@return  devuelveel inventario o NULL si falla algo.
*/
Inventory* player_get_inventory(Player* player);

#endif
