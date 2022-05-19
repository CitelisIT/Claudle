#include"dico.h"


    table_t* dico_load(char* filename){
        table_t* table = table_create(10000);
        FILE* ptr = fopen(filename, "r");
        char ch[30] = "";
        if (ptr == NULL) {
            printf("file can't be opened \n");
            return NULL;
        }
        
        while(fgets(ch, 30, ptr) != NULL){
            for (int i = 0; i < strlen(ch); i++)
            {
                if (ch[i] == '\n' || ch[i] == '\r')
                {
                    ch[i] = '\0';
                }
            }            
            bool added = table_add(table, ch);
            
        }
        fclose(ptr);
        return table;
    }
    