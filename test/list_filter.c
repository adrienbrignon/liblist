/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Test the list_filter function.
*/

#include <criterion/criterion.h>

#include "list.h"

static int not_null(node_t *node)
{
    return node->data != NULL;
}

Test(list_filter, test_on_empty_list)
{
    list_t *new = NULL;
    list_t *list = list_new();

    cr_assert_not_null(list);
    cr_assert_eq(list->length, 0);

    new = list_filter(list, not_null);

    cr_assert_not_null(new);
    cr_assert_eq(new->length, 0);
}

Test(list_filter, test_on_list_with_three_nodes)
{
    list_t *new = NULL;
    list_t *list = list_new();

    cr_assert_not_null(list);
    list_push(list, "hello");
    list_push(list, NULL);
    list_push(list, "world");
    cr_assert_eq(list->length, 3);

    new = list_filter(list, not_null);

    cr_assert_str_eq(list->first->data, "hello");
    cr_assert_str_eq(list->last->data, "world");
    cr_assert_eq(list->length, 3);
    cr_assert_not_null(new);
    cr_assert_eq(new->length, 2);
    cr_assert_str_eq(new->first->data, "hello");
    cr_assert_str_eq(new->last->data, "world");
}

Test(list_filter, test_on_list_with_no_matching_nodes)
{
    list_t *new = NULL;
    list_t *list = list_new();

    cr_assert_not_null(list);
    list_push(list, NULL);
    list_push(list, NULL);
    list_push(list, NULL);
    cr_assert_eq(list->length, 3);

    new = list_filter(list, not_null);

    cr_assert_eq(list->length, 3);
    cr_assert_not_null(new);
    cr_assert_eq(new->length, 0);
}
