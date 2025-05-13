#include <stdio.h>
#include "utils.h"
#include "catify.h"

// Entry point
int main(int argc, char *argv[]) {
    catify_words(argv+1, print_word);
    printf("\n");
    return 0;
}