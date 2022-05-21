#include"../src/entropy.h"

int main()
{
    printf("importation mots: \n");
    table_t* dico = dico_load("../dico_fr_gutenberg.txt",5);
    printf("Dico importé \n");

    paterns* pat = calc_patern(5);

    dico_t* list_patern = init_dico(dico);
    printf("%d \n",list_patern->size);

    update_entropy(list_patern,pat);

    destroy_patern(pat);
    destroy_dico(list_patern);
    table_destroy(dico);
}
