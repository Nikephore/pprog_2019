/**
 * @brief Implementa la interfaz del juego y todos los callbacks para los diversos comandos
 *
 * @file game.c
 * @authors Luis Nucifora y Álvaro Platón
 * @version 2.0
 * @date 11/03/2019
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_reader.h"

#define N_CALLBACK 10

struct _Game{
  Space* spaces[MAX_SPACES + 1];
  Command *last_cmd;
  Player *player;
  Object *object[MAX_OBJECTS + 1];
  Die *die;
};
/**
   Define el tipo de función para los callbacks
*/
typedef void (*callback_fn)(Game* game);

/**
   Lista de callbacks para cada comando en el juego
*/
void game_callback_unknown(Game* game);
void game_callback_exit(Game* game);
void game_callback_next(Game* game);
void game_callback_back(Game* game);
void game_callback_take(Game* game);
void game_callback_drop(Game* game);
void game_callback_roll(Game* game);
void game_callback_left(Game* game);
void game_callback_right(Game* game);
void game_callback_inspect(Game* game);

static callback_fn game_callback_fn_list[N_CALLBACK]={
  game_callback_unknown,
  game_callback_exit,
  game_callback_next,
  game_callback_back,
  game_callback_take,
  game_callback_drop,
  game_callback_roll,
  game_callback_left,
  game_callback_right,
  game_callback_inspect};

/**
   Implementación de la interfaz de juego
*/

/**
   Funciones de creación y destrucción del Juego
*/
/**
*@brief se crea nuestro juego.
*@param1 game. Se pasa el juego como puntero a crear
*@return devuelve OK si todo ha ido bien y si no, devuelve ERROR
*/

Game* game_create(){
  Game *newGame = NULL;
  int i = 0;

  newGame = (Game*)malloc(sizeof(Game));
  if(newGame == NULL){
    return ERROR;
  }

  for (i = 0; i < MAX_SPACES; i++){
    newGame->spaces[i] = NULL;
  }


  if((newGame->player = player_create(1)) == NULL){
    return ERROR;
  }

  if((newGame->die = die_create(1)) == NULL){
    return ERROR;
  }

  for(i=0; i<MAX_OBJECTS; i++){
    newGame->object[i] = NULL;
  }

  newGame->last_cmd = NULL;

  return newGame;
}
/**
*@brief creamos nuestro juego a partir de un archivo
*@param1 game. Pasamos el juego como puntero a crear
*@param2 filename. El fichero que se usara para crear el juego
*@return devuelve OK si todo ha ido bien y si no, devuelve ERROR
*/

STATUS game_create_from_file(Game* game, char* filename) {

  if (game_reader_load_spaces(game, filename) == ERROR){
    return ERROR;
  }

  if(game_reader_load_objects(game, filename) == ERROR){
    return ERROR;
  }

  game_set_player_location(game, game_get_space_id_at(game, 0));

  return OK;
}

/**
*@brief libera la memoria reservada para nuestro juego
*@param1 game. El juego que vamos a liberar
*@return devuelve OK si todo ha ido bien y si no, devuelve ERROR
*/

STATUS game_destroy(Game* game) {
  int i = 0;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
    space_destroy(game->spaces[i]);
  }

  for (i = 0; (i < MAX_OBJECTS) && (game->object[i] != NULL); i++) {
    object_destroy(game->object[i]);
  }

  die_destroy(game->die);
  player_destroy(game->player);

  return OK;
}

/**
   Funciones de adición de elementos
*/
/**
*@brief añade un espacio al juego
*@param1 game. El juego al que añadimos el espacio
*@param2 space. El espacio que añadimos al juego
*@return devuelve OK si todo ha ido bien y si no, devuelve ERROR
*/
STATUS game_add_space(Game* game, Space* space) {
  int i = 0;

  if (space == NULL) {
    return ERROR;
  }

  while ( (i < MAX_SPACES) && (game->spaces[i] != NULL)){
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}
/**
*@brief añade un objeto al juego
*@param1 game. El juego al que añadimos el objeto
*@param2 space. El objeto que añadimos al juego
*@return devuelve OK si todo ha ido bien y si no, devuelve ERROR
*/
STATUS game_add_object(Game* game, Object *object){
  int i = 0;

  if(game == NULL || object == NULL){
    return ERROR;
  }

  while((i<MAX_OBJECTS) && (game->object[i] != NULL)){
    i++;
  }

  if(i >= MAX_OBJECTS){
    return ERROR;
  }

  game->object[i] = object;

  return OK;
}

/**
   Funciones de obtención de información (getters)
*/
/**
*@brief  obtiene la id de un espacio en el juego
*@param1 game. Juego del que se obtiene la id del espacio
*@param2 position. Posicion del espacio del juego que nos interesa
*@return devuelve la id del espacio pedido o devuelve NO_ID si hubo algun error
*/

Id game_get_space_id_at(Game* game, int position) {

  if (position < 0 || position >= MAX_SPACES) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}
/**
*@brief se obtiene el espacio en el que se desarrolla el juego
*@param1 game. El juego al que nos referimos
*@param2 id. La id del espacio al que nos referimos
*@return devuelve el espacio donde se desarrolla e juego, o NULL si hubo algun problema
*/
Space* game_get_space(Game* game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  /*Busca el espacio que coincide con la id dada*/
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])){
      return game->spaces[i];
    }
  }

  return NULL;
}
/**
*@brief se obtiene el espacio en el que se encuentra el jugador
*@param1 game. El juego al que pertencece el jugador
*@return devuelve la id del espacio en la cual esta el jugador, o NULL si hubo algun problema
*/

