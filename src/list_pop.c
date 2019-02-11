/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Remove a node from the list end.
*/

#include <stdlib.h>

#include "list.h"

void *list_pop(list_t *list)
{
    void *data = NULL;
    node_t *node = list->last;

    if (list->length == 0)
        return data;

    data = node->data;
    list->last = node->previous;
    list->length--;

    free(node);

    if (list->length > 0) {
        list->last->next = NULL;
    } else {
        list->first = NULL;
        list->last = NULL;
    }

    return data;
}
