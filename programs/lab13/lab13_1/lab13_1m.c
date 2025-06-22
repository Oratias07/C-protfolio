# include <lab13_1.h>

int main()
{
    PStack stack;
    int element;
    
    // initialized stack
    stack->head = NULL;
    stack->size = 0;

    printf("Please enter %d integer number to entry a stack: ", NUM);
    while (stack->size < NUM)
    {
        printf("Number %d: ", stack->size + 1);
        if ((scanf("%d", element)) < 1)
        {
            printf("Error reading number to entry.\n");
            return 1;
        }

        Push(stack, element);
    }
}