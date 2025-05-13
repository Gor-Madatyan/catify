#pragma once
#include <stdio.h>
#include <string.h>

// Handles printing of a word
void print_word(char* word);

// Returns a translated word or NULL if there is no common translation for that word
char* translate_word(const char* word, int n);

// changes a part of a word or the whole word if translate_word is valid for it
void transform_word(char* transformed_word, const char* word);

// normalizes some exceptions in the English, so analyzing it can be easier
void normalize(char* str1, const char* str2);
