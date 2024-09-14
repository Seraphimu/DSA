#include "KMP.h"

int main(void) {
    char string[] = "This is a simple example.";
    char pattern[] = "simple";

    int p = KMP(string, pattern);
    if (p == NOTFOUND) {
        printf("Not Found!\n");
    }
    else {
        printf("%s\n", string + p);
    }

    return 0;
}