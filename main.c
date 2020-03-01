#include <stdlib.h>
#include "fileIO.h"
#include "utilities.h"
#include "sortStrings.h"

int main(void) {
    int lineLen = getNumberOfLines();
    char **anagram = (char **) calloc(lineLen, sizeof(char *));
    for (int i = 0; i < lineLen; i++) {
        anagram[i] = (char *) calloc(MAX_SENTENCE_LEN, sizeof(char));
    }
    //Reads in Anagrams
    readAnagrams(anagram, lineLen);
    /*Sorts File*/
    quickSort(anagram, 0, lineLen - 1);
    /*Outputs Sorted string to the output.txt*/
    outputSortedSentences(anagram, lineLen);
    /*Outputs the list of Anagrams*/
    outputAnagrams(anagram, lineLen);
    /*Outputs the list of Missing Anagrams*/
    outputMissingAnagrams(anagram, lineLen);

    /*Frees the allocated memory*/
    for(int i = 0; i< lineLen; i++)
    {
        free(anagram[i]);
    }
    free(anagram);

    return 0;
}