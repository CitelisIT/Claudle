#include <stdio.h>
#include "../src/hashtable.h"

int main()
{
    table_t *one_table = table_create(8);

    element_t *elem1 = element_create(1, "aaa");
    element_t *elem2 = element_create(2, "abc");
    element_t *elem3 = element_create(3, "bbb");
    element_t *elem4 = element_create(4, "ccc");

    table_add(one_table, elem1);

    printf("%d", table_contains(one_table, 1));
}