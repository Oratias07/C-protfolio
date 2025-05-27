# define _CRT_SECURE_NO_WARNINGS
# define CODE 11 // max length of code
# define DEPARTMENTS 4 // department mount
# define MARKS 3 // marks mount
# define MAX_NAME 256 // max length of name
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// struct
typedef struct node
{
	char code[CODE];
	char* name;
	char Dep[DEPARTMENTS];
	int marks[MARKS];
	float avg;
	struct node* next;
} std;

// functions prototype
void Error_Msg(char* str);
std* FromFileToList(FILE *in);
std* Delete_Stud(std* toDel, std* head);
std* DeleteList(std* head);
void PrintList(std* head);
std* FindMax(std* head);

int main()
{
	int i;
	FILE* f;
	std* Head = NULL,* temp;

	if ((f = fopen("List.txt", "rt")) == NULL)
    {
        Error_Msg("input error");
    }

    Head = FromFileToList(f);
    if (Head == NULL)
    {
        Error_Msg("The input file is empty");
    }

    fclose(f);

	printf("\nThe list is:\n");
	PrintList(Head);
	
	temp = FindMax(Head);
    
    printf("The student with max average:\n");
	printf("%s %s %s ", temp->code, temp->name, temp->Dep);

    for(i = 0; i < MARKS; i++)
    {
        printf("%d ", temp->marks[i]);
    }
    printf("\n");

    Head = Delete_Stud(temp, Head);

	printf("\nThe list after change:\n");
	PrintList(Head);

	Head = DeleteList(Head); // Head = NULL
    
    return 0;
}

// creates nodes, receives input for each, builds a linked list
std* FromFileToList(FILE *in)
{
    std* temp,* head = NULL;
    char buffer[MAX_NAME];

    while (1)
    {
        // allocate for new student
        if ((temp = (std*)malloc(sizeof(std))) == NULL)
        {
            DeleteList(head);
            Error_Msg("Error allocating new std.\n");
        }

        // pulling data from the file
        if ((fscanf(in, "%s %s %s %d %d %d", temp->code, buffer, temp->Dep, 
            &temp->marks[MARKS - 3], &temp->marks[MARKS - 2], &temp->marks[MARKS - 1])) != 6) 
        {
            free(temp);
            break; // exit on EOF or bad format
        }

        // allocate for name
        if ((temp->name = (char*)malloc(strlen(buffer) + 1)) == NULL) 
        {            
            DeleteList(head);
            Error_Msg("Error allocating name.\n");
        }
        strcpy(temp->name, buffer);
        
        // calculate average
        temp->avg = (float)(temp->marks[MARKS - 3] + temp->marks[MARKS - 2] + temp->marks[MARKS - 1]) / MARKS;
       
        // update the head of the list
        temp->next = head;
        head = temp;
    }

    return head;
}

void Error_Msg(char* str)
{
	printf("\n%s",str);
        exit(1);
}

// frees the names and the entire linked list
std* DeleteList(std* head)
{
    std* temp = head;

    while (head != NULL)
    {
        head = head->next;

        free(temp->name); // free name 
        free(temp); // free node

        temp = head;
    }

    return head;
}

// print all fields of the list
void PrintList(std* head)
{
    std* temp = head;

	while (temp != NULL)
    {
		printf("%s %s %s %d %d %d\n", temp->code, temp->name, temp->Dep, 
            temp->marks[MARKS - 3], temp->marks[MARKS - 2], temp->marks[MARKS - 1]);

        temp = temp->next;
	}
    printf("\n");
}

// return the address of the maximum average in linked list
std* FindMax(std* head)
{
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;

    std* max = FindMax(head->next);

    if (head->avg > max->avg)
    {
        return head;
    }
    else
    {
        return max;
    }
}

// remove student with max average
std* Delete_Stud(std* toDel, std* head)
{
  if (head == NULL) return NULL;

  if (toDel == head)
  {
    head = head->next;
    free(toDel->name);
    free(toDel);
  }

  else
  {
    std* temp = head;

    while (temp->next != toDel)
    {
        temp = temp->next;
    }

    temp->next = toDel->next;
    free(toDel->name);
    free(toDel);
  }

  return head;
}
