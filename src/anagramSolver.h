//
// Created by Ashraf Ali on 18/02/2020.
//

#ifndef ANAGRAM_ANAGRAMSOLVER_H
#define ANAGRAM_ANAGRAMSOLVER_H

//stdbool is used in anagramSolver.c and fileIO.c, saves the hassle of including it twice
#include <stdbool.h>

/*Returns true if 2 sentences are anagrams of each other*/
bool isAnagram(char *sentence1, char *sentence2);

int missingAnagram(char *sentence1, char *sentence2);

#endif //ANAGRAM_ANAGRAMSOLVER_H
