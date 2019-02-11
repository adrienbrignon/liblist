/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Remove a node from the list beginning.
*/

#include <stdlib.h>

#include "list.h"

void *list_shift(list_t *list)
{
    void *data = NULL;
    node_t *node = list->first;

    if (list->length == 0)
        return data;

    data = node->data;
    list->first = node->next;
    list->length--;

    free(node);

    if (list->length > 0) {
        list->first->previous = NULL;
    } else {
        list->first = NULL;
        list->last = NULL;
    }

    return data;
}
