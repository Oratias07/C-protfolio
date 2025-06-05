#include "JGheader.h"

// adds a node to the head of the node list
void add_as_first(kNode node, pNodeList node_list)
{
    if (node_list == NULL || node == NULL)
    {
        printf("The node list or node is not defined.\n");
        // free_all(node_list);
        // error_message("The node list or node is not defined.\n");
    }

    if (node_list->head == NULL)
    {
        node_list->head = node;
        node_list->tail = node;
    }
    else
    {
        node->next = node_list->head;
        node_list->head->prev = node;
        node_list->head = node;
    }

    node_list->num_of_step++;
}

/* the game runs in a loop until a stopping condition is met */
int game_on(pNodeList pNodes_list, int max_steps)
{
    int steps = 0, k_current, i;
    kNode current = pNodes_list->head; // the current k for comparing

    while (1)
    {
        steps++;

        if (current == NULL) // beyond the boundaries
        {
            printf("Going beyond the boundaries of the game!\n");
            break;
        }

        k_current = current->k;
        if (k_current == 0) // reached a dead end
        {
            printf("You reached a dead end!\n");
            break;
        }

        else if (steps > max_steps) // reached the maximum number of steps
        {
            printf("You have reached the maximum number of steps in the game!\n");
            break;
        }
        
        else if (k_current == 1 || k_current == -1) // removing the node
        {
            delete_current(pNodes_list, current);
        }

        else
        {
            for (i = 0; i < k_current; i++)
            {
                if (k_current > 0) current = current->next;
                else if (k_current < 0) current = current->prev;

                if (current == NULL) break; // beyond the boundaries (ends the loop in the next iteration)
            }
        }
    }

    return steps; // total number of rounds
}

/* printing the doubly linked list */
void print_list(kNode node)
{
    if (node == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("%d", node->k);
    if (node->next != NULL) 
    {
        printf(" --> ");
        print_list(node->next);
    } 
    
    else printf("\n");
}

/* delete the current node */
void delete_current(pNodeList pNodes_list, kNode current)
{
    if (current->next == NULL) // current is the last element at doubly linked list
    {
        pNodes_list->tail = current->prev;
        current->prev->next = NULL;
   }

    else if (current->prev == NULL) // current is the first element at doubly linked list
    {
        pNodes_list->head = current->next;
        current->next->prev = NULL;
    }

    else // current is in the middle of a doubly linked list
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    free(current);
}

/* frees the list */
void free_all(pNodeList list)
{
    kNode temp;

    while (list->head)
    {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    free(list);
}

/* print error message and exit program */
void error_message(char* str)
{
    printf("%s", str);
    exit(1);
}
