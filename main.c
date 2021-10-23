# include <stdio.h>
# include <strings.h>
# include <time.h>
# include <stdlib.h>
# include "linkedlist.h"

void song_cmp_test(){
    printf("Testing song_cmp:\n\t");

    struct song_node * pcomp1 = insert_front(0, "pearl jam", "even flow");
    pcomp1 = insert_front(pcomp1, "pearl jam", "even flow");
    printf("Comparing song: ");
    print_list(pcomp1);
    printf("\t\t%d\n", songcmp(pcomp1->next, pcomp1));

    struct song_node * pcomp2 = insert_front(0, "pearl jam", "even flow");
    pcomp2 = insert_front(pcomp2, "pearl jam", "alive");
    printf("\tComparing song: ");
    print_list(pcomp2);
    printf("\t\t%d\n", songcmp(pcomp2->next, pcomp2));

    struct song_node * pcomp3 = insert_front(0, "pearl jam", "even flow");
    pcomp3 = insert_front(pcomp3, "pink floyd", "time");
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

void remove_node_test(){
    struct song_node * playlist = insert_front(0 ,"radiohead", "street spirit (fade out)");
    playlist = insert_front(playlist, "radio head","paranoid android");
    playlist = insert_front(playlist, "pink floyd","time");
    playlist = insert_front(playlist, "pearl jam","yellow ledbetter");
    playlist = insert_front(playlist, "pearl jam","even flow");
    playlist = insert_front(playlist, "pearl jam","alive");
    playlist = insert_front(playlist, "ac/dc", "thunderstruck");
   
    printf("\n");
    print_list(playlist);
    printf("\n");
    printf("Testing remove_node:\n\n");

    printf("Removing [ac/dc: thunderstruck]\n\t");
    playlist = remove_node(playlist, "AC/Dc", "thunderstruck");
    print_list(playlist);
    printf("Removing [radiohead: street spirit (fade out)]\n\t");
    playlist = (remove_node(playlist, "radioHeAd", "street sPirit (fade out)"));
    print_list(playlist);
    printf("Removing [pearl jam: yellow ledbetter]\n\t");
    playlist = (remove_node(playlist, "pearl JaM", "yeLLOW ledbetter"));
    print_list(playlist);
    printf("Removing [pearl jam: yellow ledbetter]\n\t");
    playlist = (remove_node(playlist, "pearl jAM", "yeLLOW ledbetter"));
    print_list(playlist);
    // free();
}
int main(){
    // struct song_node * playlist = insert_front(0 ,"Wonderwall","Oasis");
    // playlist = insert_front(playlist, "Wish You Were Here","Pink Floyd");
    // playlist = insert_front(playlist, "All Along the Watchtower","Bob Dylan");
    // playlist = insert_front(playlist, "Little Wing","Jimi Hendrix");
    // playlist = insert_front(playlist, "Layla","Cream");

    // printf("Testing print_list:\n\t");
    // print_list(playlist);

    // printf("Testing find_node:\n\t");
    // print_song_node(find_node(playlist, "Bob Dylan","All Along the Watchtower"));

    // printf("Testing find_song:\n\t");
    // printf("%s\n", find_song(playlist, "Bob Dylan"));

    // printf("Testing random_node:\n\t");
    // print_song_node(random_node(playlist));
        
    // printf("Testing remove_node:\n\t");
    // print_list(remove_node(playlist, "Pink Floyd", "Wish You Were Here"));
    // print_list(remove_node(playlist, "Pink Floyd", "Wish You Were Here"));

    // song_cmp_test();

    remove_node_test();

    return 0;
}
