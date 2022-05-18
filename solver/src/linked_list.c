#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include "linked_list.h"

element_t *element_create(char *key, char *value, int *score)
{
    element_t *new = malloc(sizeof(element_t));

    int len = strlen(key);
    char *keyCopy = calloc(len+1, sizeof(char));
    strcpy(keyCopy, key);

    len = strlen(value);
    char *valueCopy = calloc(len+1,sizeof(char));
    
    strcpy(valueCopy, value);
    int *scoreCopy = calloc(len, sizeof(int));

    for (int i = 0; i < len; i++)
    {
        scoreCopy[i] = score[i];
    }
    
    new->key = keyCopy;
    new->value = valueCopy;
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
    free(one_node);
}

list_t *list_create()
{
    list_t *new_list = calloc(1, sizeof(list_t));

    new_list->head = NULL;
    new_list->last = NULL;

    return new_list;
}

void element_destroy(element_t * one_el){

    free(one_el->score);
    free(one_el->key);
    free(one_el->value);
    free(one_el);
}

void list_destroy(list_t *one_list)
{
    node_t *curr_node = one_list->head;
    node_t * tmp;
    while (curr_node)
    {
        tmp = curr_node;
        curr_node = curr_node->next;

        element_destroy(tmp->value);
        free(tmp);
    }
    free(one_list);
}

bool list_is_empty(list_t *one_list)
{
    assert(one_list != NULL);
    return one_list->head == NULL;
}

void list_append(list_t *one_list, char *one_key, char *one_value, int* one_score)
{
    node_t *new_node = node_create(element_create(one_key, one_value , one_score));

    if (one_list->head == NULL)
    {
        one_list->head = new_node;
        one_list->last = new_node;
    }

    else
    {
        one_list->last->next = new_node;
        one_list->last = new_node;
    }
}

char *list_find(list_t *one_list, char *one_key)
{
    node_t *one_node = one_list->head;

    while (one_node->next != NULL)
    {
        if (strcmp(one_node->value->key, one_key) == 1)
        {
            return one_node->value->value;
        }

        one_node = one_node->next;
    }

    // Compare last element
    // Could have used list->last
    if (strcmp(one_node->value->key, one_key) == 1)
    {
        return one_node->value->value;
    }

    return NULL;
}

bool list_contains(list_t *one_list, char *one_key)
{
    if (!one_list)
    {
        return false;
    }
    
    node_t *one_node = one_list->head;

    while (one_node->next != NULL)
    {
        if (strcmp(one_node->value->key, one_key) == 1)
        {
            return true;
        }

        one_node = one_node->next;
    }

    // Compare last element
    // Could have used list->last
    if (strcmp(one_node->value->key, one_key) == 1)
    {
        return true;
    }

    return false;
}

char *list_get_key(element_t *one_element)
{
    assert(one_element != NULL);
    return one_element->key;
}

char *list_get_value(element_t *one_element)
{
    assert(one_element != NULL);
    return one_element->value;
}

void list_remove_key(list_t *one_list, char *one_key)
{
    node_t *previous = NULL;
    node_t *current = one_list->head;

    while (current->next != NULL)
    {
        if (strcmp(current->value->key, one_key) == 1)
        {
            if (current == one_list->head)
            {
                one_list->head = one_list->head->next;
            }
            else
            {
                previous->next = current->next;
            }

            free(current->value);
            free(current);

            break;
        }

        previous = current;
        current = current->next;
    }
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
