//
// Created by Ashraf Ali on 02/02/2020.
//
#include <stdio.h>
#include "fileIO.h"
#include "utilities.h"

const char *INPUT_TEXT_FILE = "../input.txt";
const char *OUTPUT_TEXT_FILE = "../output.txt";

int readAnagrams(char **inputAnagrams) {
    FILE *fp = fopen(INPUT_TEXT_FILE, "r+");
    int lineNumber = 0;
    if (!fp) {
        perror("Whooops something went wrong, check if the file is in the correct area.");
        return -1;
    } else {
        while (fgets(inputAnagrams[lineNumber], MAX_SENTENCE_LEN, fp)) {
            lineNumber++;
            /*Changes all '\n' to null terminators*/
            for (int j = 0; j < MAX_SENTENCE_LEN; j++) {
                if (inputAnagrams[lineNumber][j] == '\n') {
                    inputAnagrams[lineNumber][j] = '\0';
                }
            }
        }
    }

    return lineNumber;
}

void outputSortedSentences(char **array, int lineLen) {
    FILE *fp = fopen(OUTPUT_TEXT_FILE, "w");
    /*Error Checking*/
    if (!fp) {
        perror("Error locating and opening output file");
    }

    /*Prints the lines one by one*/
    fprintf(fp, "The sorted list of strings is as follows:\n");
    for (int i = 0; i < lineLen; i++) {
        fprintf(fp, "%s", array[i]);
    }
    fprintf(fp,"\n");
    fclose(fp);
}