/**
*@brief obtiene el número de objetos de un jugador
*@param1 p. El jugador del que queremos obtener el nombre
*@return devuelve el número de objetos del jugador.
*/
int player_get_num_objects(Player * p){
  if(!p)
    return -1;

  return inventory_get_num_objects(p->inventory);
}

BOOL player_search_object(Player * p, Id id){
  if(!p)
    return FALSE;

  return inventory_compare(p->inventory, id);
}
