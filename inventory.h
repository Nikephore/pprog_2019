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

Inventory *inventory_create();

void inventory_destroy(Inventory *inv);

void inventory_print(Inventory *inv);

/*Funciones de obtención de datos del inventario*/

int inventory_get_max_objects(Inventory *inv);

Id* inventory_get_objects(Inventory *inv);

int inventory_get_num_objects(Inventory *inv);

Id inventory_get_object_id(Inventory *inv, int i);

STATUS inventory_compare(Inventory *inv, Id id);

/*Funciones de establecimiento de datos del inventario*/

STATUS inventory_set_object(Inventory *inv, Id id);

STATUS inventory_drop_object(Inventory *inv, Id id);

#endif
