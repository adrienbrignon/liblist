/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Test whether at least one node in the list passes the given test.
*/

#include <stddef.h>

#include "list.h"

int list_some(list_t *list, list_test_function_t *fn)
{
    node_t *node = list->first;

    while (node != NULL) {
        if (fn(node))
            return 1;

        node = node->next;
    }

    return 0;
}