Id game_get_player_location(Game* game) {
  if(!game){
    return  NO_ID;
  }

  return player_get_location(game->player);
}
/**
*@brief se obtiene un número entre 1 y 6 simulando la tirada de un dado
*@param1 game. El juego al que pertenece el dado
*@return se devuelve el número entre el 1 y 6, o -1 si hay algún error
*/

int game_get_die(Game* game){
  if(!game){
    return -1;
  }

  return die_get_roll(game->die);
}
/**
*@brief se obtiene el objeto al cual pertenece una id
*@param1 game. El juego al que pertenece el objeto
*@param2 id. La id del objeto a buscar
*@return se devuelve la direccion del objeto que coincide con la id, o NULL si ninguno coincide
*/
Object* game_get_object(Game* game, Id id){
  int i = 0;

  if(game == NULL || id == NO_ID){
    return NULL;
  }

  for(i=0; i<MAX_OBJECTS && game->object[i] != NULL; i++){
    if(id == object_get_id(game->object[i])){
      return game->object[i];
    }
  }

  return NULL;
}
/**
*@brief se obtiene el id del objeto
*@param1 game. El juego al que pertenece el objeto
*@param2 i. El numero del objeto a buscar
*@return se devuelve el número del objeto
*/
Id game_get_object_id(Game* game, int i){

  if(game == NULL || i < 0 || i > MAX_OBJECTS){
    return NO_ID;
  }

  return object_get_id(game->object[i]);

  return ERROR;
}
/**
*@brief se obtiene el nombre de un objeto
*@param1 game. El juego al que nos referimos
*@param2 id. La id del objeto del cual vamos a obtener el nombre
*@return devuelve el nombre del objeto al que nos referimos, o NULL si hubo algun problema
*/
char* game_get_object_name(Game* game, Id id){
  int i = 0;

  if(!game || id == NO_ID){
    return NULL;
  }

  for(i=0; i<MAX_OBJECTS; i++){
    if(object_get_id(game->object[i]) == id){
      return object_get_name(game->object[i]);
    }
  }

  return NULL;
}
/**
*@brief se obtiene el número del objeto
*@param1 game. El juego al que pertenece el objeto
*@param2 id. La id del objeto a buscar
*@return se devuelve el número del objeto que coincide con la id, o -1 si ninguno coincide
*/
int game_get_object_num(Game* game, Id id){
  int i = 0;

  if(!game || id == NO_ID){
    return -1;
  }

  for(i=0; i<MAX_OBJECTS; i++){
    if(object_get_id(game->object[i]) == id){
      return i;
    }
  }
  return -1;
}
/**
@brief se obtiene el espacio en el que se encuentra el objeto
*@param1 game. El juego al que pertencece el objeto
*@param2 id. El id del objeto cuya localización queremos encontrar
*@return devuelve la id del espacio en la cual esta el objeto, o NO_ID si hubo algun problema
*/
Id game_get_object_location(Game* game, Id id) {
  int i=0;

  if(!game || id == NO_ID){
    return ERROR;
  }

  i = game_get_object_num(game, id);


  return object_get_location(game->object[i]);
}
/**
*@brief obtiene el ultimo comando introducido
*@param1 game. El juego en el que buscamos el ultimo comando
*@return devuelve el ultimo comando introducido
*/
T_Command game_get_last_command(Game* game){
  return command_get_cmd(game->last_cmd);
}

