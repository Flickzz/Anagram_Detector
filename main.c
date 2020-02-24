#include <stdio.h>
#include <stdlib.h>
#include "fileIO.h"
#include "utilities.h"
#include "sortStrings.h"
#include "anagramSolver.h"

int main(void) {

    char **anagram = (char **) calloc(MAX_LINE_LEN, sizeof(char *));
    for (int i = 0; i < MAX_LINE_LEN; i++) {
        anagram[i] = (char *) calloc(MAX_SENTENCE_LEN, sizeof(char));
    }
    int lineLen = readAnagrams(anagram);

    /*Sorts File*/
    quickSort(anagram, 0, lineLen - 1);
    /*Outputs Sorted string to the output.txt*/
    outputSortedSentences(anagram, lineLen);
    return 0;
}