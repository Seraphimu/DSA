#include "KMP.h"

int KMP(char * string, char * pattern) {
    int n = strlen(string);
    int m = strlen(pattern);
    int s, p, * match;
    if (n < m) {
        return NOTFOUND;
    }

    match = (int *)malloc(sizeof (int) * m);
    buildMatch(pattern, match);
    s = p = 0;

    while (s < n && p < m) {
        if (string[s] == pattern[p]) {
            s++;
            p++;
        }
        else if (p > 0) {
            p = match[p - 1] + 1;
        }
        else {
            s++;
        }
    }

    return (p = m) ? (s - m) : NOTFOUND;
}

void buildMatch(char * pattern, int * match) {
    int i, j;
    int m = strlen(pattern);
    match[0] = -1;

    for (j = 1; j < m; j++) {
        while ((i >= 0) && (pattern[i + 1] != pattern[j])) {
            i = match[i];
        }

        if (pattern[i + 1] == pattern[j]) {
            match[j] = i + 1;
        }
        else {
            match[j] = -1;
        }
    }
}