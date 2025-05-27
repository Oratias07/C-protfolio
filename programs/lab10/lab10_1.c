# define _CRT_SECURE_NO_WARNINGS
# define N 5
# define MAX_NAME 10
# include <stdio.h>
# include <stdlib.h>

// struct
typedef struct node
{
    int code;
    char name[MAX_NAME];
    struct node* next;
} Item;

/* 
   The program creates N nodes, receives input for each,
   builds a linked list, prints it, and then frees the memory.
*/
int main()
{
	int i;
	Item* head = NULL,* temp;

    // create N nodes
	for (i = 1; i <= N; i++)
    {
        temp = (Item*)malloc(sizeof(Item));
        if (temp == NULL)
        {
            printf("Error allocating new item.\n");
            return 1;
        }

        printf("Enter a new code and name: ");
        if (scanf("%d %s", &temp->code, temp->name) < 2)
        {
            printf("Error reading new code or name.\n");
            return 1;
        }
        printf("\n");

        temp->next = head;
        head = temp;
    }

    // print all fields of the list
    temp = head;
	printf("The List is:  ");
	while (temp != NULL)
    {
		printf("(%d, %s)", temp->code, temp->name);
        if (temp->next != NULL) printf(" --> ");

        temp = temp->next;
	}
    printf("\n\n");

    // free the list
    temp = head;
	while(temp != NULL)
    {
        head = head->next;
        free(temp);
        temp = head;
    }
    
    return 0;
}
