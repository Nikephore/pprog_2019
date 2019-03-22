/**
 * @brief Se encarga de las funciones y la gestion del espacio de nuestro juego
 *
 * @file space.c
 * @authors Luis Nucifora y Álvaro Platón
 * @version 2.0
 * @date 7/03/2019
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "object.h"
#include "set.h"
/**
* @brief La estructura de un espacio
*
* Almacena las diferentes informaciones de un espacio
*/
typedef struct _Space Space;

#define NUM 3
#define LETTERS 8
#define MAX_SPACES 100
#define FIRST_SPACE 1

/**
*@brief creamos el espacio
*@param1 Id. Pasamos la id para crear el espacio
*@return devuelve la direccion del espacio o NULL si ha ocurrido algun fallo
*/
Space* space_create(Id id);

/**
*@brief libera la memoria reservada para el espacio
*@param1 space. Espacio a liberar
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS space_destroy(Space* space);

/**
*@brief obtenemos la id del espacio
*@param1 space. Espacio del cual queremos obtener la id
*@return devuelve la id del espacio o NO_ID si hubo algun problema
*/
Id space_get_id(Space* space);

/**
*@brief establece el nombre de un espacio
*@param1 space. Espacio al que queremos cambiar el nombre
*@param2 name. Nombre que queremos establecerle al espacio
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS space_set_name(Space* space, char* name);

/**
*@brief obtiene el nombre de un espacio
*@param1 space. Espacio del cual queremos obtener el nombre
*@return devuelve el nombre del espacio
*/
const char* space_get_name(Space* space);

/**
*@brief establece el norte de un espacio
*@param1 space. Espacio del cual queremos establecerle el norte
*@param2  id. Id del norte
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS space_set_north(Space* space, Id id);

/**
*@brief obtiene el norte del espacio introducido
*@param1 space. Espacio del cual queremos saber el norte
*@return devuelve la id del norte del espacio o NO_ID si ha ocurrido algun error
*/
Id space_get_north(Space* space);

/**
*@brief establece el sur de un espacio
*@param1 space. Espacio del cual queremos establecerle el sur
*@param2  id. Id del sur
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS space_set_south(Space* space, Id id);

/**
*@brief obtiene el sur del espacio introducido
*@param1 space. Espacio del cual queremos saber el sur
*@return devuelve la id del sur del espacio o NO_ID si ha ocurrido algun error
*/
Id space_get_south(Space* space);

/**
*@brief establece el este de un espacio
*@param1 space. Espacio del cual queremos establecerle el este
*@param2  id. Id del este
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS space_set_east(Space* space, Id id);

/**
*@brief obtiene el este del espacio introducido
*@param1 space. Espacio del cual queremos saber el este
*@return devuelve la id del este del espacio o NO_ID si ha ocurrido algun error
*/
Id space_get_east(Space* space);

/**
*@brief establece el oeste de un espacio
*@param1 space. Espacio del cual queremos establecerle el oeste
*@param2  id. Id del oeste
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS space_set_west(Space* space, Id id);

/**
*@brief obtiene el oeste del espacio introducido
*@param1 space. Espacio del cual queremos saber el oeste
*@return devuelve la id del este del espacio o NO_ID si ha ocurrido algun error
*/
Id space_get_west(Space* space);

/**
*@brief imprime el espacio por pantalla
*@param1 space. Espacio que se quiere imprimir
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/
STATUS space_print(Space* space);

/**
*@brief establecemos la id del espacio
*@param1 space. Espacio del cual queremos establecer la id
*@param2 id. Id que se quiere establecer en el espacio
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/

STATUS space_add_object(Space *space, Id id);

/**
*@brief borramos la id del espacio
*@param1 space. Espacio del cual queremos eliminar la id
*@param2 id. Id que se quiere eliminar en el espacio
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/

STATUS space_delete_object(Space *space, Id id);

/**
*@brief obtiene el numero de objetos que hay en el espacio
*@param1 space. Espacio del cual queremos saber el numero de espacios
*@return devuelve el numero de espacios
*/

int space_get_num_object(Space* space);

/**
*@brief genera la descripcion grafica de nuestros objetos
*@param1 space. Espacio del cual queremos establecer la id
*@param2 illu1. Ilustracion del objeto
*@param3 i. Contabiliza el numero de objetos del espacio que son descritos
*@return devuelve la descripcion grafica de cada objeto
*/
STATUS space_get_gdesc(Space* space, char *illu1, int i);
/**
*@brief obtiene el objeto en el espacio
*@param1 space. Espacio del cual queremos establecer la id
*@return devuelve los objetos que hay en nuestro espacio
*/
Set* space_get_object(Space* space);

/**
*@brief genera la descripcion grafica de nuestros objetos
*@param1 space. Espacio del cual queremos establecer la id
*@param2 illu. Ilustracion de las casillas especiales de nuestro espacio
*@param3 i. Contabilizqa el numero de objetos del espacio que son descritos
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/

STATUS space_set_gdesc(Space* space, char* illu, int i);

/**
*@brief genera la descripcion grafica de nuestros objetos y los ilustra
*@param1 space. Espacio del cual queremos establecer la id
*@param2 i. Contabiliza el numero de objetos del espacio que son descritos
*@return devuelve la descripcion grafica de cada objeto
*/

char* space_get_gdesc_illustration(Space* space, int i);

/**
*@brief comprueba los objetos de nuestro espacio
*@param1 space. Espacio del cual queremos establecer la id
*@param2 id. La id del objecto a comprobar
*@return devuelve OK si todo ha ido bien y si no devuelve ERROR
*/

STATUS space_check_object(Space* space, Id id);

#endif
