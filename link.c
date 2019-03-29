/**
 * @brief
 *
 * @file link.c
 * @authors Victor Perea
 * @version 1.0
 * @date 15/03/2019
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"

/**
* @brief La estructura de un link
*
* Almacena las diferentes informaciones de un link
*/
struct _Link{
  Id id;
  char name[WORD_SIZE + 1];
  Id ids_spaces[NUM_IDS];
  BOOL state;
};

/*
*
* @brief: reserva memoria dinámica suficiente para almacenar un link, guarda su Id
* y tambien los Id de los espacios que une
* @params: la id del link como parametro de entrada
* @params1: una id de uno de los espacios como parametro de entrada
* @params2: una id del otro espacio como parametro de entrada
* @return: la dirección del link creado
*
*/
Link* link_create(Id id, Id id_space1, Id id_space2){

  Link *newLink = NULL;

  if (id == NO_ID)
    return NULL;

    newLink = (Link*) malloc(sizeof(Link));

    if (newLink == NULL) {
      return NULL;
    }

    newLink->id = id;
    newLink->name[0] = '\0';
    newLink->ids_spaces[0] = id_space1;
    newLink->ids_spaces[1] = id_space2;
    newLink->state = FALSE;

    return newLink;
}

/*
*
* @brief: libera la memoria dinámica reservada del link que se ha recibido
* @params: recibe como parámetro de entrada el link a liberar
* @return:
*
*/
STATUS link_destroy(Link* link){
  if(!link){
    return ERROR;
  }
  free(link);
  link = NULL;
  return OK;
}

/*
*
* @brief: cambia la id de un link
* @params1: una dirección de memoria del link
* @params2: una nueva id a introducir
* @return: devuelve ERROR si no se ha cambiado correctamente, u OK si lo ha hecho
*
*/
STATUS link_set_id(Link* link, Id id){
  if(!link || id == NO_ID){
    return ERROR;
  }
  link->id = id;
  return OK;
}

/*
*
* @brief:obtener la Id del link
* @params: la dirección de memoria donde esta el link
* @return:devuelve la Id del link
*
*/
Id link_get_id(Link* link){
  if(!link){
    return NO_ID;
  }
  return link->id;
}

/*
*
* @brief: cambia el nombre del link
* @params1: introduce la direccion de un link
* @params2: una cadena de caracteres con un nombre a guardar
* @return: devuelve ERROR si no se ha cambiado el nombre, u OK si lo ha hecho correctamente
*
*/
STATUS link_set_name(Link* link, const char* name){
  if(!link || name == '\0'){
    return ERROR;
  }
  if (!strcpy(link->name, name)) {
    return ERROR;
  }

  return OK;
}

/*
*
* @brief: accede al link y devuelve su nombre
* @params: recibe como parámetro de entrada un link
* @return: devuelve la cadena de caracteres del nombre del link
*
*/
const char* link_get_name(Link* link){
  if(!link){
    return NULL;
  }
  return link->name;
}

/*
*
* @brief: accede al link y devuelve un id de un espacio
* @params: recibe como parámetro de entrada un link
* @return: devuelve el id del primer espacio
*
*/
Id link_get_space1_id(Link* link){
  if (!link){
    return ERROR;
  }

  return link->ids_spaces[0];
}

/*
*
* @brief: accede al link y devuelve un id de un espacio
* @params: recibe como parámetro de entrada un link
* @return: devuelve el id del segundo espacio
*
*/
Id link_get_space2_id(Link* link){
  if (!link){
    return ERROR;
  }

  return link->ids_spaces[1];
}

/*
*
* @brief: accede al link y cambia el estado del link
* @params: recibe como parámetro de entrada un link
* @return: Devuelve OK si ha cambiado el estado del link y error si no lo ha cambiado
*
*/
STATUS link_change_state(Link* link){
  if (!link){
    return ERROR;
  }

  if(link->state == TRUE){
    link->state = FALSE;
    return OK;
  }

  if(link->state == FALSE){
    link->state = TRUE;
    return OK;
  }
}

/**
*@brief imprime el link por pantalla
*@param1 link que se quiere imprimir
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS link_print(Link* link) {

  if (!link) {
    return ERROR;
  }

  fprintf(stdout, "--> Link (Id: %ld; Name: %s; Espacio 1: %ld; Espacio 2: %ld;)\n", link->id, link->name, link->ids_spaces[0], link->ids_spaces[1]);


  return OK;
}
