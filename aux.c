  if(strcpy(des, game_get_description(game)) != NULL){
    sprintf(str, " Description: %s", des);
    screen_area_puts(ge->descript, str);
  }

char* game_get_description(Game* game){

  if(game == NULL){
    return NULL;
  }

  return game->gdesc;
}
