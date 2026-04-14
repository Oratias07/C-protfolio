# include "lab13_3.h"

int main()
{
    PQue queue = (PQue)malloc(sizeof(Queue));
    int element, del_elem;

    if (queue == NULL)
    {
        printf("Error allocating Queue.\n");
        return 1;
    }
    // initialized Queue
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    printf("Please enter %d integer number to entry a Queue:\n", NUM);
    GetValue(queue, &element, ScanInt);
    PrintQueue(queue); // printing the Queue

    while (queue->size > 0)
    {
        if (Dequeue(queue, &del_elem))
        {
            printf("The value taken out is: %d.\n", del_elem);
            PrintQueue(queue);
        }
    }
    printf("The Queue is empty.\n");

    FreeQueue(queue, queue->size);
    free(queue);
    return 0;
}