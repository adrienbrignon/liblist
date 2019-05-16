/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Create a new list with the given callback on old list values.
*/

#include <stddef.h>

#include "list.h"

list_t *list_map(list_t *list, list_map_callback_t *callback)
{
    list_t *new = list_new();
    node_t *node = list->first;

    if (new == NULL)
        return new;
    while (node != NULL) {
        list_push(new, callback(node->data));

        node = node->next;
    }

    return new;
}
