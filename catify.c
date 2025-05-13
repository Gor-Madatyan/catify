#include "utils.h"
#include "catify.h"

void catify(char *str1, const char *str2) {
    transform_word(str1, str2);
    if (strcmp(str1, str2) == 0) {
        char normalized_word[10];
        normalize(normalized_word, str2);
        transform_word(str1, normalized_word);
    }
}

void catify_words(char **words, const StringProcessor processor) {
    char *word;

    while ((word = *words++)) {
        char catified_word[10];
        catify(catified_word, word);

        processor(catified_word);
    }
}
