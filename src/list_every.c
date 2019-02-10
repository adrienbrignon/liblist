/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Test whether all nodes in the list pass a given test.
*/

#include <stddef.h>

#include "list.h"

int list_every(list_t *list, list_test_function_t *test)
{
    node_t *node = list->first;

    while (node != NULL) {
        if (!test(node))
            return 0;

        node = node->next;
    }

    return 1;
}
