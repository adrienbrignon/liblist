/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Check if at least one node in the list passes the given test.
*/

#include <stddef.h>

#include "list.h"

int list_some(list_t *list, list_some_callback_t *callback)
{
    node_t *node = list->first;

    while (node != NULL) {
        if (callback(node))
            return 1;

        node = node->next;
    }

    return 0;
}
