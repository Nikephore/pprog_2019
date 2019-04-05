/**
 * @brief Se encarga de probar el funcionamiento del dado
 *
 * @file die_test.c
 * @authors Álvaro Platón
 * @version 1.0
 * @date 28/02/2019
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "die.h"
#define DIM 10

int main(){

  Die *die1;
  Id id=0;

  die1 = die_create(id);

  printf("El valor de die_get_roll es: %d", die_get_roll(die1));

  printf("La última tirada ha sido: %d", die_roll(die1));

  die_print(die1);
  die_destroy(die1);



  return 0;
}
