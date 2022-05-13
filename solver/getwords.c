#include "getwords.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char *ALPHABET = "abcdefghijklmnopqrstuvwxyz";

void compute(list_t *pattern, list_t *pool, list_t *goodchar, char *notinword, char *word)
// This function computes :
// - The correct letters in the word and their positions
// - The pool of potential caracters and
// - The notinword array
{
    int pattern_size = list_get_size(pattern);
    int i = 0;
    while (i < pattern_size)
    {
        int notinword_len = strlen(notinword);
        switch (list_get_value(pattern->head))
        {

            {
            case 2:                                                    // Letter is at the right place
                word[i] = list_get_key(pattern->head);                 // Add the letter to the word
                list_append(goodchar, list_get_key(pattern->head), i); // Add the letter to the goodchar list
                break;

            case 1:                                                // Letter is not at the right place but is in the word
                list_append(pool, list_get_key(pattern->head), i); // Add the letter to the pool
                break;

            case 0:                                                     // Letter is not in the word
                notinword[notinword_len] = list_get_key(pattern->head); // Add the letter to the notinword array
                break;

            default:
                break;
            }
        }
        list_remove_first(pattern);
        i++;
    }
}

void suggestion(list_t *pool, list_t *goodchar, char *word, int length)
// This function computes a word suggestion given the pool of potential caracters and the correct letters in the word and their positions

{
    int i = 0;
    while (i < length)
    {
        if (list_find(goodchar, word[i]) == i) // This means that word[i] is a correct letter
        {
        }
        else // We have to find a new letter from the pool
        {
            // TODO : Find a new letter from the pool and replace word[i] with it
            // Attention : Do not select a letter from the pool where letter->value == i ! (This means that the letter is not here)
        }
        i++;
    }
}

int main() // Some tests : need to be moved into a test file
{
    int length = 0;
    printf("Enter length : ");
    scanf("%d", &length);
    char word[256] = "";
    int i = 0;
    while (i < length) // We initialize the word as a random string
    {
        word[i] = ALPHABET[rand() % 26];
        i++;
    }
    word[i] = '\0';
    printf("%s \n", word);
    char notinword[256] = "";
    list_t *pattern1 = list_create();
    list_t *pattern2 = list_create();
    list_t *pattern3 = list_create();
    list_t *pattern4 = list_create();
    list_t *pattern5 = list_create();
    list_t *pool = list_create();
    list_t *goodchar = list_create();
    list_append(pattern1, 'g', 1);
    list_append(pattern1, 'l', 2);
    list_append(pattern1, 'e', 0);
    list_append(pattern1, 'n', 2);
    list_append(pattern1, 't', 0);
    compute(pattern1, pool, goodchar, notinword, word);
    list_destroy(pattern1);
    list_append(pattern2, 'b', 0);
    list_append(pattern2, 'r', 0);
    list_append(pattern2, 'i', 0);
    list_append(pattern2, 'c', 0);
    list_append(pattern2, 'k', 0);
    compute(pattern2, pool, goodchar, notinword, word);
    list_destroy(pattern2);
    list_append(pattern3, 'j', 0);
    list_append(pattern3, 'u', 1);
    list_append(pattern3, 'm', 0);
    list_append(pattern3, 'p', 0);
    list_append(pattern3, 'y', 0);
    compute(pattern3, pool, goodchar, notinword, word);
    list_destroy(pattern3);
    list_append(pattern4, 'v', 0);
    list_append(pattern4, 'o', 0);
    list_append(pattern4, 'z', 0);
    list_append(pattern4, 'h', 0);
    list_append(pattern4, 'd', 0);
    compute(pattern4, pool, goodchar, notinword, word);
    list_destroy(pattern4);
    list_append(pattern5, 'w', 0);
    list_append(pattern5, 'a', 0);
    list_append(pattern5, 'q', 0);
    list_append(pattern5, 'f', 0);
    list_append(pattern5, 's', 1);
    compute(pattern5, pool, goodchar, notinword, word);
    list_destroy(pattern5);
    printf("POOL : ");
    int j = 0;
    int pool_len = list_get_size(pool);
    while (j < pool_len)
    {
        printf("%c", list_get_key(pool->head));
        list_remove_first(pool);
        j++;
    }
    printf("\n");
    int k = 0;
    int goodchar_len = list_get_size(goodchar);
    while (k < goodchar_len)
    {
        printf("%c : %d \n", list_get_key(goodchar->head), list_get_value(goodchar->head));
        list_remove_first(goodchar);
        k++;
    }
    suggestion(pool, goodchar, word, length);
    printf("%s \n", word);
    list_destroy(pool);
    list_destroy(goodchar);

    return 0;
}
