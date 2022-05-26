#include <stdlib.h>
#include <stdio.h>
#include "strat_in_6.h"

#ifndef __ENTROPY__
#define __ENTROPY__

struct _paterns
{
    int **patern;
    int size;
};

typedef struct _paterns paterns;

void destroy_patern(paterns *one_patern);

paterns *init_patern(int n);

void calc_patern(paterns *pat);

int count_same_patern(table_t *dico, int *patern, char *word);

table_t *new_selected_table(table_t *dico, int *patern, char *word);

bool compare_patern(int *patern, char *word, char *word_to_test);

double calc_prob_patern(table_t *dico, int *patern, char *word);

double calc_bit_patern(double proba_patern);

double calc_entropy(table_t *dico, char *word, paterns *pat);

void update_entropy(table_t *dico, paterns *pat);

#endif // __ENTROPY__
