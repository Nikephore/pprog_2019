/**
 * @brief Muestra la interfaz grafica del juego por pantalla
 *
 * @file graphic_engine.c
 * @authors PPROG teachers & Luis Nucifora & Álvaro Platón
 * @version 2.0
 * @date 12/03/2019
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "screen.h"
#include "graphic_engine.h"
/**
* @brief La estructura de nuestro motor grafico
*
* Almacena las diferentes informaciones de nuestro motor grafico
*/
struct _Graphic_engine{
  Area *map, *descript, *banner, *help, *feedback;
};

/*
* @brief: Inicializa la estructura graphic_engine, reserva la memoria necesaria para la estructura y define sus campos
* @return: devuelve la direccion de la memoria reservada para la estructura
*/

Graphic_engine *graphic_engine_create(){
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init();
  ge = (Graphic_engine *) malloc(sizeof(Graphic_engine));

  if(!ge){
    return NULL;
  }

  ge->map      = screen_area_init( 1, 1, 48, 14);
  ge->descript = screen_area_init(50, 1, 29, 14);
  ge->banner   = screen_area_init(28,16, 23,  1);
  ge->help     = screen_area_init( 1,17, 78,  2);
  ge->feedback = screen_area_init( 1,20, 78,  2);

  return ge;
}
/*
* @brief: libera la memoria reservada para una estructura de graphic_engine
*/
void graphic_engine_destroy(Graphic_engine *ge){
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}
/*
* @brief: imprime por pantalla toda la información del juego, el mapa, la descripcion de los jugadores, objetos que hay, los comandos que puedes poner y tus últimos comandos
* @params 1: recibe la direccion de una estructura de graphic_engine
* @params 2: recibe la direccion de una estructura de game
*/

void graphic_engine_paint_game(Graphic_engine *ge, Game *game){
  Id id_act = NO_ID, id_next = NO_ID;
  Id obj_loc = NO_ID, pla_loc = NO_ID;
  Id id_aux = NO_ID;
  int die = 0;
  int i;
  char dir;
  Space* space_act = NULL;
  Space* space_next = NULL;
  char str[STRING], ob1[STRING], ob2[STRING], ob3[STRING], ob4[STRING];
  T_Command last_cmd = UNKNOWN;
  Id linkaux;

  extern char *cmd_to_str[];


  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID){
    space_act = game_get_space(game, id_act);
    linkaux = space_get_south(space_act);
    id_next = link_get_space2_id(game_get_link(game, linkaux));
    space_next = game_get_space(game, id_next);

        if((id_aux = game_get_object_id(game,0)) != NO_ID){
            if(game_get_object_location(game,id_aux) == id_act)
              sprintf(ob1, "FR ");
            else
              sprintf(ob1, "   ");
          }
          if((id_aux = game_get_object_id(game,1)) != NO_ID){
            if(game_get_object_location(game,id_aux) == id_act)
              sprintf(ob2, "FA ");
            else
              sprintf(ob2, "   ");
          }
          if((id_aux = game_get_object_id(game,2)) != NO_ID){
            if(game_get_object_location(game,id_aux) == id_act)
              sprintf(ob3, "FV ");
            else
              sprintf(ob3, "   ");
          }
          if((id_aux = game_get_object_id(game,3)) != NO_ID){
            if(game_get_object_location(game,id_aux) == id_act)
              sprintf(ob4, "FM");
            else
              sprintf(ob4, "  ");
          }

        if(game_get_player_location(game)== 5 && game_get_player_location(game)==id_act)
          dir='>';
        else if(game_get_player_location(game)==8 && game_get_player_location(game)==id_act)
          dir='>';
        else if(game_get_player_location(game)==9 && game_get_player_location(game)==id_act)
          dir='>';
        else if(game_get_player_location(game)==13 && game_get_player_location(game)==id_act)
          dir='>';
        else if(game_get_player_location(game)==17 && game_get_player_location(game)==id_act)
          dir='>';
        else if(game_get_player_location(game)==21 && game_get_player_location(game)==id_act)
          dir='>';
        else if(game_get_player_location(game)==16 && game_get_player_location(game)==id_act)
          dir='<';
        else if(game_get_player_location(game)==22 && game_get_player_location(game)==id_act)
          dir='<';
        else
          dir=' ';

        if (id_act != NO_ID) {
          sprintf(str, "  +-----------+");
          screen_area_puts(ge->map, str);
          sprintf(str, "  | >8D     %2d|%c",(int) id_act, dir);
          screen_area_puts(ge->map, str);
          sprintf(str, "  |   %s |",space_get_gdesc_illustration(space_act,0));
          screen_area_puts(ge->map, str);
          sprintf(str, "  |   %s |",space_get_gdesc_illustration(space_act,1));
          screen_area_puts(ge->map, str);
          sprintf(str, "  |   %s |",space_get_gdesc_illustration(space_act,2));
          screen_area_puts(ge->map, str);
          sprintf(str, "  |%s%s%s%s|",ob1,ob2,ob3,ob4);
          screen_area_puts(ge->map, str);
          sprintf(str, "  +-----------+");
          screen_area_puts(ge->map, str);
        }

        if((id_aux = game_get_object_id(game,0)) != NO_ID){
            if(game_get_object_location(game,id_aux) == id_next)
              sprintf(ob1, "FR ");
            else
              sprintf(ob1, "   ");
          }
          if((id_aux = game_get_object_id(game,1)) != NO_ID){
            if(game_get_object_location(game,id_aux) == id_next)
              sprintf(ob2, "FA ");
            else
              sprintf(ob2, "   ");
          }
          if((id_aux = game_get_object_id(game,2)) != NO_ID){
            if(game_get_object_location(game,id_aux) == id_next)
              sprintf(ob3, "FV ");
            else
              sprintf(ob3, "   ");
          }
          if((id_aux = game_get_object_id(game,3)) != NO_ID){
            if(game_get_object_location(game,id_aux) == id_next)
              sprintf(ob4, "FM");
            else
              sprintf(ob4, "  ");
          }

            if(game_get_player_location(game)==5 && game_get_player_location(game)==id_next)
              dir='>';
            else if(game_get_player_location(game)==8 && game_get_player_location(game)==id_next)
              dir='>';
            else if(game_get_player_location(game)==9 && game_get_player_location(game)==id_next)
              dir='>';
            else if(game_get_player_location(game)==13 && game_get_player_location(game)==id_next)
              dir='>';
            else if(game_get_player_location(game)==17 && game_get_player_location(game)==id_next)
              dir='>';
            else if(game_get_player_location(game)==21 && game_get_player_location(game)==id_next)
              dir='>';
            else if(game_get_player_location(game)==16 && game_get_player_location(game)==id_next)
              dir='<';
            else if(game_get_player_location(game)==22 && game_get_player_location(game)==id_next)
              dir='<';
            else
              dir=' ';


        if (id_next != NO_ID) {
          sprintf(str, "        v");
          screen_area_puts(ge->map, str);
          sprintf(str, "  +-----------+");
          screen_area_puts(ge->map, str);
          sprintf(str, "  |         %2d|%c",(int) id_next, dir);
          screen_area_puts(ge->map, str);
          sprintf(str, "  |   %s |",space_get_gdesc_illustration(space_next,0));
          screen_area_puts(ge->map, str);
          sprintf(str, "  |   %s |",space_get_gdesc_illustration(space_next,1));
          screen_area_puts(ge->map, str);
          sprintf(str, "  |   %s |",space_get_gdesc_illustration(space_next,2));
          screen_area_puts(ge->map, str);
          sprintf(str, "  |%s%s%s%s|",ob1,ob2,ob3,ob4);
          screen_area_puts(ge->map, str);
        }
      }

  /* Paint the in the description area */


  screen_area_clear(ge->descript);
  sprintf(str," Object location:");
  screen_area_puts(ge->descript, str);

  for(i=0; i < MAX_OBJECTS; i++){
    if((id_aux = game_get_object_id(game, i)) != NO_ID){
      if ((obj_loc = game_get_object_location(game,id_aux)) != NO_ID){
        sprintf(str, "  %s: %d", (game_get_object_name(game,i+1)), (int)obj_loc);
        screen_area_puts(ge->descript, str);
      }
    }
  }


  if ((pla_loc = game_get_player_location(game)) != NO_ID){
    sprintf(str, " Player location:%d", (int)pla_loc);
    screen_area_puts(ge->descript, str);
  }

  if ((die = game_get_die(game)) != -1){
    sprintf(str, " Die value:%d", (int)die);
    screen_area_puts(ge->descript, str);
  }


  if(game_get_description(game) != NULL && game_get_last_command(game) == INSPECT){
        printf("ERR1: %s", game_get_description(game));
        sprintf(str, " Description: %s", game_get_description(game));
        screen_area_puts(ge->descript, str);

    }

  /* Paint the in the banner area */
  screen_area_puts(ge->banner, " The game of the Goose ");

  /* Paint the in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     next(n), back(b), exit(e), take(t), drop(d), roll(rl), right(r), left(l), inspect(i)");
  screen_area_puts(ge->help, str);

  /* Paint the in the feedback area */
  last_cmd = game_get_last_command(game);
  sprintf(str, " %s", cmd_to_str[last_cmd-NO_CMD]);
  screen_area_puts(ge->feedback, str);

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
