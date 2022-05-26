#include "dico.h"

table_t *dico_load(char *filename, int n)
{
    table_t *table = table_create(1024);
    FILE *ptr = fopen(filename, "r");
    char ch[30] = "";
    if (ptr == NULL)
    {
        printf("\x1b[31m\x1b[2mLe dictionnaire n'a pas pu être ouvert\x1b[0m\n");
        return NULL;
    }

    while (fgets(ch, 30, ptr) != NULL)
    {
        for (int i = 0; i < strlen(ch); i++)
        {
            if (ch[i] == '\n' || ch[i] == '\r')
            {
                ch[i] = '\0';
            }
        }
        if (strlen(ch) == n)
        {
            bool added = table_add(table, ch);
            if (added)
            {
                table->nb_word++;
            }
        }
    }
    fclose(ptr);
    return table;
}
