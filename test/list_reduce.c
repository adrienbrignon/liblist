/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Test the list_reduce function.
*/

#include <criterion/criterion.h>

#include "list.h"

static void reducer(int *accumulator, node_t *node)
{
    *accumulator = *accumulator + strlen(node->data);
}

Test(list_reduce, test_on_empty_list)
{
    list_t *list = list_new();

    cr_assert_not_null(list);
    cr_assert_eq(list->length, 0);
    cr_assert_eq(list_reduce(list, reducer), 0);
}

Test(list_reduce, test_on_list_with_three_nodes)
{
    list_t *list = list_new();

    cr_assert_not_null(list);
    list_push(list, "i");
    list_push(list, "like");
    list_push(list, "trains");
    cr_assert_eq(list->length, 3);
    cr_assert_eq(list_reduce(list, reducer), 11);
}
