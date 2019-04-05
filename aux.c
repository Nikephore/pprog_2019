BOOL space_search_object(Space *space, Id id){

  if(space == NULL || id == NO_ID){
    return FALSE;
  }

  return set_compare(space->set, id);
}
