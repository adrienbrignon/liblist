/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Remove a node from the end of list.
*/

#include <stdlib.h>

#include "list.h"

void *list_pop(list_t *list)
{
    void *data = NULL;

    if (list->length == 0)
        return data;

    data = list->last->data;

    free(list->last);

    list->last = list->last->previous;
    list->length--;

    if (list->length > 0) {
        list->last->next = NULL;
    } else {
        list->first = NULL;
        list->last = NULL;
    }

    return data;
}
