/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Test the list_unshift function.
*/

#include <criterion/criterion.h>

#include "list.h"

Test(list_unshift, test_with_one_node)
{
    list_t *list = list_new();

    cr_assert_not_null(list);
    cr_assert_eq(list_unshift(list, "cat"), 1);
    cr_assert_eq(list->length, 1);
    cr_assert_eq(list->first->data, "cat");
    cr_assert_eq(list->first, list->last);
    cr_assert_null(list->first->previous);
    cr_assert_null(list->first->next);
}

Test(list_unshift, test_with_two_nodes)
{
    list_t *list = list_new();

    cr_assert_not_null(list);
    cr_assert_eq(list_unshift(list, "cat"), 1);
    cr_assert_eq(list_unshift(list, "dog"), 2);
    cr_assert_eq(list->length, 2);
    cr_assert_str_eq(list->first->data, "dog");
    cr_assert_str_eq(list->last->data, "cat");
    cr_assert_str_eq(list->first->next->data, "cat");
    cr_assert_str_eq(list->last->previous->data, "dog");
    cr_assert_str_eq(list->last->previous->next->data, "cat");
    cr_assert_str_eq(list->first->next->previous->data, "dog");
    cr_assert_null(list->first->previous);
    cr_assert_null(list->last->next);
}
