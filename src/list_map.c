/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Create a new list with the results of calling a function for every list node.
*/

#include <stddef.h>

#include "list.h"

list_t *list_map(list_t *list, list_map_function_t *callback)
{
    list_t *new = new_list();
    node_t *node = list->first;

    if (new == NULL)
        return new;
    while (node != NULL) {
        list_push(new, callback(node->data));

        node = node->next;
    }

    return new;
}
