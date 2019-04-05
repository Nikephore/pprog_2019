BOOL inventory_compare(Inventory *inv, Id id){
  int i;

  if(inv == NULL || id == NO_ID){
    return FALSE;
  }

  for(i=0; i<inventory_get_num_objects(inv); i++){
    if(inventory_get_object_id(inv, i) == id){
      return TRUE;
    }
  }

  return FALSE;
}
