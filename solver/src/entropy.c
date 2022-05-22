#include"entropy.h"
#include<math.h>

word_t* init_word(char* word){
    word_t* new = calloc(1,sizeof(word_t));
    int len = strlen(word);
    char *keyCopy = calloc(len+1, sizeof(char));
    strcpy(keyCopy, word);
    new->word = keyCopy;
    new->entropy = 0;
    new->next = NULL;
    return new;
    }

void word_prepend(dico_t* dico, char* word){
    word_t* t = (word_t *)calloc(1,sizeof(word_t));
    int len = strlen(word);
    char *keyCopy = calloc(len+1, sizeof(char));
    strcpy(keyCopy, word);
    t->word = keyCopy;
    t->entropy = 0;
    t->next = dico->word;
    dico->word = t;
}

dico_t* init_dico(table_t* dico){
    dico_t* new_dico = calloc(1,sizeof(dico_t));
    new_dico->word = NULL;
    new_dico->size = 0;
    for (int i = 0; i < dico->size; i++)
    {
        list_t* el = dico->bucket[i];
        node_t* sel = el->head;

        while (sel!=NULL)
        {
            word_prepend(new_dico, sel->value->key);
            new_dico->size++;
            sel = sel->next;
        }
        
    }
    return new_dico;
}

void destroy_word(word_t* word){
    free(word->word);
    free(word);
}

void destroy_dico(dico_t* dico){
    word_t *curr_word = dico->word;
    word_t *tmp = NULL;
    while(curr_word)
    {
        tmp = curr_word;
        curr_word = curr_word->next;

        destroy_word(tmp);
    }
    free(dico);
}

void destroy_patern(paterns* one_patern){
    int n = one_patern->size;
    for (int i = 0; i < pow(3,n); i++)
    {      
        free(one_patern->patern[i]);
    }
    free(one_patern->patern);
    free(one_patern);
}

paterns* calc_patern(int n){
    paterns* all_patern = calloc(1, sizeof(paterns));
    all_patern->patern = calloc(pow(3,n),sizeof(int *));
    for (int i = 0; i < pow(3,n); i++)
    {
        int a = i;
        all_patern->patern[i] = calloc(n,sizeof(int));
        for (int j = 0; j < n; j++)
        {
            all_patern->patern[i][j] = a%3;
            a=a/3;
        }
    }  
    all_patern->size = n;  
    return all_patern;
}

int count_same_patern(dico_t* dico,int* patern, char* word, paterns* one_patern){
    word_t* curr = dico->word;
    int count = 0;
    while (curr!=NULL)
    {
        // TO DO: Algo qui compare tout les mots du dico et qui calcul leur patern par rapport a celui qu'on a //
        break;
    }
    return dico->size;
}

double calc_prob_patern(dico_t* dico, int* patern, char* word, paterns* pat){
    int posibilities = count_same_patern(dico,patern,word,pat);
    return posibilities/dico->size;
}

double calc_bit_patern(dico_t* dico,int* patern, long proba_patern, char* word){
    
    return log2(1/proba_patern);

}

double calc_entropy(dico_t* dico, char* word, paterns* pat){
    double entropy = 0;
    int n = strlen(word);
    for (int i = 0; i < pow(3,n); i++)
    {
        double p = calc_prob_patern(dico,pat->patern[i],word,pat);
        entropy = entropy + p*calc_bit_patern(dico,pat->patern[i],p,word);
    }
    return entropy;
}

void update_entropy(dico_t* dico,paterns* pat){
    word_t* curr = dico->word;
    int i = 0;
    while (curr!=NULL)
    {
        i++;
        printf("prog : %d \n",i);
        curr->entropy = calc_entropy(dico,curr->word,pat);
        curr = curr->next;
    }
}