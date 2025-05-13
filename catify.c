#include "utils.h"
#include "catify.h"

void catify(char *str1, const char *str2) {
    transform_word(str1, str2);
}

void catify_words(char** words, const StringProcessor processor) {
    char* word;

    while ((word = *words++)) {
        char catified_word[10];
        catify(catified_word, word);

        processor(catified_word);
    }
}