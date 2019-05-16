/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** Test the list_concat function.
*/

#include <criterion/criterion.h>

#include "list.h"

Test(list_concat, test_with_empty_lists)
{
    list_t *a = list_new();
    list_t *b = list_new();
    list_t *c = NULL;

    cr_assert(a != NULL && b != NULL);
    cr_assert(a->length == 0 && b->length == 0);

    c = list_concat(a, b, NULL);

    cr_assert_eq(c->length, 0);
    cr_assert_null(c->first);
    cr_assert_null(c->last);
}

Test(list_concat, test_with_two_lists)
{
    list_t *a = list_new();
    list_t *b = list_new();
    list_t *c = NULL;

    cr_assert(a != NULL && b != NULL);
    list_push(a, "hello");
    list_push(b, "world");
    cr_assert(a->length == 1 && b->length == 1);

    c = list_concat(a, b, NULL);

    cr_assert(a->length == 1 && b->length == 1 && c->length == 2);
    cr_assert_str_eq(a->first->data, "hello");
    cr_assert_str_eq(b->first->data, "world");
    cr_assert_str_eq(c->first->data, "hello");
    cr_assert_str_eq(c->last->data, "world");
}

Test(list_concat, test_with_three_lists)
{
    list_t *a = list_new();
    list_t *b = list_new();
    list_t *c = list_new();
    list_t *d = NULL;

    cr_assert(a != NULL && b != NULL && c != NULL);
    list_push(a, "hello");
    list_push(b, "world");
    list_push(c, "such a");
    list_push(c, "nice day");
    cr_assert(a->length == 1 && b->length == 1 && c->length == 2);

    d = list_concat(a, b, c, NULL);

    cr_assert_not_null(d);
    cr_assert(d->length == 4);
    cr_assert_str_eq(d->first->data, "hello");
    cr_assert_str_eq(d->first->next->data, "world");
    cr_assert_str_eq(d->first->next->next->data, "such a");
    cr_assert_str_eq(d->first->next->next->next->data, "nice day");
}
