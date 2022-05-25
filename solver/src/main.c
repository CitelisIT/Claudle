#include "entropy.h"
#include "io.h"

int main()
{
    int word_size = read_word_lengths();

    int end_answer[word_size];
    for (int i = 0; i < word_size; i++)
    {
        end_answer[i] = 2;
    }

    paterns *pat = init_patern(word_size);
    calc_patern(pat);

    printf("importation mots: \n");
    table_t *dico = dico_load("../dictionaries/francais/dico5.txt", word_size);
    printf("Dico importé \n");

    // Get the max of the precalculated list x

    printf("%s", proposed_word);

    int *user_response = get_hints(word_size);

    while (user_response != -1 || user_response = end_answer)
    {
        table_t *new_list = new_selected_table(dico, proposed_word, user_response);

        update_entropy(new_list, pat);

        // select max from this new list x

        printf("%s", proposed_word);

        table_destroy(new_list);

        user_response = get_hints(word_size);
    }

    return 0;
}
