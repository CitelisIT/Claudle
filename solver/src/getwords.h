#include "list.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef __GETWORDS_H__
#define __GETWORDS_H__

void compute(word_t *pattern, word_t *pool, word_t *goodchar, char *notinword, char *word);

void suggestion(word_t *pool, word_t *goodchar, char *word, int length);

#endif // __GETWORDS_H__
