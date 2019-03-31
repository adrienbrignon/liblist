/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Destroy a list and it's node.
*/

#include <stdlib.h>

#include "list.h"

void list_destroy(list_t *list)
{
    node_t *node = list->first;

    while (node != NULL) {
        node_t *next = node->next;

        free(node);

        node = next;
    }

    free(list);
}
