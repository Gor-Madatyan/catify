#include <string.h>
#include "utils.h"
#include "dictionary.h"
#include <ctype.h>
#include <stdio.h>

void transform_word(char *transformed_word, const char *word) {
    const int word_length = (int) strlen(word);
    for (int i = word_length; i > 0; --i) {
        const char *translated_part = translate_word(word, i);
        if (translated_part) {
            strcpy(transformed_word, translated_part);
            strcat(transformed_word, word + i);
            if (isupper(word[0])) transformed_word[0] = (char) toupper(transformed_word[0]);
            return;
        }
    }
    strcpy(transformed_word, word);
}

char *translate_word(const char *word, const int n) {
    for (const WordTranslateEntry *entries = prefix_translate_table; entries->from; entries++)
        if (strlen(entries->from) == n && strncasecmp(entries->from, word, n) == 0) return entries->to;

    return nullptr;
}

void normalize(char *str1, const char *str2) {
    const int len = (int) strlen(str2);
    strcpy(str1, str2);
    if (strcasecmp(str1 + len - 3, "ies") == 0) str1[len - 3] = 'y', str1[len - 2] = 's', str1[len - 1] = '\0';
    else if (strcasecmp(str1 + len - 2, "es") == 0) str1[len - 2] = 's', str1[len - 1] = '\0';
    else if (strcasecmp(str1 + len - 2, "ie") == 0) str1[len - 2] = 'y', str1[len - 1] = '\0';
}

char *translate_postfix(const char *str) {
    for (const WordTranslateEntry *entry = postfix_translate_table; entry->from; entry++)
        if (strcasecmp(entry->from, str) == 0) return entry->to;
    return nullptr;
}

void transform_postfix(char *word) {
    for (int i = 0; word[i]; ++i) {
        const char *translated_part = translate_postfix(word + i);
        if (translated_part) {
            const int postfix_length = (int) strlen(translated_part);
            strcpy(word + i, translated_part);
            word[i + postfix_length] = '\0';
            return;
        }
    }
}

inline void print_word(char *word) {
    printf("%s ", word);
}
