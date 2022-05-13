#include "../src/getwords.h"

const char *ALPHABET = "abcdefghijklmnopqrstuvwxyz";

int main()
{
    int length = 0;
    printf("Enter length : ");
    scanf("%d", &length);
    char word[256] = "";
    int i = 0;
    while (i < length) // We initialize the word as a random string
    {
        word[i] = ALPHABET[rand() % 26];
        i++;
    }
    word[i] = '\0';
    printf("%s \n", word);
    char notinword[256] = "";
    list_t *pattern1 = list_create();
    list_t *pattern2 = list_create();
    list_t *pattern3 = list_create();
    list_t *pattern4 = list_create();
    list_t *pattern5 = list_create();
    list_t *pool = list_create();
    list_t *goodchar = list_create();
    list_append(pattern1, 'g', 1);
    list_append(pattern1, 'l', 2);
    list_append(pattern1, 'e', 0);
    list_append(pattern1, 'n', 2);
    list_append(pattern1, 't', 0);
    compute(pattern1, pool, goodchar, notinword, word);
    list_destroy(pattern1);
    list_append(pattern2, 'b', 0);
    list_append(pattern2, 'r', 0);
    list_append(pattern2, 'i', 0);
    list_append(pattern2, 'c', 0);
    list_append(pattern2, 'k', 0);
    compute(pattern2, pool, goodchar, notinword, word);
    list_destroy(pattern2);
    list_append(pattern3, 'j', 0);
    list_append(pattern3, 'u', 1);
    list_append(pattern3, 'm', 0);
    list_append(pattern3, 'p', 0);
    list_append(pattern3, 'y', 0);
    compute(pattern3, pool, goodchar, notinword, word);
    list_destroy(pattern3);
    list_append(pattern4, 'v', 0);
    list_append(pattern4, 'o', 0);
    list_append(pattern4, 'z', 0);
    list_append(pattern4, 'h', 0);
    list_append(pattern4, 'd', 0);
    compute(pattern4, pool, goodchar, notinword, word);
    list_destroy(pattern4);
    list_append(pattern5, 'w', 0);
    list_append(pattern5, 'a', 0);
    list_append(pattern5, 'q', 0);
    list_append(pattern5, 'f', 0);
    list_append(pattern5, 's', 1);
    compute(pattern5, pool, goodchar, notinword, word);
    list_destroy(pattern5);
    printf("POOL : ");
    int j = 0;
    int pool_len = list_get_size(pool);
    while (j < pool_len)
    {
        printf("%c", list_get_key(pool->head));
        list_remove_first(pool);
        j++;
    }
    printf("\n");
    int k = 0;
    int goodchar_len = list_get_size(goodchar);
    while (k < goodchar_len)
    {
        printf("%c : %d \n", list_get_key(goodchar->head), list_get_value(goodchar->head));
        list_remove_first(goodchar);
        k++;
    }
    suggestion(pool, goodchar, word, length);
    printf("%s \n", word);
    list_destroy(pool);
    list_destroy(goodchar);

    return 0;
}
