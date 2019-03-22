/**
 * @brief Se encarga de las funciones y la gestion del jugador de nuestro juego
 *
 * @file player.c
 * @authors Luis Nucifora, Jose Ramon Morales
 * @version 2.5
 * @date 15/03/2019
 * @copyright GNU Public License
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
/**
* @brief La estructura de un jugador
*
* Almacena las diferentes informaciones de un jugador
*/
struct _Player {
  Id id;
  Id location;
  char name[WORD_SIZE + 1];
  Inventory* inventory;
};
/**
* @brief inicializa un jugador
* @param1
* @return devuelve la direccion del jugador o NULL si hubo algun error
*/
Player * player_create(Id id){

  Player *player = NULL;


  player = (Player *) malloc(sizeof (Player));
  if(!player){
    return NULL;
  }

  player->id = id;
  player->location = NO_ID;
  player->name[0] = '\0';
  player->inventory = inventory_create();

  return player;
}
/**
*@brief libera el jugador que se ha pasado como argumento
*@param1 p. Jugador a liberar
*@return devuelve OK si se pudo liberar y ERROR si hubo algun problema
*/
STATUS player_destroy(Player * p){
  if(!p)
    return ERROR;

  if(p->inventory != NULL){
    inventory_destroy(p->inventory);
  }

  free(p);
  p = NULL;

  return OK;
}
/**
*@brief obtiene la id de un jugador
*@param1 p. El jugador del que queremos obtener la id
*@return devuelve la id del jugador o NO_ID si hubo algun error
*/
Id player_get_id(Player * p){
  if(!p)
    return NO_ID;

  return p->id;
}
/**
*@brief obtiene el nombre de un jugador
*@param1 p. El jugador del que queremos obtener el nombre
*@return devuelve el nombre del jugador.
*/
char* player_get_name(Player * p){
  if(!p)
    return NULL;

  return p->name;
}
/*
*@brief obtiene la localizacion de un jugador
*@param1 p. El jugador del que queremos obtener la localizacion
*@return devuelve la localizacion del jugador o NULL si hubo algun ERROR
*/
Id player_get_location(Player * p){
  if(!p)
    return NO_ID;

  return p->location;
}

/**
*@brief cambia la id de un jugador
*@param1 p. El jugador del que queremos cambiar la Id
*@param2 id. Id para sutituir la id actual del jugador
*@return devuelve OK si se pudo cambiar la id o ERROR si algo fallo
*/
STATUS player_set_id(Player * p, Id id){

  if(!p)
    return ERROR;

  p->id = id;
return OK;
}
/**
*@brief cambia el nombre de un jugador
*@param1 p. El jugador del que queremos cambiar el nombre
*@param2 name. Nombre para sutituir el nombre actual del jugador
*@return devuelve OK si se pudo cambiar el nombre o ERROR si algo fallo
*/
STATUS player_set_name(Player * p, char* name){

  if(!p)
    return ERROR;

  if(strcpy(p->name,name)!= 0)
    return ERROR;
return OK;
}
/**
*@brief cambia la localizacion de un jugador
*@param1 p. El jugador del que queremos cambiar la localizacion
*@param2 loc. localizacion para sutituir la localizacion actual del jugador
*@return devuelve OK si se pudo cambiar la localizacion o ERROR si algo fallo
*/
STATUS player_set_location(Player * p, Id location){
  if(!p)
    return ERROR;

  p->location = location;

return OK;
}

/*
*@brief imprime el jugador en una direccion especifica
*@param1 f. La direccion en la que se quiere imprimir el jugador
*@param2 p. El jugador que se quiere imprimir
*@return  devuelve OK si se pudo cambiar o ERROR si fallo algo
*/
STATUS player_print(Player * p){
  if(!p)
    return ERROR;

  fprintf(stdout, "[ID: %ld | Name: %s | Location: %ld\n",
                  p->id, p->name, p->location);
  inventory_print(p->inventory);

  return OK;
}
/*
*@brief Añade elemento al inventario.
*@param1 player. El jugador donde se quiere añadir.
*@param2 id. Id del elemento a añadir.
*@return  devuelve OK si se pudo cambiar o ERROR si fallo algo
*/
STATUS player_add_element(Player* player, Id id){
  if(player == NULL || id == NO_ID ){
    return ERROR;
  }

  if(player->inventory == NULL){
    player->inventory = inventory_create();
  }

  if(inventory_set_object(player->inventory, id) == ERROR){
    return ERROR;
  }

  return OK;
}
/*
*@brief Elimina elemento del inventario.
*@param1 player. El jugador donde se quiere eliminar.
*@param2 id. Id del elemento a eliminar.
*@return  devuelve OK si se pudo cambiar o ERROR si fallo algo.
*/
STATUS player_delete_element(Player *player, Id id){
  if(player == NULL || id == NO_ID ){
    return ERROR;
  }

  if(inventory_drop_object(player->inventory, id) == ERROR){
    return ERROR;
  }

  return OK;
}
/*
*@brief comprueba si existe un elemento en el inventario.
*@param1 player. El jugador donde se quiere comprobar.
*@param2 id. Id del elemento a comprobar.
*@return  devuelve OK si se pudo cambiar o ERROR si fallo algo.
*/
STATUS player_check_element(Player* player, Id id){
  if(!player || id == NO_ID){
    return ERROR;
  }

  return inventory_compare(player->inventory, id);
}
/*
*@brief devuelve el inventario.
*@param1 player. El jugador donde se quiere devolver el inventario..
*@return  devuelveel inventario o NULL si falla algo.
*/
Inventory* player_get_inventory(Player* player){
  if (!player) {
    return NULL;
  }
  return player->inventory;
}
