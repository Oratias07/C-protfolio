#include "JGheader.h"

int main()
{
    pNodeList pNodes_list = malloc(sizeof(*pNodes_list)); // pointer for k list nodes
    kNode k_node; // pointer for k node
    int max_steps; // maximum number of steps
    int steps; // number of rounds in the game

    // define for START
    if (pNodes_list == NULL) error_message("Error allocatinf failed.\n");
    pNodes_list->num_of_step = 0;
    pNodes_list->head = NULL;
    pNodes_list->tail = NULL;


    printf("Welcome To The Jumping Game!\n");
    printf("Please enter %d integers to define the steps.\n", N);

    /* receives N integers from user and build doubly linked list (add to head) */
    while (pNodes_list->num_of_step < N)
    {
        if ((k_node = (kNode)malloc(sizeof(*k_node))) == NULL)
        {
            free_all(pNodes_list);
            error_message("Error allocating new k.\n");
        }

        k_node->next = NULL;
        k_node->prev = NULL;

        printf("step number %d: ", pNodes_list->num_of_step + 1);
        if ((scanf("%d", &k_node->k)) < 1)
        {
            free_all(pNodes_list);
            error_message("Error reading k number.\n");
        }

        add_as_first(k_node, pNodes_list);
    }

    /* receives maximum number of steps */
    printf("Enter the maximum number of steps for the game: ");
    if ((scanf("%d", &max_steps)) < 1)
    {
        free_all(pNodes_list);
        error_message("Error reading maximum number of steps.\n");
    }

    /* START GAME */
    steps = game_on(pNodes_list, max_steps);
    printf("The game is over with %d steps.\n", steps);

    print_list(pNodes_list->head);

    free_all(pNodes_list);
    return 0; // end of the game
}