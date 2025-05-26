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
std* Delete_Stud(std* toDel,std* head);
std* DeleteList(std* head);
void PrintList(std* head);
std* FindMax(std* head);
void freeAll(std**);

int main()
{
	int i;
	FILE *f;
	std *Head=NULL, *temp;

	if((f=fopen("List.txt","rt")) == NULL)
           Error_Msg("input error");
	Head=FromFileToList(f);
        if(Head == NULL)
          Error_Msg("The input file is empty");

        fclose(f);
	printf("\nThe list is:");
	PrintList(Head);
	
	temp = FindMax(Head);
        printf("\n\nthe student with max average:\n");
	printf("%s %s %s ",temp->code,temp->name,temp->Dep);
        for(i=0;i<3;i++)
          printf(" %d ",temp->marks[i]);

	printf("\n\nThe list after change:");
	Head=Delete_Stud(FindMax(Head),Head);
	PrintList(Head);
	Head = DeleteList(Head);        /*Head = NULL */
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
            freeAll(&head);
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
            freeAll(&head);
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

void freeAll(std** head)
{
    std* temp = *head;

    while (*head != NULL)
    {
        (*head) = (*head)->next;

        free(temp->name); // free name 
        free(temp); // free node

        temp = *head;
    }
}



std* Delete_Stud(std* toDel,std* head)
{
  if(head == NULL)
    return NULL;

  if(toDel==head)
  {

  }
  else
  {

  }
  return head;
}
