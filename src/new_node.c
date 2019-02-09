/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Create a new node instance.
*/

#include <stdlib.h>

#include "list.h"

node_t *new_node(void *data)
{
    node_t *node = malloc(sizeof *node);

    if (node == NULL)
        return NULL;

    node->data = data;
    node->next = NULL;
    node->previous = NULL;

    return node;
}
