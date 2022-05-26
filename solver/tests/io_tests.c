#include "../src/io.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int l = read_word_lengths();
    printf("%d\n", l);
    error_t *error = (error_t *)calloc(1, sizeof(error_t));
    printf("input \"01\" is valid : %d\n", validate_input("01", 5, error));
    printf("input \"011111\" is valid : %d\n", validate_input("011111", 5, error));
    printf("input \"01213\" is valid : %d\n", validate_input("01213", 5, error));
    printf("input \"01210\" is valid : %d\n", validate_input("01210", 5, error));
    user_input *hints = get_hints(5);
    printf("hints: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d", hints->response[i]);
    }
    printf("\n");
    printf("exited: %d\n", hints->exited);
    printf("valid: %d\n", hints->valid);
    destroy_user_input(hints);
    free(error);
}
