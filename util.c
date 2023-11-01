#include <stdio.h>
#include <string.h>
#include "util.h"

void printWordWithChars(char *word, int chars) {
    while (*word != '\0') {
        if ((chars >> (*word - 'a')) & 1) {
            /* Character has been guessed, print to screen */
            printf("%c", *word);
        } else {
            /* Character not yet guessed */
            printf("_");
        }
        word++;
    }
    printf("\n");
}

int isComplete(char *word, int chars) {
    int complete = 1;
    while (complete == 1 && *word != '\0') {
        if (!((chars >> (*word - 'a')) & 1)) {
            /* Character not in bit array */
            complete = 0;
        }
        word++;
    }
    return complete;
}

char getCharacter() {
    char str[20];
    char result = '\0';

    while (result == '\0') {
        printf("Guess a character: ");
        gets(str);

        if (strlen(str) == 1) {
            result = *str;
        } else {
            printf("\nPlease enter a single character\n");
        }
    }

    return result;
}

int strContainsChar(char *str, char ch) {
    int found = 0;
    while (!found && *str != '\0') {
        if (*str == ch) {
            found = 1;
        }
        str++;
    }
    return found;
}