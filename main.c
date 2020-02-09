#include <stdio.h>
#include <stdlib.h>
#include "fileIO.h"
#include "utilities.h"
#include "sortStrings.h"

int main() {

    char anagram[MAX_LINE_LEN][MAX_SENTENCE_LEN];
    for (int i = 0; i < MAX_LINE_LEN; i++)
        for (int j = 0; j < MAX_SENTENCE_LEN; j++)
            anagram[i][j] = '\0';
    /*Reads the input file into a 2D array*/
    int lineLen = readAnagrams(anagram);

    char **anagram2 = (char **) malloc(sizeof(char *) * lineLen);

    for (int i = 0; i < MAX_LINE_LEN; i++)
        anagram2[i] = (char *) malloc(sizeof(char) * MAX_SENTENCE_LEN);

    for (int i = 0; i < lineLen; i++) {
        anagram2[i] = anagram[i];
    }
    /*Sorts File*/
    quickSort(anagram2, 0, lineLen - 1);
    for (int i = 0; i < lineLen; i++) {
        printf("%s", anagram2[i]);
    }
    return 0;
}