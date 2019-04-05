  if(strcpy(des, game_get_description(game)) != NULL){
    sprintf(str, " Description: %s", des);
    screen_area_puts(ge->descript, str);
  }
