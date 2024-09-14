#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NOTFOUND -1

int KMP(char * string, char * pattern);

void buildMatch(char * pattern, int * match);