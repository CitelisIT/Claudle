#include <stdio.h>
#include "../src/linked_list.h"

int main()
{
    char *word1 = "aaa";
    char *value1 = "a";
    int score1[3] = {1, 0, 1};
    int *score1_pt = &score1[0];

    char *word2 = "bbb";
    char *value2 = "b";
    int score2[3] = {1, 0, 0};
    int *score2_pt = score2;

    char *word3 = "c";
    char *value3 = "c";
    int score3[3] = {2, 2, 0};
    int *score3_pt = score3;

    char *word4 = "c";
    char *value4 = "c";
    int score4[3] = {2, 2, 0};
    int *score4_pt = score4;

    element_t *element1 = element_create(word1, value1, score1_pt);
    node_t *node1 = node_create(element1);

    element_t *element2 = element_create(word2, value2, score2_pt);
    node_t *node2 = node_create(element2);

    element_t *element3 = element_create(word3, value3, score3_pt);
    node_t *node3 = node_create(element3);

    element_t *element4 = element_create(word4, value4, score4_pt);
    node_t *node4 = node_create(element4);

    list_t *one_list = list_create();

    list_append(one_list, element1->key, element1->value, element1->score);
    list_append(one_list, element2->key, element2->value, element2->score);
    list_append(one_list, element3->key, element3->value, element3->score);
    list_append(one_list, element4->key, element4->value, element4->score);

    list_print(one_list);

    // First in last out
    list_destroy(one_list);

    node_destroy(node1);
    node_destroy(node2);
    node_destroy(node3);
    node_destroy(node4);

    element_destroy(element1);
    element_destroy(element2);
    element_destroy(element3);
    element_destroy(element4);
}
