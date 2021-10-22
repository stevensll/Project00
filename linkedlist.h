#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct song_node {
    char name[200];
    char artist[200];
    struct song_node *next;
};

struct song_node * insert_front(struct song_node *node, char *name, char *artist);

struct song_node * ordered_insert(struct song_node *node, char *name, char *artist);

int songcmp(struct song_node *a, struct song_node *b);

void print_list(struct song_node *node);

void print_song_node(struct song_node *node);

struct song_node * find_node(struct song_node *node, char *artist, char *name);

char * find_song(struct song_node *node, char * artist);

struct song_node * random_node(struct song_node *node);

struct song_node * remove_node(struct song_node *node, char *artist, char *name);

struct song_node * free_list(struct song_node *node);