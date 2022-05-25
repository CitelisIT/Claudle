#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "linked_list.h"

element_t *element_create(char *key, double entropy, int *score)
{
    element_t *new = malloc(sizeof(element_t));

    int len = strlen(key);
    char *keyCopy = calloc(len + 1, sizeof(char));
    strcpy(keyCopy, key);

    new->entropy = entropy;

    int *scoreCopy = calloc(len, sizeof(int));
    if (!score)
    {
        for (int i = 0; i < len; i++)
        {
            scoreCopy[i] = 0;
        }
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            scoreCopy[i] = score[i];
        }
    }

    new->key = keyCopy;
    new->score = scoreCopy;

    return new;
}

node_t *node_create(element_t *value)
{
    node_t *node = calloc(1, sizeof(node_t));
    node->value = value;

    return node;
}

void node_destroy(node_t *one_node)
{
    element_destroy(one_node->value);
    free(one_node);
}

list_t *list_create()
{
    list_t *new_list = calloc(1, sizeof(list_t));

    new_list->head = NULL;
    new_list->size = 0;
    new_list->last = NULL;

    return new_list;
}

list_t *list_copy(list_t *one_list)
{
    list_t *new_list = list_create();

    node_t *curr = one_list->head;
    while (curr)
    {
        list_append(new_list, curr->value->key, curr->value->entropy, curr->value->score);
        curr = curr->next;
    }

    return new_list;
}

void element_destroy(element_t *one_el)
{

    free(one_el->score);
    free(one_el->key);
    free(one_el);
}

void list_destroy(list_t *one_list)
{
    node_t *curr_node = one_list->head;
    node_t *tmp = NULL;
    while (curr_node)
    {
        tmp = curr_node;
        curr_node = curr_node->next;

        node_destroy(tmp);
    }
    free(one_list);
}

bool list_is_empty(list_t *one_list)
{
    assert(one_list != NULL);
    return one_list->head == NULL;
}

void list_append(list_t *one_list, char *one_key, long entropy, int *one_score)
{
    node_t *new_node = node_create(element_create(one_key, entropy, one_score));

    if (one_list->head == NULL)
    {
        one_list->head = new_node;
        one_list->size++;
        one_list->last = new_node;
    }

    else
    {
        one_list->last->next = new_node;
        one_list->size++;
        one_list->last = new_node;
    }
}

double list_find(list_t *one_list, char *one_key)
{
    node_t *one_node = one_list->head;

    while (one_node)
    {
        if (strcmp(one_node->value->key, one_key) == 0)
        {
            return one_node->value->entropy;
        }

        one_node = one_node->next;
    }

    return 0;
}

bool list_contains(list_t *one_list, char *one_key)
{
    if (!one_list)
    {
        return false;
    }

    node_t *one_node = one_list->head;

    while (one_node)
    {
        if (strcmp(one_node->value->key, one_key) == 0)
        {
            return true;
        }

        one_node = one_node->next;
    }

    return false;
}

char *list_get_key(element_t *one_element)
{
    assert(one_element != NULL);
    return one_element->key;
}

double list_get_entropy(element_t *one_element)
{
    assert(one_element != NULL);
    return one_element->entropy;
}

int* list_get_score(element_t *one_element)
{
    assert(one_element != NULL);
    return one_element->score;
}

int list_get_size(list_t *one_list)
{
    assert(one_list != NULL);
    int size = 0;
    node_t *one_node = one_list->head;

    while (one_node)
    {
        size++;
        one_node = one_node->next;
    }

    return size;
}

void list_remove_key(list_t *one_list, char *one_key)
{
    node_t *previous = NULL;
    node_t *current = one_list->head;

    // if it's the first element
    if (current != NULL && strcmp(current->value->key, one_key) == 0)
    {
        one_list->head = one_list->head->next;
        node_destroy(current);
        return;
    }

    while (current != NULL && strcmp(current->value->key, one_key) != 0)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        return;
    }

    previous->next = current->next;

    node_destroy(current);
}

void list_remove_first(list_t *one_list)
{
    node_t *tmp = one_list->head;
    one_list->head = one_list->head->next;
    node_destroy(tmp);
}

void list_print(list_t *one_list)
{
    assert(one_list != NULL);

    bool first = true;

    printf("[");
    node_t *current = one_list->head;
    while (current != NULL)
    {
        if (!first)
        {
            printf(",");
        }
        printf(" %s", current->value->key);
        first = false;
        current = current->next;
    }

    if (!first)
    {
        printf(" ");
    }
    printf("]\n");
}
