#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include <err.h>
#include <errno.h>
#include <stdbool.h>
#include <assert.h>

list_t *list_create()
{

    list_t *new_list = calloc(1, sizeof(list_t));

    if (new_list == NULL)
    {
        err(ENOMEM, "can't allocate a new list");
    }

    return new_list;
}

void list_destroy(list_t *one_list)
{

    assert(one_list != NULL);

    element_t *current = one_list->head;
    element_t *tmp;
    while (current != NULL)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    free(one_list);
}

bool list_is_empty(list_t *one_list)
{
    assert(one_list != NULL);
    return one_list->head == NULL;
}

void list_append(list_t *one_list, char one_key, int one_value)
{
    element_t *new_element = calloc(1, sizeof(element_t));
    new_element->key = one_key;
    new_element->value = one_value;
    new_element->next = NULL;
    if (one_list->head == NULL)
    {
        one_list->head = new_element;
    }
    else
    {
        element_t *tmp = one_list->head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new_element;
    }
}

void element_print(element_t *one_element)
{
    assert(one_element != NULL);
    printf("%c: %d\n", one_element->key, one_element->value);
}

void list_print(list_t *one_list)
{
    assert(one_list != NULL);

    bool first = true;

    printf("[");
    element_t *current = one_list->head;
    while (current != NULL)
    {
        if (!first)
        {
            printf(",");
        }
        printf(" %s : %s", current->key, current->value);
        first = false;
        current = current->next;
    }

    if (!first)
    {
        printf(" ");
    }
    printf("]\n");
}

bool list_contains(list_t *one_list, char one_key)
{
    assert(one_list != NULL);
    assert(one_key != NULL);

    element_t *current = one_list->head;
    while (current != NULL)
    {
        if (strcmp(current->key, one_key) == 0)
        {
            return true;
        }
        current = current->next;
    }

    return false;
}

int list_find(list_t *one_list, char one_key)
{
    element_t *tmp = one_list->head;
    while (tmp != NULL)
    {
        if (strcmp(tmp->key, one_key) == 0)
        {
            return (tmp->value);
        }
        tmp = tmp->next;
    }
    return NULL;
}

void list_remove_first(list_t *one_list)
{
    assert(one_list != NULL);

    element_t *tmp = one_list->head;
    one_list->head = one_list->head->next;
    free(tmp);
}

char list_get_key(element_t *one_element)
{
    assert(one_element != NULL);
    return one_element->key;
}

int list_get_value(element_t *one_element)
{
    assert(one_element != NULL);
    return one_element->value;
}
