/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Create a new node instance.
*/

#include <stdlib.h>

#include "list.h"

node_t *list_node(void *data)
{
    node_t *node = NULL;

    if ((node = malloc(sizeof *node)) == NULL)
        return NULL;

    node->data = data;
    node->next = NULL;
    node->previous = NULL;

    return node;
}
