/**
 * @brief Implementa la interfaz del juego y todos los callbacks para los diversos comandos
 *
 * @file game.h
 * @authors Luis Nucifora y Álvaro Platón
 * @version 2.0
 * @date 11/03/2019
 * @copyright GNU Public License
 */
#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "object.h"
#include "player.h"
#include "die.h"
#include "types.h"
#include "set.h"
#include "link.h"
#include "inventory.h"
/**
* @brief La estructura de nuestro juego
*
* Almacena las diferentes informaciones de nuestro juego
*/
typedef struct _Game Game;


/**
*@brief se crea nuestro juego.
*@param1 game. Se pasa el juego como puntero a crear
*@return devuelve OK si todo ha ido bien y si no, devuelve ERROR
*/

Game* game_create();

/**
*@brief creamos nuestro juego a partir de un archivo
*@param1 game. Pasamos el juego como puntero a crear
*@param2 filename. El fichero que se usara para crear el juego
*@return devuelve OK si todo ha ido bien y si no, devuelve ERROR
*/

STATUS game_create_from_file(Game* game, char* filename);

/**
*@brief actualiza nuestro juego cuando se introduce un comando
*@param1 game. El juego que vamos a actualizar
*@param2 cmd. El comando que vamos a introducir
*@return devuelve OK si todo ha ido bien y si no, devuelve ERROR
*/

STATUS game_update(Game* game, Command *cmd);

/**
*@brief libera la memoria reservada para nuestro juego
*@param1 game. El juego que vamos a liberar
*@return devuelve OK si todo ha ido bien y si no, devuelve ERROR
*/

STATUS game_destroy(Game* game);

/**
*@brief comprueba si nuestro juego ha acabado
*@param1 game. El juego que comprobamos si ha llegado a su fin
*@return si el juego ha acabado devuelve TRUE y si no ha acabado, devuelve FALSE
*/

BOOL   game_is_over(Game* game);

/**
*@brief imprime por pantalla nuestro juego
*@param1 game. El juego que vamos a imprimir por pantalla
*@return
*/

void   game_print_screen(Game* game);

/**
*@brief imprime la informacion de nuestro juego
*@param1 game. Juego del que se imprimira la informacion
*@return
*/
void   game_print_data(Game* game);

/**
*@brief se obtiene el espacio al cual pertenece una id
*@param1 game. El juego al que pertenece el espacio
*@param2 id. La id del espacio a buscar
*@return se devuelve la direccion del espacio que coincide con la id, o NULL si ninguno coincide
*/
Space* game_get_space(Game* game, Id id);

/**
*@brief se obtiene el link al cual pertenece una id
*@param1 game. El juego al que pertenece el espacio
*@param2 id. La id del link a buscar
*@return se devuelve la direccion del link que coincide con la id, o NULL si ninguno coincide
*/
Link* game_get_link(Game* game, Id id);

/**
*@brief se obtiene el objeto al cual pertenece una id
*@param1 game. El juego al que pertenece el objeto
*@param2 id. La id del objeto a buscar
*@return se devuelve la direccion del objeto que coincide con la id, o NULL si ninguno coincide
*/
Object* game_get_object(Game* game, Id id);
/**
*@brief se obtiene el id del objeto
*@param1 game. El juego al que pertenece el objeto
*@param2 i. El numero del objeto a buscar
*@return se devuelve el número del objeto
*/
Id game_get_object_id(Game* game, int i);
/**
*@brief se obtiene el número del objeto
*@param1 game. El juego al que pertenece el objeto
*@param2 id. La id del objeto a buscar
*@return se devuelve el número del objeto que coincide con la id, o -1 si ninguno coincide
*/

int game_get_object_num(Game* game, Id id);

/**
*@brief se obtiene un número entre 1 y 6 simulando la tirada de un dado
*@param1 game. El juego al que pertenece el dado
*@return se devuelve el número entre el 1 y 6, o -1 si hay algún error
*/

int game_get_die(Game* game);

/**
*@brief se obtiene el espacio en el que se encuentra el jugador
*@param1 game. El juego al que pertencece el jugador
*@return devuelve la id del espacio en la cual esta el jugador, o NULL si hubo algun problema
*/

Id game_get_player_location(Game* game);

/**
@brief se obtiene el espacio en el que se encuentra el objeto
*@param1 game. El juego al que pertencece el objeto
*@param2 id. El id del objeto cuya localización queremos encontrar
*@return devuelve la id del espacio en la cual esta el objeto, o NO_ID si hubo algun problema
*/

Id game_get_object_location(Game* game, Id id);
/**
*@brief se obtiene el nombre de un objeto
*@param1 game. El juego al que nos referimos
*@param2 id. La id del objeto del cual vamos a obtener el nombre
*@return devuelve el nombre del objeto al que nos referimos, o NULL si hubo algun problema
*/
char * game_get_object_name(Game* game, Id id);

char* game_get_description(Game* game);

char* game_get_object_description(Game* game, Id id);

/**
*@brief obtiene el ultimo comando introducido
*@param1 game. El juego en el que buscamos el ultimo comando
*@return devuelve el ultimo comando introducido
*/
T_Command game_get_last_command(Game* game);

/**
*@brief obtiene el ultimo imput introducido
*@param1 game. El juego en el que buscamos el ultimo imput
*@return devuelve el ultimo imput introducido
*/
char* game_get_command_imput(Game* game);
/**
*@brief añade un espacio al juego
*@param1 game. El juego al que añadimos el espacio
*@param2 space. El espacio que añadimos al juego
*@return devuelve OK si todo ha ido bien y si no, devuelve ERROR
*/

STATUS game_add_space(Game* game, Space* space);

/**
*@brief añade un objeto al juego
*@param1 game. El juego al que añadimos el objeto
*@param2 space. El objeto que añadimos al juego
*@return devuelve OK si todo ha ido bien y si no, devuelve ERROR
*/
STATUS game_add_object(Game* game, Object* object);

/**
*@brief añade un link al juego
*@param1 game. El juego al que añadimos el link
*@param2 space. El link que añadimos al juego
*@return devuelve OK si todo ha ido bien y si no, devuelve ERROR
*/
STATUS game_add_link(Game* game, Link *link);

/**
*@brief  obtiene la id de un espacio en el juego
*@param1 game. Juego del que se obtiene la id del espacio
*@param2 position. Posicion del espacio del juego que nos interesa
*@return devuelve la id del espacio pedido o devuelve NO_ID si hubo algun error
*/

Id game_get_space_id_at(Game* game, int position);

/**
*@brief establece una ubicacion a un jugador
*@param1 game. Juego al que pertenece el jugador
*@param2 id. Id del espacio que se quiere asignar
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/

STATUS game_set_player_location(Game* game, Id id);

/**
*@brief establece una ubicacion a un objeto
*@param1 game. Juego al que pertenece el objeto
*@param2 id. Id del espacio que se quiere asignar
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/

STATUS game_set_object_location(Game* game, Id id);
/**
*@brief se obtiene el espacio en el que se desarrolla el juego
*@param1 game. El juego al que nos referimos
*@param2 id. La id del espacio al que nos referimos
*@return devuelve el espacio donde se desarrolla e juego, o NULL si hubo algun problema
*/
Space* game_get_space(Game* game, Id id);

Id game_inspect_select(Game* game);

char* game_get_space_description(Game* game);

#endif
