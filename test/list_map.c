/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Test the list_map function.
*/

#include <string.h>
#include <criterion/criterion.h>

#include "list.h"

static void *reverse(void *str)
{
    size_t j = 0;
    size_t i = 0;

    if (str == NULL || (*(char *) str) == '\0')
        return str;

    i = strlen(str) - 1;

    while (i > j) {
        char tmp = ((char *) str)[i];

        ((char *) str)[i--] = ((char *) str)[j];
        ((char *) str)[j++] = tmp;
    }

    return str;
}

Test(list_map, test_on_empty_list)
{
    list_t *new = NULL;
    list_t *list = list_new();

    cr_assert_not_null(list);
    cr_assert_eq(list->length, 0);

    new = list_map(list, reverse);

    cr_assert_not_null(new);
    cr_assert_eq(new->length, 0);
    cr_assert_eq(list->length, 0);
}

Test(list_map, test_on_string_nodes)
{
    list_t *new = NULL;
    list_t *list = list_new();

    cr_assert_not_null(list);
    list_push(list, strdup("hello"));
    list_push(list, strdup("world"));
    list_push(list, strdup("lol"));
    cr_assert_eq(list->length, 3);

    new = list_map(list, reverse);

    cr_assert_not_null(new);
    cr_assert_eq(new->length, 3);
    cr_assert_eq(list->length, 3);
    cr_assert_str_eq(list->first->data, "olleh");
    cr_assert_str_eq(list->first->next->data, "dlrow");
    cr_assert_str_eq(list->first->next->next->data, "lol");
}
