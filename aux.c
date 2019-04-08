BOOL set_compare(Set *set, Id id){
  int i = 0;

  if(set == NULL || id == NO_ID){
    return FALSE;
  }

  for(i=0; i < set->num_elem; i++){
    if(set->array_id[i] == id){
      return TRUE;
    }
  }

  return FALSE;
}
