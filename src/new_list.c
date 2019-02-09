/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Create a new list instance.
*/

#include <stdlib.h>

#include "list.h"

list_t *new_list(void)
{
    list_t *list = malloc(sizeof *list);

    if (list == NULL)
        return list;

    list->length = 0;
    list->first = NULL;
    list->last = NULL;

    return list;
}
