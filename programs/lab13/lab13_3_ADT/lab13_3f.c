# include "lab13_3.h"


void GetValue(PQue queue, void* element, int(ScanItem)(void*))
{
    while (queue->size < NUM)
    {
        printf("Number %d: ", queue->size + 1);
        if (ScanItem(element)) Enqueue(queue, element);
    }
}

int PrintInt(void* element)
{
    if ((scanf("%d", (int*)element)) < 1)
    {
        printf("Error reading number to entry.\n");
        return 0;
    }
    return 1;
}

void Enqueue(PQue Q, void* new_elem)
{
}
