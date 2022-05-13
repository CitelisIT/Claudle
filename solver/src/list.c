#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include <err.h>
#include <errno.h>
#include <stdbool.h>
#include <assert.h>

word_t *word_create()
{

    word_t *new_word = calloc(1, sizeof(word_t));

    if (new_word == NULL)
    {
        err(ENOMEM, "can't allocate a new word");
    }

    return new_word;
}

list_t *list_create()
{
    list_t *new_list = calloc(1, sizeof(list_t));

    if (new_list == NULL)
    {
        err(ENOMEM, "can't allocate a new list");
    }

    return new_list;
}

void word_destroy(word_t *one_word)
{

    assert(one_word != NULL);

    element_t *current = one_word->head;
    element_t *tmp;
    while (current != NULL)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    free(one_word);
}

void list_destroy(list_t *one_list)
{

    assert(one_list != NULL);

    word_t *current = one_list->sublist;
    word_t *tmp;
    while (current != NULL)
    {
        tmp = current;
        current = current->next;
        word_destroy(tmp);
    }
    free(one_list);
}

bool word_is_empty(word_t *one_word)
{
    assert(one_word != NULL);
    return one_word->head == NULL;
}

bool list_is_empty(list_t *one_list)
{
    assert(one_list != NULL);
    return one_list->sublist == NULL;
}

void word_append(word_t *one_word, char one_key, int one_value)
{
    element_t *new_element = calloc(1, sizeof(element_t));
    new_element->key = one_key;
    new_element->value = one_value;
    new_element->next = NULL;
    if (one_word->head == NULL)
    {
        one_word->head = new_element;
    }
    else
    {
        element_t *tmp = one_word->head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new_element;
    }
}

void list_append(list_t *one_list, word_t *one_word)
{
    if (one_list->sublist == NULL)
    {
        one_list->sublist = one_word;
    }
    else
    {
        word_t *tmp = one_list->sublist;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = one_word;
    }
}

void element_print(element_t *one_element)
{
    assert(one_element != NULL);
    printf("%c: %d\n", one_element->key, one_element->value);
}

void word_print(word_t *one_word)
{
    assert(one_word != NULL);

    bool first = true;

    printf("[");
    element_t *current = one_word->head;
    while (current != NULL)
    {
        if (!first)
        {
            printf(",");
        }
        printf(" %c : %d", current->key, current->value);
        first = false;
        current = current->next;
    }

    if (!first)
    {
        printf(" ");
    }
    printf("]\n");
}

void list_print(list_t *one_list)
{
    assert(one_list != NULL);

    bool first = true;

    printf("[");
    word_t *current = one_list->sublist;
    while (current != NULL)
    {
        if (!first)
        {
            printf(",");
        }
        word_print(current);
        first = false;
        current = current->next;
    }

    if (!first)
    {
        printf(" ");
    }
    printf("]\n");
}

bool word_contains(word_t *one_word, char one_key)
{
    assert(one_word != NULL);

    element_t *current = one_word->head;
    while (current != NULL)
    {
        if (current->key == one_key)
        {
            return true;
        }
        current = current->next;
    }

    return false;
}

bool list_contains(list_t *one_list, word_t *one_word)
{
    element_t *letter;
    assert(one_list != NULL);
    assert(one_word != NULL);
    bool contain = false;
    word_t *current = one_list->sublist;
    while (current != NULL)
    {
        for (int i = 0; i < word_get_size(current); i++)
        {
            letter = current->head;
            if (word_contains(current, letter->key))
            {
                contain = true;
            }
            else
            {
                contain = false;
            }
        }
        current = current->next;
    }

    return contain;
}

int list_get_size(list_t *one_list)
{
    assert(one_list != NULL);
    int size = 0;
    word_t *tmp = one_list->sublist;
    while (tmp != NULL)
    {
        size++;
        tmp = tmp->next;
    }
    return size;
}

int word_find(word_t *one_word, char one_key)
{
    element_t *tmp = one_word->head;
    while (tmp != NULL)
    {
        if (tmp->key == one_key)
        {
            return (tmp->value);
        }
        tmp = tmp->next;
    }
    return 0;
}

void word_remove_first(word_t *one_word)
{
    assert(one_word != NULL);

    element_t *tmp = one_word->head;
    one_word->head = one_word->head->next;
    free(tmp);
}

char word_get_key(element_t *one_element)
{
    assert(one_element != NULL);
    return one_element->key;
}

int word_get_value(element_t *one_element)
{
    assert(one_element != NULL);
    return one_element->value;
}

int word_get_size(word_t *one_word)
{
    assert(one_word != NULL);
    int size = 0;
    element_t *tmp = one_word->head;
    while (tmp != NULL)
    {
        size++;
        tmp = tmp->next;
    }
    return size;
}

word_t *word_copy(word_t *one_word)
{
    assert(one_word != NULL);
    word_t *new_word = word_create();
    element_t *tmp = one_word->head;
    while (tmp != NULL)
    {
        word_append(new_word, tmp->key, tmp->value);
        tmp = tmp->next;
    }
    return new_word;
}

list_t *list_copy(list_t *one_list)
{
    assert(one_list != NULL);
    list_t *new_list = list_create();
    word_t *tmp = one_list->sublist;
    while (tmp != NULL)
    {
        list_append(new_list, tmp);
        tmp = tmp->next;
    }
    return new_list;
}

char *word_to_char(word_t *one_word)
{
    assert(one_word != NULL);

    bool first = true;
    char *mot = "";
    element_t *current = one_word->head;
    while (current != NULL)
    {
        if (!first)
            mot = mot + current->key;
        first = false;
        current = current->next;
    }

    return mot;
}

word_t *char_to_word(char *one_word)
{
    assert(one_word != NULL);
    word_t *w = word_create();
    for (size_t i = 0; i < strlen(one_word); i++)
    {
        word_append(w, one_word[i], 0);
    }
    return w;
}
