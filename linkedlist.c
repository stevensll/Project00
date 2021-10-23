#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "linkedlist.h"

struct song_node * insert_front(struct song_node *node, char *artist, char *name){
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
    else printf("Node not found\n");
}

struct song_node * ordered_insert(struct song_node *node, char *artist, char *name){

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

// returns the name of the first song by the given artist
char * find_song(struct song_node *node, char * artist){
    while (node) {
        if (!strcasecmp((node->artist), artist)) return node->name;
        else node = (node->next);
    }
    return 0;
}

// returns a random song from the given playlist
struct song_node * random_node(struct song_node *node){
    int count = 0;
    struct song_node *start = node;
    while(start){
        count++;
        start = start->next;
    }
    srand(time(NULL));
    int r = rand() % count;
    // printf("%d %d\n", count, r);
    while(node && r){
        r--;
        node = node->next;
    }
    return node;
}

struct song_node * remove_node(struct song_node *node, char *artist, char *name){
    if (!node) return node;
    struct song_node *front = node;
    if ((!strcasecmp((node->artist), artist)) && (!strcasecmp((node->name), name))) {
        front = node->next;
        free(node);
        return front;
    }
    int status = 0;
    while (node->next) {
        struct song_node *temp = node->next;
        if ((!strcasecmp(((node->next)->artist), artist)) && (!strcasecmp(((node->next)->name), name))) {
            node->next = temp->next;
            free(temp);
            status = 1;
            break;
        }
        node = node->next;
    }
    if(!status) printf("[%s, %s] not found\n", artist, name);
    return front;
}

struct song_node * free_list(struct song_node *node){

}