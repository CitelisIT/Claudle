#include <stdbool.h>
#include <stdint.h>
#include "linked_list.h"

#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

const char *hash_key = "8e7766f113d6818faafa2241e85295746ddfedc1463c435b52895683d6974ca8";
const int hashOutputSize = 4;

typedef struct table_t
{
    int size;
    int count;

    list_t** buckets;
} table_t;

int hash(char *some_value);

table_t *table_create(int size);

// Double the size of one_table
void *table_resize(table_t *one_table);

void table_destroy(table_t *one_table);

int table_indexof(table_t *one_table, uint32_t hashCode);

bool table_add(table_t *one_table, element_t *element);

// path MUST be of the form *.txt
void table_add_txt(table_t *one_table, char *path);

bool table_contains(table_t *one_table, int one_key);

char *table_get(table_t *one_table, int one_key);

#endif /* __HASHTABLE_H__ */
