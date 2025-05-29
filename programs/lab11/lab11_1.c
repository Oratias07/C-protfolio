# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <stdlib.h>

// structures
typedef struct Item
{
	int num;
	struct Item* next;
} Item;

typedef struct List
{
    Item* head;
    Item* tail;
    int count;
} List;

// functions prototype
void Error_Msg(char*);
void AddAsFirst(Item* ,List* );
void AddAsLast(Item* ,List* );
void MoveToAnotherList(List* ,List* ,List* );
void CreateList(List* ,FILE *);
void PrintItem(Item* );
void PrintList(List* ,char*);
void DeleteList(List* list);

/// @brief 
/// Initializes a list of integers from a file and separates them into two lists
/// one containing positive numbers and one containing negative numbers
/// Displays all three lists and releases all allocated memory
/// @return '0' when the program is work done successfully
int main()
{
    List L, Posit, Negat;
    FILE* in = fopen("ThreeLists.txt", "rt");

    if (in == NULL)
    {
        Error_Msg("Input file is wrong.\n");
    }

    L.head = NULL;
    L.tail = NULL;
    L.count = 0;
	
    Posit.head = NULL;
    Posit.tail = NULL;
    Posit.count = 0;

    Negat.head = NULL;
    Negat.tail = NULL;
    Negat.count = 0;

    CreateList(&L, in);
    PrintList(&L, "\nMy List:\n");
    MoveToAnotherList(&L, &Posit, &Negat);
    PrintList(&Posit, "\nThe Positive List:\n");
    PrintList(&Negat, "\nThe Negative List:\n");
    printf("\n");

    fclose(in);
    DeleteList(&Posit);
    DeleteList(&Negat);
    return 0;
}

// adds an item to the head of the list
void AddAsFirst(Item* item,List* list)
{
    if (list == NULL || item == NULL)
    {
        printf("The list or item is not defined. (AAF)\n");
        return;
    }

    if (list->head == NULL)
    {
        list->head = item;
        list->head->next = NULL;
        list->tail = item;
    }
    else
    {
        item->next = list->head;
        list->head = item;
    }
    list->count++;
}

// adds an item to the tail of the list
void AddAsLast(Item* item,List* list)
{
    if (list == NULL || item == NULL)
    {
        printf("The list or item is not defined. (AAL)\n");
        return;
    }

    item->next = NULL;

    if (list->head == NULL)
    {
        list->head = item;
        list->tail = item;
    }
    else
    {
        list->tail->next = item;
        list->tail = item;
    }
    list->count++;
}
/// @brief Sorts the numbers in a main list into two lists (positive and negative)
/// @param list Pointer to the list to scan.
/// @param posit Pointer to store the count of positive numbers
/// @param negat Pointer to store the count of negative numbers
void MoveToAnotherList(List* list, List* posit, List* negat)
{
    Item* temp = list->head,* next; // save next node before moving the current one

    while (temp != NULL) // at the end of sorted, list is going to be empty (NULL)
    {
        next = temp->next;

        if (temp->num >= 0) // the value is positive
        {
            AddAsLast(temp, posit);
        }

        if (temp->num < 0) // the value is negative
        {
            AddAsFirst(temp, negat);
        }
        
        temp = next;
        list->count--;
    }

    list->head = NULL;
    list->tail = NULL;
    // list->count is will be 0 (line 138)
}

// reads integers from a file and creates a linked list

void CreateList(List* L, FILE* f)
{
	int value;
	Item* temp;
	while (fscanf(f, "%d", &value) == 1)
    {
		temp = (Item*)malloc(sizeof(struct Item));
		if (temp == NULL)
        {
            DeleteList(L);
            Error_Msg("Memory allocation failed!\n");
		}

		temp->num = value;
		temp->next = NULL;
		if (L->head == NULL)
        {
            L->head=temp;
        }
		else
        {
            L->tail->next=temp;
        }

		L->tail = temp;
		L->count++;
	}
}

void PrintItem(Item* node)
{
	printf("%d", node->num);
    if (node->next != NULL) printf(" --> "); // if node is not the last in linked list
}

void PrintList(List* L ,char* title)
{
	Item* temp = L->head;
	printf("%s", title);
	while (temp)
    {
		PrintItem(temp); // print item
		temp = temp->next;
	}
	printf("\nThere are %d items in the list.\n", L->count);
}

// frees the entire linked list
void DeleteList(List* list)
{
    Item* temp = list->head;

    while (temp != NULL)
    {
        list->head = list->head->next;
        free(temp); // free node
        temp = list->head;
    }

    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
}

void Error_Msg(char* msg)
{
	printf("\n%s", msg);
	exit(1);
}