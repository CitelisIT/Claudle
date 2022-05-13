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

    table->buckets = calloc(size, sizeof(list_t));

    return table;
}

void *table_resize(table_t *one_table)
{
    int newSize = 2 * one_table->size;

    list_t *buckets = calloc(newSize, sizeof(list_t));

    for(int i = 0; i < one_table->size; i++)
    {
        list_t *bucket = &one_table->buckets[i];
        node_t *current = bucket->head;

        // Get new index for current bucket
        while(current != NULL)
        {
            element_t *element = current->value;
            int newIndex = hash(element->key) % newSize;

            list_append(&buckets[newIndex], element->key, element->value);

            current = current->next;
        }

        free(&bucket);
    }

    free(one_table->buckets);

    one_table->buckets = buckets;
    one_table->size = newSize;
}

void table_destroy(table_t *one_table)
{
    if(one_table == NULL)
    {
        return;
    }

    for(int i = 0; i < one_table->size; i++)
    {
        list_destroy(&one_table->buckets[i]);
    }
    free(one_table->buckets);
}

int table_indexof(table_t *one_table, char one_key)
{
    return hash(one_key) % one_table->size;
}

bool table_add(table_t *one_table, char one_key, int one_value)
{
    if(one_table->count == one_table->size)
    {
        // TODO: resize table
        return false;
    }

    int index = table_indexof(one_table, one_key);

    if (list_contains(&one_table->buckets[index], one_key))
    {
        return false;
    }
    else
    {
        list_append(&one_table->buckets[index], one_key, one_value);
        one_table->count++;
        return true;
    }
}

bool table_contains(table_t *one_table, char one_key)
{
    int index = table_indexof(one_table, one_key);

    return list_contains(&one_table->buckets[index], one_key);
}

int table_get(table_t *one_table, char one_key)
{
    int index = table_indexof(one_table, one_key);
<<<<<<< HEAD:solver/src/table.c
    int val = (list_find(one_table->sublist[index], one_key));
=======

    char *val = *(list_find(&one_table->buckets[index], one_key));

>>>>>>> sd:solver/table.c
    return val;
}