#include <string.h>
#include "dictionary.h"
#include "utils.h"
#include <ctype.h>

void transform_word(char* transformed_word, const char* word) {
    const int word_length = (int) strlen(word);
    for (int i = word_length; i > 0; --i) {
        const char *translated_part = translate_word(word, i);
        if (translated_part) {
            strcpy(transformed_word,translated_part);
            strcat(transformed_word, word + i);
            if (isupper(word[0])) transformed_word[0] = (char) toupper(transformed_word[0]);
            return;
        }
    }
    strcpy(transformed_word, word);
}

char* translate_word(const char* word, const int n) {
    char lowercase_word[10];
    for (int i = 0;i<10;i++) lowercase_word[i] = (char) tolower(word[i]);
    for (const WordTranslateEntry *entries = translate_table; entries->from; entries++)
        if (strlen(entries->from) == n && strncmp(entries->from,lowercase_word, n) == 0) return entries->to;

    return nullptr;
}

inline void print_word(char* word) {
    printf("%s ", word);
}