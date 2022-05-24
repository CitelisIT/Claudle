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

int *get_hints(size_t word_size);

bool validate_input(char *input, size_t word_size, error_t *error);

#endif
