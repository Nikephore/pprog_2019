/**
 * @brief Muestra la interfaz grafica del juego por pantalla
 *
 * @file graphic_engine.h
 * @authors PPROG teachers & Luis Nucifora & Álvaro Platón
 * @version 2.0
 * @date 12/03/2019
 * @copyright GNU Public License
 */


#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"
#include "game_reader.h"
#include "command.h"
#include "space.h"

#define STRING 255
/**
* @brief La estructura de nuestro motor grafico
*
* Almacena las diferentes informaciones de nuestro motor grafico
*/
typedef struct _Graphic_engine Graphic_engine;

/*
* @brief: Inicializa la estructura graphic_engine, reserva la memoria necesaria para la estructura y define sus campos
* @return: devuelve la direccion de la memoria reservada para la estructura
*/

Graphic_engine* graphic_engine_create();

/*
* @brief: libera la memoria reservada para una estructura de graphic_engine
*/

void graphic_engine_destroy(Graphic_engine *ge);

/*
* @brief: imprime por pantalla toda la información del juego, el mapa, la descripcion de los jugadores, objetos que hay, los comandos que puedes poner y tus últimos comandos
* @params 1: recibe la direccion de una estructura de graphic_engine
* @params 2: recibe la direccion de una estructura de game
*/

void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif
