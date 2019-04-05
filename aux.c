void game_callback_inspect(Game* game){
  int i = 0;
  Id id_space = NO_ID, id_object = NO_ID;

  if(!game){
    return;
  }

  id_space = game_get_player_location(game);

  if(strcmp(command_get_imput(game->last_cmd),"space") == 0 || strcmp(command_get_imput(game->last_cmd),"s") == 0){
    return;
  }

  for(i=0; i<MAX_OBJECTS; i++){

    if(player_get_inventory(game->player) == NULL || player_get_num_objects(game->player) < MAX_OBJECTS){
      if(game->object[i] != NULL){
        id_object = game_get_object_id(game, i);
    /*Compara el nombre del objeto con el que se le pasa por el comando*/
        if(strcmp(object_get_name(game->object[i]),command_get_imput(game->last_cmd)) == 0){
          if (space_search_object(game_get_space(game, id_space), id_object) == TRUE || player_search_object(game->player, id_object) == TRUE){
            strcpy(game->gdesc, object_get_description(game->object[i]));
            return;
          }
        }
      }
    }
  }
  return;
}
