#include "list.h"
#include "table.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char *ALPHABET = "abcdefghijklmnopqrstuvwxyz";

char *getword(list_t *pattern, int size, char *notinword)
{
    char word[] = "test";
    char pool[256] = "test"; // initialize the pool
    int i = 0;               // index for the pattern

    while (i < size)
    {
        size_t pool_len = strlen(pool);

        switch (list_get_value(pattern->head))
        {
        case 2:
            word[i] = list_get_key(pattern->head);
            break;

        case 1:
            word[i] = pool[rand() % pool_len];
            pool[pool_len + 1] = list_get_key(pattern->head);
            pool[pool_len + 2] = '\0';
            break;

        case 0:
            word[i] = pool[rand() % pool_len];
            pool[pool_len + 1] = list_get_key(pattern->head);
            pool[pool_len + 2] = '\0';
            break;

        default:
            break;
        }
        list_remove_first(pattern);
        i++;
    }
    printf("%s\n", word);
}

int main()
{
    list_t *pattern = list_create();
    list_append(pattern, 'l', 2);
    list_append(pattern, 'o', 1);
    list_append(pattern, 'v', 0);
    list_append(pattern, 'e', 2);
    int size = list_get_size(pattern);
    char *notinword = ""; // Unused yet
    getword(pattern, size, notinword);
    list_destroy(pattern);
    return 0;
}
