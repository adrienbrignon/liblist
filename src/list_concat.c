/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Merge two or more lists, into a new one.
*/

#include <stdarg.h>
#include <stddef.h>

#include "list.h"

static inline void copy_nodes(const list_t *to, const list_t *from)
{
    list_t *list = (list_t *) from;

    while (list->last != NULL) {
        list_push((list_t *) to, from->last->data);

        list->last = list->last->previous;
    }
}

list_t *list_concat(const list_t *list, ...)
{
    va_list arg;
    list_t *new = new_list();
    list_t *tmp = (list_t *) list;

    if (list == NULL)
        return (list_t *) list;

    copy_nodes(new, tmp);
    va_start(arg, list);

    while ((tmp = va_arg(arg, list_t *)) != NULL)
        copy_nodes(new, tmp);

    va_end(arg);

    return new;
}
