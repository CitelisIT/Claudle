#include"strat_in_6.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

char* alpabet = "abcdefghijklmnopqrstuvwxyz";

board *init_board(int len){
    board * b = calloc(1,sizeof(board));
    b->size = len;
    b->scores = calloc(26,sizeof(int*));
    for (size_t a = 0; a < 26; a++)
    {
        b->scores[a] = calloc(len,sizeof(int));
    }
    return b;    
}

void change_board(board *current,int *colors,char * word){
    for (int i = 0; i < current->size; i++)
    {
        int a = word[i] - 'a';
        current->scores[a][i] = colors[i];
    }
}

void destroy_board(board* b){
    for (size_t a = 0; a < 26; a++)
    {
        free(b->scores[a]);
    }
    free(b->scores);
    free(b);
}

void print_board(board *current){
    for (int i = 0; i < current->size; i++)
    {
        for (int a = 0; a < 26; a++)
        {
            printf("%d  ",current->scores[a][i]);    
        }
        printf("\n");
    }
    
}

char* letter_met(list_t* previous_tries){
    node_t* t = previous_tries->head;
    char* letter_met = "";
    if (t==NULL)
    {
        return "";
    }
    char * l;
    while (t != NULL) 
    {   
        l = t->value->key;
        for (size_t i = 0; i < strlen(l); i++)
        {
            for (size_t j = 0; j < strlen(letter_met); j++)
            {
                if (letter_met[j] != l[i])
                {
                    letter_met = letter_met + l[i];
                }
            }
            
            
        }
        t = t->next;
        
    }
    return letter_met;
}

char * getnewword(table_t* dico, list_t* previous_tries,int n){
    printf("%d",dico->size);
    for (int i = 0; i < dico->size; i++)
    {  
        node_t *word = (dico->bucket[i])->head;
        char* letters_met = letter_met(previous_tries);
        bool return_word = false;
        while (word!=NULL)
        {
            element_t *str = word->value;
                if (strcmp(letters_met,str->key)==NULL ){
                    return_word = true;      
                }
                else
                {
                    return_word = false;
                }   
            }
            word = word->next;
        if (return_word)
        {
            return word->value->key;
        }
    }   
    return NULL;
}




char * getfinalword(table_t* dico, board* b){
    int n = b->size;
    char * word = calloc(n+1,sizeof(char));
    for (size_t a = 0; a < n; a++)
    {
        word[a] = '$';
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int l = b->scores[i][j];
            if (l==2 || l==1)
            {
                for (int a = 0; a < n; a++)
                {
                    if (word[a]=='$')
                    {
                        word[a] = alpabet[i];
                        break;
                    }
                }
            }
        }
    }

    char * fword = calloc(n+1,sizeof(char));
    for (size_t a = 0; a < n; a++)
    {
        fword[a] = '$';
    }
    
    for (size_t i = 0; i < strlen(word); i++)
    {
        for (int j = 0; j < n; j++)
        {
            int k = word[i]-'a';
            if (k != '$'-'a')
            {
                if (b->scores[k][j] == 2)
            {
                fword[j]=word[i];
            }
            }
            
                
        }
    }
    bool ret_word = false;
    char * tmpword = calloc(n+1,sizeof(char));
    for (size_t a = 0; a < n; a++)
    {
        tmpword[a] = fword[a];
    }   
    while(!ret_word)
    {
        for (int i = 0; i < n; i++)
        {
            
            for (int j = 0; j < n; j++)
            {
                if (fword[j]=='$')
                {
                    tmpword[j]=word[(i+j)%n];
                }
            }
            
            ret_word = table_contains(dico,tmpword);
            if (ret_word)
            {
                free(fword);
                free(word);
                return tmpword;
            }   
            strcpy(tmpword,fword);            
        }
    }        
    free(fword);
    free(word);
    return tmpword;
}