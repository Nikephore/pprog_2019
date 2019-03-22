/**
 * @brief Se encarga de las funciones y la gestion de un dado
 *
 * @file die.c
 * @authors Álvaro Platón
 * @version 2.0
 * @date 28/02/2019
 * @copyright GNU Public License
 */
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "die.h"
#include "types.h"
/**
* @brief La estructura de un dado
*
* Almacena las diferentes informaciones de un dado
*/
struct _Die{
  Id id;
  int lastroll;
};
/*
*
* @brief: reserva memoria dinámica suficiente para almacenar un dado y guarda su Id
* @params: una id como parametro de entrada
* @return: la dirección del dado creado
*
*/
Die * die_create(Id id){

  Die *die = NULL;

  die=(Die*)malloc(sizeof (Die));
  if (!die)
    return NULL;

  die->id = id;
  die->lastroll=0;
  return die;
}
/*
*
* @brief: genera un numero aleatorio al "tirar" el dado
* @params: recibe como parámetro de entrada el dado que hemos usado
* @return: devuelve el numero aleatorio generado por nuestro dado
*
*/
int die_roll(Die * die){

  if(!die)
    return -1;

  srand(time(NULL));

  die->lastroll = rand()%6+1;

return die->lastroll;
}
/*
*
* @brief: limita los valores maximoy y minimos que se pueden generar con nuestro dado
* @params: recibe como parámetro de entrada nuestro dado
* @return: devuelve el numero aleatorio generado por nuestro dado
*
*
*/
int die_get_roll(Die * die){

  if(!die){
    return -1;
  }

  if(die->lastroll<0 || die->lastroll>6){
    return -1;
  }

  return die->lastroll;
}

/*
*
* @brief: imprime la información de un dado por pantalla
* @params1: el dado que se va a imprimir
* @return: devuelve ERROR si no se ha impreso correctamente, u OK si lo ha hecho correctamente
*
*/
STATUS die_print(Die* die) {

  if (!die) {
    return ERROR;
  }

  fprintf(stdout, "--> Die (Id: %ld; Number: %d)\n", die->id, die->lastroll);

  return OK;
}
/*
*
* @brief: libera la memoria dinámica reservada del dado que se ha recibido
* @params: recibe como parámetro de entrada el dado a liberar
* @return: devuelve ERROR si no se ha liberado la memoria, u OK si lo ha hecho correctamente
*
*/
STATUS die_destroy(Die* die){
  if(!die){
    return ERROR;
  }
    free(die);
  return OK;
}
