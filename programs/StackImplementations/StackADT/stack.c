# include "lab13_3.h"


// structures
typedef struct Item
{
    void* num;
    struct Item* next;
} *PItem, Item;

typedef struct Queue
{
    Item* head, * tail;
    int size; // a current number of items
} Queue;

Queue* QueueCreate()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue)
    {
        printf("Error allocating Queue.\n");
        exit(1);
    }

    // initialized Queue
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

// specific functions
int QueueSize(Queue* queue) { return queue->size; }

boolean PlacementInt(Item* q, type elem)
{
    q->num = malloc(sizeof(int));
    if (!q->num)
    {
        printf("Error num allocated.\n");
        return FALSE;
    }
    *(int*)(q->num) = *(int*)elem;
    return TRUE;
}

void PrintInt(type elem) { printf("%d", *(int*)elem); }

void PlacementIntOut(type elem, Queue* Q) { *(int*)elem = *(int*)Q->head->num; }

boolean ScanInt(type element)
{
    if ((scanf("%d", (int*)element)) < 1)
    {
        printf("Error reading number to entry.\n");
        return FALSE;
    }
    return TRUE;
}

// general functions (ADT)
void GetValue(Queue* queue, type element, boolean(ScanItem)(type), boolean(PlacementItem)(Item*, type))
{
    while (QueueSize(queue) < NUM)
    {
        printf("Number %d: ", QueueSize(queue) + 1);
        if (ScanItem(element)) Enqueue(queue, element, PlacementItem);
    }
}

void Enqueue(Queue* Q, type new_elem, boolean(PlacementItem)(PItem, type))
{
    PItem temp = (Item*)malloc(sizeof(Item));

    if (temp == NULL)
    {
        printf("Error allocating new Item.\n");
        FreeQueue(Q, QueueSize(Q));
        exit(1);
    }

    if (!PlacementItem(temp, new_elem))
    {
        FreeQueue(Q, QueueSize(Q));
        exit(1);
    }

    temp->next = NULL;

    if (Q->head == NULL) // adding the first member
    {
        Q->head = temp;
        Q->tail = temp;
    }
    else // there is a member in the haed of queue
    {
        Q->tail->next = temp;
        Q->tail = temp;
    }
    Q->size++;
}

void PrintQueue(Queue* Q, void(PrintItem)(type))
{
    PItem temp = Q->head;

    printf("The current Queue is: { ");
    while (temp)
    {
        PrintItem(temp->num);
        if (temp->next != NULL) printf(", ");
        temp = temp->next;
    }
    printf(" }\n");
}

boolean Dequeue(Queue* Q, type del_elem, void(PlacementItemOut)(type, Queue*))
{
    if (Q->head == NULL) return FALSE;

    PlacementItemOut(del_elem, Q);
    FreeQueue(Q, 1);
    return TRUE;
}

void FreeQueue(Queue* Q, int size)
{
    Item* temp;

    while (size > 0)
    {
        temp = Q->head;
        Q->head = Q->head->next;
        free(temp->num);
        free(temp);

        size--;
        Q->size--;
    }
    if (Q->size == 0)
    {
        free(Q);
        Q->head = NULL;
    }
}
