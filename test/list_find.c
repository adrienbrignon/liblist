/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Test the list_find function.
*/

#include <criterion/criterion.h>

#include "list.h"

static int filter(node_t *node)
{
    return strcmp(node->data, "world") == 0;
}

Test(list_find, test_on_empty_list)
{
    list_t *list = list_new();

    cr_assert_not_null(list);
    cr_assert_eq(list->length, 0);
    cr_assert_eq(list_push(list, "hello"), 1);
    cr_assert_eq(list_push(list, "world"), 2);
    cr_assert_eq(list_push(list, "!"), 3);
    cr_assert_str_eq(list_find(list, filter)->data, "world");
}
