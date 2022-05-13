#include <stdbool.h>

#ifndef __LIST_H__
#define __LIST_H__

struct _element_t
{
    char key;
    int value;
    struct _element_t *next;
};

typedef struct _element_t element_t;

struct _list_t
{
    element_t *head;
};

typedef struct _list_t list_t;

list_t *list_create();

void list_destroy(list_t *one_list);

bool list_is_empty(list_t *one_list);

void list_append(list_t *one_list, char one_key, int one_value);

void element_print(element_t *one_element);

void list_print(list_t *one_list);

bool list_contains(list_t *one_list, char one_key);

int list_find(list_t *one_list, char one_key);

void list_remove_first(list_t *one_list);

char list_get_key(element_t *one_element);

int list_get_value(element_t *one_element);

int list_get_size(list_t *one_list);

list_t *list_copy(list_t *one_list);

#endif /* __LIST_H__ */
