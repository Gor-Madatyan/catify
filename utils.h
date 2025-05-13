#pragma once

#define MAX_WORD_LENGTH 10

// Handles printing of a word
void print_word(char* word);

// Returns a translated word or NULL if there is no common translation for that word
char* translate_word(const char* word, int n);

// changes a part of a word or the whole word if translate_word is valid for it
void transform_word(char* transformed_word, const char* word);

// normalizes some exceptions in the English, so analyzing it can be easier
void normalize(char* str1, const char* str2);

//handle postfixes such as s and convert them to more cat like
char *translate_postfix(const char *str);

// transforms postfix
void transform_postfix(char *word);
