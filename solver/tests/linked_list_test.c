#include <stdio.h>
#include "../src/linked_list.h"

int main()
{
    char *word1 = "aaaaa";
    double value1 = 1;
    int score1[5] = {1, 0, 1, 1, 0};
    int *score1_pt = &score1[0];

    char *word2 = "bbb";
    double value2 = 2;
    int score2[5] = {1, 0, 0, 0, 0};
    int *score2_pt = score2;

    char *word3 = "ccc";
    double value3 = 33;
    int score3[5] = {2, 2, 0, 2, 2};
    int *score3_pt = score3;

    char *word4 = "ddd";
    double value4 = 4;
    int score4[5] = {2, 2, 0, 0, 0};
    int *score4_pt = score4;



    list_t *one_list = list_create();

    list_append(one_list, word1, value1, score1);
    list_append(one_list, word2, value2, score2);
    list_append(one_list, word3, value3, score3);
    list_append(one_list, word4, value4, score4);    
    list_remove_key(one_list,word4);

    list_print(one_list);

//    double getEntropy1 = list_find(one_list, word1);
//    double getEntropy2 = list_find(one_list, word2);
//    double getEntropy4 = list_find(one_list, word4);
//
//    printf("The entropy of word1, 2 and 4 are: %s, %s, %s, respectively\n", 
//    getEntropy1, getEntropy2, getEntropy4); 

    char *wrongWord = "loa";

    printf("%s is in the list: %d\n", wrongWord, list_contains(one_list, wrongWord));
    printf("%s is in the list: %d\n", word1, list_contains(one_list, word1));

    element_t *maxElem = list_max_entropy(one_list);

    printf("%f", maxElem->entropy);

    list_destroy(one_list);
}
