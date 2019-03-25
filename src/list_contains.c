/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Check if a list contains the given data.
*/

#include <stddef.h>

#include "list.h"

int list_contains(list_t *list, void *data)
{
    node_t *node = list->first;

    while (node != NULL) {
        if (node->data == data)
            return 1;

        node = node->next;
    }

    return 0;
}
