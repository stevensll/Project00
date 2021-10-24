#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "linkedlist.h"
#define LIB_SIZE 27

struct song_node ** make_lib();
struct song_node ** add_list(struct song_node ** lib, struct song_node * node);

struct song_node ** search_song(struct song_node ** lib, char * artist, char * name);

struct song_node ** search_artist(struct song_node ** lib, char * artist, char * name);

void print_by_letter(struct song_node ** lib, char letter);

void print_by_artist(struct song_node ** lib, char * artists);

void print_lib(struct song_node ** lib);

void print_shuffle(struct song_node ** lib);

struct song_node ** delete_song(struct song_node ** lib, char * artist, char * name);

struct song_node ** free_lib(struct song_node ** lib);
