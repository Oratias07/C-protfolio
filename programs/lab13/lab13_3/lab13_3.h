# ifndef _queue_ex
# define _queue_ex

// structures
typedef struct Item
{
    int num;
    struct Item* next;
} Item;

typedef struct Que
{
    Item *head, *tail;
    int size; // a current number of items
} Queue, *PQue;

// functions declaration
void Enqueue(PQue Q, int new_elem); // add a new member to list of the queue
int Dequeue(PQue Q, int* del_value); // delete member from the queue and "return" the deleted value using int *del_value

# endif