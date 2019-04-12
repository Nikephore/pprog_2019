/**
 * @brief Implementa el inventario de objetos que porta el jugador
 *
 * @file inventory.c
 * @authors Luis Nucifora
 * @version 1.0
 * @date 15/03/2019
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include "inventory.h"

/**
* @brief La estructura de un inventory
*
* Almacena las diferentes informaciones de un inventory
*/
struct _Inventory{
  Set *set;
  int max_objects;
};

/**
*
* @brief: reserva memoria dinámica suficiente para almacenar un inventory
* @params: no tiene parametros
* @return: la dirección del inventory creado
*
*/
Inventory *inventory_create(){

  Inventory *new_inv = NULL;

  new_inv = (Inventory*) malloc (sizeof(Inventory));

  if(new_inv == NULL){
    return NULL;
  }

  new_inv->set = set_create();
  new_inv->max_objects = MAX_INV;

  return new_inv;
}

/**
*
* @brief: libera la memoria dinámica reservada del link que se ha recibido
* @params: la direccion del inventory a destruir
* @return: nada
*
*/
void inventory_destroy(Inventory *inv){

  if(inv == NULL){
    return;
  }

  set_destroy(inv->set);

  free(inv);

  return;
}


/**
*
* @brief: compara si esta el objeto en el inventory
* @params: la direccion del inventory
* @params1: la id del objeto
* @return: TRUE si esta y FALSE si no
*
*/
BOOL inventory_compare(Inventory *inv, Id id){
  int i;

  if(inv == NULL || id == NO_ID){
    return FALSE;
  }

  for(i=0; i<inventory_get_num_objects(inv); i++){
    if(inventory_get_object_id(inv, i) == id){
      return TRUE;
    }
  }

  return FALSE;
}


/**
*
* @brief: obtiene el numero de objetos maximos
* @params: la direccion del inventory
* @return: el numero de objetos maximos
*
*/
int inventory_get_max_objects(Inventory *inv){

  if(inv == NULL){
    return -1;
  }

  return inv->max_objects;
}

/**
*
* @brief: obtiene los id de los objetos del inventory
* @params: la direccion del inventory
* @return: el array con los id de los objetos que contiene
*
*/
Id* inventory_get_objects(Inventory *inv){

  int i = 0;

  if(inv == NULL || inv->set == NULL){
    return NULL;
  }

  while(i<MAX_INV){
    if(set_get_id(inv->set, i) == NO_ID){
      return NULL;
    }
    i++;
  }

  return set_get_all(inv->set);
}


/**
*
* @brief: obtiene el numero de objetos que hay
* @params: la direccion del inventory
* @return: el numero de objetos que hay
*
*/
int inventory_get_num_objects(Inventory *inv){

  if(inv == NULL){
    return -1;
  }

  return set_get_num_id(inv->set);
}

/**
*
* @brief: obtiene el id del objeto deseado
* @params: la direccion del inventory
* @params2: numero que marca la posicion del objeto que se quiere tener el id
* @return: el id del objeto si esta, sino NO_ID
*
*/
Id inventory_get_object_id(Inventory *inv, int i){

  if(inv == NULL || i < 0 || i > MAX_INV){
    return NO_ID;
  }

  return set_get_id(inv->set, i);
}


/**
*
* @brief: guardar un objeto en el set perteneciente al inventory
* @params: la direccion del inventory
* @params2: El id del objeto
* @return: si se ha guardado OK, sino ERROR
*
*/
STATUS inventory_set_object(Inventory *inv, Id id){

  if(inv == NULL || id == NO_ID){
    return ERROR;
  }

  if(set_get_num_id(inv->set) >= MAX_INV){
    return ERROR;
  }

  set_add_object(inv->set, id);

  return OK;
}


/**
*
* @brief: deja un objeto del inventory
* @params: la direccion del inventory
* @params2: El id del objeto
* @return: devuelve OK si ha salido bien o ERROR de lo contrario
*
*/
STATUS inventory_drop_object(Inventory *inv, Id id){

  if(inv == NULL || id == NO_ID){
    return ERROR;
  }

  if(set_get_num_id(inv->set) <= 0){
    return ERROR;
  }

  set_del_object(inv->set, id);

  return OK;
}


/**
*
* @brief: imprime por pantalla el inventory
* @params: la direccion del inventory
* @return: nada
*
*/
void inventory_print(Inventory *inv){

  if(inv == NULL){
    return;
  }

  set_print(inv->set);
  fprintf(stdout, "Número de elementos del inventario: %d\n",
          inventory_get_num_objects(inv));
  fprintf(stdout, "Número máximo de elementos del inventario: %d\n",
          inventory_get_max_objects(inv));

  return;
}
