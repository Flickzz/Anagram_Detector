#include <stdio.h>
#include <stdlib.h>
#include "fileIO.h"
#include "utilities.h"
#include "sortStrings.h"
#include "anagramSolver.h"
int main() {

    char **anagram2 = (char **) calloc(MAX_LINE_LEN, sizeof(char *));
    for (int i = 0; i < 14; i++) {
        anagram2[i] = (char *) calloc(MAX_SENTENCE_LEN, sizeof(char));
    }
    int lineLen = readAnagrams(anagram2);

    /*Sorts File*/
    quickSort(anagram2, 0, lineLen - 1);
    /*Prints Contents of the 2d array*/
    for (int i = 0; i < lineLen; i++) {
        printf("%s\n", anagram2[i]);
    }
    return 0;
}