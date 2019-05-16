/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Test the list_contains function.
*/

#include <criterion/criterion.h>

#include "list.h"

Test(list_contains, should_contain)
{
    char *bonjour = "bonjour";
    list_t *list = list_new();

    cr_assert_not_null(list);
    cr_assert_eq(list_push(list, "hey"), 1);
    cr_assert_eq(list_push(list, "hola"), 2);
    cr_assert_eq(list_push(list, bonjour), 3);
    cr_assert_eq(list_contains(list, bonjour), 1);
}
