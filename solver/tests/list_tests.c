#include "../src/list.h"
#include <stdlib.h>
#include <stdio.h>
#include "assert.h"

int main()
{
    printf("creation");
    list_t *pattern = list_create();
    printf("créé");
    word_t* crane = char_to_word("crane");
    word_t* slate = char_to_word("slate");
    word_t* query = char_to_word("query");
    list_append(pattern, crane);
    list_append(pattern, slate);
    list_append(pattern, query);
    assert(list_get_size(pattern) == 3);
    list_destroy(pattern);
    return 0;
}
