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
    word_t *pattern1 = word_create();
    word_t *pattern2 = word_create();
    word_t *pattern3 = word_create();
    word_t *pattern4 = word_create();
    word_t *pattern5 = word_create();
    word_t *pool = word_create();
    word_t *goodchar = word_create();
    word_append(pattern1, 'g', 1);
    word_append(pattern1, 'l', 2);
    word_append(pattern1, 'e', 0);
    word_append(pattern1, 'n', 2);
    word_append(pattern1, 't', 0);
    compute(pattern1, pool, goodchar, notinword, word);
    word_destroy(pattern1);
    word_append(pattern2, 'b', 0);
    word_append(pattern2, 'r', 0);
    word_append(pattern2, 'i', 0);
    word_append(pattern2, 'c', 0);
    word_append(pattern2, 'k', 0);
    compute(pattern2, pool, goodchar, notinword, word);
    word_destroy(pattern2);
    word_append(pattern3, 'j', 0);
    word_append(pattern3, 'u', 1);
    word_append(pattern3, 'm', 0);
    word_append(pattern3, 'p', 0);
    word_append(pattern3, 'y', 0);
    compute(pattern3, pool, goodchar, notinword, word);
    word_destroy(pattern3);
    word_append(pattern4, 'v', 0);
    word_append(pattern4, 'o', 0);
    word_append(pattern4, 'z', 0);
    word_append(pattern4, 'h', 0);
    word_append(pattern4, 'd', 0);
    compute(pattern4, pool, goodchar, notinword, word);
    word_destroy(pattern4);
    word_append(pattern5, 'w', 0);
    word_append(pattern5, 'a', 0);
    word_append(pattern5, 'q', 0);
    word_append(pattern5, 'f', 0);
    word_append(pattern5, 's', 1);
    compute(pattern5, pool, goodchar, notinword, word);
    word_destroy(pattern5);
    printf("POOL : ");
    int j = 0;
    int pool_len = word_get_size(pool);
    while (j < pool_len)
    {
        printf("%c", word_get_key(pool->head));
        word_remove_first(pool);
        j++;
    }
    printf("\n");
    int k = 0;
    int goodchar_len = word_get_size(goodchar);
    while (k < goodchar_len)
    {
        printf("%c : %d \n", word_get_key(goodchar->head), word_get_value(goodchar->head));
        word_remove_first(goodchar);
        k++;
    }
    suggestion(pool, goodchar, word, length);
    printf("%s \n", word);
    word_destroy(pool);
    word_destroy(goodchar);

    return 0;
}
