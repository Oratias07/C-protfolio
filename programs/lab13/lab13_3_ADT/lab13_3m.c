# include "lab13_3.h"

int main()
{
    int element, del_elem;
    Queue* queue = QueueCreate();


    printf("Please enter %d integer number to entry a Queue:\n", NUM);
    GetValue(queue, &element, ScanInt, PlacementInt);
    PrintQueue(queue, PrintInt); // printing the Queue

    while (QueueSize(queue) > 0)
    {
        if (Dequeue(queue, &del_elem, PlacementIntOut))
        {
            printf("The value taken out is: %d.\n", del_elem);
            PrintQueue(queue, PrintInt);
        }
    }
    printf("The Queue is empty.\n");

    FreeQueue(queue, QueueSize(queue));
    return 0;
}