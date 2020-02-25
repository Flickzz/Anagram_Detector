//
// Created by Ashraf Ali on 02/02/2020.
//
#include <stdio.h>
#include <stdbool.h>
#include "fileIO.h"
#include "utilities.h"
#include "anagramSolver.h"

const char *INPUT_TEXT_FILE = "../input.txt";
const char *OUTPUT_TEXT_FILE = "../output.txt";

/*Reads the length of the input file*/
int getNumberOfLines() {
    //Careful of /n different on different computers
    FILE *fp = fopen(INPUT_TEXT_FILE, "r");
    int lineNum = 0;
    for (int c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n') {
            lineNum++;
        }
    }
    fclose(fp);
    return lineNum;
}

void readAnagrams(char **inputAnagrams) {
    FILE *fp = fopen(INPUT_TEXT_FILE, "r+");
    int lineNumber = 0;
    if (!fp) {
        perror("Whoops something went wrong, check if the file is in the correct area.");
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
        fprintf(fp, "%s\n", array[i]);
    }
    fprintf(fp, "\n");
    fclose(fp);
}

void outputAnagrams(char **array, int lineLen) {
    FILE *fp = fopen(OUTPUT_TEXT_FILE, "a");
    if (!fp) {
        perror("Error outputing to file");
    }
    bool visited[lineLen];

    int anagramCounter = 0;//Stores how many anagrams have been outputed
    bool newLine = false;
    for (int i = 0; i < lineLen; i++) {
        /*Skips already printed anagrams*/
        if (!visited[i]) {
            /*Skims through other senetences and finds which ones are anagrams of index i*/
            for (int j = i + 1; j < lineLen; j++) {
                if (isAnagram(array[i], array[j])) {
                    /*If the anagram of index i hasn't been printed yet, it'll print it*/
                    if (!visited[i]) {
                        anagramCounter++;
                        fprintf(fp, "Anagram %d: \"%s\" ", anagramCounter, array[i]);
                        visited[i] = true;
                        newLine = true;
                    }
                    /*Prints the sentences which are anagrams of index i*/
                    fprintf(fp, "\"%s\" ", array[j]);
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
    fclose(fp);
}

void outputMissingAnagrams(char **array, int lineLen) {
    FILE *fp = fopen(OUTPUT_TEXT_FILE, "a");
    if (!fp) {
        perror("Error outputing file");
    }
    bool visited[lineLen];
    bool newLine = false;

    for (int i = 0; i < lineLen; i++) {
        if (!visited[i]) {
            for (int j = 0; j < lineLen; j++) {
                int missingCharacters = missingAnagram(array[i], array[j]);
                if (missingCharacters > 0) {
                    if (!visited[i]) {
                        visited[i] = true;
                        fprintf(fp, "if %d characters are removed, \"%s\" is a missing anagram of", missingCharacters, array[i]);
                        newLine = true;
                    }
                    fprintf(fp, " \"%s\" ", array[j]);
                    visited[j] = true;
                }
            }
        }
        /*Outputs a newline after every new anagram set*/
        if (newLine) {
            newLine = false;
            fprintf(fp, "\n");
        }
    }
    fclose(fp);
}