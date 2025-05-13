#include <stdio.h>
#include <string.h>
#include "dictionary.h"

typedef void (*StringProcessor)(char*);

// Returns a pointer to the new string without mutating the old one
void catify(char *str1, const char *str2);

// At the end of the array there will be a NULL pointer
void catify_words(char** words, StringProcessor processor);

// Handles printing of a word
void print_word(char* word);

// Returns a translated word or NULL if there is no common translation for that word
char* translate_word(const char* word, int n);

//changes a part of a word or the whole word if translate_word is valid for it
void transform_word(char* transformed_word, const char* word);

// Entry point
int main(int argc, char *argv[]) {
    catify_words(argv+1, print_word);
    printf("\n");
    return 0;
}

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

void print_word(char* word) {
    printf("%s ", word);
}