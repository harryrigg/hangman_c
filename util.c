#include <stdio.h>
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
