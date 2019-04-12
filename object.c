/**
 * @brief Se encarga de las funciones y la gestion del objeto de nuestro juego
 *
 * @file object.c
 * @authors Álvaro Platón, Víctor Perea y Jose Ramon Morales
 * @version 3.0
 * @date 05/03/2019
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"
#include "space.h"
/**
* @brief La estructura de un objeto
*
* Almacena las diferentes informaciones de un objeto
*/
struct _Object {
  Id id;
  Id location;
  char name[WORD_SIZE + 1];
  char description[WORD_SIZE];
  char alt_desc[WORD_SIZE];
  BOOL movable;
  BOOL moved;
  BOOL hidden;
  Id open;
  BOOL illuminate;
  BOOL turnedon;
};
/*
*
* @brief: reserva memoria dinámica suficiente para almacenar un objeto y guarda su Id
* @params: una id como parametro de entrada
* @return: la dirección del objeto creado
*
*/
Object * object_create(Id id){

  Object *obj = NULL;

  if(id == NO_ID){
    return NULL;
  }

  obj=(Object*)malloc(sizeof (Object));
  if (!obj)
    return NULL;

  obj->id = id;
  obj->name[0] = '\0';
  obj->location = NO_ID;
  obj->description[0] = '\0';
  obj->movable = FALSE;
  obj->moved = FALSE;
  obj->hidden = FALSE;
  obj->open = NO_ID;
  obj->illuminate = FALSE;
  obj->turnedon = FALSE;

  return obj;
  }
  /*location
  *
  * @brief:obtener la Id del objeto
  * @params: la dirección de memoria donde esta el objeto
  * @return:devuelve la Id del objeto
  *
  */
Id object_get_id(Object *obj){
  if (!obj){
    return NO_ID;
  }

  return obj->id;
  }
  /*
  *
  * @brief: accede al objeto y devuelve su nombre
  * @params: recibe como parámetro de entrada un objeto
  * @return: devuelve la cadena de caracteres del nombre del objeto
  *, des);
        object_set_location(ob
  */
char* object_get_name(Object *obj){
  if (!obj)
    return NULL;

  return obj->name;
}
/*
*
* @brief: accede al objeto y devuelve su nombre
* @params: recibe como parámetro de entrada un objeto
* @return: devuelve la cadena de caracteres del nombre del objeto
*
*/
Id object_get_location(Object *obj){
  if (!obj){
    return NO_ID;
  }

  return obj->location;
}

char* object_get_description(Object *obj){
  if(!obj){
    return NULL;
  }
  if(obj->moved == FALSE){
    printf("Odesc: %s\n", obj->description);
  }else{
    printf("Odesc: %s\n", obj->alt_desc);
  }
  return obj->description;
  }
/*
*
* @brief: cambia la id de un objeto
* @params1: una dirección de memoria del objeto
* @params2: una nueva id a introducir
* @return: devuelve ERROR si no se ha cambiado correctamente, u OK si lo ha hecho
*
*/
STATUS object_set_id(Object *obj, Id id){
  if (!obj || id<0)
    return ERROR;

  obj->id = id;

  return OK;
  }
  /*, des);
        object_set_location(ob
  *
  * @brief: cambia el nombre del objeto
  * @params1: introduce la direccion de un objeto
  * @params2: una cadena de caracteres con un nombre a guardar
  * @return: devuelve ERROR si no se ha liberado la memoria, u OK si lo ha hecho correctamente
  *
  */
STATUS object_set_name(Object* obj, char *name){
    if (!obj || !name){
      return ERROR;
    }

    if (!strcpy(obj->name, name)){
      return ERROR;
  }
  return OK;
}
/*
*
* @brief: cambia la localización del objeto
* @params1: introduce la direccion de un objeto
* @params2: una id con una localización a guardar
* @return: devuelve ERROR si no se ha liberado la memoria, u OK si lo ha hecho correctamente
*
*/
STATUS object_set_location(Object* obj, Id location){
  if (!obj){
    return ERROR;
  }

  obj->location = location;

  return OK;
}

