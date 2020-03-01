//
// Created by Ashraf Ali on 02/02/2020.
//
#include "utilities.h"

#ifndef ANAGRAM_FILEIO_H
#define ANAGRAM_FILEIO_H

void readAnagrams(char **inputAnagrams, int lineLen);
void outputSortedSentences(char **array, int lineLen);
int getNumberOfLines();
void outputAnagrams(char **array, int lineLen);
void outputMissingAnagrams(char **array, int lineLen);

#endif //ANAGRAM_FILEIO_H
