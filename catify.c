#include "utils.h"
#include "catify.h"
#include <string.h>

void catify(char *str1, const char *str2) {
    transform_word(str1, str2);
    if (strcmp(str1, str2) == 0) {
        char normalized_word[MAX_WORD_LENGTH];
        normalize(normalized_word, str2);
        transform_word(str1, normalized_word);
    }
    transform_postfix(str1);
}

void catify_words(char **words, const StringProcessor processor) {
    char *word;

    while ((word = *words++)) {
        char catified_word[MAX_WORD_LENGTH];
        catify(catified_word, word);

        processor(catified_word);
    }
}
