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