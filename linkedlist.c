#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "linkedlist.h"

struct song_node * insert_front(struct song_node *node, char *name, char *artist){
    struct song_node * n = malloc(sizeof(struct song_node));
    strncpy(n->name, name, strlen(name));
    strncpy(n->artist, artist, strlen(artist));
    n->next = 0;
    
    if(node) n->next = node;
    else node = n;
    return n;
}

void print_list(struct song_node *node){
    printf("[ ");
    while(node){
        printf("{%s, %s} | ", node->artist, node->name);
        node = node->next;
    }
    printf("]\n");
}

struct song_node * ordered_insert(struct song_node *node, char *name, char *artist){

}

// compares alphabetical by artist then by song name
int songcmp(struct song_node *a, struct song_node *b){
    int val = strcasecmp(a->artist, b->artist);
    if (!val){
        val = strcasecmp(a->name, b->name); 
    }
    return val;
}



struct song_node * find_node(char *artist, char *name){
    
}

char * find_song(char * artist){

}

struct song_node * random_node(){

}

struct song_node * remove_node(char *artist, char *name){

}

struct song_node * free_list(struct song_node *node){

}