#include <stdio.h>
#include "../src/hashtable.h"

int main()
{
    table_t *one_table = table_create(8);

    char *word1 = "aaaaa";
    long value1 = 2.;
    int score1[5] = {1, 0, 1, 1, 0};
    int *score1_pt = &score1[0];

    element_t *elem1 = element_create(word1, value1, score1_pt);

//    char *word2 = "bbb";
//    char *value2 = "b";
//    int score2[3] = {1, 0, 0};
//    int *score2_pt = score2;
//
//    char *word3 = "ccc";
//    char *value3 = "c";
//    int score3[3] = {2, 2, 0};
//    int *score3_pt = score3;
//
//    char *word4 = "ddd";
//    char *value4 = "d";
//    int score4[3] = {2, 2, 0};
//    int *score4_pt = score4;

    table_add(one_table, elem1);

    printf("%d", table_contains(one_table, word1));
    element_destroy(elem1);
    table_destroy(one_table);
}
