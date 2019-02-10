/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** The library main header.
*/

#ifndef LIST_H_
#define LIST_H_

typedef struct node
{
    void *data;
    struct node *next;
    struct node *previous;
} node_t;

typedef struct list
{
    int length;
    node_t *first;
    node_t *last;
} list_t;

typedef int (list_test_function_t)(node_t *node);

int list_push(list_t *list, void *node);
int list_unshift(list_t *list, void *node);
int list_some(list_t *list, list_test_function_t *fn);
int list_every(list_t *list, list_test_function_t *fn);

void *list_pop(list_t *list);
void *list_shift(list_t *list);

list_t *new_list(void);
list_t *list_concat(list_t *list, ...);
list_t *list_filter(list_t *list, list_test_function_t *fn);

node_t *new_node(void *data);

#endif
