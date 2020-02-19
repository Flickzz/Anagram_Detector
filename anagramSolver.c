//
// Created by Ashraf Ali on 18/02/2020.
//
#include "anagramSolver.h"

/*Returns an integer stating how close to being an anagram one sentence is to another*/
/*If the integer is 0, they are anagrams of eachother*/
int isAnagram(char *sentence1, char *sentence2) {
    int sentence1Characters[26];//Stores the frequency of each alphabetic character in sentence 1
    int sentence2Characters[26];//Stores the frequency of each alphabetic character in sentence 2

    /*Counts the frequency of each character in the first sentence*/
    for (int i = 0; sentence1[i] != '\0'; i++) {
        char current = tolower(sentence1[i]);
        if (current >= 'a' && current <= 'z') {
            sentence1Characters[current - 'a']++;
        }
    }
    /*Counts the frequency of each character in the second sentence*/
    for (int i = 0; sentence2[i] != '\0'; i++) {
        char current = tolower(sentence2[i]);
        if (current >= 'a' && current <= 'z') {
            sentence1Characters[current - 'a']++;
        }
    }

    int frequencyDistance;
    for (int i = 0; i < 26; i++) {
        frequencyDistance += sentence1Characters[i] - sentence2Characters[i];
    }

    return frequencyDistance;
}