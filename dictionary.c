#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dictionary.h"

Dictionary *loadDictionary(char *path) {
    FILE *fp;
    Dictionary *dictionary;
    int dictionarySize;
    char **dictionaryArr;
    int dictionaryOffset = 0;
    char nextWord[31];

    /* Open dictionary file */
    fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Could not open dictionary file");
        return NULL;
    }

    /* Read dictionary size */
    if (fscanf(fp, "%d ", &dictionarySize) != 1) {
        printf("Invalid dictionary file format\n");
        return NULL;
    }

    /* Create dictionary array */
    dictionaryArr = malloc(dictionarySize * sizeof(char *));

    /* Read words into dictionary */
    while (dictionaryOffset < dictionarySize && fgets(nextWord, 31, fp) != NULL) {
        /* Truncate newline character */
        nextWord[strlen(nextWord) - 1] = '\0';
        dictionaryArr[dictionaryOffset] = (char*) strdup(nextWord);
        dictionaryOffset++;
    }

    /* Create dictionary object */
    dictionary = malloc(sizeof(Dictionary));
    dictionary->dictionary = dictionaryArr;
    dictionary->length = dictionarySize;

    return dictionary;
}

void freeDictionary(Dictionary *dictionary) {
    int i;
    for (i = 0; i < dictionary->length; i++) {
        free(dictionary->dictionary[i]);
    }
    free(dictionary->dictionary);
    free(dictionary);
}
