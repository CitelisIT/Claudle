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

struct _word_t
{
    element_t *head;
    struct _word_t *next;
};

typedef struct _word_t word_t;

struct _list_t
{
    word_t *sublist;
};

typedef struct _list_t list_t;

// LIST_T FUNCTIONS

list_t *list_create();

void list_destroy(list_t *one_list);

bool list_is_empty(list_t *one_list);

void list_append(list_t *one_list, word_t *one_word);

void list_print(list_t *one_list);

bool list_contains(list_t *one_list, word_t *one_word);

int list_get_size(list_t *one_list);

list_t *list_copy(list_t *one_list);

// WORD_T FUNCTIONS

word_t *word_create();

void word_destroy(word_t *one_word);

bool word_is_empty(word_t *one_word);

void word_append(word_t *one_word, char one_key, int one_value);

void element_print(element_t *one_element);

void word_print(word_t *one_word);

bool word_contains(word_t *one_word, char one_key);

int word_find(word_t *one_word, char one_key);

void word_remove_first(word_t *one_word);

char word_get_key(element_t *one_element);

int word_get_value(element_t *one_element);

int word_get_size(word_t *one_word);

word_t *word_copy(word_t *one_word);

char *word_to_char(word_t *one_word);

word_t *char_to_word(char *one_word);

#endif /* __LIST_H__ */
