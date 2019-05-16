/*
** EPITECH PROJECT, 2018
** liblist
** File description:
** The library main header.
*/

#ifndef LIST_H_
#define LIST_H_

#include <stddef.h>

typedef struct node {
    void *data;
    struct node *next;
    struct node *previous;
} node_t;

typedef struct list {
    size_t length;
    node_t *first;
    node_t *last;
} list_t;

typedef void (list_reduce_callback_t)(int *accumulator, node_t *node);

typedef int (list_find_callback_t)(node_t *node);
typedef int (list_some_callback_t)(node_t *node);
typedef int (list_every_callback_t)(node_t *node);
typedef int (list_filter_callback_t)(node_t *node);

typedef void *(list_map_callback_t)(void *data);

void list_destroy(list_t *list);

int list_push(list_t *list, void *data);
int list_unshift(list_t *list, void *data);
int list_contains(list_t *list, void *data);
int list_some(list_t *list, list_some_callback_t *fn);
int list_every(list_t *list, list_every_callback_t *fn);
int list_reduce(list_t *list, list_reduce_callback_t *callback);

void *list_pop(list_t *list);
void *list_shift(list_t *list);

list_t *list_new(void);
list_t *list_concat(list_t *list, ...);
list_t *list_map(list_t *list, list_map_callback_t *fn);
list_t *list_filter(list_t *list, list_filter_callback_t *fn);

node_t *list_node(void *data);
node_t *list_find(list_t *list, list_find_callback_t *callback);

#endif
