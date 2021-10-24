# include <stdio.h>
# include <strings.h>
# include <time.h>
# include <stdlib.h>
# include "library.h"

void find_test(){
    struct song_node * playlist = insert_front(0 ,"radiohead", "street spirit (fade out)");
    playlist = insert_front(playlist, "radiohead","paranoid android");
    playlist = insert_front(playlist, "pink floyd","time");
    playlist = insert_front(playlist, "pearl jam","yellow ledbetter");
    playlist = insert_front(playlist, "pearl jam","even flow");
    playlist = insert_front(playlist, "pearl jam","alive");
    playlist = insert_front(playlist, "ac/dc", "thunderstruck");
    
    printf("Testing find_node:\n\n");
    print_list(playlist);
    printf("\n");

    printf("Looking for [pearl jam: even flow]\n\t");
    print_song_node(find_node(playlist, "pearl jam", "even flow"));
    printf("Looking for [pearl jam: daughter]\n\t");
    print_song_node(find_node(playlist, "pearl jam", "daughter"));
    printf("\n");

    printf("=============================================\n");
    printf("Testing find_artist:\n\n");
    printf("Looking for [pink floyd]\n\t");
    printf("%s\n", find_artist(playlist,"pink floyd"));
    printf("Looking for [pearl jam]\n\t");
    printf("%s\n", find_artist(playlist, "pearl jam"));

    playlist = free_list(playlist);
}

void song_cmp_test(){
    printf("Testing song_cmp:\n\t");
    struct song_node * playlist = insert_front(0, "pearl jam", "even flow");
    playlist = insert_front(playlist, "pearl jam", "even flow");
    playlist = insert_front(playlist, "pearl jam", "alive");
    playlist = insert_front(playlist, "pink floyd", "time");
    
    printf("Comparing songs:\n\t");
    print_song_node(playlist->next->next->next);
    printf("\t");
    print_song_node(playlist->next->next);
    printf("\t\t%d\n", songcmp(playlist->next->next, playlist->next->next->next));

    printf("\tComparing song:\n\t");
    print_song_node(playlist->next->next);
    printf("\t");
    print_song_node(playlist->next);
    printf("\t\t%d\n", songcmp(playlist->next->next, playlist->next));

    printf("\tComparing song:\n\t");
    print_song_node(playlist->next);
    printf("\t");
    print_song_node(playlist->next->next);
    printf("\t\t%d\n", songcmp(playlist->next, playlist->next->next));

    printf("\tComparing songs:\n\t");
    print_song_node(playlist->next->next);
    printf("\t");
    print_song_node(playlist);
    printf("\t\t%d\n", songcmp(playlist->next->next, playlist));
    playlist = free_list(playlist);
    print_list(playlist);

}

void random_node_test(){
    struct song_node * playlist = insert_front(0 ,"radiohead", "street spirit (fade out)");
    playlist = insert_front(playlist, "radiohead","paranoid android");
    playlist = insert_front(playlist, "pink floyd","time");
    playlist = insert_front(playlist, "pearl jam","yellow ledbetter");
    playlist = insert_front(playlist, "pearl jam","even flow");
    playlist = insert_front(playlist, "pearl jam","alive");
    playlist = insert_front(playlist, "ac/dc", "thunderstruck");
    
    printf("Testing random_node:\n\n");
    print_list(playlist);
    printf("\n");

    print_song_node(random_node(playlist));
    print_song_node(random_node(playlist));
    print_song_node(random_node(playlist));
    print_song_node(random_node(playlist));

    playlist = free_list(playlist);
}

void remove_node_test(){
    struct song_node * playlist = insert_front(0 ,"radiohead", "street spirit (fade out)");
    playlist = insert_front(playlist, "radiohead","paranoid android");
    playlist = insert_front(playlist, "pink floyd","time");
    playlist = insert_front(playlist, "pearl jam","yellow ledbetter");
    playlist = insert_front(playlist, "pearl jam","even flow");
    playlist = insert_front(playlist, "pearl jam","alive");
    playlist = insert_front(playlist, "ac/dc", "thunderstruck");
   
    printf("Testing remove_node:\n\n");
    print_list(playlist);
    printf("\n");

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
    printf("\n");
    playlist = free_list(playlist);
    print_list(playlist);
}

void ordered_insert_test(){
    struct song_node * playlist = insert_front(0, "a", "r");
    printf("Testing ordered_insert\n\n");    
    print_list(playlist);
    playlist = ordered_insert(playlist, "a", "t");
    printf("\nInserting {a, t}\n\t");
    print_list(playlist);
    playlist = ordered_insert(playlist, "a", "s");
    printf("Inserting {a, s}\n\t");
    print_list(playlist);
    playlist = ordered_insert(playlist, "a", "t");
    printf("Inserting {a, t}\n\t");
    print_list(playlist);
    playlist = ordered_insert(playlist, "b", "a");
    printf("Inserting {b, a}\n\t");
    print_list(playlist);
    playlist = ordered_insert(playlist, "b", "b");
    printf("Inserting {b, b}\n\t");
    print_list(playlist);
    playlist = ordered_insert(playlist, "a", "t");
    printf("Inserting {b, b}\n\t");
    print_list(playlist);
    playlist = ordered_insert(playlist, "a", "a");
    printf("Inserting {a, a}\n\t");
    print_list(playlist);
}

void make_lib_test(){
    struct song_node * a1 = insert_front(0, "a1", "s1");
    a1 = insert_front(a1, "a1", "s2");
    struct song_node * a2 = insert_front(0, "a2", "s1");
    struct song_node * a3 = insert_front(0, "a3", "s1");
    struct song_node * a4 = insert_front(0, "a4", "s1");
    struct song_node * a5 = insert_front(0, "a5", "s1");
    struct song_node * a6 = insert_front(0, "a6", "s1");
    struct song_node * a7 = insert_front(0, "a7", "s1");
    struct song_node * a8 = insert_front(0, "a8", "s1");
    struct song_node * a9 = insert_front(0, "a9", "s1");
    struct song_node ** lib = make_lib();
    print_lib(lib);
    lib = add_list(lib, a1);
    lib = add_list(lib, a2);
    lib = add_list(lib, a3);
    lib = add_list(lib, a4);
    lib = add_list(lib, a5);
    lib = add_list(lib, a6);
    lib = add_list(lib, a7);
    lib = add_list(lib, a8);
    lib = add_list(lib, a9);
    print_lib(lib);

}

int main(){
    // printf("=============================================\n");
    // find_test();
    // printf("=============================================\n");
    // remove_node_test();
    // srand(time(NULL));
    // printf("=============================================\n");
    // random_node_test();
    // printf("=============================================\n");
    // song_cmp_test();
    // printf("=============================================\n");
    // ordered_insert_test();
    make_lib_test();
    return 0;
}
