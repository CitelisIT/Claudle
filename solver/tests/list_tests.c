#include "../src/list.h"
#include <stdlib.h>
#include <stdio.h>
#include "assert.h"

int main()
{
    list_t *pattern = list_create();
    list_append(pattern, 'a', 1);
    list_append(pattern, 'b', 2);
    list_append(pattern, 'c', 2);
    assert(list_get_size(pattern) == 3);
    assert(list_find(pattern, 'a') == 1);
    assert(list_find(pattern, 'b') == 2);
    assert(list_find(pattern, 'c') == 2);
    list_destroy(pattern);
    return 0;
}
