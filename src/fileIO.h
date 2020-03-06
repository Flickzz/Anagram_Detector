//
// Created by Ashraf Ali on 02/02/2020.
//
#include "utilities.h"

#ifndef ANAGRAM_FILEIO_H
#define ANAGRAM_FILEIO_H

/*Reads in sentences from our input file into a 2d array of characters*/
void readPotentialAnagrams(char **listOfPotentialAnagrams, int lineLen);

/*Outputs the sorted list of sentences from the 2d array into an output file*/
void outputSortedSentences(char **array, int lineLen);

/*Reads the length of the input file*/
int getNumberOfLines();

/*Finds and appends all anagram sets into a file*/
void outputAnagrams(char **array, int lineLen);

/*Finds and appends all missing anagram sets into an output file*/
void outputMissingAnagrams(char **array, int lineLen);

#endif //ANAGRAM_FILEIO_H
