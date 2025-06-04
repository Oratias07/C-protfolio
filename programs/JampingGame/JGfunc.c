#include "JGheader.h"

// adds an node to the head of the node_list
void add_as_first(kNode* node, pNodeList* node_list)
{
    if ((*node_list) == NULL || (*node) == NULL)
    {
        printf("The node list or node is not defined.\n");
        return;
    }

    if ((*node_list)->head == NULL)
    {
    //     (*(*node_list)->head)->next = NULL;
    //     (*(*node_list)->head)->prev = NULL;
    //     (*(*node_list)->tail)->next = NULL;
    //     (*(*node_list)->tail)->prev = NULL;

        (*node_list)->head = node;
        (*node_list)->tail = node;

    }
    else
    {
        (*node)->next = (*node_list)->head;
        (*(*node_list)->head)->prev = (*node);
        (*(*node_list)->head) = (*node);
    }

    (*node_list)->num_of_step++;
}
