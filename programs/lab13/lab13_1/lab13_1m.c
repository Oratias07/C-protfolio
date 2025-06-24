#include "lab13_1.h"

int main()
{
    PStack stack = (Stack*)malloc(sizeof(Stack));
    int element, del_elem;

    if (stack == NULL)
    {
        printf("Error allocating stack.\n");
        return 1;
    }
    // initialized stack
    stack->head = NULL;
    stack->size = 0;

    printf("Please enter %d integer number to entry a stack: ", NUM);
    while (stack->size < NUM)
    {
        printf("Number %d: ", stack->size + 1);
        if ((scanf("%d", &element)) < 1)
        {
            printf("Error reading number to entry.\n");
            return 1;
        }

        Push(stack, element);
    }
    PrintStack(*stack); // printing the stack at LIFO way

    while (stack->size > 0)
    {
        if (Pop(stack, &del_elem))
        {
            printf("The value taken out is: %d.\n", del_elem);
            PrintStack(*stack);
        }
    }
    printf("The stack is empty.\n");

    free(stack);
    return 0;
}