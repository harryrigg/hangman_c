#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "dictionary.h"
#include "util.h"

/* Number of guesses the player is allowed to make before losing */
const int NUM_GUESSES = 6;

int main() {
    Dictionary *dictionary;
    char *word;
    char guess;
    int complete = 0;
    int remainingGuesses = NUM_GUESSES;
    /* Bit array containing which characters the player has already guessed */
    int chars = 0;

    srand(time(NULL));

    /* Load dictionary */
    dictionary = loadDictionary("dictionary.txt");
    if (dictionary == NULL) {
        return 1;
    }

    /* Choose a word at random */
    word = dictionary->dictionary[rand() % dictionary->length];

    while (remainingGuesses > 0 && !complete) {
        printf("Remaining guesses: %d\n", remainingGuesses);
        printWordWithChars(word, chars);

        guess = getCharacter();

        if ((chars >> (guess - 'a')) & 1) {
            /* Already guessed */
            printf("Character has already been guessed!\n");
            remainingGuesses--;
        } else if (strContainsChar(word, guess)) {
            /* Not already guessed and word contains character */
            chars |= 1 << (guess - 'a');
            complete = isComplete(word, chars);
        } else {
            /* Not already guessed and word does not contain character */
            printf("Whoops! The word doesn't contain that character!\n");
            remainingGuesses--;
        }

        printf("\n");
    }

    /* Print result */
    if (complete) {
        printWordWithChars(word, chars);
        printf("You win!\n");
    } else {
        printf("Hangman, you lose!\n");
        printf("The word was `%s`\n", word);
    }

    /* Free dictionary */
    freeDictionary(dictionary);

    return 0;
}
