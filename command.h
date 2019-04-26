/**
 * @brief Implementa la barra de comandos
 *
 * @file command.h
 * @author Luis Miguel Nucifora
 * @version 2.0
 * @date 10-03-2019
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"
/**
* @brief La estructura de un comando
*
* Almacena las diferentes informaciones de los comandos
*/
typedef struct _Command Command;

typedef enum enum_Command {
  NO_CMD = -1,
  UNKNOWN,
  EXIT,
  NEXT,
  BACK,
  TAKE,
  DROP,
  ROLL,
  LEFT,
  RIGHT,
  INSPECT,
  MOVE,
  TURNON,
  TURNOFF
  } T_Command;
  /*
  *
  * @brief: reserva memoria dinámica suficiente crear un nuevo comando
  * @return: devuelve el comando creado
  *
  */
Command* command_create();
/*
*
* @brief: libera la memoria dinámica reservada del comando que se ha creado
* @params: recibe como parámetro de entrada un comando
* @return:
*
*/
void command_destroy(Command* command);
/*
*
* @brief: Obtiene el comando creado
* @params: recibe como parámetro de entrada un comando
* @return: devuelve el comando creado
*/
T_Command command_get_cmd(Command* command);
/*
*
* @brief: asigna el comando creado a un objeto
* @params: recibe como parámetro de entrada un comando
* @return: devuelve el objeto al que se refiere el comando
*
*/
char *command_get_imput(Command* command);
/*
*
* @brief: se encarga de copiar comandos
* @params: recibe como parámetro de entrada un comando
* @return: devuelve una copia de dicho comando
*
*/
Command *command_copy(Command *command);
/*
*
* @brief: obtiene el comando introducido por el usuario
* @params:
* @return: devuelve OK si se ha realizado de manera corracta, o ERROR en caso contrario
*
*/
STATUS command_get_user_input();

#endif
