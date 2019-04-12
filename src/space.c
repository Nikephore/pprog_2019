/**
 * @brief Se encarga de las funciones y la gestion del espacio de nuestro juego
 *
 * @file space.c
 * @authors Luis Nucifora & Álvaro Platón
 * @version 2.0
 * @date 07/03/2019
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"


/**
* @brief La estructura de un espacio
*
* Almacena las diferentes informaciones de un espacio
*/
struct _Space {
  Id id;
  char name[WORD_SIZE + 1];
  char gdesc[NUM][LETTERS];
  char description[WORD_SIZE + 1];
  char ldescription[WORD_SIZE + 1];
  Id link_north;
  Id link_south;
  Id link_east;
  Id link_west;
  Id link_up;
  Id link_down;
  BOOL light;
  Set *set;
};
/**
*@brief creamos el espacio
*@param1 Id. Pasamos la id para crear el espacio
*@return devuelve la direccion del espacio o NULL si ha ocurrido algun fallo
*/
Space* space_create(Id id) {

  Space *newSpace = NULL;

  if (id == NO_ID)
    return NULL;

  newSpace = (Space *)malloc(sizeof (Space));

  if (newSpace == NULL) {
    return NULL;
  }

  newSpace->id = id;
  newSpace->name[0] = '\0';
  newSpace->description[0] = '\0';
  newSpace->ldescription[0] = '\0';
  newSpace->link_north = NO_ID;
  newSpace->link_south = NO_ID;
  newSpace->link_east = NO_ID;
  newSpace->link_west = NO_ID;
  newSpace->link_up = NO_ID;
  newSpace->link_down = NO_ID;
  newSpace->light = TRUE;

  newSpace->set = set_create();

  return newSpace;
}
/**
*@brief libera la memoria reservada para el espacio
*@param1 space. Espacio a liberar
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS space_destroy(Space* space) {
  if (!space) {
    return ERROR;
  }

  if(space->set != NULL){
    set_destroy(space->set);
  }

  free(space);
  space = NULL;

  return OK;
}
/**
*@brief establece el nombre de un espacio
*@param1 space. Espacio al que queremos cambiar el nombre
*@param2 name. Nombre que queremos establecerle al espacio
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS space_set_name(Space* space, char* name) {
  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }

  return OK;
}
/**
*@brief establece el enlace al norte de un espacio
*@param1 space. Espacio del cual queremos establecerle el norte
*@param2  id. Id del norte
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS space_set_north_link(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->link_north = id;
  return OK;
}
/**
*@brief establece el enlace al sur de un espacio
*@param1 space. Espacio del cual queremos establecerle el sur
*@param2  id. Id del sur
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS space_set_south_link(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->link_south = id;
  return OK;
}
/**
*@brief establece el enlace al este de un espacio
*@param1 space. Espacio del cual queremos establecerle el este
*@param2  id. Id del este
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS space_set_east_link(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->link_east = id;
  return OK;
}
/**
*@brief establece el enlace al oeste de un espacio
*@param1 space. Espacio del cual queremos establecerle el oeste
*@param2  id. Id del oeste
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS space_set_west_link(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->link_west = id;
  return OK;
}

/**
*@brief establece el enlace hacia arriba de un espacio
*@param1 space. Espacio del cual queremos establecerle el oeste
*@param2  id. Id de arriba
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS space_set_up_link(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->link_up = id;
  return OK;
}

/**
*@brief establece el enlace hacia abajo de un espacio
*@param1 space. Espacio del cual queremos establecerle el oeste
*@param2  id. Id de abajo
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS space_set_down_link(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->link_down = id;
  return OK;
}

/**
*@brief establece la descripción de un espacio
*@param1 space. Espacio del cual queremos establecerle las descripciones
*@param2  char*. descripción del espacio.
*@param3  char*. descripción larga del espacio.
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS space_set_description(Space* space, char* description, char* ldescription){
    if (!space || !description || !ldescription) {
    return ERROR;
  }

  if (!strcpy(space->description, description)) {
    return ERROR;
  }

  if (!strcpy(space->ldescription, ldescription)) {
    return ERROR;
  }

  return OK;
}
/**
*@brief establece la iluminación de un espacio
*@param1 space. Espacio del cual queremos establecer la iluminación
*@param2  BOOL. iluminación del espacio.
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS space_set_light(Space* space, BOOL light){
  if (!space || !light) {
  return ERROR;
}

space->light = light;

return OK;
}
/**
*@brief obtiene el nombre de un espacio
*@param1 space. Espacio del cual queremos obtener el nombre
*@return devuelve el nombre del espacio
*/
const char * space_get_name(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->name;
}
/**
*@brief obtenemos la id del espacio
*@param1 space. Espacio del cual queremos obtener la id
*@return devuelve la id del espacio o NO_ID si hubo algun problema
*/
Id space_get_id(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->id;
}
/**
*@brief obtiene el norte del espacio introducido
*@param1 space. Espacio del cual queremos saber el norte
*@return devuelve la id del norte del espacio o NO_ID si ha ocurrido algun error
*/
Id space_get_north_link(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->link_north;
}
/**
*@brief obtiene el sur del espacio introducido
*@param1 space. Espacio del cual queremos saber el sur
*@return devuelve la id del sur del espacio o NO_ID si ha ocurrido algun error
*/
Id space_get_south_link(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->link_south;
}
/**
*@brief obtiene el este del espacio introducido
*@param1 space. Espacio del cual queremos saber el este
*@return devuelve la id del este del espacio o NO_ID si ha ocurrido algun error
*/
Id space_get_east_link(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->link_east;
}
/**
*@brief obtiene el oeste del espacio introducido
*@param1 space. Espacio del cual queremos saber el oeste
*@return devuelve la id del este del espacio o NO_ID si ha ocurrido algun error
*/
Id space_get_west_link(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->link_west;
}
/**
*@brief obtiene la zona superior del espacio introducido
*@param1 space. Espacio del cual queremos saber el oeste
*@return devuelve la id de la zona superior del espacio o NO_ID si ha ocurrido algun error
*/
Id space_get_up_link(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->link_up;
}
/**
*@brief obtiene la zona inferior del espacio introducido
*@param1 space. Espacio del cual queremos saber el oeste
*@return devuelve la id de la zona inferior del espacio o NO_ID si ha ocurrido algun error
*/
Id space_get_down_link(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->link_down;
}
/**
*@brief obtiene el objeto en el espacio
*@param1 space. Espacio del cual queremos establecer la id
*@return devuelve los objetos que hay en nuestro espacio
*/
Set* space_get_object(Space* space){
  if (!space) {
    return NULL;
  }
  return space->set;
}

