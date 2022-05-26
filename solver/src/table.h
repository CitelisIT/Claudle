#include <stdbool.h>
#include "halfsiphash.h"
#include "linked_list.h"

#ifndef __TABLE__H__
#define __TABLE_H__

typedef struct _table_t
{
    list_t **bucket;
    int nb_word;
    int size;
} _table_t;

typedef struct _table_t table_t;

int hash(char *some_value);

table_t *table_create(int size);

void table_destroy(table_t *one_table);

int table_indexof(table_t *one_table, char *one_key);

bool table_add(table_t *one_table, char *one_key);

bool table_contains(table_t *one_table, char *one_key);

int table_get(table_t *one_table, char *one_key);

table_t *table_copy(table_t *one_table);

void table_remove(table_t *one_table, char *one_key);

element_t *table_max_entropy(table_t *one_table);

#endif /* __TABLE_H__ */
