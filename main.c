# include <stdio.h>
# include <strings.h>
# include <time.h>
# include <stdlib.h>
# include "linkedlist.h"

void song_cmp_test(){
    printf("Testing song_cmp:\n\t");

    struct song_node * pcomp1 = insert_front(0, "even flow", "pearl jam");
    pcomp1 = insert_front(pcomp1, "even flow", "pearl jam");
    printf("Comparing song: ");
    print_list(pcomp1);
    printf("\t\t%d\n", songcmp(pcomp1->next, pcomp1));

    struct song_node * pcomp2 = insert_front(0, "even flow", "pearl jam");
    pcomp2 = insert_front(pcomp2, "alive", "pearl jam");
    printf("\tComparing song: ");
    print_list(pcomp2);
    printf("\t\t%d\n", songcmp(pcomp2->next, pcomp2));

    struct song_node * pcomp3 = insert_front(0, "even flow", "pearl jam");
    pcomp3 = insert_front(pcomp3, "time", "pink floyd");
    printf("\tComparing song: ");
    print_list(pcomp3);
    printf("\t\t%d\n", songcmp(pcomp3->next, pcomp3));
    free(pcomp1);
    free(pcomp2);
    free(pcomp3);
}

void random_node_test(){
    printf("Testing random_node():\n");
}
int main(){
    struct song_node * playlist = insert_front(0 ,"Wonderwall","Oasis");
    playlist = insert_front(playlist, "Wish You Were Here","Pink Floyd");
    playlist = insert_front(playlist, "All Along the Watchtower","Bob Dylan");
    playlist = insert_front(playlist, "Little Wing","Jimi Hendrix");
    playlist = insert_front(playlist, "Layla","Cream");

    printf("Testing print_list:\n\t");
    print_list(playlist);

    printf("Testing find_node:\n\t");
    print_song_node(find_node(playlist, "Bob Dylan","All Along the Watchtower"));

    printf("Testing find_song:\n\t");
    printf("%s\n", find_song(playlist, "Bob Dylan"));

    printf("Testing random_node:\n\t");
    print_song_node(random_node(playlist));
    printf("Completed\n");
    // printf("Testing remove_node:\n\t");
    // print_list(remove_node(playlist, "Pink Floyd", "Wish You Were Here"));



    // song_cmp_test();

  

    return 0;
}
