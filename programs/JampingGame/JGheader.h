#ifndef _JAMPING_GAME_HEADER_
#define _JAMPING_GAME_HEADER_

#define _CRT_SECURE_NO_WARNINGS
#define N 10
#include <stdio.h>
#include <stdlib.h> ///////?

// structures
typedef struct kNode
{
    int k;
    struct kNode* prev,* next;
} *kNode;

typedef struct nodeList
{
    kNode* head;
    kNode* tail;
    int num_of_step;
} *pNodeList;


// functions prototype
/* adding node as first of doubly linked list */
void add_as_first(kNode* node, pNodeList* node_list);

/**/

/**/


#endif