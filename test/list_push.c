/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Test the list_push function.
*/

#include <criterion/criterion.h>

#include "list.h"

Test(list_push, test_with_one_node)
{
    list_t *list = list_new();

    cr_assert_not_null(list);
    cr_assert_eq(list_push(list, "cat"), 1);
    cr_assert_eq(list->length, 1);
    cr_assert_eq(list->first->data, "cat");
    cr_assert_eq(list->first, list->last);
    cr_assert_null(list->first->previous);
    cr_assert_null(list->first->next);
}

Test(list_push, test_with_two_nodes)
{
    list_t *list = list_new();

    cr_assert_not_null(list);
    cr_assert_eq(list_push(list, "cat"), 1);
    cr_assert_eq(list_push(list, "dog"), 2);
    cr_assert_eq(list->length, 2);
    cr_assert_str_eq(list->first->data, "cat");
    cr_assert_str_eq(list->last->data, "dog");
    cr_assert_str_eq(list->first->next->data, "dog");
    cr_assert_str_eq(list->last->previous->data, "cat");
    cr_assert_str_eq(list->last->previous->next->data, "dog");
    cr_assert_str_eq(list->first->next->previous->data, "cat");
    cr_assert_null(list->first->previous);
    cr_assert_null(list->last->next);
}

Test(list_push, test_with_two_three_nodes)
{
    list_t *list = list_new();

    cr_assert_not_null(list);
    cr_assert_eq(list_push(list, "foo"), 1);
    cr_assert_eq(list_push(list, "bar"), 2);
    cr_assert_eq(list_push(list, "2000"), 3);
    cr_assert_eq(list->length, 3);
    cr_assert_str_eq(list->first->data, "foo");
    cr_assert_str_eq(list->last->data, "2000");
    cr_assert_str_eq(list->first->next->data, "bar");
    cr_assert_str_eq(list->last->previous->data, "bar");
    cr_assert_str_eq(list->last->previous->next->data, "2000");
    cr_assert_str_eq(list->first->next->previous->data, "foo");
    cr_assert_eq(list->first->next->next, list->last);
    cr_assert_eq(list->last->previous->previous, list->first);
    cr_assert_null(list->first->previous);
    cr_assert_null(list->last->next);
}
