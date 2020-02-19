#include <string.h>
#include "sortStrings.h"
#include <stdlib.h>
#include <ctype.h>

/*Swaps sentences within a character array*/
void swap(char **array, int i, int j) {
    char *temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}


int compare(char *sentence1, char *sentence2) {
    //Copies the sentences onto a charachter array that we can make lowercase
    char *sentence1_lowercase = malloc((strlen(sentence1) + 1) * sizeof(char));
    char *sentence2_lowercase = malloc((strlen(sentence2) + 1) * sizeof(char));

    strcpy(sentence1_lowercase, sentence1);
    strcpy(sentence2_lowercase, sentence2);

    //Make the Copies Lower case
    for (int i = 0; sentence1_lowercase[i] != '\0'; i++) {
        tolower(sentence1_lowercase);
    }
    for (int i = 0; sentence2_lowercase[i] != '\0'; i++) {
        tolower(sentence2_lowercase);
    }
    //Compare strings in their lower charachter form
    int comparison = strcmp(sentence1_lowercase, sentence2_lowercase);
    //Free Memory
    free(sentence1_lowercase);
    free(sentence2_lowercase);
    return comparison;
}

int partition(char **array, int first, int last) {
    swap(array, first, (first + last) / 2); // swap middle value into first pos
    char *pivot = array[first];     // remember pivot

    int index1 = first + 1; // index of first unknown value
    int index2 = last;    // index of last unknown value
    while (index1 <= index2) { // while some values still unknown
        if (compare(array[index1], pivot) < 0)
            index1++;
        else if (compare(array[index2], pivot) > 0)
            index2--;
        else {
            swap(array, index1, index2);
            index1++;
            index2--;
        }
    }
    swap(array, first, index2); // put the pivot value between the two
    // sublists and return its index
    return index2;
}


void quickSort(char **array, int first, int last) {

    //if the size of the array is equal to 0 or 1, the array is sorted by definition
    if (first < last) {
        int pivotIndex = partition(array, first, last);
        quickSort(array, first, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, last);
    }
}