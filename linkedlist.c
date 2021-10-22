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

void print_song_node(struct song_node *node){
    if (node) printf("{%s, %s}\n", node->artist, node->name);
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

// returns a node containing the given artist and name
struct song_node * find_node(struct song_node *node, char *artist, char *name){
    while (node) {
        if ((!strcasecmp((node->artist), artist)) && (!strcasecmp((node->name), name))) return node;
        else node = (node->next);
    }
    return 0;
}

// returns the name of the first song by the given author
char * find_song(struct song_node *node, char * artist){
    while (node) {
        if (!strcasecmp((node->artist), artist)) return node->name;
        else node = (node->next);
    }
    return 0;
}

struct song_node * random_node(struct song_node *node){

}

struct song_node * remove_node(struct song_node *node, char *artist, char *name){
    struct song_node *temp;
    struct song_node *front = node;
    if ((!strcasecmp((node->artist), artist)) && (!strcasecmp((node->name), name))) {
        temp = node->next;
        free(node);
        return temp;
    }
    while (node->next) {
        if ((!strcasecmp(((node->next)->artist), artist)) && (!strcasecmp(((node->next)->name), name))) {
            temp = node->next;
            free(node->next);
           // temp->next = ((temp->next)->next);
            temp = temp->next;
            break;
        }
        else node = (node->next);
    }
    return front;
}

struct song_node * free_list(struct song_node *node){

}