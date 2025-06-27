#include "Stack_Header_Array.h"

// initialization of a new stack with capacity of size elements
void InitStack(PStack s, int size)
{
    s->Array = (int*)malloc(size * sizeof(int));
    if (s->Array == NULL)
    {
        printf("Initialte allocating faild.\n");
        exit(1);
    }
    s->count = 0;
    s->top = -1;
    s->size = size;
}

// add a new member to array of the stack
void Push(PStack s, int new_elem)
{
    if (s->count >= s->size)
    {
        printf("\n\nThe Stack is full\n");
        return;
    }

    s->top++;
    s->Array[s->top] = new_elem;
    s->count++;
}

// delete member from the array of the stack and return the deleted value using int* del_value
int Pop(PStack s, int* del_value)
{
    if (s->count < 1)
    {
        printf("\nThe Stack is empty\n");
        return 0;
    }

    // the array is not empty, delete the last member
    *del_value = s->Array[s->top];
    s->top--;
    s->count--;
    return 1;
}

// free the array is created an allocating
void FreeStack(PStack st)
{
    free(st->Array);
    st->count = 0;
    st->size = 0;
    st->top = -1;
    st->Array = NULL;
}
