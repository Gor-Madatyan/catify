#include <string.h>
#include "dictionary.h"
#include "utils.h"
#include <ctype.h>

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
    for (const WordTranslateEntry *entries = translate_table; entries->from; entries++)
        if (strlen(entries->from) == n && strncasecmp(entries->from, word, n) == 0) return entries->to;

    return nullptr;
}

void normalize(char *str1, const char *str2) {
    const int len = (int) strlen(str2);
    strcpy(str1, str2);
    if (strcasecmp(str1+len-3,"ies") == 0) str1[len-3] = 'y', str1[len-2] = 's', str1[len-1] = '\0';
    else if (strcasecmp(str1+len-2,"es") == 0) str1[len-2] = 's', str1[len-1] = '\0';
    else if (strcasecmp(str1+len-2,"ie") == 0) str1[len-2] = 'y', str1[len-1] = '\0';
}

inline void print_word(char *word) {
    printf("%s ", word);
}
