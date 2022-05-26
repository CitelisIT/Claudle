#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "io.h"

user_input *get_hints(size_t word_size)
{
    // Get input from user as a single string and ensure it contains only 0, 1 and 2
    // Keep getting input from user until it is valid
    user_input *resp = calloc(1, sizeof(user_input));
    char *input = (char *)calloc(word_size + 1, sizeof(char));
    resp->response = calloc(word_size, sizeof(int));
    char c;
    bool valid = false;
    error_t *error = (error_t *)calloc(1, sizeof(error_t));
    do
    {
        printf("Entrez les indices donnés par le jeu : ");
        fgets(input, word_size + 1, stdin);
        valid = validate_input(input, word_size, error);
        if (!valid)
        {
            if (error->exited)
            {
                printf("\x1b[1mJeu terminé, à bientôt :)\x1b[0m\n");
                resp->exited = true;
                free(input);
                free(error);
                return resp;
            }
            else if (error->invalid_char)
            {
                printf("\x1b[1m\x1b[31mEntrez uniquement des 0, 1 et 2\x1b[0m\n");
            }
            else if (error->invalid_size)
            {
                printf("\x1b[1m\x1b[31mEntrez exactement %zu chiffres\x1b[0m\n", word_size);
            };
        }
        while ((c = getchar()) != '\n' && c != EOF)
        {
            error->invalid_size = true;
            valid = false;
        }
        error->invalid_char = false;
        error->invalid_size = false;
    } while (!valid);

    // Convert the string to an array of ints
    resp->valid = true;
    for (size_t i = 0; i < word_size; i++)
    {
        resp->response[i] = input[i] - '0';
        if (resp->response[i] != 2)
        {
            resp->valid = false;
        }
    }

    free(input);
    free(error);
    return resp;
}

bool validate_input(char *input, size_t word_size, error_t *error)
{
    // ensure input is a string of 0, 1 and 2
    // ensure input is of length word_size
    // return true if input is valid

    if (strcmp(input, "-1\n") == 0)
    {
        error->exited = true;
        return false;
    }

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

int read_word_lengths()
{
    FILE *file = fopen("wsolf.txt", "r");
    if (file == NULL)
    {
        printf("\x1b[1m\x1b[31mImpossible d'ouvrir le fichier wsolf.txt\x1b[0m\n");
        return NULL;
    }

    int n;

    fscanf(file, "%d\n", &n);

    fclose(file);
    return n;
}

void destroy_user_input(user_input *input)
{
    free(input->response);
    free(input);
}