# include "lab13_3.h"


void GetValue(PQue queue, void* element, int(ScanItem)(void*))
{
    while (queue->size < NUM)
    {
        printf("Number %d: ", queue->size + 1);
        if (ScanItem(element)) Enqueue(queue, *(int*)element);
    }

}

int ScanInt(void* element)
{
    if ((scanf("%d", (int*)element)) < 1)
    {
        printf("Error reading number to entry.\n");
        return 0;
    }
    return 1;
}

void Enqueue(PQue Q, int new_elem)
{
    Item* temp = (Item*)malloc(sizeof(Item));

    if (temp == NULL)
    {
        printf("Error allocating new Item.\n");
        FreeQueue(Q, Q->size);
        free(Q);
        exit(1);
    }

    temp->num = new_elem;
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

int Dequeue(PQue Q, int* del_value)
{
    if (Q->head == NULL) return 0;

    *del_value = Q->head->num;
    FreeQueue(Q, 1);
    return 1;
}

void PrintQueue(PQue Q)
{
    Item* temp = Q->head;

    printf("The current Queue is: { ");
    while (temp != NULL)
    {
        printf("%d", temp->num);
        if (temp->next != NULL) printf(", ");
        temp = temp->next;
    }
    printf(" }\n");
}

void FreeQueue(PQue Q, int size)
{
    PQue temp;

    while (size > 0)
    {
        temp = Q->head;
        Q->head = Q->head->next;
        free(temp);

        size--;
        Q->size--;
    }
}
