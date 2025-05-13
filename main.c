#include <stdio.h>
#include <string.h>

typedef void (*StringProcessor)(char*);

typedef struct {
    char* from;
    char* to;
} WordTranslateEntry;

const WordTranslateEntry translate_table[] = {
    // Section I.A: Key Noun/Pronoun/Adjective/Adverb Changes
    {"human", "hooman"},
    {"person", "hooman"}, // Using "hooman" as a general replacement
    {"people", "hoomans"}, // Added plural
    {"cat", "catte"},
    {"kitten", "kitteh"},
    {"dog", "doggo"},
    {"food", "fudz"},
    {"meal", "nom noms"},
    {"money", "tuna"},
    {"house", "maowse"},
    {"home", "maowse"},
    {"lawyer", "pawyer"},
    {"legal", "pawgal"},
    {"law", "teh claw"},
    {"advice", "tipz"},
    {"problem", "prawblem"}, // Or "ishoo"
    {"now", "nmeow"}, // Or "right meow"
    {"very", "vewy"},
    {"really", "sooo"}, // Or "muchly"
    {"good", "gud"},
    {"bad", "no gud"},
    {"my", "mai"},
    {"mine", "mainz"}, // Added possessive pronoun
    {"you", "yoo"}, // Or "u", or "hooman" if addressing owner
    {"your", "ur"}, // Also in misspellings
    {"the", "teh"},
    {"a", "uh"}, // "a" can sometimes be "uh"
    // "an" is often kept as is, or could be "uhn" - kept as is for simplicity here
    {"love", "luv"}, // Or "lurv"
    {"please", "pleez"}, // Or "plz"
    {"because", "becuz"}, // Or "coz"
    {"communication", "commeownication"},
    {"immediately", "right meow"}, // Or "immediateliny", "statcat"
    {"important", "vewy big deal"}, // Or "vewy big deal"
    {"sleep", "naps"}, // Or "snoozles"
    {"small", "smol"},
    {"little", "smol"}, // Or "tiny"
    {"big", "beeg"},
    {"large", "beeg"}, // "chonky" often refers to weight/build

    // Section I.B: Common Verb Changes & Phrasing
    {"are", "ar"},
    {"am", "be"}, // As in "Me be hungry"
    {"was", "wuz"},
    {"were", "wur"},
    {"have", "haz"}, // Or "hav"
    {"want", "wantz"}, // Or "needz", "must haz"
    {"need", "needz"},
    {"can", "ken"},
    {"will", "gonna"}, // Or "will"
    {"sue", "soo"},
    {"talk", "meow about"},
    {"speak", "meow about"},
    {"think", "fink"}, // Or "reckon"
    {"look", "looksee"}, // Or "inspect"
    {"tell", "tellz"},
    {"say", "sez"},
    {"give", "gib"},
    {"get", "getz"},

    // From Section II: Common Misspellings (suitable for direct substitution)
    {"enough", "enuff"},
    {"what", "wut"},
    {"with", "wif"},
    {"of", "ov"},
    // "your" -> "ur" (already listed above)
    {"sure", "shur"},
    {"friend", "fren"},
    {"picture", "piktur"},
    {"story", "tale"}, // Often kept, but could be "tail" (tale)

    // Additional common cat-related terms that fit the substitution model
    {"attention", "attenshunz"},
    {"baby", "bebeh"},
    {"bird", "birb"},
    {"box", "boxie"}, // Often "box" or "boxie"
    {"hello", "mrrp"}, // A common cat greeting sound
    {"thank", "fank"},
    {"tonight", "tonite"},
    {"tomorrow", "tomowwow"},
    {"today", "todayz"},
    {"why", "wai"},
    //word starters
    {"per","purr"},
    // Terminator for the array
    {nullptr, nullptr}
};

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