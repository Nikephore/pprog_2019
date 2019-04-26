/**
 * @brief Implementa la barra de comandos
 *
 * @file command.c
 * @author  Luis Miguel Nucifora
 * @version 2.0
 * @date 10-03-2019
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "command.h"

#define CMD_LENGHT 30
#define N_CMD 12
/**
* @brief La estructura de un comando
*
* Almacena las diferentes informaciones de los comandos
*/
struct _Command{
  T_Command cmd;
  char imp[WORD_SIZE + 1];
};

char *cmd_to_str[N_CMD] = {"No command", "Unknown", "Exit", "Next", "Back", "Take",
                             "Drop", "Roll", "Left", "Right", "Inspect", "Move", "TurnOn", "TurnOff"};
char *short_cmd_to_str[N_CMD] = {"","","e","n","b","t","d","rl","l","r","i","m", "on", "off"};
/*
*
* @brief: reserva memoria dinámica suficiente crear un nuevo comando
* @return: devuelve el comando creado
*
*/
Command* command_create(){
  Command *new_command = NULL;

  new_command = (Command*)malloc(sizeof(Command));
  if(!new_command){
    return NULL;
  }

  new_command->cmd = NO_CMD;
  new_command->imp[0] = '\0';

  return new_command;
}
/*
*
* @brief: libera la memoria dinámica reservada del comando que se ha creado
* @params: recibe como parámetro de entrada un comando
* @return:
*
*/
void command_destroy(Command *command){
  if(command == NULL){
    return;
  }

  free(command);

  return;
}
/*
*
* @brief: Obtiene el comando creado
* @params: recibe como parámetro de entrada un comando
* @return: devuelve el comando creado
*/
T_Command command_get_cmd(Command *command){
  if(!command){
    return NO_CMD;
  }
  printf("Cmd2: %d\n", command->cmd);
  return command->cmd;
}
/*
*
* @brief: asigna el comando creado a un objeto
* @params: recibe como parámetro de entrada un comando
* @return: devuelve el objeto al que se refiere el comando
*
*/
char *command_get_imput(Command *command){
  if(!command){
    return NULL;
  }
  return command->imp;
}
/*
*
* @brief: se encarga de copiar comandos
* @params: recibe como parámetro de entrada un comando
* @return: devuelve una copia de dicho comando
*
*/
Command *command_copy(Command *command){
  Command *copy = NULL;

  if(!command){
    return NULL;
  }

  copy = command;

  return copy;
}
/*
*
* @brief: obtiene el comando introducido por el usuario
* @params:
* @return: devuelve OK si se ha realizado de manera corracta, o ERROR en caso contrario
*
*/
STATUS command_get_user_input(Command *command){
  char input[CMD_LENGHT] = "";
  char input1[CMD_LENGHT] = "";
  char buff[CMD_LENGHT] = "";
  int i = UNKNOWN - NO_CMD + 1;
  int aux;

  if(!command){
    return NO_CMD;
  }

  command->cmd = NO_CMD;
  fgets(buff, WORD_SIZE, stdin);
  aux=sscanf(buff, "%s %s", input, input1);
  if(aux > 0){
    command->cmd = UNKNOWN;
    strcpy(command->imp,"");

    while(command->cmd == UNKNOWN && i < N_CMD){
      if(!strcasecmp(input, short_cmd_to_str[i]) || !strcasecmp(input, cmd_to_str[i])){
        command->cmd = i + NO_CMD;
        if(aux > 1 && command->cmd == TAKE){
          strcpy(command->imp, input1);
        }
        else if(aux > 1 && command->cmd == DROP){
          strcpy(command->imp, input1);
        }
        else if(aux > 1 && command->cmd == INSPECT){
          strcpy(command->imp, input1);
        }
        else if(aux > 1 && command->cmd == MOVE){
          strcpy(command->imp, input1);
        }
        else if(aux > 1 && command->cmd == TURNON){
          strcpy(command->imp, input1);
        }
        else if(aux > 1 && command->cmd == TURNOFF){
          strcpy(command->imp, input1);
        }
      }
      else{
        i++;
      }
    }
  }
  else{
    command->cmd = UNKNOWN;
    strcpy(command->imp,"");
  }
  return OK;
}
