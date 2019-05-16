/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Test the list_some function.
*/

#include <criterion/criterion.h>

#include "list.h"

static int not_null(node_t *node)
{
    return node->data != NULL;
}

Test(list_some, test_on_empty_list)
{
    list_t *list = list_new();

    cr_assert_not_null(list);
    cr_assert_eq(list->length, 0);
    cr_assert_eq(list_some(list, not_null), 0);
}

Test(list_some, should_return_true)
{
    list_t *list = list_new();

    cr_assert_not_null(list);
    list_push(list, NULL);
    list_push(list, NULL);
    list_push(list, "NULL");
    cr_assert_eq(list->length, 3);
    cr_assert_eq(list_some(list, not_null), 1);
}

Test(list_some, should_return_false)
{
    list_t *list = list_new();

    cr_assert_not_null(list);
    list_push(list, NULL);
    list_push(list, NULL);
    list_push(list, NULL);
    cr_assert_eq(list->length, 3);
    cr_assert_eq(list_some(list, not_null), 0);
}
