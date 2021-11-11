#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ASCII_GAP 32
#define EXPECTED_NUMBER_OF_ARGUMENTS 2
#define INVALID_NUMBER_OF_ARGUMENTS_ERROR 1
#define MEMORY_ALLOCATION_ERROR 2

/**
 * Checks if correct number of arguments were passed.
 *
 * @param argc number of arguments
 */

void correctNumberOfArguments(int argc) {
    if (argc != EXPECTED_NUMBER_OF_ARGUMENTS) {
        perror("Need exactly 2 arguments");
        exit(INVALID_NUMBER_OF_ARGUMENTS_ERROR);
    }
}

/**
 * converts the input string to specified format.
 *
 * @param input the string needed to be converted
 * @param output the converted string
 */

void convertString(char *input, char *output) {
    if (!*input) {
        *output = '\0';
        return;
    }
    if (*input == ' ') {
        convertString(input + 1, output);
    } else if (*input >= 'a' && *input <= 'z') {
        int curChar = (int) *input;
        *output = (char) (curChar - ASCII_GAP);
        convertString(input + 1, output + 1);
    } else if (*input == '*') {
        *output = *input;
        output++;
        *output = *input;
        convertString(input + 1, output + 1);
    } else {
        *output = *input;
        convertString(input + 1, output + 1);
    }
}

/**
 * Calculates the size of output string based on the input string
 *
 * @param input the string passed in argument
 */

size_t getOutputSize(char *input) {
    size_t expectedSize = strlen(input) + 1;
    while (*input) {
        if (*input == ' ')
            expectedSize--;
        else if (*input == '*')
            expectedSize++;
        input++;
    }
    return expectedSize;
}

/**
 * checks if memory allocation was successful
 *
 * @param string the string that was allocated
 */

void checkMemoryAllocation(const char *string){
    if(string == NULL){
        perror("Memory Allocation Error");
        exit(MEMORY_ALLOCATION_ERROR);
    }
}

/**
 * processes the input and computes the output and prints them
 *
 * @param input the string passed in argument
 */

void processString(char *input) {
    size_t size = getOutputSize(input);
    char *output = (char *) malloc(size * sizeof(char));
    checkMemoryAllocation(output);
    convertString(input, output);
    printf("\"%s\" -> \"%s\"",input,output);
    free(output);
}

int main(int argc, char *argv[]) {
    correctNumberOfArguments(argc);
    processString(argv[1]);
    return 0;
}