#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ASCII_GAP 32
#define EXPECTED_NUMBER_OF_ARGUMENTS 2
#define INVALID_NUMBER_OF_ARGUMENTS_ERROR 1


void correctNumberOfArguments(int argc) {
    if (argc != EXPECTED_NUMBER_OF_ARGUMENTS) {
        perror("Need exactly 2 arguments");
        exit(INVALID_NUMBER_OF_ARGUMENTS_ERROR);
    }
}

void transformString(char *input, char *output) {
    if (!*input) {
        *output = '\0';
        return;
    }
    if (*input == ' ') {
        transformString(input + 1, output);
    } else if (*input >= 'a' && *input <= 'z') {
        int curChar = (int) *input;
        *output = (char) (curChar - ASCII_GAP);
        transformString(input + 1, output + 1);
    } else if (*input == '*') {
        *output = *input;
        output++;
        *output = *input;
        transformString(input + 1, output + 1);
    } else {
        *output = *input;
        transformString(input + 1, output + 1);
    }
}

size_t allocateOutputSize(char *input) {
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

void processString(char *input) {
    size_t size = allocateOutputSize(input);
    char *output = (char *) malloc(size * sizeof(char));
    transformString(input, output);
    printf("\"%s\" -> \"%s\"",input,output);
    free(output);
}

int main(int argc, char *argv[]) {
    //correctNumberOfArguments(argc);
    printf("%s\n",argv[0]);
    printf("%s\n",argv[2]);

    processString(argv[1]);
    return 0;
}