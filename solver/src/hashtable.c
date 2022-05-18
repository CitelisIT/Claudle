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

    list_t **buckets = calloc(newSize, sizeof(list_t*));

    uint8_t bytesHash[hashOutputSize];

    for (int i = 0; i < one_table->size; i++)
    {
        list_t *bucket = one_table->buckets[i];
        node_t *current = bucket->head;

        // Get new index for current bucket
        while (current != NULL)
        {
            element_t *element = current->value;

            // Get new index of the word
            // 5 IS TEMPORARY -- CHANGE IN FINAL IMPLEMENTATION
            halfsiphash(element->value, 5, hash_key, bytesHash, hashOutputSize);
            int newIndex = *(uint32_t *)(bytesHash) % newSize;

            list_append(buckets[newIndex], element->key, element->value);

            current = current->next;
        }

        free(bucket);
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
        list_destroy(one_table->buckets[i]);
    }
    free(one_table->buckets);
}

int table_indexof(table_t *one_table, uint32_t hashCode)
{
    return *hashCode % one_table->size;
}

bool table_add(table_t *one_table, element_t *element)
{
    uint8_t bytesHash[hashOutputSize];

    if (one_table->count == one_table->size)
    {
        table_resize(one_table);

        // 5 IS TEMPORARY -- CHANGE IN THE FINAL IMPLEMENTATION
        halfsiphash(element->value, 5, hash_key, bytesHash, hashOutputSize);
        int index = table_indexof(one_table, *(uint32_t *)(bytesHash));

        list_append(&one_table->buckets[index], element->key, element->value);
        one_table->count++;
        return true;
    }

    halfsiphash(element->value, 5, hash_key, bytesHash, hashOutputSize);
    int index = table_indexof(one_table, *(uint32_t *)(bytesHash));

<<<<<<< HEAD
    if (list_contains(&one_table->buckets[index], *element->key))
=======
    if (list_contains(one_table->buckets[index], one_key))
>>>>>>> 692779aac6f7a892a90c3d1ec87f0d65e011c92c
    {
        return false;
    }
    else
    {
<<<<<<< HEAD
        list_append(&one_table->buckets[index], element->key, element->value);
=======
        list_append(one_table->buckets[index], one_key, one_value);
>>>>>>> 692779aac6f7a892a90c3d1ec87f0d65e011c92c
        one_table->count++;
        return true;
    }
}

void table_add_txt(table_t *one_table, char *path)
{
    FILE *file = fopen(path, "r");
    element_t *element = calloc(1, sizeof(element_t));
    int tempKey = 0;

    if(file != NULL)
    {
        while(!feof(file))
        {
            element->key = &tempKey;

            // The 5 is a temp value, in the final implementation
            // it'll take the word list word length
            element->value = fgetc(file);

            table_add(one_table, element);

            tempKey++;
        }
    }
    return;
}

bool table_contains(table_t *one_table, int one_key)
{
    int index = table_indexof(one_table, one_key);

    return list_contains(one_table->buckets[index], one_key);
}

char *table_get(table_t *one_table, int one_key)
{
    int index = table_indexof(one_table, one_key);

    char *val = *(list_find(one_table->buckets[index], one_key));

    return val;
}