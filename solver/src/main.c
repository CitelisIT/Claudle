#include "entropy.h"
#include "io.h"

int main()
{
    int word_size = read_word_lengths();

    table_t *dico;
    paterns *pat = init_patern(word_size);
    calc_patern(pat);

    char *proposed_word = "";

    switch (word_size)
    {
    case 4:
        proposed_word = "abdc";
        printf("importation mots: \n");
        table_t *dico4 = dico_load("dictionaries/francais/dico4.txt", word_size);
        printf("Dico importé \n");
        printf("%s\n", proposed_word);
        dico = dico4;
        break;
    case 5:
        proposed_word = "crane";
        printf("importation mots: \n");
        table_t *dico5 = dico_load("dictionaries/francais/dico5.txt", word_size);
        printf("Dico importé \n");
        printf("%s\n", proposed_word);
        dico = dico5;
        break;
    case 6:
        proposed_word = "abdcef";
        printf("importation mots: \n");
        table_t *dico6 = dico_load("dictionaries/francais/dico6.txt", word_size);
        printf("Dico importé \n");
        printf("%s\n", proposed_word);
        dico = dico6;
        break;
    case 7:
        proposed_word = "abdcefg";
        printf("importation mots: \n");
        table_t *dico7 = dico_load("dictionaries/francais/dico7.txt", word_size);
        printf("Dico importé \n");
        printf("%s\n", proposed_word);
        dico = dico7;
        break;
    case 8:
        proposed_word = "abdcefgh";
        printf("importation mots: \n");
        table_t *dico8 = dico_load("dictionaries/francais/dico8.txt", word_size);
        printf("Dico importé \n");
        printf("%s\n", proposed_word);
        dico = dico8;
        break;
    case 9:
        proposed_word = "abdcefghi";
        printf("importation mots: \n");
        table_t *dico9 = dico_load("dictionaries/francais/dico9.txt", word_size);
        printf("Dico importé \n");
        printf("%s\n", proposed_word);
        dico = dico9;
        break;
    case 10:
        proposed_word = "abdcefghij";
        printf("importation mots: \n");
        table_t *dico10 = dico_load("dictionaries/francais/dico10.txt", word_size);
        printf("Dico importé \n");
        printf("%s\n", proposed_word);
        dico = dico10;
        break;

    default:
        break;
    }

    user_input *user_response = create_user_response(word_size);
    update_user_response(user_response, word_size);
    table_t *new_list = new_selected_table(dico, user_response->response, proposed_word);
    update_entropy(new_list, pat);

    element_t *tmp;

    while (!user_response->exited && !user_response->valid)
    {
        if (table_is_empty(new_list))
        {
            printf("pas de mots correspondants =(");
            table_destroy(new_list);
            destroy_user_input(user_response);
            destroy_patern(pat);
            return 0;
        }

        tmp = table_max_entropy(new_list);

        if (!tmp->key)
        {
            printf("pas de mots correspondants =(");
            table_destroy(new_list);
            destroy_user_input(user_response);
            destroy_patern(pat);
            return 0;
        }

        proposed_word = tmp->key;

        printf("%s\n", proposed_word);

        update_user_response(user_response, word_size);

        new_list = new_selected_table(new_list, user_response->response, proposed_word);

        update_entropy(new_list, pat);
    }
    table_destroy(new_list);
    destroy_user_input(user_response);
    destroy_patern(pat);
    return 0;
}
