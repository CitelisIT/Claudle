#include <stdbool.h>

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

typedef struct element_t
{
    char *key;
    long entropy;
    int *score;
} element_t;

element_t *element_create(char *key, long entropy, int *score);

void element_destroy(element_t *one_el);

typedef struct node_t
{
    struct node_t *next;
    element_t *value;
} node_t;

node_t *node_create(element_t *value);

void node_destroy(node_t *one_node);

typedef struct list_t
{
    node_t *head;
    node_t *last;
} list_t;

list_t *list_create();

void list_destroy(list_t *one_list);

bool list_is_empty(list_t *one_list);

void list_append(list_t *one_list, char *one_key, long entropy, int *one_score);

long list_find(list_t *one_list, char *one_key);

bool list_contains(list_t *one_list, char *one_key);

char *list_get_key(element_t *one_element);

long list_get_entropy(element_t *one_element);

void list_remove_key(list_t *one_list, char *one_key);

// Might not need these for the solver
// void element_print(element_t *one_element);
//
void list_print(list_t *one_list);
//
// void list_remove_first(list_t *one_list);

int list_get_size(list_t *one_list);

#endif /* __LINKED_LIST_H__ */
