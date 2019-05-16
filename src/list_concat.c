/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Merge two or more lists into a new one.
*/

#include <stdarg.h>
#include <stddef.h>

#include "list.h"

static void copy_nodes(list_t *to, list_t *from)
{
    node_t *node = from->first;

    while (node != NULL) {
        list_push(to, node->data);

        node = node->next;
    }
}

list_t *list_concat(list_t *list, ...)
{
    va_list arg;
    list_t *tmp = NULL;
    list_t *new = list_new();

    if (new == NULL || list == NULL)
        return list;

    copy_nodes(new, list);
    va_start(arg, list);

    while ((tmp = va_arg(arg, list_t *)) != NULL)
        copy_nodes(new, tmp);

    va_end(arg);

    return new;
}
