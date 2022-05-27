#include "entropy.h"
#include "io.h"

int main()
{
    int word_size = read_word_lengths();

    if (word_size == -1)
    {
        return 1;
    }

    table_t *dico = NULL;
    paterns *pat = init_patern(word_size);
    calc_patern(pat);

    char *proposed_word = "";

    printf("Importation des mots...\n");

    switch (word_size)
    {
    case 4:
        proposed_word = "seau";
        table_t *dico4 = dico_load("dictionaries/francais/dico4.txt", word_size);
        dico = dico4;
        break;
    case 5:
        proposed_word = "pares";
        table_t *dico5 = dico_load("dictionaries/francais/dico5.txt", word_size);
        dico = dico5;
        break;
    case 6:
        proposed_word = "castre";
        table_t *dico6 = dico_load("dictionaries/francais/dico6.txt", word_size);
        dico = dico6;
        break;
    case 7:
        proposed_word = "castree";
        table_t *dico7 = dico_load("dictionaries/francais/dico7.txt", word_size);
        dico = dico7;
        break;
    case 8:
        proposed_word = "orientes";
        table_t *dico8 = dico_load("dictionaries/francais/dico8.txt", word_size);
        dico = dico8;
        break;
    case 9:
        proposed_word = "entourees";
        table_t *dico9 = dico_load("dictionaries/francais/dico9.txt", word_size);
        dico = dico9;
        break;
    case 10:
        proposed_word = "clairement";
        table_t *dico10 = dico_load("dictionaries/francais/dico10.txt", word_size);
        dico = dico10;
        break;

    default:
        break;
    }

    if (dico == NULL)
    {
        return 1;
    }
    printf("\x1b[32mDico importé\x1b[0m\n");
    printf("Mot Proposé : \x1b[1m%s\x1b[0m\n", proposed_word);

    user_input *user_response = create_user_response(word_size);
    update_user_response(user_response, word_size);
    table_t *new_list = new_selected_table(dico, user_response->response, proposed_word);
    update_entropy(new_list, pat);

    element_t *tmp;

    while (!user_response->exited && !user_response->valid)
    {

        if (table_is_empty(new_list))
        {
            printf("\x1b[31mPas de mots correspondants =(\x1b[0m\n");
            table_destroy(new_list);
            destroy_user_input(user_response);
            destroy_patern(pat);
            return 0;
        }

        tmp = table_max_entropy(new_list);

        if (!tmp)
        {
            printf("\x1b[31mPas de mots correspondants =(\x1b[0m\n");
            table_destroy(new_list);
            destroy_user_input(user_response);
            destroy_patern(pat);
            return 0;
        }

        if (!tmp->key)
        {
            printf("\x1b[31mPas de mots correspondants =(\x1b[0m\n");
            table_destroy(new_list);
            destroy_user_input(user_response);
            destroy_patern(pat);
            return 0;
        }

        proposed_word = tmp->key;

        printf("Mot Proposé : \x1b[1m%s\x1b[0m\n", proposed_word);
        update_user_response(user_response, word_size);

        new_list = new_selected_table(new_list, user_response->response, proposed_word);

        update_entropy(new_list, pat);
    }
    table_destroy(new_list);
    destroy_user_input(user_response);
    destroy_patern(pat);
    return 0;
}
