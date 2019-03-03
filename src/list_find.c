/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Return the first node that passes the given test.
*/

#include <stddef.h>

#include "list.h"

node_t *list_find(list_t *list, list_find_callback_t *callback)
{
    node_t *node = list->first;

    while (node != NULL) {
        if (callback(node))
            return node;

        node = node->next;
    }

    return 0;
}
