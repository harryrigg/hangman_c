#ifndef _DICTIONARY_H
#define _DICTIONARY_H

typedef struct {
    char **dictionary;
    int length;
} Dictionary;

/* Loads the dictionary from the specified file path */
/* First line in dictionary file must specify the number of words */
/* Each subsequent line is a word in the dictionary */
/* The dictionary must not contain any words longer than 30 characters */
Dictionary *loadDictionary(char *path);

/* Frees dictionary object */
void freeDictionary(Dictionary *dictionary);

#endif