//
// Created by Ashraf Ali on 18/02/2020.
//
#include "anagramSolver.h"
#include <ctype.h>

/*Returns true if 2 sentences are anagrams of each other*/
bool isAnagram(char *sentence1, char *sentence2) {

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

    /*If any of the letter frequencies are different, it isn't anagram and hence it must return false*/
    for (int i = 0; i < 26; i++) {
        if (sentence1CharacterFrequency[i] != sentence2CharacterFrequency[i]) {
            return false;
        }
    }

    /*Otherwise if all frequencies are equal, it returns true*/
    return true;
}

/*Finds whether sentence 1 is a missing anagram of sentence 2 if x characters are removed*/
int missingAnagram(char *sentence1, char *sentence2) {

    /*Finds number of alphabetic characters in sentence 1*/
    int charactersInSentence1 = 0;
    for (int i = 0; sentence1[i] != '\0'; i++) {
        char currentChar = tolower(sentence1[i]);
        if (currentChar >= 'a' && currentChar <= 'z') {
            charactersInSentence1++;
        }
    }
    /*Finds the number of alphabetic characters in sentence 2*/
    int charactersInSentence2 = 0;
    for (int i = 0; sentence2[i] != '\0'; i++) {
        char currentChar = tolower(sentence2[i]);
        if (currentChar >= 'a' && currentChar <= 'z') {
            charactersInSentence2++;
        }
    }
    /*If they're equal length, they can't be missing anagrams of each other*/
    if (charactersInSentence1 == charactersInSentence2) {
        return -1;
    }

    int sentence1CharacterFrequency[26] = {0};//Stores the frequency of each alphabetic character in sentence 1
    int sentence2CharacterFrequency[26] = {0};//Stores the frequency of each alphabetic character in sentence 2

    /*Stores the frequency of the first parts of each alphabetic character until one of the arrays hits the null terminator*/
    for (int i = 0, j = 0; sentence1[i] != '\0' && sentence2[j] != '\0'; i++, j++) {
        /*Skips through any character that isn't alphabetic*/
        while (tolower(sentence1[i]) < 'a' || tolower(sentence1[i]) > 'z') {
            i++;
            if (sentence1[i] == '\0')
                break;
        }
        if (tolower(sentence1[i]) >= 'a' && tolower(sentence1[i]) <= 'z') {
            sentence1CharacterFrequency[tolower(sentence1[i]) - 'a']++;
        }
        /*Skips through any character that isn't alphabetic*/
        while (tolower(sentence2[j]) < 'a' || tolower(sentence2[j]) > 'z') {
            j++;
            if (sentence2[j] == '\0')
                break;
        }
        if (tolower(sentence2[j]) >= 'a' && tolower(sentence2[j]) <= 'z') {
            sentence2CharacterFrequency[tolower(sentence2[j]) - 'a']++;
        }
    }
    /*Checks if they're actually missing anagrams*/
    for (int i = 0; i < 26; i++) {
        if (sentence1CharacterFrequency[i] != sentence2CharacterFrequency[i]) {
            return -1;
        }
    }
    int missingCharacters = charactersInSentence1 - charactersInSentence2;

    return missingCharacters;
}