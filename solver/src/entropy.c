#include "entropy.h"
#include <math.h>

void destroy_patern(paterns *one_patern)
{
    int n = one_patern->size;
    for (int i = 0; i < pow(3, n); i++)
    {
        free(one_patern->patern[i]);
    }
    free(one_patern->patern);
    free(one_patern);
}

paterns *init_patern(int n)
{
    paterns *all_patern = calloc(1, sizeof(paterns));
    all_patern->patern = calloc(pow(3, n), sizeof(int *));
    for (int i = 0; i < pow(3, n); i++)
    {
        all_patern->patern[i] = calloc(n, sizeof(int));
    }
    all_patern->size = n;
    return all_patern;
}

void calc_patern(paterns *pat)
{
    for (int i = 0; i < pow(3, pat->size); i++)
    {
        int a = i;
        for (int j = 0; j < pat->size; j++)
        {
            pat->patern[i][j] = a % 3;
            a = a / 3;
        }
    }
}

bool compare_patern(int *pattern, char *word, char *word_to_test)
{
    bool *checked = calloc(strlen(word), sizeof(bool));
    for (size_t i = 0; i < strlen(word); i++) // first pass to eliminate 2s
    {
        if (pattern[i] == 2)
        {
            if (word[i] == word_to_test[i])
            {
                checked[i] = true;
            }
            else
            {
                free(checked);
                return false;
            }
        }
    }
    for (size_t i = 0; i < strlen(word); i++) // second pass to eliminate 1s
    {
        if (pattern[i] == 1)
        {
            bool valid = false;
            for (size_t j = 0; j < strlen(word); j++)
            {
                if (!checked[j] && word[i] == word_to_test[j])
                {
                    if (i == j)
                    {
                        free(checked);
                        return false;
                    }
                    else
                    {
                        checked[j] = true;
                        valid = true;
                        break;
                    }
                }
            }
            if (!valid)
            {
                free(checked);
                return false;
            }
        }
    }
    for (size_t i = 0; i < strlen(word); i++)
    {
        if (pattern[i] == 0)
        {
            for (size_t j = 0; j < strlen(word_to_test); j++)
            {
                if (word[i] == word_to_test[j] && !checked[j])
                {
                    free(checked);
                    return false;
                }
            }
        }
    }
    free(checked);
    return true;
}

int calculate_nb_matches(char *word, int *patern, table_t *dico)
{
    list_t *possibleMatches = list_copy(dico);
    int matches = 0;
    node_t *possibleMatch = possibleMatches->head;
    printf("cc\n");
    while (possibleMatch)
    {
        if (strcmp(possibleMatch->value->key, word))
        {
            matches++;
        }
        bool matchBool = true;
        char *lettersUsed = "";
        for (size_t j = 0; j < strlen(word); j++)
        {
            if (patern[j] == 1)
            {
                char tmp = word[j];
                strncat(lettersUsed, &tmp, 1);
                if (strchr(possibleMatch->value->key, word[j] - 'a') != NULL || word[j] == possibleMatch->value->key[j])
                {
                    matchBool = false;
                    break;
                }
            }
            else if (patern[j] == 2)
            {
                strncat(lettersUsed, &word[j], 1);
                if (word[j] != possibleMatch->value->key[j])
                {
                    matchBool = false;
                    break;
                }
            }
        }
        for (size_t j = 0; j < strlen(word); j++)
        {
            if (strchr(lettersUsed, word[j] - 'a') != NULL)
            {
                continue;
            }
            if (patern[j] == 0)
            {
                if (strchr(possibleMatch->value->key, word[j] - 'a') != NULL)
                {
                    matchBool = false;
                    break;
                }
            }
        }
        if (matchBool)
        {
            matches++;
        }
        possibleMatch = possibleMatch->next;
    }
    return matches;
}

int count_same_patern(table_t *dico, int *patern, char *word)
{
    list_t **lists = dico->bucket;
    int count = 0;
    bool add_count = false;
    for (int i = 0; i < dico->size; i++)
    {
        node_t *curr = lists[i]->head;
        while (curr != NULL)
        {
            if (curr->value != NULL)
            {
                add_count = compare_patern(patern, word, curr->value->key);
                if (add_count)
                {
                    count++;
                }
                add_count = false;
                curr = curr->next;
            }
        }
    }
    return count;
}

table_t *new_selected_table(table_t *dico, int *patern, char *word)
{
    list_t **lists = dico->bucket;
    table_t *new_table = table_create(dico->size);
    bool add_word = false;
    for (int i = 0; i < dico->size; i++)
    {
        node_t *curr = lists[i]->head;
        while (curr != NULL)
        {
            if (curr->value != NULL)
            {
                add_word = compare_patern(patern, word, curr->value->key);
                if (add_word)
                {
                    table_add(new_table, curr->value->key);
                }
                add_word = false;
                curr = curr->next;
            }
        }
    }
    table_destroy(dico);
    return new_table;
}

double calc_prob_patern(table_t *dico, int *patern, char *word)
{
    int posibilities = count_same_patern(dico, patern, word);
    return ((double)posibilities) / ((double)dico->nb_word);
}

double calc_bit_patern(double proba_patern)
{
    if (proba_patern == 0)
    {
        return 0;
    }

    return log2(1 / proba_patern);
}

double calc_entropy(table_t *dico, char *word, paterns *pat)
{
    double entropy = 0;
    int n = strlen(word);
    for (int i = 0; i < pow(3, n); i++)
    {
        double p = calc_prob_patern(dico, pat->patern[i], word);
        entropy = entropy + p * calc_bit_patern(p);
    }
    return entropy;
}

void update_entropy(table_t *dico, paterns *pat)
{
    list_t **lists = dico->bucket;
    for (int i = 0; i < dico->size; i++)
    {
        if (lists[i])
        {
            node_t *curr = lists[i]->head;
            while (curr != NULL)
            {
                curr->value->entropy = calc_entropy(dico, curr->value->key, pat);
                // printf("%f, %s\n", curr->value->entropy, curr->value->key);
                curr = curr->next;
            }
        }
    }
}
