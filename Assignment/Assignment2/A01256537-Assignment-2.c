#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARACTER 100

/**
 * wordSearch - searches the word in the string and returns it's position.
 *
 * @param string - the pointer to line to find the word in.
 * @param word - the pointer to word that need to be found.
 * @return index of the word if found, otherwise returns -1.
 */

int wordSearch(char * string, char * word) {
    char * tempString = string;
    char * tempWord = word;
    int flag = 0;

    for(int i = 0; i < strlen(string); i++) {
        if(*tempString == *tempWord) {
            char * tempPointer = tempString;
            int wordIndex;
            bool charFound = true;
            for(wordIndex = 0; wordIndex < strlen(word) && charFound; wordIndex++) {
                if(*tempPointer == *tempWord) {
                    tempWord++;
                    tempPointer++;
                } else {
                    charFound = false;
                }
            }
            tempWord = word;
            if(wordIndex == strlen(word)) {
                return i;
                flag = 1;
            }
        }
        tempString++;
    }
    if(flag == 0) {
        return -1;
    }
}

/**
 * processFile - opens and reads the file and print the line number and position of the word in the file.
 *
 * @param fileName - name of the file to read.
 * @param word - the word that need to searched in the file.
 */

void processFile(char * fileName, char * word) {
    FILE * file = fopen(fileName, "r");
    if(file == NULL) {
        printf("File not found.");
    }

    char line[MAX_CHARACTER];
    int index = 0;
    int lineNumber = 1;
    int flag = 0;

    while (fgets(line, MAX_CHARACTER, file) != NULL && flag == 0) {
        index = wordSearch(line, word);
        if(index != -1) {
            printf("Line: %d, character: %d\n", lineNumber, index+1);
            flag = 1;
        }
        lineNumber++;
    }
    if(flag == 0){
        printf("Not found!");
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if(argc != 3){
        perror("Wrong Number of Arguments");
        return -1;
    }
    processFile(argv[1],argv[2]);
    return 0;
}