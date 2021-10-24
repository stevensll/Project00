#include "library.h"
//makes 2D array of song_nodes size 27
struct song_node ** make_lib(){
    struct song_node ** lib = malloc(LIB_SIZE*sizeof(struct song_node *));
    int i = 0;
    while(i < LIB_SIZE){
        lib[i] = NULL;
        i++;
    }
    return lib;
}
//adds a list to the first null entry in the library, if full just returns lib
struct song_node ** add_list(struct song_node ** lib, struct song_node * node){
    int i = 0;
    while(i < LIB_SIZE){
        if(!lib[i]){
            lib[i] = node;
            return lib;
        }
        i++;
    }
    printf("No space left in library");
    return lib;
}

struct song_node ** search_song(struct song_node ** lib, char * artist, char * name){}

struct song_node ** search_artist(struct song_node ** lib, char * artist, char * name){}

void print_by_letter(struct song_node ** lib, char letter){}

void print_by_artist(struct song_node ** lib, char * artists){}

void print_lib(struct song_node ** lib){
    int i = 0;
    while(i < LIB_SIZE){
        print_list(lib[i]);   
        i++;
    }
}

void print_shuffle(struct song_node ** lib){}

struct song_node ** delete_song(struct song_node ** lib, char * artist, char * name){}

struct song_node ** free_lib(struct song_node ** lib){
    int i = 0;
    while(i < LIB_SIZE){
        free_list(lib[i]);
        i++;
    }
    return lib;
}
