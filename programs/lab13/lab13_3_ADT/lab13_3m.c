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
    GetValue(queue, &element, PrintInt);

    // while (queue->size < NUM)
    // {
    //     printf("Number %d: ", queue->size + 1);
    //     if ((scanf("%d", &element)) < 1)
    //     {
    //         printf("Error reading number to entry.\n");
    //         return 1;
    //     }

    //     Enqueue(queue, element);
    // }
    PrintQueue(*queue); // printing the Queue at LIFO way

    while (queue->size > 0)
    {
        if (dequeue(queue, &del_elem))
        {
            printf("The value taken out is: %d.\n", del_elem);
            PrintQueue(*queue);
        }
    }
    printf("The Queue is empty.\n");

    free(queue);
    return 0;
}