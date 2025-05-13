#pragma once

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
    {"for","fur"},
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