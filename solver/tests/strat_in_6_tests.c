#include"../src/strat_in_6.h"

int main()
{
    char* target = "canne";
    
    printf("hash : %d \n",hash(target));
    char alph[26] = "abcdefghijklmnopqrstuvwxyz";
    int length = 0;
    printf("Enter length : ");
    scanf("%d", &length);
    char word[256] = "";
    int i = 0;
    while (i < length) // We initialize the word as a random string
    {
        word[i] = alph[rand() % 26];
        i++;
    }
    word[i] = '\0';
    list_t* wordmet = list_create();
    
    printf("importation mots: \n");
    table_t* dico = dico_load("../dico_fr_gutenberg.txt");
    printf("Dico importé \n");


    int s1[5] = {0,0,0,0,0};
    int s2[5] = {0,2,0,0,0};
    int s3[5] = {0,0,0,1,0};
    int s4[5] = {2,0,0,2,0};
    int s5[5] = {0,0,0,0,0};

    board * ba = init_board(length);
    

    printf("ajout liste de mots testés \n");

    list_append(wordmet,"fjord","test1",s1);
    change_board(ba,s1,"fjord");
    list_append(wordmet,"waltz","test2",s2);
    change_board(ba,s2,"waltz");
    list_append(wordmet,"vibex","test3",s3);
    change_board(ba,s3,"vibex");
    list_append(wordmet,"chunk","test4",s4);
    change_board(ba,s4,"chunk");
    list_append(wordmet,"gymps","test5",s5);
    change_board(ba,s5,"gymps");
    
    printf("calcul du mot final \n");
    

    

    print_board(ba);
    int n = ba->size;
    char *final_word= getfinalword(dico,ba);

    printf("%s ?= %s",target, final_word);

    

    free(final_word);

    table_destroy(dico);
    list_destroy(wordmet);
    destroy_board(ba);
}
