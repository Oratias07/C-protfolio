#ifndef _JAMPING_GAME_HEADER_
#define _JAMPING_GAME_HEADER_

#define _CRT_SECURE_NO_WARNINGS
#define N 10
#include <stdio.h>
#include <stdlib.h>

// structures
typedef struct kNode
{
    int k;
    struct kNode* prev, * next;
} *PkNode;

typedef struct nodeList
{
    PkNode head;
    PkNode tail;
    int num_of_step;
} *pNodeList;


// functions prototype
/* adds an node to the head of the node list */
void add_as_first(PkNode node, pNodeList node_list);

/* frees the list */
void free_all(pNodeList list);

/* print error message and exit program */
void error_message(char* str);

/* the game runs in a loop until a stopping condition is met */
int game_on(pNodeList pNodes_list, int max_steps);

/* printing doubly linked list */
void print_list(PkNode node);

/* delete the current node */
void delete_current(pNodeList pNodes_list, PkNode current);


#endif
