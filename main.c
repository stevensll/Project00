#include <stdio.h>
#include <strings.h>


int main(){


  
  struct song_node * playlist = insert_front(playlist ,"Wonderwall","Oasis");
  playlist = insert_front(playlist, "Wish You Were Here","Pink Floyd");
  playlist = insert_front(playlist, "All Along the Watchtower","Bob Dylan");
  playlist = insert_front(playlist, "Little Wing","Jimi Hendrix");
  playlist = insert_front(playlist, "Layla","Cream");

  print_list(playlist);
  
  

  


  

  return 0;
}
