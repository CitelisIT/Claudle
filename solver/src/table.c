#include <stdlib.h>
#include <stdio.h>
#include "table.h"

int hash(char *some_value)
{
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
    table->sublist = calloc(size, sizeof(list_t *));
    for (int i = 0; i < size; i++)
    {
        table->sublist[i] = list_create();
    }
    return table;
}

void table_destroy(table_t *one_table)
{
    int i = 0;
    for (i = 0; i < one_table->size; i++)
    {
        list_destroy(one_table->sublist[i]);
    }
    free(one_table->sublist);
    free(one_table);
}

int table_indexof(table_t *one_table, char *one_key)
{
    return hash(one_key) % one_table->size;
}

bool table_add(table_t *one_table, char *one_key, char *one_value)
{
    int index = table_indexof(one_table, one_key);
    if (list_contains(one_table->sublist[index], one_key))
    {
        return false;
    }
    else
    {
        list_append(one_table->sublist[index], one_key, one_value);
        return true;
    }
}

bool table_contains(table_t *one_table, char *one_key)
{
    int index = table_indexof(one_table, one_key);
    return list_contains(one_table->sublist[index], one_key);
}

char *table_get(table_t *one_table, char *one_key)
{
    int index = table_indexof(one_table, one_key);
    char *val = *(list_find(one_table->sublist[index], one_key));
    return val;
}
