#include <stdio.h>
#include "utils.h"
#include "catify.h"

// Entry point
int main(const int argc, char *argv[]) {
    if (argc > 1) catify_words(argv + 1, print_word);
    else {
        char raw[10];
        char catified[10];
        while (scanf("%s", raw) != EOF) {
            catify(catified, raw);
            print_word(catified);
            char temp;
            if ((temp = (char) getchar()) == '\n') {
                printf("\n");
            }
            else ungetc(temp, stdin);
        };
    }
    printf("\n");
    return 0;
}
