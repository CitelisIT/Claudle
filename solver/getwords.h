#include "list.h"

#ifndef __GETWORDS_H__
#define __GETWORDS_H__

void compute(list_t *pattern, list_t *pool, list_t *goodchar, char *notinword, char *word);

void suggestion(list_t *pool, list_t *goodchar, char *word, int length);

#endif // __GETWORDS_H__