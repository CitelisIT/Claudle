#ifndef __STRAT_IN_6__
#define __STRAT_IN_6__
#include<stdbool.h>
#include<string.h>
#include"dico.h"

struct _board
{
    int ** scores;
    int size;
};

typedef struct _board board;

board *init_board(int len);

void change_board(board * current, int* colors, char * word);

void destroy_board(board* b);

void print_board(board *current);

char *element_to_char(element_t *one_word);

element_t *char_to_word(char *one_word);

char* letter_met(list_t* previous_tries);

char * getnewword(table_t* dico, list_t* previous_tries,int n);

char * getfinalword(table_t* dico, board* b);







#endif