/**
*@brief obtiene la descripción del espacio introducido
*@param1 space. Espacio del cual queremos saber la descripción
*@return devuelve la id del este del espacio o NO_ID si ha ocurrido algun error
*/
char* space_get_description(Space* space){
  if (!space) {
    return NULL;
  }
  return space->description;
}
/**
*@brief obtiene la descripción larga del espacio introducido
*@param1 space. Espacio del cual queremos saber la descripción larga
*@return devuelve la id del este del espacio o NO_ID si ha ocurrido algun error
*/
char* space_get_long_description(Space* space){
  if (!space) {
    return NULL;
  }
  return space->ldescription;
}
/**
*@brief obtiene la iluminación del espacio introducido
*@param1 space. Espacio del cual queremos saber la iluminación
*@return devuelve la id del este del espacio o NO_ID si ha ocurrido algun error
*/
BOOL space_get_light(Space* space){
  if (!space) {
    return FALSE;
  }
  return space->light;
}

/**
*@brief imprime el espacio por pantalla
*@param1 space. Espacio que se quiere imprimir
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS space_print(Space* space) {
  Id idaux = NO_ID;

  if (!space) {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s; Light: %d)\n", space->id, space->name, space->light);

  idaux = space_get_north_link(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }

  idaux = space_get_south_link(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }

  idaux = space_get_east_link(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }

  idaux = space_get_west_link(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }

  idaux = space_get_up_link(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Up link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No Up link.\n");
  }

  idaux = space_get_down_link(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Down link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No Down link.\n");
  }

  if (space_get_object(space)) {
    fprintf(stdout, "---> Object in the space.\n");
  } else {
    fprintf(stdout, "---> No object in the space.\n");
  }

  return OK;
}
/**
*@brief establecemos la id del espacio
*@param1 space. Espacio del cual queremos establecer la id
*@param2 id. Id que se quiere establecer en el espacio
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/

STATUS space_add_object(Space *space, Id id){

  if(space == NULL || id == NO_ID ){
    return ERROR;
  }

  if(space->set == NULL){
    space->set = set_create();
  }

  if(set_add_object(space->set, id) == ERROR){
    return ERROR;
  }

  return OK;
}
/**
*@brief borramos la id del espacio
*@param1 space. Espacio del cual queremos eliminar la id
*@param2 id. Id que se quiere eliminar en el espacio
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/

STATUS space_delete_object(Space *space, Id id){

  if(space == NULL || id == NO_ID ){
    return ERROR;
  }

  if(set_del_object(space->set, id) == ERROR){
    return ERROR;
  }

  return OK;
}

/**
*@brief genera la descripcion grafica de nuestros objetos
*@param1 space. Espacio del cual queremos establecer la id
*@param2 illu1. Ilustracion del objeto
*@param3 i. Contabiliza el numero de objetos del espacio que son descritos
*@return devuelve la descripcion grafica de cada objeto
*/
STATUS space_get_gdesc(Space* space, char *illu1, int i){

  if(!space || !illu1 || i<0){
    return ERROR;
  }

  strcpy(space->gdesc[i], illu1);

  return OK;
}
/**
*@brief genera la descripcion grafica de nuestros objetos
*@param1 space. Espacio del cual queremos establecer la id
*@param2 illu. Ilustracion de las casillas especiales de nuestro espacio
*@param3 i. Contabilizqa el numero de objetos del espacio que son descritos
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS space_set_gdesc(Space* space, char* illu, int i){

  if(!space || !illu || i<0){
    return ERROR;
  }

  strcpy(space->gdesc[i], illu);

  return OK;
}
/**
*@brief genera la descripcion grafica de nuestros objetos y los ilustra
*@param1 space. Espacio del cual queremos establecer la id
*@param2 i. Contabiliza el numero de objetos del espacio que son descritos
*@return devuelve la descripcion grafica de cada objeto
*/
char* space_get_gdesc_illustration(Space* space, int i){
  if(!space || i < 0){
    return NULL;
  }

  return space->gdesc[i];
}
/**
*@brief comprueba los objetos de nuestro espacio
*@param1 space. Espacio del cual queremos establecer la id
*@param2 id. La id del objecto a comprobar
*@return devuelve TRUE si todo ha ido bien y si no devuelve FALSE
*/
BOOL space_search_object(Space *space, Id id){

  if(space == NULL || id == NO_ID){
    return FALSE;
  }

  return set_compare(space->set, id);
}
