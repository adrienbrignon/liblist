/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Test the list_pop function.
*/

#include <criterion/criterion.h>

#include "list.h"

Test(list_pop, test_on_empty_list)
{
    list_t *list = list_new();

    cr_assert_not_null(list);
    cr_assert_null(list_pop(list));
    cr_assert_eq(list->length, 0);
}

Test(list_pop, test_on_list_with_two_nodes)
{
    list_t *list = list_new();

    cr_assert_not_null(list);
    list_unshift(list, "a");
    list_unshift(list, "b");
    cr_assert_eq(list->length, 2);
    cr_assert_str_eq(list_pop(list), "a");
    cr_assert_str_eq(list_pop(list), "b");
    cr_assert_eq(list->length, 0);
    cr_assert_null(list->first);
    cr_assert_null(list->last);
}
