#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include "table.h"

#ifndef __DICO__H__
#define __DICO_H__

table_t *dico_load(char *filename, int n);

#endif