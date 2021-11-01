#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define FILE_NOT_FOUND_ERROR 120
#define MAX_LINES_IN_FILE 200
#define MAX_INPUT_LENGTH 100

/**
 * mapCharactersUsingFile - reads file and transforms the input string if characters appear in file
 *                          the specified characters from the file into the output string.
 *
 * @param fileName - the file to be read.
 * @param input - the string to be mapped and transformed.
 * @param output - the transformed string.
 */

void mapCharactersUsingFile(char *fileName, char *input, char *output) {
    FILE * file = fopen(fileName,"r");
    if(file == NULL){
        perror("File Not Found!");
        exit(FILE_NOT_FOUND_ERROR);
    }
    char transformArray[MAX_LINES_IN_FILE];
    char transformedArray[MAX_LINES_IN_FILE];
    int index = 0;
    while(!feof(file)) {
        fscanf(file, "%c %c\n", &transformArray[index], &transformedArray[index]);
        index++;
    }
    fclose(file);
    bool flag = true;
    while(*input){
        char * pointerToTranformArray = transformArray;
        char * pointerToTransformedArray = transformedArray;
        while (*pointerToTranformArray && flag){
            if(*input == *pointerToTranformArray) {
                *output = *pointerToTransformedArray;
                flag = false;
            }
            pointerToTranformArray++;
            pointerToTransformedArray++;
        }
        if(flag){
            *output = *input;
        }
        input++;
        output++;
        flag = true;
    }


}

int main() {
    char * fileName = "input.txt";
    char testArray1[MAX_INPUT_LENGTH];
    char testArray2[MAX_INPUT_LENGTH];
    char testArray3[MAX_INPUT_LENGTH];
    mapCharactersUsingFile(fileName,"Ascend.",testArray1);
    printf("input = \"%s\" is mapped to output = \"%s\"\n","Ascend.",testArray1);
    mapCharactersUsingFile(fileName,"Seyed",testArray2);
    printf("input = \"%s\" is mapped to output = \"%s\"\n","Seyed",testArray2);
    mapCharactersUsingFile(fileName,"Adam's name.",testArray3);
    printf("input = \"%s\" is mapped to output = \"%s\"\n","Adam's name.",testArray3);
    return 0;
}
