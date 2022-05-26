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

    printf("%d", compare_patern(s3, "abcde", "tydyp"));
    // update_entropy(dico, pat);
    destroy_patern(pat);
    table_destroy(dico);
    table_destroy(newtable);
}
