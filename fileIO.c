//
// Created by Ashraf Ali on 02/02/2020.
//
#include <stdio.h>
#include "fileIO.h"
#include "utilities.h"

const char *INPUT_TEXT_FILE = "../input.txt";

int readAnagrams(char inputAnagrams[][MAX_SENTENCE_LEN]) {
    FILE *fp = fopen(INPUT_TEXT_FILE, "r+");
    int lineNumber = 0;
    if (fp == NULL) {
        perror("Whooops something went wrong");
    } else {
        while (fgets(inputAnagrams[lineNumber], sizeof(inputAnagrams[lineNumber]), fp) != NULL) {
            lineNumber++;
        }
    }
    return lineNumber;
}
