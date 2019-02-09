/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Remove the first element of the list.
*/

#include <stdlib.h>

#include "list.h"

void *list_shift(list_t *list)
{
    void *data = NULL;

    if (list->length == 0)
        return data;

    data = list->first->data;

    free(list->first);

    list->first = list->first->next;
    list->length--;

    if (list->length > 0) {
        list->first->previous = NULL;
    } else {
        list->first = NULL;
        list->last = NULL;
    }

    return data;
}
