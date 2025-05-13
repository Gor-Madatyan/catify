#include <string.h>
#include "dictionary.h"
#include "utils.h"

void transform_word(char* transformed_word, const char* word) {
    const int word_length = (int) strlen(word);
    for (int i = word_length; i > 0; --i) {
        const char *translated_part = translate_word(word, i);
        if (translated_part) {
            strcpy(transformed_word,translated_part);
            strcat(transformed_word, word + i);
            return;
        }
    }
    strcpy(transformed_word, word);
}

char* translate_word(const char* word, const int n) {
    for (const WordTranslateEntry *entries = translate_table; entries->from; entries++)
        if (strlen(entries->from) == n && strncmp(entries->from, word, n) == 0) return entries->to;

    return nullptr;
}

inline void print_word(char* word) {
    printf("%s ", word);
}