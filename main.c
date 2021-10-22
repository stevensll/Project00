# include <stdio.h>
# include <strings.h>
# include <time.h>
# include <stdlib.h>
# include "linkedlist.h"

int main(){
  
  struct song_node * playlist = insert_front(0 ,"Wonderwall","Oasis");
  playlist = insert_front(playlist, "Wish You Were Here","Pink Floyd");
  playlist = insert_front(playlist, "All Along the Watchtower","Bob Dylan");
  playlist = insert_front(playlist, "Little Wing","Jimi Hendrix");
  playlist = insert_front(playlist, "Layla","Cream");

  printf("Testing print_list:\n\t");
  print_list(playlist);
  
  printf("Testing song_cmp:\n\t");

  struct song_node * pcomp1 = insert_front(0, "even flow", "pearl jam");
  struct song_node * pcomp2 = insert_front(0, "time", "plink floyd");
  printf("%d\n", songcmp(pcomp1, pcomp2));

  


  

  return 0;
}
