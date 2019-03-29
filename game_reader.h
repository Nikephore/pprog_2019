/**
 * @brief Carga los espacios de nuestro juego
 *
 * @file game_reader.h
 * @author Luis Nucifora
 * @version 2.0
 * @date 07-03-2019
 * @copyright GNU Public License
 */

#ifndef GAME_READER
#define GAME_READER

#include "game.h"
#include "types.h"
#include "space.h"
#include "object.h"
#include "link.h"

#define MAX_STRING 3

/**
*@brief carga los espacios necesarios para el juego
*@param1 game. Juego en el que queremos cargar los espacios necesarios
*@param2 filename. Contiene el nombre del archivo en el que se encuentran los datos de carga de espacios
*@return devuelve OK si se ejecuto sin problemas y si ha habido algún problema devolvera ERROR
*/

STATUS game_reader_load_spaces (Game* game, char*filename);

/**
*@brief carga los objetos necesarios para el juego
*@param1 game. Juego en el que queremos cargar los espacios necesarios
*@param2 filename. Contiene el nombre del archivo en el que se encuentran los datos de carga de espacios
*@return devuelve OK si se ejecuto sin problemas y si ha habido algún problema devolvera ERROR
*/

STATUS game_reader_load_objects (Game* game, char*filename);

/**
*@brief carga los enlaces necesarios para el juego
*@param1 game. Juego en el que queremos cargar los espacios necesarios
*@param2 filename. Contiene el nombre del archivo en el que se encuentran los datos de carga de enlaces
*@return devuelve OK si se ejecuto sin problemas y si ha habido algún problema devolvera ERROR
*/

STATUS game_reader_load_links (Game* game, char*filename);


#endif
