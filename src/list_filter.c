/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Create a new list with all elements that pass the given test.
*/

#include <stddef.h>

#include "list.h"

list_t *list_filter(list_t *list, list_filter_callback_t *callback)
{
    list_t *new = list_new();
    node_t *node = list->first;

    if (new == NULL)
        return new;
    while (node != NULL) {
        if (callback(node))
            list_push(new, node->data);

        node = node->next;
    }

    return new;
}
