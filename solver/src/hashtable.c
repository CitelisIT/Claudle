#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"
#include "halfsiphash.h"

const char *hash_key = "8e7766f113d6818faafa2241e85295746ddfedc1463c435b52895683d6974ca8";
const int hashOutputSize = 4;

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

            list_append(buckets[newIndex], element->key, element->value, element->score);

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
    return hashCode % one_table->size;
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

        list_append(one_table->buckets[index], element->key, element->value, element->score);
        one_table->count++;
        return true;
    }

    halfsiphash(element->value, 5, hash_key, bytesHash, hashOutputSize);
    int index = table_indexof(one_table, *(uint32_t *)(bytesHash));

    if (list_contains(one_table->buckets[index], element->key))
    {
        return false;
    }
    else
    {
        list_append(one_table->buckets[index], element->key, element->value, element->score);
        one_table->count++;
        return true;
    }
}

void table_add_txt(table_t *one_table, char *path)
{
    FILE *file;
    element_t *element = calloc(1, sizeof(element_t));
    char *word;
    size_t length = 0;
    ssize_t read;

    file = fopen(path, "r");

    if(file == NULL)
    {
        // Might want to add an error message
        return;
    }

    while((read = getline(&word, &length, file)) != -1)
    {
        element->key = word;
        element->score = calloc(1, sizeof(int));
        element->value = 0;
        table_add(one_table, element);
    }

    fclose(file);
    if(word)
    {
        free(word);
    }

    return;
}

bool table_contains(table_t *one_table, char *one_key)
{
    uint8_t bytesHash[hashOutputSize];
    // 5 IS TEMPORARY
    halfsiphash(one_key, 5, hash_key, bytesHash, hashOutputSize);

    int index = table_indexof(one_table, *(uint32_t *)(bytesHash));

    return list_contains(one_table->buckets[index], one_key);
}

char *table_get(table_t *one_table, char *one_key)
{
    uint8_t bytesHash[hashOutputSize];
    // 5 IS TEMPORARY
    halfsiphash(one_key, 5, hash_key, bytesHash, hashOutputSize);

    int index = table_indexof(one_table, *(uint32_t *)(bytesHash));

    char val = *(list_find(one_table->buckets[index], one_key));

    return &val;
}
