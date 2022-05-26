#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "table.h"
#include "linked_list.h"

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

bool table_is_empty(table_t *one_table)
{
    if (one_table == NULL)
    {
        return true;
    }

    // If all the list in the table are empty, we consider the table empty
    for (int index = 0; index < one_table->size; index++)
    {
        if (!list_is_empty(one_table->bucket[index]))
        {
            return false;
        }
    }

    return true;
}

const char *hash_key = "8e7766f113d6818faafa2241e85295746ddfedc1463c435b52895683d6974ca8";
const int hashOutputSize = 4;
int table_indexof(table_t *one_table, char *one_key)
{

    uint8_t bytesHash[hashOutputSize];

    int wordLength = strlen(one_key);

    halfsiphash(one_key, wordLength, hash_key, bytesHash, hashOutputSize);

    return *(uint32_t *)(bytesHash) % one_table->size;
}

bool table_add(table_t *one_table, char *one_key)
{
    int *s = NULL;

    int ind = table_indexof(one_table, one_key);
    if (list_contains(one_table->bucket[ind], one_key))
    {
        return false;
    }
    list_prepend(one_table->bucket[ind], one_key, 0, s);
    one_table->nb_word++;
    return true;
}

bool table_contains(table_t *one_table, char *one_key)
{
    int index = table_indexof(one_table, one_key);
    return list_contains(one_table->bucket[index], one_key);
}

table_t *table_copy(table_t *one_table)
{
    table_t *new_table = table_create(one_table->size);
    for (int i = 0; i < one_table->size; i++)
    {
        list_t *list = one_table->bucket[i];
        list_t *new_list = list_copy(list);
        new_table->bucket[i] = new_list;
    }
    new_table->nb_word = one_table->nb_word;
    return new_table;
}

void table_remove(table_t *one_table, char *one_key)
{
    int index = table_indexof(one_table, one_key);
    list_remove_key(one_table->bucket[index], one_key);
}

element_t *table_max_entropy(table_t *one_table)
{
    // Given a table, return the element with highest entropy
    int index = 0;
    double maxEntropy = 0;
    element_t *maxElement;

    // if (index > one_table->size)
    // {
    //     return maxElement;
    // }

    for (; index < one_table->size; index++)
    {
        list_t *currentList = one_table->bucket[index];

        // If the list is empty, there's no element
        if (list_is_empty(currentList))
        {
            continue;
        }

        // Get the element with highest entropy in current list
        element_t *currentElement = list_max_entropy(currentList);

        if (maxEntropy < currentElement->entropy)
        {
            maxElement = currentElement;
            maxEntropy = maxElement->entropy;
        }
    }

    return maxElement;
}
