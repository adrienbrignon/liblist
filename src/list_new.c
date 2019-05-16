/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Create a new list instance.
*/

#include <stdlib.h>

#include "list.h"

list_t *list_new(void)
{
    list_t *list = NULL;

    if ((list = malloc(sizeof *list)) == NULL)
        return NULL;

    list->length = 0;
    list->first = NULL;
    list->last = NULL;

    return list;
}
