/**
 * @brief Define el bucle de juego
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphic_engine.h"
#include "game_reader.h"
#include "command.h"

int main(int argc, char *argv[]){
  Game *game = NULL;
  Command *command = NULL;
  Graphic_engine *gengine;

if (argc < 2){
  fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
 return 1;
}

game = game_create();
if (game == NULL){
  fprintf(stderr, "Error while initializing game.\n");
  return 1;
}

if (game_create_from_file(game, argv[1]) == ERROR){
  fprintf(stderr, "Error while initializing game.\n");
  return 1;
}

if ((gengine = graphic_engine_create()) == NULL){
  fprintf(stderr, "Error while initializing graphic engine.\n");
  game_destroy(game);
  return 1;
}

if((command = command_create()) == NULL){
  fprintf(stderr, "Error while initializing command.\n");
  game_destroy(game);
  graphic_engine_destroy(gengine);
  return 1;
}
while ( (command_get_cmd(command) != EXIT) && !game_is_over(game) ){
		  graphic_engine_paint_game(gengine, game);
      if(command_get_user_input(command) == ERROR){
        game_destroy(game);
        graphic_engine_destroy(gengine);
        command_destroy(command);
        return 1;
      }
      printf("Command %d\n", command_get_cmd(command));
      game_update(game, command);
}

game_destroy(game);
graphic_engine_destroy(gengine);
command_destroy(command);

return 0;
}
