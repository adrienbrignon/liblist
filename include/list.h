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

int list_push(list_t *list, void *node);
int list_unshift(list_t *list, void *node);

void *list_pop(list_t *list);
void *list_shift(list_t *list);

list_t *new_list(void);
list_t *list_concat(const list_t *list, ...);

node_t *new_node(void *data);

#endif
