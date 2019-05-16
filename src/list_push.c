/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Insert a node at the list end.
*/

#include <stdlib.h>

#include "list.h"

int list_push(list_t *list, void *data)
{
    node_t *node = NULL;

    if ((node = list_node(data)) == NULL)
        return -1;

    node->previous = list->last;
    list->last = node;
    list->length++;

    if (list->length == 1)
        list->first = node;
    else if (list->length > 1)
        node->previous->next = node;

    return list->length;
}
