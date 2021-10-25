#include "library.h"
//makes 2D array of song_nodes size 27
struct song_node ** make_lib(){
    struct song_node ** lib = calloc(LIB_SIZE, sizeof(struct song_node *));
    return lib;
}
//adds a list to the first null entry in the library, if full just returns lib
struct song_node ** add_list(struct song_node ** lib, struct song_node * node){
    // int i = 0;
    // while(i < LIB_SIZE){
    //     if(!lib[i]){
    //         lib[i] = node;
    //         return lib;
    //     }
    //     i++;
    // }
    // printf("No space left in library");
    // return lib;
    lib[lib_index(node->artist)] = ordered_insert(lib[lib_index(node->artist)], node->artist, node->name);
    return lib;
}

int lib_index(char *artist) {
    if (!isalpha(artist[0])) return 0;
    return ((int) tolower(artist[0])) - 96; 
}

struct song_node * search_song(struct song_node ** lib, char * artist, char * name){
    return (find_node(lib[lib_index(artist)], artist, name));
}

struct song_node * search_artist(struct song_node ** lib, char * artist){
    return (find_artist(lib[lib_index(artist)], artist));
}

void print_by_letter(struct song_node ** lib, char letter){
    char * letterp = &letter;
    struct song_node * letter_list = lib[lib_index(letterp)];
    printf("%c: ", letter);
    print_list(letter_list);
}

void print_by_artist(struct song_node ** lib, char * artist){
    struct song_node * letter = lib[lib_index(artist)];
    printf("%s: [", artist);
    while (letter) {
        if (!strcmp(letter->artist, artist)) {
            printf("{%s, %s} |", letter->artist, letter-> name);
        }
        letter = letter->next;
    }
    printf(" ]\n");
}

void print_lib(struct song_node ** lib){
    if (lib[0]) {
        printf("Other: ");
        print_list(lib[0]);
    }
    int i = 1;
    while(i < LIB_SIZE){
        if (lib[i]) {
            printf("%c: ", (char) (i + 96));
            print_list(lib[i]);   
        }
        i++;
    }
}

void print_shuffle(struct song_node ** lib){
    int i = 0;
    while (i < 3) {
        int index = (int)(rand() % LIB_SIZE);
        struct song_node * node = random_node(lib[index]);
        while (!node) {
            index = (rand() % LIB_SIZE);
            node = random_node(lib[index]);
        }
        print_song_node(node);
        i++;
    }
}

struct song_node ** delete_song(struct song_node ** lib, char * artist, char * name){
    lib[lib_index(artist)] = remove_node(lib[lib_index(artist)], artist, name);
    return lib;
}

struct song_node ** clear_lib(struct song_node ** lib){
    int i = 0;
    while(i < LIB_SIZE){
        lib[i] = free_list(lib[i]);
        i++;
    }
    return lib;
}
