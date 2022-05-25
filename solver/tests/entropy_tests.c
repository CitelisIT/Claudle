#include"../src/entropy.h"
#include<math.h>

int main()
{
    printf("importation mots: \n");
    table_t* dico = dico_load("../dictionaries/francais/dico5.txt",5);
    printf("Dico importé \n");

    paterns* pat = init_patern(5);
    calc_patern(pat);

    
    printf("lsite crée \n");
    // int s3[5] = {0,0,0,1,0};
    // printf("%f vs %f\n",calc_bit_patern(liste_patern,s3,0.5,"crane"),log2(2));
    
    // double p = calc_prob_patern(liste_patern,s3,"crane",pat);
    // printf("prob = %f\n",p);

    // printf("%d",compare_patern(s3,"crane","couin"));
    update_entropy(dico,pat);
    printf("fin ^^");
    destroy_patern(pat);
    table_destroy(dico);
}
