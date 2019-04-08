/**
 * @brief Define las funciones del inventario de objectos
 *
 * @file inventory.h
 * @authors Luis Nucifora
 * @version 1.0
 * @date 15/03/2019
 * @copyright GNU Public License
 */

 #ifndef INVENTORY_H
 #define INVENTORY_H

 #include "set.h"
 #include "types.h"

 #define MAX_INV 4

 typedef struct _Inventory Inventory;

/*Funciones de creación, destrucción e impresión del inventario*/

/**
*
* @brief: reserva memoria dinámica suficiente para almacenar un inventory
* @params: no tiene parametros
* @return: la dirección del inventory creado
*
*/
Inventory *inventory_create();

/**
*
* @brief: libera la memoria dinámica reservada del link que se ha recibido
* @params: la direccion del inventory a destruir
* @return: nada
*
*/
void inventory_destroy(Inventory *inv);

/**
*
* @brief: imprime por pantalla el inventory
* @params: la direccion del inventory
* @return: nada
*
*/
void inventory_print(Inventory *inv);

/*Funciones de obtención de datos del inventario*/

/**
*
* @brief: obtiene el numero de objetos maximos
* @params: la direccion del inventory
* @return: el numero de objetos maximos
*
*/
int inventory_get_max_objects(Inventory *inv);

/**
*
* @brief: obtiene los id de los objetos del inventory
* @params: la direccion del inventory
* @return: el array con los id de los objetos que contiene
*
*/
Id* inventory_get_objects(Inventory *inv);

/**
*
* @brief: obtiene el numero de objetos que hay
* @params: la direccion del inventory
* @return: el numero de objetos que hay
*
*/
int inventory_get_num_objects(Inventory *inv);

/**
*
* @brief: obtiene el id del objeto deseado
* @params: la direccion del inventory
* @params2: numero que marca la posicion del objeto que se quiere tener el id
* @return: el id del objeto si esta, sino NO_ID
*
*/
Id inventory_get_object_id(Inventory *inv, int i);

/**
*
* @brief: compara si esta el objeto en el inventory
* @params: la direccion del inventory
* @params1: la id del objeto
* @return: TRUE si esta y FALSE si no
*
*/
BOOL inventory_compare(Inventory *inv, Id id);

/*Funciones de establecimiento de datos del inventario*/

/**
*
* @brief: guardar un objeto en el set perteneciente al inventory
* @params: la direccion del inventory
* @params2: El id del objeto
* @return: si se ha guardado OK, sino ERROR
*
*/
STATUS inventory_set_object(Inventory *inv, Id id);

/**
*
* @brief: deja un objeto del inventory
* @params: la direccion del inventory
* @params2: El id del objeto
* @return: devuelve OK si ha salido bien o ERROR de lo contrario
*
*/
STATUS inventory_drop_object(Inventory *inv, Id id);

#endif
