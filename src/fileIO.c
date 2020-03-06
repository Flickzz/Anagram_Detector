//
// Created by Ashraf Ali on 02/02/2020.
//
#include <stdio.h>
#include "fileIO.h"
#include "utilities.h"
#include "anagramSolver.h"
#include <stdlib.h>

/*Location of Input File*/
const char *INPUT_TEXT_FILE = "../input.txt";
/*Location of Output File*/
const char *OUTPUT_TEXT_FILE = "../output.txt";

/*Reads the length of the input file*/
int getNumberOfLines() {
    FILE *fp = fopen(INPUT_TEXT_FILE, "r");

    int lineNum = 0;

    /*Goes character by character until it hits */
    for (int c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n') {
            lineNum++;
        }
    }
    /*Closes the input file*/
    fclose(fp);

    /*Returns the length of the input file*/
    return lineNum + 1;
}

/*Reads in sentences from our input file into a 2d array of characters*/
void readPotentialAnagrams(char **listOfPotentialAnagrams, int lineLen) {
    /*Opens File*/
    FILE *fp = fopen(INPUT_TEXT_FILE, "r+");

    int lineNumber = 0;
    /*Error Checking*/
    if (!fp) {
        perror("Whoops something went wrong, check if the file is in the correct area.");
    }
        /*Goes through the File and inputs each sentence line by line into our 2d array*/
    else {
        while (fgets(listOfPotentialAnagrams[lineNumber], MAX_SENTENCE_LEN, fp)) {
            lineNumber++;
            if (lineNumber == lineLen)
                break;
        }
    }
    /*Gets rid of \n in favour of null terminators*/
    for (int i = 0; i < lineNumber; i++) {
        for (int j = 0; j < MAX_SENTENCE_LEN; j++) {
            if (listOfPotentialAnagrams[i][j] == '\n') {
                listOfPotentialAnagrams[i][j] = '\0';
            }
        }
    }
    fclose(fp);
}

/*Outputs the sorted list of sentences from the 2d array into an output file*/
void outputSortedSentences(char **array, int lineLen) {
    /*Opens output file in write mode*/
    FILE *fp = fopen(OUTPUT_TEXT_FILE, "w");

    /*Error Checking*/
    if (!fp) {
        perror("Error locating and opening output file");
    }

    /*Prints the sorted list of strings line by line*/
    fprintf(fp, "The sorted list of strings is as follows:\n");
    for (int i = 0; i < lineLen; i++) {
        fprintf(fp, "%s\n", array[i]);
    }
    fprintf(fp, "\n");
    fclose(fp);
}

/*Finds and appends all anagram sets into a file*/
void outputAnagrams(char **array, int lineLen) {
    /*Opens File in append mode*/
    FILE *fp = fopen(OUTPUT_TEXT_FILE, "a");
    if (!fp) {
        perror("Error outputing to file");
    }

    /*Stores which indexes have been outputed*/
    bool *visited = (bool *) calloc(lineLen, sizeof(bool));

    /*Stores how many anagrams have been outputed*/
    int anagramCounter = 0;
    /*Determines whether or not the program should go to the next line*/
    bool newLine = false;

    /*Goes through the 2D array of strings, finds anagram subsets and prints them*/
    for (int i = 0; i < lineLen; i++) {
        /*Skips already printed anagrams*/
        if (!visited[i]) {
            /*Skims through other senetences and finds which ones are anagrams of index i*/
            for (int j = i + 1; j < lineLen; j++) {
                /*Checks if i is an anagram of j*/
                if (isAnagram(array[i], array[j])) {
                    /*If the anagram of index i hasn't been printed yet, it'll print it*/
                    if (!visited[i]) {
                        anagramCounter++;//Increments the number of anagrams that have been found
                        fprintf(fp, "Anagram %d: \"%s\" ", anagramCounter, array[i]);
                        /*Adds i to the list of strings that have been printed*/
                        visited[i] = true;
                        newLine = true;
                    }
                    /*Prints the sentences which are anagrams of index i*/
                    fprintf(fp, "\"%s\" ", array[j]);
                    /*Adds j to the list of strings that have been printed*/
                    visited[j] = true;
                }
            }
            /*Outputs a newline after every new anagram set*/
            if (newLine) {
                newLine = false;
                fprintf(fp, "\n");
            }
        }
    }
    fprintf(fp, "\n");
    /*Frees the visited boolean array from memory*/
    free(visited);
    fclose(fp);
}

/*Finds and appends all missing anagram sets into an output file*/
void outputMissingAnagrams(char **array, int lineLen) {
    /*Opens File in append mode*/
    FILE *fp = fopen(OUTPUT_TEXT_FILE, "a");
    /*Error Checking*/
    if (!fp) {
        perror("Error outputing file");
    }

    /*Goes through the 2D array finds sets of missing anagrams*/
    for (int i = 0; i < lineLen; i++) {
        /*Determines whether or not the program should go to the next line*/
        bool newLine = false;

        /*Stores which indexes have been outputed, only stores the printed indexes of the current missing anagram subsets*/
        bool *visited = (bool *) calloc(lineLen, sizeof(bool));

        /*Skims through the list of strings and finds which ones are anagrams of */
        for (int j = 0; j < lineLen; j++) {
            /*Skips already printed missing anagram subsets*/
            if (!visited[j]) {
                /*Stores the number of characters of which i is a missing anagram of j, -1 is stores if i isn't a missing anagram of j*/
                int missingChar = missingAnagram(array[i], array[j]);
                if (missingChar > 0) {
                    newLine = true;
                    /*Prints i and j as missing anagrams*/
                    fprintf(fp, "\"%s\" is a missing anagram of \"%s\"", array[i],
                            array[j]);
                    visited[j] = true;
                    /*Goes through the string list and finds whether or not any index is an anagram of j. If they are, it follows that they are also a missing anagram of i*/
                    for (int k = 0; k < lineLen; k++) {
                        if (j != k && isAnagram(array[j], array[k])) {
                            fprintf(fp, " \"%s\"", array[k]);
                            visited[k] = true;
                        }
                    }
                    /*Prints the number of missing characters that need to be removed*/
                    fprintf(fp, " if %d characters are removed", missingChar);
                }
            }
            /*Goes to the next line after every missing anagram set*/
            if (newLine) {
                newLine = false;
                fprintf(fp, "\n");
            }
        }
        /*Frees the boolean array from memory*/
        free(visited);
    }
    fclose(fp);
}