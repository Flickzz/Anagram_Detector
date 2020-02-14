//
// Created by Ashraf Ali on 02/02/2020.
//
#include <stdio.h>
#include "fileIO.h"
#include "utilities.h"

const char *INPUT_TEXT_FILE = "../input.txt";

int readAnagrams(char **inputAnagrams) {
    FILE *fp = fopen(INPUT_TEXT_FILE, "r+");
    int lineNumber = 0;
    if (fp == NULL) {
        perror("Whooops something went wrong, check if the file is in the correct area.");
        return -1;
    } else {
        while (fgets(inputAnagrams[lineNumber], MAX_SENTENCE_LEN, fp)) {
            lineNumber++;
        }
    }

    for (int i = 0; i < lineNumber; i++) {
        for (int j = 0; j < MAX_SENTENCE_LEN; j++) {
            if (inputAnagrams[i][j] == '\n') {
                inputAnagrams[i][j] = '\0';
            }
        }
    }

    return lineNumber;
}