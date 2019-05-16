/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Insert a node at the list beginning.
*/

#include <stdlib.h>

#include "list.h"

int list_unshift(list_t *list, void *data)
{
    node_t *node = NULL;

    if ((node = list_node(data)) == NULL)
        return -1;

    node->next = list->first;
    list->first = node;
    list->length++;

    if (list->length == 1)
        list->last = list->first;
    else if (list->length > 1)
        node->next->previous = node;

    return list->length;
}
