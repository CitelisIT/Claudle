#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "io.h"

int *get_hints(size_t word_size)
{
    // Get input from user as a single string and ensure it contains only 0, 1 and 2
    // Keep getting input from user until it is valid
    char *input = (char *)calloc(word_size + 1, sizeof(char));
    char c;
    bool valid = false;
    error_t *error = (error_t *)calloc(1, sizeof(error_t));
    do
    {
        printf("Entrez les indices donnés par le jeu : ");
        fgets(input, word_size + 1, stdin);
        valid = validate_input(input, word_size, error);
        while ((c = getchar()) != '\n' && c != EOF)
        {
            error->invalid_size = true;
            valid = false;
        }
        if (!valid)
        {
            if (error->invalid_char)
            {
                printf("\x1b[1m\x1b[31mEntrez uniquement des 0, 1 et 2\x1b[0m\n");
            }
            else if (error->invalid_size)
            {
                printf("\x1b[1m\x1b[31mEntrez exactement %zu chiffres\x1b[0m\n", word_size);
            };
        }
        error->invalid_char = false;
        error->invalid_size = false;
    } while (!valid);

    // Convert the string to an array of ints
    int *hints = (int *)malloc(sizeof(int) * word_size);
    for (size_t i = 0; i < word_size; i++)
    {
        hints[i] = input[i] - '0';
    }

    free(input);
    free(error);
    return hints;
}

bool validate_input(char *input, size_t word_size, error_t *error)
{
    // ensure input is a string of 0, 1 and 2
    // ensure input is of length word_size
    // return true if input is valid

    for (size_t i = 0; i < word_size; i++)
    {
        if (input[i] != '0' && input[i] != '1' && input[i] != '2')
        {
            error->invalid_char = true;
            return false;
        }
    }
    if (strlen(input) < word_size)
    {
        error->invalid_size = true;
        return false;
    }
    return true;
}
