#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "table.h"

int hash(char *one_word)
{
    char *some_value = one_word;
    int res = 0;
    int i = 0;
    for (i = 0; some_value[i] != '\0'; i++)
    {
        res = res + some_value[i];
    }
    return res;
}

table_t *table_create(int size)
{
    table_t *table = calloc(1, sizeof(table_t));
    table->size = size;
    table->nb_word = 0;
    table->bucket = calloc(size, sizeof(list_t *));
    for (int i = 0; i < size; i++)
    {
        table->bucket[i] = list_create();
    }
    return table;
}

void table_destroy(table_t *one_table)
{
    int i = 0;
    for (i = 0; i < one_table->size; i++)
    {
        list_destroy(one_table->bucket[i]);
    }
    free(one_table->bucket);
    free(one_table);
}

int table_indexof(table_t *one_table, char *one_key)
{
    int ind = hash(one_key) % (one_table->size);
    return ind < 0 ? ind + one_table->size : ind;
}

bool table_add(table_t *one_table, char *one_key)
{
    int *s = NULL;

    int ind = table_indexof(one_table, one_key);
    if (list_contains(one_table->bucket[ind], one_key))
    {
        return false;
    }
    list_append(one_table->bucket[ind], one_key, 0, s);
    return true;
}

bool table_contains(table_t *one_table, char *one_key)
{
    int index = table_indexof(one_table, one_key);
    return list_contains(one_table->bucket[index], one_key);
}
