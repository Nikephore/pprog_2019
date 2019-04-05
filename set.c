/**
 * @brief Se encarga de las funciones y la gestion de un conjunto de objetos llamado set
 *
 * @file set.c
 * @authors Luis Nucifora
 * @version 2.0
 * @date 10/03/2019
 * @copyright GNU Public License
 */
#include <stdlib.h>
#include <stdio.h>
#include "set.h"

/**
* @brief La estructura de un conjunto de objetos o set
*
* Almacena las diferentes informaciones de un conjunto de objetos o set
*/
struct _Set{
  Id array_id[MAX_NUM_ID];
  int num_elem;
};
/*
*
* @brief: reserva memoria dinámica suficiente para almacenar un set y guarda su Id
* @return: la dirección del set creado
*
*/
Set* set_create(){
  Set *new_set = NULL;
  int i = 0;

  new_set = (Set*) malloc(sizeof(Set));

  if(!new_set){
    return NULL;
  }

  for(i=0; i<MAX_NUM_ID; i++){
    new_set->array_id[i] = NO_ID;
  }

  new_set->num_elem = 0;

  return new_set;
}
/*
*
* @brief: libera la memoria dinámica reservada del set que se ha recibido
* @params: recibe como parámetro de entrada el set a liberar
* @return: devuelve ERROR si no se ha liberado la memoria, u OK si lo ha hecho correctamente
*
*/
void set_destroy(Set *set){

  if(set == NULL){
    return;
  }

  free(set);

  return;
}
/*
*
* @brief: añade un objeto a nuestro set
* @params1: recibe como parámetro de entrada el objeto a añadir al set
* @params2: recibe la id del objeto añadido
* @return: devuelve ERROR si no se ha liberado la memoria, u OK si lo ha hecho correctamente
*
*/
STATUS set_add_object(Set *set, Id id){

  int i = 0;

  if(set == NULL || set->num_elem == (MAX_NUM_ID-1) || id == NO_ID){
    return ERROR;
  }

  for(i=0; i<MAX_NUM_ID; i++){
    if(set->array_id[i] == NO_ID){
      set->array_id[i] = id;
      set->num_elem++;
      return OK;
    }
  }

  return ERROR;
}
/*
*
* @brief: elimina un objeto de nuestro set
* @params1: recibe como parámetro de entrada el objeto a eliminar del set
* @params2: recibe la id del objeto eliminado
* @return: devuelve ERROR si no se ha liberado la memoria, u OK si lo ha hecho correctamente
*
*/
STATUS set_del_object(Set *set, Id id){

  int aux = 0;

  if(set == NULL || set->num_elem == 0 || id == NO_ID){
    return ERROR;
  }

  aux = set_search_object(set, id);

  set->array_id[aux] = NO_ID;

  set->num_elem--;

  return OK;
}
/*
*
* @brief: compara un objeto de nuestro set
* @params1: recibe como parámetro de entrada el objeto a comparar del set
* @params2: recibe la id del objeto comparado
* @return: devuelve ERROR si no se ha liberado la memoria, u OK si lo ha hecho correctamente
*
*/
BOOL set_compare(Set *set, Id id){
  int i = 0;

  if(set == NULL || id == NO_ID){
    return TRUE;
  }

  for(i=0; i < set->num_elem; i++){
    if(set->array_id[i] == id){
      return TRUE;
    }
  }

  return FALSE;
}
/*
*
* @brief: comprueba si nuestro set esta completo de objetos
* @params1: recibe como parámetro de entrada set a revisar
* @return: devuelve TRUE si es asi y FALSE si no
*/
BOOL set_full(Set *set){

  if(set == NULL){
    return FALSE;
  }

  if(set->num_elem == MAX_NUM_ID){
    return TRUE;
  }

  return FALSE;
}

/*
*
* @brief: comprueba si nuestro set esta vacio de objetos
* @params1: recibe como parámetro de entrada set a revisar
* @return: devuelve TRUE si es asi y FALSE si no
*/
BOOL set_empty(Set *set){

  if(set == NULL){
    return FALSE;
  }

  if(set->num_elem <= 0){
    return TRUE;
  }

  return FALSE;
}
/*
*
* @brief: obtiene todos los id de los objetos de nuestro set
* @params1: recibe como parámetro de entrada set a revisar
* @return: devuelve esos ids
*/
Id *set_get_all(Set *set){
  if(set == NULL){
    return NULL;
  }

  return set->array_id;
}
/*
*
* @brief: obtiene todos un id concreto de agun objeto de nuestro set
* @params1: recibe como parámetro de entrada set a revisar
* @return: devuelve dicho id
*/
Id set_get_id(Set *set, int num){
  if(set == NULL || num > MAX_NUM_ID){
    return NO_ID;
  }

  return set->array_id[num];
}
/*
*
* @brief: obtiene el numero toptal de ids de los objetos de nuestro set
* @params1: recibe como parámetro de entrada set a revisar
* @return: devuelve la cantidad de ids de nuestros objetos
*/
int set_get_num_id(Set *set){
  if(set == NULL){
    return -1;
  }

  return set->num_elem;
}
/*
*
* @brief: obtiene el numero total de objetos de nuestro set
* @params1: recibe como parámetro de entrada set a revisar
* @return: devuelve la cantidad de objetos
*/
int set_search_object(Set *set, Id id){

  int i = 0;

  if(set == NULL || id == NO_ID){
    return -1;
  }

  for(i=0; i<MAX_NUM_ID; i++){
    if(set->array_id[i] == id){
      return i;
    }
  }

  return -1;
}
/*
*
* @brief: imprime la información del set por pantalla
* @params1: el set que se va a imprimir
* @return: devuelve ERROR si no se ha impreso correctamente, u OK si lo ha hecho correctamente
*
*/
void set_print(Set *set){

  int i = 0;

  if(set == NULL){
    return;
  }

  fprintf(stdout, "número de elementos del set: %d\n",set->num_elem);

  for(i=0; i<MAX_NUM_ID; i++){
    if(set->array_id[i] != NO_ID){
      fprintf(stdout, "Set:%ld\n",set->array_id[i]);
    }
  }
}
