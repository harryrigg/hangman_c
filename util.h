#ifndef _UTIL_H
#define _UTIL_H

/* Prints the specified word, only revealing characters which are present in the chars bit array */
void printWordWithChars(char *word, int chars);

/* Returns 1 if every character in the specified word is present in the chars bit array */
int isComplete(char *word, int chars);

#endif