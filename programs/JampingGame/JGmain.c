#include "JGheader.h"

int main()
{
    pNodeList pNodes_list; // pointer for k list nodes
    kNode k_node; // pointer for k node
    int i = 0;

    // define for START
    pNodes_list->num_of_step = 0;
    pNodes_list->head = NULL;
    pNodes_list->tail = NULL;


    printf("Welcome To The Jumping Game!\n");
    printf("Please enter %d integers to define the steps.\n", N);

    while (pNodes_list->num_of_step < N)
    {
        if ((k_node = (kNode*)malloc(sizeof(kNode))) == NULL)
        {
            free_list(pNodes_list);
            error_message("Error allocating new k.\n");
        }
        k_node->next = NULL;
        k_node->prev = NULL;

        printf("step number %d: ", i);
        if ((scanf("%d", &k_node->k)) < 1)
        {
            free_list(pNodes_list);
            error_message("Error reading k number.\n");
        }

        add_as_first(k_node, pNodes_list);

        i++;
    }
}