/**
 * @brief Carga los espacios de nuestro juego
 *
 * @file game_reader.c
 * @author Luis Nucifora
 * @version 2.0
 * @date 07-03-2019
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_reader.h"

/**
*@brief carga los espacios necesarios para el juego
*@param1 game. Juego en el que queremos cargar los espacios necesarios
*@param2 filename. Contiene el nombre del archivo en el que se encuentran los datos de carga de espacios
*@return devuelve OK si se ejecuto sin problemas y si ha habido algún problema devolvera ERROR
*/


STATUS game_reader_load_spaces(Game* game, char* filename) {
  /* Declaramos e inicializamos las variables a valores nulos */
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char des[WORD_SIZE] = "", ldes[WORD_SIZE] = "";
  char* aux = "   -   ";
  char* illu[MAX_STRING];
  char* toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space* space = NULL;
  STATUS status = OK;
  int i;

  /*Comprobamos si se ha pasado correctamente el nombre del fichero como argumento*/
  if (!filename) {
    return ERROR;
  }

  /* Abrimos el archivo en modo de lectura */
  file = fopen(filename, "r");
  /*Comprobamos si se ha leido el fichero correctamente, si no devolvemos Error */
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      strcpy(des, toks);
      toks = strtok(NULL, "|");
      strcpy(ldes, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);


      for(i=0; i<MAX_STRING; i++){
        illu[i] = strtok(NULL,"|\n");
        printf("vm:%d (%s) ", i, illu[i]);
        if(illu[i] == NULL || illu[i][0] == '\n'){
          illu[i] = aux;
        }
      }

#ifdef DEBUG
      printf("Leido: %ld|%s|%s|%s|%ld|%ld|%ld|%ld\n", id, name, des, ldes, north, east, south, west);
#endif
      space = space_create(id);
      if (space != NULL) {
	       space_set_name(space, name);
         space_set_description(space, des, ldes);
	       space_set_north_link(space, north);
	       space_set_east_link(space, east);
	       space_set_south_link(space, south);
	       space_set_west_link(space, west);
	       game_add_space(game, space);

         for(i=0; i<MAX_STRING; i++){
           space_set_gdesc(space, illu[i], i);
         }
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

/**
*@brief carga los objetos necesarios para el juego
*@param1 game. Juego en el que queremos cargar los espacios necesarios
*@param2 filename. Contiene el nombre del archivo en el que se encuentran los datos de carga de espacios
*@return devuelve OK si se ejecuto sin problemas y si ha habido algún problema devolvera ERROR
*/

STATUS game_reader_load_objects(Game* game, char* filename){
  /* Declaramos e inicializamos las variables a valores nulos */
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char des[WORD_SIZE] = "";
  char altdesc[WORD_SIZE] = "";
  char* toks = NULL;
  Id id = NO_ID;
  Id position = NO_ID;
  Object* object = NULL;
  STATUS status = OK;

  /* validamos que nos llega una direccion de memoria valida donde hemos cargado nuestros datos */
  if (!filename) {
    return ERROR;
  }

  /* abrimos el archivo para leerlo posteriormente */
  file = fopen(filename, "r");
  /* comprobamos que no esta vacio */
  if (file == NULL) {
    return ERROR;
  }

  /* procedemos a la lectura de los datos de nuestro archivo y los convertimos a numero si hace falta
  para la asignacion posterior */
  while (fgets(line, WORD_SIZE, file)) {
    /* comprobamos que se trate de nuestros datos para los objetos */
    if (strncmp("#o:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      position = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(des, toks);
      toks = strtok(NULL, "|");
      strcpy(altdesc, toks);

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%s|%s\n", id, name, position, des, altdesc);
#endif


      /* creamos un objeto con la id que se lee del fichero de  */
      object = object_create(id);

      /* En caso de crearse correctamente, añadimos el
        objeto al juego y le asignamos parámetros */
      if (object != NULL) {
    	  object_set_name(object, name);
        object_set_description(object, des);
        object_set_alt_description(object, altdesc); /*Necesita modificar el data y su lectura*/
        object_set_location(object, position);
        space_add_object(game_get_space(game, position), id);
        game_add_object(game, object);
      }
    }
  }
  /* Si hay algún fallo en el fichero devolvemos ERROR */
  if (ferror(file)) {
    status = ERROR;
  }
  /* cerramos el fichero */
  fclose(file);

  return status;
}

/**
*@brief carga los enlaces necesarios para el juego
*@param1 game. Juego en el que queremos cargar los espacios necesarios
*@param2 filename. Contiene el nombre del archivo en el que se encuentran los datos de carga de enlaces
*@return devuelve OK si se ejecuto sin problemas y si ha habido algún problema devolvera ERROR
*/

STATUS game_reader_load_links (Game* game, char*filename){
  /* Declaramos e inicializamos las variables a valores nulos */
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char* toks = NULL;
  Id id = NO_ID;
  Id space1 = NO_ID, space2 = NO_ID;
  Link* link = NULL;
  STATUS status = OK;

  /* validamos que nos llega una direccion de memoria valida donde hemos cargado nuestros datos */
  if (!filename) {
    return ERROR;
  }

  /* abrimos el archivo para leerlo posteriormente */
  file = fopen(filename, "r");
  /* comprobamos que no esta vacio */
  if (file == NULL) {
    return ERROR;
  }

  /* procedemos a la lectura de los datos de nuestro archivo y los convertimos a numero si hace falta
  para la asignacion posterior */
  while (fgets(line, WORD_SIZE, file)) {
    /* comprobamos que se trate de nuestros datos para los objetos */
    if (strncmp("#l:", line, 3) == 0){
      toks = strtok(line +3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
			strcpy(name, toks);
      toks = strtok(NULL, "|");
      space1 = atol(toks);
      toks = strtok(NULL, "|");
      space2 = atol(toks);

      #ifdef DEBUG
            printf("Leido: %ld|%s|%ld|%ld|\n", id, name, space1, space2);
      #endif

      /* creamos un enlace con la id que se lee del fichero de  */
      link = link_create(id, space1, space2);

      /* En caso de crearse correctamente, añadimos el
        enlace al juego y le asignamos parámetros */
      if (!link) {
        return ERROR;
      }

      link_set_id(link, id);
      link_set_name(link, name);
      game_add_link(game, link);

    }
  }
  /* Si hay algún fallo en el fichero devolvemos ERROR */
  if (ferror(file)) {
    status = ERROR;
  }
  /* cerramos el fichero */
  fclose(file);

  return status;
}
