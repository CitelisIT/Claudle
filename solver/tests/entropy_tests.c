#include "../src/entropy.h"
#include <math.h>

int main()
{
    printf("importation mots: \n");
    table_t *dico = dico_load("../dictionaries/francais/dico5.txt", 5);
    printf("Dico importé \n");

    paterns *pat = init_patern(5);
    calc_patern(pat);

    printf("lsite crée \n");
    int s3[5] = {0, 0, 0, 1, 0};

    table_t *newtable = new_selected_table(dico, s3, "weary");

    for (int i = 0; i < newtable->size; i++)
    {
        list_print(newtable->bucket[i]);
    }

    printf("Pattern: 00010, Compare: abcde - tydyp\n");
    printf("Result : %d, expected : 1\n", compare_patern(s3, "abcde", "tydyp"));
    int s4[5] = {0, 0, 2, 2, 2};
    printf("Pattern: 00222, Compare: crane - stage\n");
    printf("Result : %d, expected : 0\n", compare_patern(s4, "crane", "stage"));
    int s5[5] = {0, 0, 0, 0, 0};
    printf("Pattern: 00000, Compare: crane - stage\n");
    printf("Result : %d, expected : 0\n", compare_patern(s5, "crane", "stage"));
    int s6[5] = {0, 0, 1, 1, 0};
    printf("Pattern: 00110, Compare: crane - aouts\n");
    printf("Result : %d, expected : 0\n", compare_patern(s6, "crane", "aouts"));
    int s7[5] = {2, 1, 0, 1, 0};
    printf("Pattern: 21010, Compare: sonos - stout\n");
    printf("Result : %d, expected : 0\n", compare_patern(s7, "sonos", "stout"));
    // update_entropy(dico, pat);
    destroy_patern(pat);
    table_destroy(dico);
    table_destroy(newtable);
}
