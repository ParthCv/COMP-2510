#include <stdio.h>
#include <string.h>

#define MAX_COLUMNS 10

/**
 * Function to convert the binary number to decimal number.
 *
 * @param binaryArray - the array with binary digits.
 * @param size - size of the array.
 * @return the decimal integer.
 */

int fromBinary(int *binaryArray, int size) {
    if(size == 0) {
        return 0;
    }
    int number = fromBinary(binaryArray, size - 1);
    return 2 * number + binaryArray[size - 1];
}

/**
 * function to read and store binary bit in a line.
 *
 * @param file - pointer to the file.
 * @param binaryArray - array to store the binary bit in one line.
 * @param numberOfColumns - number of columns in the file.
 */

void readNextNumberFromFile(FILE * file, int binaryArray[MAX_COLUMNS], int numberOfColumns) {
    for(int i = 0; i < numberOfColumns; i++){
        fscanf(file,"%d", &binaryArray[i]);
    }
}

/**
 * function to covert the binary bit of a file to decimal and print them.
 *
 * @param fileName - the name of the file to read.
 */

void processFile(char *fileName) {
    FILE *file;
    file = fopen(fileName, "r");
    if(file == NULL) {
        printf("Could not open file for reading\n");
        return;
    }

    int numberOfRows;
    int numberOfColumns;

    fscanf(file,"%d %d",&numberOfRows, &numberOfColumns);
    for(int i = 0; i < numberOfRows; i++) {
        int binArr[numberOfColumns];
        readNextNumberFromFile(file, binArr, numberOfColumns);
        int num = fromBinary(binArr, numberOfColumns);
        printf("%d\n\n",num);
    }
}

int main() {
    char FileName[] = "Math.txt";
    processFile(FileName);
    return 0;
}
