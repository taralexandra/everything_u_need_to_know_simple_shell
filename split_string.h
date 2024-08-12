#ifndef SPLIT_STRING_H
#define SPLIT_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_string(const char *str);
void free_split_string(char **array);

#endif
