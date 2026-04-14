# ifndef _queue_ex
# define _queue_ex

# define _CRT_SECURE_NO_WARNINGS
# define NUM 7
# include <stdio.h>
# include <stdlib.h>

typedef enum { FALSE, TRUE } boolean;
typedef struct Queue Queue;
typedef struct Item Item;
typedef void* type;

// general ADT functions declaration
Queue* QueueCreate(); // initialized an queue
int QueueSize(Queue*); // returning the size of the queue
void Enqueue(Queue*, type, boolean(PlacementItem)(Item*, type)); // add a new member to list of the queue (to the tail)
boolean Dequeue(Queue*, type, void(PlacementItemOut)(type, Queue*)); // delete member from the queue and "return" the deleted value using int *del_elem
void GetValue(Queue*, type, boolean(ScanItem)(type), boolean(PlacementItem)(Item*, type)); // get value for adding to the queue
void FreeQueue(Queue*, int); // free all the Item in queue and freeing the queue
void PrintQueue(Queue*, void(PrintItem)(type)); // printing the Queue

// specific int functions
boolean PlacementInt(Item*, type); // placment at the new element at the item
void PrintInt(type); // printing the item
boolean ScanInt(type); // scaning from user values for the queue
void PlacementIntOut(type, Queue*); // placement at elem the current removing

# endif