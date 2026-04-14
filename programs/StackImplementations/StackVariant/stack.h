# ifndef _queue_ex
# define _queue_ex

# define _CRT_SECURE_NO_WARNINGS
# define NUM 7
# include <stdio.h>
# include <stdlib.h>

// structures
typedef struct Item
{
    int num;
    struct Item* next;
} Item;

typedef struct Que
{
    Item* head, * tail;
    int size; // a current number of items
} Queue, * PQue;

// functions declaration
void Enqueue(PQue Q, int new_elem); // add a new member to list of the queue (to the tail)
int Dequeue(PQue Q, int* del_value); // delete member from the queue and "return" the deleted value using int *del_value
int ScanInt(void* elem); // scaning from user values for the queue
void GetValue(PQue queue, void* element, int(ScanItem)(void*)); // get value for adding to the queue
void FreeQueue(PQue Q, int); // free all the Item in queue and freeing the queue
void PrintQueue(PQue Q); // printing the Queue



# endif