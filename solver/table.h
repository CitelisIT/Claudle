#include <stdbool.h>
#include "list.h"

#ifndef __TABLE__H__
#define __TABLE_H__

typedef struct _table_t
{
    list_t **sublist;
    int size;
} table_t;

typedef struct _table_t table_t;

int hash(char *some_value);

table_t *table_create(int size);

void table_destroy(table_t *one_table);

int table_indexof(table_t *one_table, char *one_key);

bool table_add(table_t *one_table, char *one_key, char *one_value);

bool table_contains(table_t *one_table, char *one_key);

char *table_get(table_t *one_table, char *one_key);

#endif /* __TABLE_H__ */
