# define _CRT_SECURE_NO_WARNINGS
# define N 5
# include <stdio.h>
# include <stdlib.h>

// struct
typedef struct Item
{
	int num;
	struct Item* next;
} *PItem;

// functions prototype
void Error_Msg(char*);
void CreateListFromArray(PItem*, PItem*, int*);
void DeleteList(PItem*);
void ListDisplay(PItem);
int ListLength(PItem);

int main()
{
	int Arr[N] = { 3, 4, 1, 0, 8 };

	PItem list = NULL, tail = NULL;

	CreateListFromArray(&list, &tail, Arr);
	printf("\nThe length of the list is %d members\n", ListLength(list));
	printf("\nThe list is:\n");
	ListDisplay(list);
		
	DeleteList(&list);
    tail = NULL;
	return 0;
}

/// @brief counts, recursive, the nodes in the linked list
/// @param item origin linked list
/// @return return 0 when item is empty (NULL)
int ListLength(PItem item)
{
	PItem temp = item;
	int count = 0;

	if (temp != NULL)
	{
		return 1 + ListLength(temp->next); // adds 1 to the counter and moves on
	}
	return 0;
}

/// @brief print, recursive, the values in the linked list
/// @param item origin linked list
void ListDisplay(PItem item)
{
	PItem temp = item;

	if (temp != NULL)
	{
		printf("%d", temp->num);
		if (temp->next != NULL) printf(" --> ");
		
		return ListDisplay(temp->next);
	}
	printf("\n\n");

	return;
}

void Error_Msg(char* msg)
{
	printf("\n%s\n", msg);
	exit(1);
}

/// @brief create a list in a loop, unfortunately it received
/// @param head pointer for the first node
/// @param tail pointer for the last node
/// @param Arr that is taken to create a linked list
void CreateListFromArray(PItem* head, PItem* tail, int* Arr)
{
	int i;
	PItem temp;
	for (i = 0; i < N; i++)
	{
		temp = (PItem)malloc(sizeof(struct Item));
		if (temp == NULL)
        {
			DeleteList(head);
            Error_Msg("Memory allocating failed!\n");
		}
		temp->num = Arr[i];
		temp->next = NULL;
		if (*head == NULL)
		{
			*head = temp;
		}

		else
		{
			(*tail)->next = temp;
		}

		*tail = temp;
	}
}

void DeleteList(PItem* head)
{
	PItem tmp = *head;
	while (*head)
    {
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}
