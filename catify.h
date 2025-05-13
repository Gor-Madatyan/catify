#pragma once

typedef void (*StringProcessor)(char*);

// Returns a pointer to the new string without mutating the old one
void catify(char *str1, const char *str2);

// At the end of the array there will be a NULL pointer
void catify_words(char** words, StringProcessor processor);
