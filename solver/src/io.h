#ifndef __IO_H__
#define __IO_H__

#include <stdio.h>
#include <stdbool.h>

struct _error_t
{
    bool invalid_size;
    bool invalid_char;
    bool exited;
};

typedef struct _error_t error_t;

struct _user_input
{
    bool valid;
    bool exited;
    int *response;
};

typedef struct _user_input user_input;

user_input *create_user_response(size_t word_size);

void update_user_response(user_input *resp, size_t word_size);

bool validate_input(char *input, size_t word_size, error_t *error);

int read_word_lengths();

void destroy_user_input(user_input *input);

#endif
