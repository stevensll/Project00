#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "linkedlist.h"

struct song_node * insert_front(struct song_node *node, char *artist, char *name){
    struct song_node * n = malloc(sizeof(struct song_node));
    strncpy(n->name, name, STRING_SIZE);
    strncpy(n->artist, artist, STRING_SIZE);
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

/* insert alphabetically by artist then by song
    current does not add if duplicates
*/
struct song_node * ordered_insert(struct song_node *node, char *artist, char *name){
    struct song_node * a = insert_front(0, artist, name);
    //case node is empty
    if(!node) return a;

    struct song_node * start = node;
    
    //case a comes before starting node
    if(songcmp(a, node) < 0){
        return insert_front(start, artist, name);
    } else if(songcmp(a, node) == 0){
         //case where a = starting node
        return a;
    }

    //other cases
    while(node->next){
        if (songcmp(a, node)==0){
            return start;
        } else if(songcmp(a, node->next) < 0){
            a->next = node->next;
            node->next = a;
            return start;
        }  
        node = node->next;
    }
    // if we reach the end, then append a to the end
    if (songcmp(a, node) == 0){
        return start;
    }
    node->next = a;
    return start;
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
char * find_artist(struct song_node *node, char * artist){
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
    // we don't seed time here -> if we make the call to this function repeatedly, seed wont refresh fast enough. srand in main
    // srand(time(NULL));
    int r = rand() % count;
    // printf("%d %d\n", count, r);
    while(node && r){
        r--;
        node = node->next;
    }
    return node;
}

// removes the specified node and returns the playlist
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

// frees the entire playlist
struct song_node * free_list(struct song_node *node){
    if(!node) return 0;
    while (node){
        struct song_node * temp = node;
        printf("Freeing: ");
        print_song_node(temp);
        node = node->next;
        free(temp);
    }
    return node;
}