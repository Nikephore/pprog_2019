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

struct _Inventory{
  Set *set;
  int max_objects;
};


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

void inventory_destroy(Inventory *inv){

  if(inv == NULL){
    return;
  }

  set_destroy(inv->set);

  free(inv);

  return;
}

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

int inventory_get_max_objects(Inventory *inv){

  if(inv == NULL){
    return -1;
  }

  return inv->max_objects;
}

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

int inventory_get_num_objects(Inventory *inv){

  if(inv == NULL){
    return -1;
  }

  return set_get_num_id(inv->set);
}

Id inventory_get_object_id(Inventory *inv, int i){

  if(inv == NULL || i < 0 || i > MAX_INV){
    return NO_ID;
  }

  return set_get_id(inv->set, i);
}

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
