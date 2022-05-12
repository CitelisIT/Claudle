#include "list.h"
#include "table.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char *ALPHABET = "abcdefghijklmnopqrstuvwxyz";

char *getword(list_t *pattern, int size, char *notinword)
{
    char word[256] = "";
    char pool[256] = ""; // initialize the pool
    int j = 0;           // index for the pattern

    while (j < size)
    {
        size_t pool_len = strlen(pool);
        size_t notinword_len = strlen(notinword);
        char newchar = pool[rand() % pool_len]; // Potential replacement

        switch (list_get_value(pattern->head))
        {
        case 2:
            word[j] = list_get_key(pattern->head);
            break;

        case 1:

            while (strchr(notinword, newchar)) // Checks if the new char is in notinword
            {
                newchar = pool[rand() % pool_len];
            }
            word[j] = newchar;
            pool[pool_len + 1] = list_get_key(pattern->head);
            pool[pool_len + 2] = '\0';
            break;

        case 0:
            while (strchr(notinword, newchar)) // Checks if the new char is in notinword
            {
                newchar = pool[rand() % pool_len];
            }
            word[j] = newchar;
            notinword[notinword_len + 1] = list_get_key(pattern->head);
            notinword[notinword_len + 2] = '\0';
            break;

        default:
            break;
        }
        list_remove_first(pattern);
        j++;
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
    char notinword[256] = "abcdefghijklmnopqrtuvwxyz";
    getword(pattern, size, notinword);
    list_destroy(pattern);
    return 0;
}