/*
*
* @brief: cambia la descripción del objeto
* @params1: introduce la direccion de un objeto
* @params2: una cadena de caracteres con una descripción a guardar
* @return: devuelve ERROR si no se ha liberado la memoria, u OK si lo ha hecho correctamente
*
*/
STATUS object_set_description(Object* obj, char* description){
  if(!obj || !description){
    return ERROR;
  }

  if(!strcpy(obj->description, description)){
    return ERROR;
  }

  return OK;
}
/*
*
* @brief: cambia la descripción alternativa del objeto
* @params1: introduce la direccion de un objeto
* @params2: una cadena de caracteres con una descripción a guardar
* @return: devuelve ERROR si no se ha liberado la memoria, u OK si lo ha hecho correctamente
*
*/
STATUS object_set_alt_description(Object* obj, char* alt){
  if(!obj || !alt){
    return ERROR;
  }

  if(!strcpy(obj->alt_desc, alt)){
    return ERROR;
  }

  return OK;
}

/*
*
* @brief: imprime la información del objeto por pantalla
* @params1: el objeto que se va a imprimir
* @return: devuelve ERROR si no se ha impreso correctamente, u OK si lo ha hecho correctamente
*
*/
STATUS object_print(Object* obj) {

  if (!obj) {
    return ERROR;
  }

  fprintf(stdout, "--> Object (Id: %ld; Name: %s; Location: %ld)\n", obj->id, obj->name, obj->location);

  return OK;
}
/*
*
* @brief: libera la memoria dinámica reservada del objeto que se ha recibido
* @params: recibe como parámetro de entrada el objeto a liberar
* @return: devuelve ERROR si no se ha liberado la memoria, u OK si lo ha hecho correctamente
*
*/

void object_destroy(Object* obj){
    if(!obj)
      return;

    free(obj);

    return;
    }

/*
*
* @brief: cambia el estado para indicar si un objeto se puede mover
* @params: recibe como parámetro de entrada el objeto
* @return: OK si se ha cambiado el estado y ERROR si no se ha cambiado
*
*/
STATUS object_set_movable(Object* obj){
    if (!obj){
      return ERROR;
    }

    if (obj->movable == FALSE){
      obj->movable = TRUE;
    }

    if (obj->movable == TRUE){
      obj->movable = FALSE;
    }

  return OK;
}

BOOL object_is_movable(Object* obj){
  if (!obj || obj->movable == FALSE){
    return FALSE;
  }

  return TRUE;
}

BOOL object_been_moved(Object* obj){
  if (!obj || obj->moved == FALSE){
    return FALSE;
    }
    return TRUE;

  }

STATUS object_set_moved(Object* obj){
  if (!obj){
    return ERROR;
  }

  obj->moved = TRUE;

  return OK;
}

STATUS object_set_hidden(Object* obj){
    if (!obj){
      return ERROR;
    }

    if (obj->hidden == TRUE){
      obj->hidden == FALSE;
    }

    if (obj->hidden == FALSE){
      obj->hidden == TRUE;
    }
    return OK;
}



BOOL object_is_hidden(Object* obj){
    if (!obj || obj->hidden == FALSE){
      return FALSE;
    }

    return TRUE;
}

STATUS object_set_illuminate(Object* obj){
    if (!obj){
      return ERROR;
    }

    if (obj->illuminate == FALSE){
      obj->illuminate = TRUE;
    }

    if (obj->illuminate == TRUE){
      obj->illuminate = FALSE;
    }
    return OK;
}

BOOL object_illuminate_space(Object* obj){
    if (!obj || obj->illuminate == FALSE){
      return FALSE;
    }

    return TRUE;
}

BOOL object_open_link(Object* obj, Id link){
    if (!obj || obj->open == NO_ID || obj->open != link){
      return FALSE;
    }

    return TRUE;
}

STATUS object_set_turnedon(Object* obj){
    if (!obj){
      return ERROR;
    }

    if(obj->turnedon == FALSE){
      obj->turnedon = TRUE;
    }

    if(obj->turnedon == TRUE){
      obj->turnedon = FALSE;
    }
    return OK;
}

BOOL object_turned_on(Object* obj){
    if (!obj || object_illuminate_space(obj) == FALSE || obj->turnedon == FALSE){
      return FALSE;
    }

    return TRUE;
}
