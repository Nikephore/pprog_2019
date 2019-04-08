void game_callback_move(Game *game){
  Link *link;

  Id link_id = NO_ID;
  Id next_space_id = NO_ID;
  Id act_space_id = NO_ID;
  char direction[MAX_STRING] = {0};

  Player *player = game_get_player(game);

  if (!game)
      return;

  strcpy(direction, command_get_id(game->last_cmd[0]));

  if (!game || act_space_id == NO_ID)
      return;

  if (strcmp(direction, "north") == 0 || strcmp(direction, "n") == 0)
    link_id = space_get_north(game_get_space(game, game_get_player_location(game)));

  else if (strcmp(direction, "east") == 0 || strcmp(direction, "e") == 0)
    link_id = space_get_east(game_get_space(game, game_get_player_location(game)));

  else if (strcmp(direction, "south") == 0 || strcmp(direction, "s") == 0)
    link_id = space_get_south(game_get_space(game, game_get_player_location(game)));

  else if (strcmp(direction, "west") == 0 || strcmp(direction, "w") == 0)
    link_id = space_get_west(game_get_space(game, game_get_player_location(game)));

  else
    return;

  link = game_get_link(game, link_id);

}
