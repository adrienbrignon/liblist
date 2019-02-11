/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Reduce the list to a single value.
*/

#include <stddef.h>

#include "list.h"

int list_reduce(list_t *list, list_reduce_callback_t *callback)
{
    int accumulator = 0;
    node_t *node = list->first;

    while (node != NULL) {
        if (node->data != NULL)
            callback(&accumulator, node);

        node = node->next;
    }

    return accumulator;
}
