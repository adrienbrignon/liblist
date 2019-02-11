/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Check if all nodes on the list pass the given test.
*/

#include <stddef.h>

#include "list.h"

int list_every(list_t *list, list_every_callback_t *callback)
{
    node_t *node = list->first;

    while (node != NULL) {
        if (!callback(node))
            return 0;

        node = node->next;
    }

    return 1;
}
