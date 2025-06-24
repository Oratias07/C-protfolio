# ifndef _stack_and_queue
# define _stack_and_queue

# define NUM 7
# include <stdlib.h>
# include <stdio.h>

// structures
typedef struct Item
{
    int num;
    struct Item* next;
} Item;

typedef struct Stack
{
    Item* head;
    int size;
} Stack, *PStack;

// functions declaration
void Push(PStack s, int new_elem); // add a new number to list of the stack
int Pop(PStack s, int* del_value); // delete member from the stack and "return" the deleted value using int* del_value

# endif