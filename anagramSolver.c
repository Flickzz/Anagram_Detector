//
// Created by Ashraf Ali on 18/02/2020.
//
#include "anagramSolver.h"
#include <ctype.h>


/*Returns an integer stating how close to being an anagram one sentence is to another*/
/*If the integer is 0, they are anagrams of eachother*/
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

    /*Counts how far they are from each other, 0 means they are anagrams of eachother*/
    int frequencyDistance = 0;
    for (int i = 0; i < 26; i++) {
        frequencyDistance += sentence1CharacterFrequency[i] - sentence2CharacterFrequency[i];
    }

    return frequencyDistance;
}

char **listOfAnagrams(char *anagrams, int lineLen)
{
    for(int i = 0; i<lineLen; i++)
    {
        for(int j = i; j< lineLen; j++)
        {
            if(isAnagram(anagrams[i],anagrams[j]) == 1)
            {

            }
        }

    }
}