#include"entropy.h"
#include<math.h>

void destroy_patern(paterns* one_patern){
    int n = one_patern->size;
    for (int i = 0; i < pow(3,n); i++)
    {      
        free(one_patern->patern[i]);
    }
    free(one_patern->patern);
    free(one_patern);
}

paterns* init_patern(int n){
    paterns* all_patern = calloc(1, sizeof(paterns));
    all_patern->patern = calloc(pow(3,n),sizeof(int *));
    for (int i = 0; i < pow(3,n); i++)
    {
        all_patern->patern[i] = calloc(n,sizeof(int));
    }  
    all_patern->size = n;  
    return all_patern;
}

void calc_patern(paterns* pat){
    for (int i = 0; i < pow(3,pat->size); i++)
    {
        int a = i;
        for (int j = 0; j < pat->size; j++)
        {
            pat->patern[i][j] = a%3;
            a=a/3;
        }
    }
}

bool compare_patern(int* patern,char* word,char* word_to_test){
    bool ok = false;
    
    for (int i = 0; i < strlen(word); i++)
    {
        int j = 0;
        switch (patern[i])
        {
        case 2: 
            ok = (word[i] == word_to_test[i]);
            break;
        case 1:
            while (j < strlen(word) && word[i]!=word_to_test[j])
            {   
                j++;
            }
            ok = (word[i]==word[j]);
            break;
        case 0:
            while (j < strlen(word) && word[i]!=word_to_test[j])
            {
                j++;
            }
            ok = (word[i]!=word[j]);
            break;
        default:

            break;
        }
        if (!ok)
        {
            return ok;
        } 
    }
    return ok;
}

int count_same_patern(list_t* dico,int* patern, char* word){
    node_t* curr = dico->head;
    int count = 0;
    bool add_count = false;
    while (curr->next!=NULL)
    {
        add_count = compare_patern(patern,word,curr->value->key);
        if (add_count)
        {
            count++;
        }
        add_count = false;
        curr = curr->next;
        
    }
    return count;
}

double calc_prob_patern(list_t* dico, int* patern, char* word, paterns* pat){
    int posibilities = count_same_patern(dico,patern,word);
    return posibilities/dico->size;
}

double calc_bit_patern(list_t* dico,int* patern, double proba_patern, char* word){
    return log2(1/proba_patern);

}

double calc_entropy(list_t* dico, char* word, paterns* pat){
    double entropy = 0;
    int n = strlen(word);
    for (int i = 0; i < pow(3,n); i++)
    {
        double p = calc_prob_patern(dico,pat->patern[i],word,pat);
        entropy = entropy + p*calc_bit_patern(dico,pat->patern[i],p,word);
    }
    return entropy;
}

void update_entropy(list_t* dico,paterns* pat){
    node_t* curr = dico->head;
    while (curr!=NULL)
    {
        curr->value->entropy = calc_entropy(dico,curr->value->key,pat);
        printf("prog : %f \n",curr->value->entropy);
        curr = curr->next;
    }
}