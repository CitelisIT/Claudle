#include "getwords.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void compute(word_t *pattern, word_t *pool, word_t *goodchar, char *notinword, char *word)
// This function computes :
// - The correct letters in the word and their positions
// - The pool of potential caracters and
// - The notinword array
{
    int pattern_size = word_get_size(pattern);
    int i = 0;
    while (i < pattern_size)
    {
        int notinword_len = strlen(notinword);
        switch (word_get_value(pattern->head))
        {

            {
            case 2:                                                    // Letter is at the right place
                word[i] = word_get_key(pattern->head);                 // Add the letter to the word
                word_append(goodchar, word_get_key(pattern->head), i); // Add the letter to the goodchar list
                break;

            case 1:                                                // Letter is not at the right place but is in the word
                word_append(pool, word_get_key(pattern->head), i); // Add the letter to the pool
                break;

            case 0:                                                     // Letter is not in the word
                notinword[notinword_len] = word_get_key(pattern->head); // Add the letter to the notinword array
                break;

            default:
                break;
            }
        }
        word_remove_first(pattern);
        i++;
    }
}

void suggestion(word_t *pool, word_t *goodchar, char *word, int length)
// This function computes a word suggestion given the pool of potential caracters and the correct letters in the word and their positions

{
    int i = 0;
    while (i < length)
    {
        if (word_find(goodchar, word[i]) == i) // This means that word[i] is a correct letter
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
