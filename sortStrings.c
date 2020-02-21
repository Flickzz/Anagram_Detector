#include <string.h>
#include "sortStrings.h"

/*Swaps strings within a 2D character array*/
void swap(char **array, int i, int j) {
    char *temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int partition(char **array, int first, int last) {
    swap(array, first, (first + last) / 2); // swap middle value into first position
    char *pivot = array[first];     // remember pivot

    int index1 = first + 1; // index of first unknown value
    int index2 = last;    // index of last unknown value
    while (index1 <= index2) { // while some values still unknown
        //strcmpi determines which is alphabetically greater than the other, it's case insensitive
        if (strcmpi(array[index1], pivot) < 0) {
            index1++;
        } else if (strcmpi(array[index2], pivot) > 0) {
            index2--;
        } else {
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