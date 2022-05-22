#include <stdlib.h>
#include <stdio.h>
#include"dico.h"

#ifndef __ENTROPY__
#define __ENTROPY__


struct _word_t
{
    char * word;
    long entropy;
    struct _word_t* next;
};

typedef struct _word_t word_t;

struct _dico_t
{
    struct _word_t* word;
    int size;
};

typedef struct _dico_t dico_t;

struct _paterns
{
    int ** patern;
    int size;
};

typedef struct _paterns paterns;

word_t* init_word(char* word);

void destroy_dico(dico_t* dico);

void destroy_word(word_t* word);

dico_t* init_dico(table_t* dico);

void word_prepend(dico_t* dico, char* word);

void destroy_patern(paterns* one_patern);

paterns* calc_patern(int n);

int count_same_patern(dico_t* dico,int* patern, char* word, paterns* one_patern);

double calc_prob_patern(dico_t* dico, int* patern, char* word, paterns* pat);

double calc_bit_patern(dico_t* dico, int* patern, long proba_patern, char* word);

double calc_entropy(dico_t* dico, char* word, paterns* pat);

void update_entropy(dico_t* dico,paterns* pat);



#endif // __ENTROPY__
