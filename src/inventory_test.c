/**
 * @brief Prueba las funciones del módulo inventario
 *
 * @file inventory_test.c
 * @authors Luis Nucifora
 * @version 1.0
 * @date 15/03/2019
 * @copyright GNU Public License
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include "inventory.h"
 #include "set.h"

 int main(int argc, char const *argv[]) {

   Inventory *inv = NULL;
   int i = 0;
   Id id_aux;

   srand(time(NULL));

   inv = inventory_create();

   if(inv == NULL){
     fprintf(stderr, "ERROR EN LA CREACIÓN DEL INVENTARIO\n");
   }

   id_aux = rand()%MAX_INV;

   if(inventory_drop_object(inv, id_aux) == ERROR){
     fprintf(stdout, "El inventario está vacío.\n");
   }

   fprintf(stdout, "Introduciendo objetos en el inventario...\n");

   for(i=0; i<MAX_INV; i++){
     inventory_set_object(inv, (Id)i);
   }

   inventory_print(inv);

   if(inventory_set_object(inv, (Id)i) == ERROR){
     fprintf(stdout, "El inventario está lleno.\n");
   }

   id_aux = rand()%MAX_INV;

   inventory_drop_object(inv, id_aux);

   fprintf(stdout, "Imprimiendo el inventario tras tirar un objeto.\n");

   inventory_print(inv);

   inventory_destroy(inv);

   return 0;
 }
