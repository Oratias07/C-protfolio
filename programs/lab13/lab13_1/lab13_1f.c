# include <lab13_1.h>

void Push(PStack s, int element)
{
    Item* temp;

    if (s->size >= NUM - 1 || s == NULL || element == NULL)
    {
        printf("Push operation failed.\n");
        return;
    }

    else
    {
        temp = (Item*)malloc(sizeof(Item));
        if (temp == NULL)
        {
            printf("Error allocated.\n");
            exit(1);
        }

        // adding to the head and update s
        temp->num = element;
        temp->next = s->head;
        s->head = temp;
        s->size++;
    }
    // successful pushing
}

int Pop(PStack s, int* del_value)
{
    Item* temp = s->head;

    if (s->size < 1 || s->head == NULL) return 0;

    *del_value = s->head->num;
    s->head = s->head->next;
    free(temp);
    s->size--;

    return 1; // successful popping

}

void PrintStack(Stack s)
{
    int i = 0;
    printf("The members in the stack (first out- LIFO)");

    printf("{ ");
    while (i <= s.size)
    {
        printf("%d", s.head->num);
        if (s.size > 1) printf(", ");
        s.head = s.head->next;
    }
    printf(" }\n\n");
}
