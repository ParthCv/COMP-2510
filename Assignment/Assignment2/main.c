#include <stdio.h>
#include <string.h>

#define MAX_CHARACTER 100

int search(char * string, char * word) {
    char * tempString = string;
    char * tempWord = word;
    int flag = 0;

    for(int i = 0; i < strlen(string); i++) {
        if(*tempString == *tempWord) {
            char * tempPointer = tempString;
            int j;
            for(j = 0; j < strlen(word); j++) {
                if(*tempPointer == *tempWord) {
                    tempWord++;
                    tempPointer++;
                } else {
                    flag = 1;
                }
            }

            tempWord = word;
            if(flag == 0) {
                return i;
            }
        }
        tempString++;
    }
    if(flag == 1) {
        return -1;
    }
}

int wordSearch(char * string, char * word) {
    char * tempString = string;
    char * tempWord = word;
    int flag = 0;

    for(int i = 0; i < strlen(string); i++) {
        if(*tempString == *tempWord) {
            char * tempPointer = tempString;
            int j;
            for(j = 0; j < strlen(word); j++) {
                if(*tempPointer == *tempWord) {
//                    printf("%c\n",*tempWord);
//                    printf("%c\n",*tempPointer);
//                    printf("\n");
                    tempWord++;
                    tempPointer++;
                } else {
                    break;
                }
            }

            tempWord = word;
            if(j == strlen(word)) {
                flag = 1;
                return i;
            }
        }
        tempString++;
    }
    if(flag == 0) {
        return -1;
    }
}

void processFile(char * fileName, char * word) {
    FILE * file = fopen(fileName, "r");
    if(file == NULL) {
        printf("File not found.");
    }

    char line[MAX_CHARACTER];
    int index = 0;
    int lineNumber = 1;
    int flag = 0;

    while (fgets(line, MAX_CHARACTER, file) != NULL) {
        index = search(line, word);
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
}