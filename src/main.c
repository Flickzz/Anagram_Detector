#include <stdlib.h>
#include "fileIO.h"
#include "utilities.h"
#include "sortStrings.h"

int main(void) {
    /*Gets the number of sentences(potential anagrams) in our input file*/
    int lineLen = getNumberOfLines();

    /*Allocates memory for our 2D array, uses calloc to initialize them with null terminators*/
    char **listOfPotentialAnagrams = (char **) calloc(lineLen, sizeof(char *));
    for (int i = 0; i < lineLen; i++) {
        listOfPotentialAnagrams[i] = (char *) calloc(MAX_SENTENCE_LEN, sizeof(char));
    }

    //Reads a list of strings into a 2D Array
    readPotentialAnagrams(listOfPotentialAnagrams, lineLen);
    /*Sorts the array of strings in alphabetical order*/
    quickSort(listOfPotentialAnagrams, 0, lineLen - 1);
    /*Outputs Sorted string to a .txt file named output*/
    outputSortedSentences(listOfPotentialAnagrams, lineLen);
    /*Appends the list of detected Anagrams to the same .txt file*/
    outputAnagrams(listOfPotentialAnagrams, lineLen);
    /*Appends the list of detected Missing Anagrams the same .txt file*/
    outputMissingAnagrams(listOfPotentialAnagrams, lineLen);

    /*Frees the allocated memory*/
    for(int i = 0; i< lineLen; i++)
    {
        free(listOfPotentialAnagrams[i]);
    }
    free(listOfPotentialAnagrams);

    return 0;
}