//
// Created by Ashraf Ali on 18/02/2020.
//
#include "anagramSolver.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "stdlib.h"
#include "utilities.h"
#include <string.h>

/*Returns true if 2 sentences are anagrams of each other*/
int isAnagram(char *sentence1, char *sentence2) {

    int sentence1CharacterFrequency[26] = {0};//Stores the frequency of each alphabetic character in sentence 1
    int sentence2CharacterFrequency[26] = {0};//Stores the frequency of each alphabetic character in sentence 2

    /*Counts the frequency of each character in the first sentence*/
    for (int i = 0; sentence1[i] != '\0'; i++) {
        char current = tolower(sentence1[i]);
        if (current >= 'a' && current <= 'z') {
            sentence1CharacterFrequency[current - 'a']++;
        }
    }
    /*Counts the frequency of each character in the second sentence*/
    for (int i = 0; sentence2[i] != '\0'; i++) {
        char current = tolower(sentence2[i]);
        if (current >= 'a' && current <= 'z') {
            sentence2CharacterFrequency[current - 'a']++;
        }
    }

    /*If any of the letter frequencies are different it isn't anagram and hence returns false*/
    for (int i = 0; i < 26; i++) {
        if (sentence1CharacterFrequency[i] != sentence2CharacterFrequency[i]) {
            return false;
        }
    }
    /*Otherwise if all frequencies are equal, it returns true*/
    return true;
}

/*Finds whether sentence1 is a missing anagram of sentence 2 if x characters are removed*/
int missingAnagram(char *sentence1, char *sentence2) {
    int sentence1CharacterFrequency[26] = {0};//Stores the frequency of each alphabetic character in sentence 1
    int sentence2CharacterFrequency[26] = {0};//Stores the frequency of each alphabetic character in sentence 2

    /*loops until one of the sentences is null and counts the frequency of each*/
    for (int i = 0; sentence1[i] != '\0' && sentence2[i] != '\0'; i++) {
        char currentSen1 = tolower(sentence1[i]);
        char currentSen2 = tolower(sentence2[i]);
        if (currentSen1 >= 'a' && currentSen1 <= 'z' && currentSen2 >= 'a' && currentSen2 <= 'z') {
            sentence1CharacterFrequency[currentSen1 - 'a']++;
            sentence2CharacterFrequency[currentSen2 - 'a']++;
        }
    }

    /*Sees whether the first part of each sentences are anagrams of eachother*/
    for (int i = 0; i < 26; i++) {
        /*If they're not anagrams of each other it returns null*/
        if (sentence1CharacterFrequency[i] != sentence2CharacterFrequency[i]) {
            return -1;
        }
    }

    /*Finds how many characters are missing*/
    int missingCharacters = strlen(sentence1) - strlen(sentence2);

    if (missingCharacters > 0) {
        return missingCharacters;
    } else {
        return -1;
    }
}