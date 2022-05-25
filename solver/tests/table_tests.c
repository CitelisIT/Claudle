#include <stdlib.h>
#include <stdio.h>
#include "../src/table.h"

int main()
{
    table_t *table = table_create(10);
    printf("Created table\n");
    table_add(table, "hello");
    printf("Added hello\n");
    table_add(table, "world");
    printf("Added world\n");
    table_remove(table, "hello");
    printf("Removed hello\n");
    table_destroy(table);
    printf("Destroyed table\n");
}
