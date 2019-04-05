/**
 * @brief Se encarga de comprobar el correcto funcionamiento de set
 *
 * @file set.c
 * @authors Luis Nucifora
 * @version 2.0
 * @date 10/03/2019
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "set.h"

int main(){
  Set *set = NULL;
  int i = 0, j = 0, aux = 0;
  Id id_test = 0;

  srand(time(NULL));

  /*creamos un set*/
  set = set_create();
  if(set == NULL){
    printf("Error al crear el set");
    return -1;
  }

  if(set_del_object(set, id_test) == ERROR){
    printf("El conjunto está vacío\n");
  }

  printf("Introduciendo elementos...\n");

  /*Llenamos el set*/
  for(i=0; i<MAX_NUM_ID-1; i++){
    if(set_add_object(set,i) == ERROR){
      return -1;
    }
  }

  /*Intentamos introducir un elemento a un set lleno*/
  if(set_add_object(set,i+1) == ERROR){
    printf("El conjunto está lleno\n");
  }

  /*Imprimimos el set por pantalla*/
  set_print(set);

  /*Buscamos un objeto en el conjunto*/
  id_test = rand()%13;
  j = set_search_object(set, id_test);

  printf("Objecto buscado: %d\n",j );

  /*Borramos un número aleatorio de objetos del set*/
  aux = rand()%13;
  for(i=0; i<aux; i++){
    set_del_object(set, i);
  }

  /*Imprimimos el set por pantalla tras borrar los objetos*/
  set_print(set);

  /*comprobamos si un elemento está en el set*/
  id_test = rand()%13;
  if(set_compare(set, aux) == FALSE){
    printf("El elemento %ld NO se encuentra en el set\n", id_test);
  }
  else if(set_compare(set, aux) == TRUE){
    printf("El elemento %ld SÍ se encuentra en el set\n", id_test);
  }



  /*destruimos el set*/
  set_destroy(set);

  return 0;
}
