#include"../src/entropy.h"
#include<math.h>

int main()
{
    printf("importation mots: \n");
    table_t* dico = dico_load("../dictionaries/francais/dico5.txt",5);
    printf("Dico importé \n");

    paterns* pat = init_patern(5);
    calc_patern(pat);

    list_t* liste_patern = list_create();
    for (int i = 0; i < dico->size; i++)
    {
        list_t* el = dico->bucket[i];
        node_t* sel = el->head;

        while (sel!=NULL)
        {
            list_append(liste_patern, sel->value->key, sel->value->entropy, sel->value->score);
            sel = sel->next;
        }
        
    }
    printf("lsite crée \n");
    int s3[5] = {0,0,0,1,0};
    // printf("%f vs %f\n",calc_bit_patern(liste_patern,s3,0.5,"crane"),log2(2));
    
    // double p = calc_prob_patern(liste_patern,s3,"crane",pat);
    // printf("prob = %f\n",p);

    // printf("%d",compare_patern(s3,"crane","couin"));
    update_entropy(liste_patern,pat);

    destroy_patern(pat);
    list_destroy(liste_patern);
    table_destroy(dico);
}
