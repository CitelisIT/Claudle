#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"
#include "halfsiphash.h"


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

    for (int i = 0; i < one_table->size; i++)
    {
        list_t *bucket = &one_table->buckets[i];
        node_t *current = bucket->head;

        // Get new index for current bucket
        while (current != NULL)
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
    if (one_table == NULL)
    {
        return;
    }

    for (int i = 0; i < one_table->size; i++)
    {
        list_destroy(&one_table->buckets[i]);
    }
    free(one_table->buckets);
}

int table_indexof(table_t *one_table, int *one_key)
{
    return one_key % one_table->size;
}

bool table_add(table_t *one_table, char *one_key, char *one_value)
{
    if (one_table->count == one_table->size)
    {
        table_resize(one_table);

        list_append(&one_table->buckets[index], one_key, one_value);
        one_table->count++;
        return true;
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

void table_add_txt(table_t *one_table, char *path)
{
    FILE *file = fopen(path, "r");
    element_t *pair = calloc(1, sizeof(element_t));

    if(file != NULL)
    {
        while(word = fgetc(file))
        {
            if(word == EOF)
            {
                break;
            }
            // The 5 is a temp value, in the final implementation
            // it'll take the word list word length
            halfsiphash(word, 5, hash_key, hashCode, 4);
            table_add(one_table, hashCode, word);
        }
    }
    return;
}

bool table_contains(table_t *one_table, char *one_key)
{
    int index = table_indexof(one_table, one_key);

    return list_contains(&one_table->buckets[index], one_key);
}

char *table_get(table_t *one_table, char *one_key)
{
    int index = table_indexof(one_table, one_key);

    char *val = *(list_find(&one_table->buckets[index], one_key));

    return val;
}