/**
   Funciones de establecimiento de datos (setters)
*/
/**
*@brief establece una ubicacion a un jugador
*@param1 game. Juego al que pertenece el jugador
*@param2 id. Id del espacio que se quiere asignar
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS game_set_player_location(Game* game, Id id) {

  if (id == NO_ID || !game) {
    return ERROR;
  }

  player_set_location(game->player, id);

  return OK;
}
/**
*@brief establece una ubicacion a un objeto
*@param1 game. Juego al que pertenece el objeto
*@param2 id. Id del espacio que se quiere asignar
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/

STATUS game_set_object_location(Game* game, Id id) {
  int i=0;

  if (id == NO_ID || game == NULL) {
    return ERROR;
  }

  i = game_get_object_num(game, id);

  object_set_location(game->object[i], id);

  return OK;
}

/**
   Funciones de impresión y actualización
*/
/**
*@brief actualiza nuestro juego cuando se introduce un comando
*@param1 game. El juego que vamos a actualizar
*@param2 cmd. El comando que vamos a introducir
*@return devuelve OK si todo ha ido bien y si no, devuelve ERROR
*/
STATUS game_update(Game* game, Command *cmd) {
  if(!game || !cmd){
    return ERROR;
  }

  game->last_cmd = command_copy(cmd);
  (*game_callback_fn_list[command_get_cmd(cmd)])(game);

  return OK;
}
/**
*@brief imprime la informacion de nuestro juego
*@param1 game. Juego del que se imprimira la informacion
*@return
*/
void game_print_data(Game* game) {
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }

  printf("=> Player location: %d\n", (int) player_get_location(game->player));
  printf("=> Die last roll: %d\n", (int) die_get_roll(game->die));
  printf("prompt:> ");
}
/**
*@brief comprueba si nuestro juego ha acabado
*@param1 game. El juego que comprobamos si ha llegado a su fin
*@return si el juego ha acabado devuelve TRUE y si no ha acabado, devuelve FALSE
*/

BOOL game_is_over(Game* game) {
  return FALSE;
}

/**
   Implementación de los Callbacks para cada acción
*/
/**
*@brief se encarga de permitirnos introducir un comando invalido en nuestro juego
*@param1 game. El juego que estamos utilizando
*@return
*/
void game_callback_unknown(Game* game) {
}
/**
*@brief se encarga de permitirnos introducir un comando para salir de nuestro juego
*@param1 game. El juego que estamos utilizando
*@return
*/
void game_callback_exit(Game* game) {
}
/**
*@brief se encarga de permitirnos introducir un comando next para avanzar en nuestro juego
*@param1 game. El juego que estamos utilizando
*@return
*/
void game_callback_next(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID) {
	game_set_player_location(game, current_id);
      }
      return;
    }
  }
}
/**
*@brief se encarga de permitirnos movernos por el juego hacia atras
*@param1 game. El juego que estamos utilizando
*@return
*/
void game_callback_back(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID) {
	game_set_player_location(game, current_id);
      }
      return;
    }
  }
}
/**
*@brief nos permite coger objetos de nuestro juego
*@param1 game. El juego que estamos utilizando
*@return
*/
void game_callback_take(Game* game){
  int i = 0;
  Id aux_id = NO_ID;

  if(!game){
    return;
  }

  for(i=0; i<MAX_OBJECTS; i++){
    if(player_get_object(game->player) == NO_ID){ /*Comprueba que el jugador no tiene objeto*/
      if(game->object[i] != NULL){
        /*Compara el nombre del objeto con el que se le pasa por el comando*/
        if(strcmp(object_get_name(game->object[i]),command_get_object(game->last_cmd)) == 0){
          aux_id = object_get_id(game->object[i]);
          /*Comprueba que el jugador y el objeto están en la misma casilla*/
          if(game_get_player_location(game) == game_get_object_location(game, aux_id)){
            /*Pasa la id del objeto al objeto del jugador*/
            player_set_object(game->player, object_get_id(game->object[i]));
            /*Establece que el objeto no se encuentra en ninguna casilla*/
            object_set_location(game->object[i], NO_ID);
          }
        }
      }
    }
  }

return;
}
/**
*@brief nos permite soltar los objetos que hemos cogido con take en nuestro juego
*@param1 game. El juego que estamos utilizando
*@return
*/
void game_callback_drop(Game* game){
  int aux;
  Id pla_id = NO_ID;
  Id obj_id = NO_ID;

  if(!game){
    return;
  }

  pla_id = game_get_player_location(game);
  obj_id = player_get_object(game->player);
  aux = game_get_object_num(game, obj_id);

  /*Se le quita el objeto al jugador*/
  player_set_object(game->player, NO_ID);
  /*Se establece la ubicacion del objeto en la casilla
   en la que se encuentra el jugador*/
  object_set_location(game->object[aux], pla_id);
return;
}
/**
*@brief nos permite generar una tirada aleatoria con los dados de nuestro juego
*@param1 game. El juego que estamos utilizando
*@return
*/
void game_callback_roll(Game* game){
  if(!game){
    return;
  }

  die_roll(game->die);

  return;
}
/**
*@brief nos permite saltar de una casilla a otra que esten conectadas mutuamente por la izquierda
*@param1 game. El juego que estamos utilizando
*@return
*/
void game_callback_left(Game* game){
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_west(game->spaces[i]);
      if (current_id != NO_ID) {
  game_set_player_location(game, current_id);
      }
      return;
    }
  }
}
/**
*@brief nos permite saltar de una casilla a otra que esten conectadas mutuamente por la derecha
*@param1 game. El juego que estamos utilizando
*@return
*/
void game_callback_right(Game* game){
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_east(game->spaces[i]);
      if (current_id != NO_ID) {
  game_set_player_location(game, current_id);
      }
      return;
    }
  }
  return;
}

void game_callback_inspect(Game* game){

  return;
}
