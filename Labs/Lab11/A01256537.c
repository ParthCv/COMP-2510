#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE_OF_ARRAY 5

/**
 * Compares two integers.
 */

bool compareInt(void *first, void *second) {
    int *firstInt = (int *) first;
    int *secondInt = (int *) second;
    return *firstInt > *secondInt;
}

/**
 * Compares two doubles.
 */

bool compareDouble(void *first, void *second) {
    double *firstDouble = (double *) first;
    double *secondDouble = (double *) second;
    return *firstDouble > *secondDouble;
}

/**
 * Compares two characters.
 */

bool compareChar(void *first, void *second) {
    char *firstChar = (char *) first;
    char *secondChar = (char *) second;
    return *firstChar > *secondChar;
}

/**
 * Swap the values of the void pointers.
 */

void swap(void *first, void *second, size_t numberOfBytes) {
    char temp[numberOfBytes];
    memcpy(temp, first, numberOfBytes);
    memcpy(first, second, numberOfBytes);
    memcpy(second, temp, numberOfBytes);
}

/**
 * Function for generic bubble sort.
 */

void genericBubbleSort(void *array, size_t size, size_t byteSize, bool(*compare)(void *first, void *second)) {
    while (true) {
        bool swapped = false;
        for (int i = 1; i < size; i++) {
            if (compare((char *) array + byteSize * (i - 1), (char *) array + byteSize * i)) {
                swapped = true;
                swap((char *) array + byteSize * (i - 1), (char *) array + byteSize * i, byteSize);
            }
        }
        if (!swapped) {
            return;
        }
    }
}

int main() {
    int arrayInt[SIZE_OF_ARRAY] = {10, 1, 8, 5, 7};
    printf("Unsorted Integer array -\n");
    for (int i = 0; i < SIZE_OF_ARRAY; i++) {
        printf("A[%d] = %d\t", i, arrayInt[i]);
    }
    genericBubbleSort(arrayInt, SIZE_OF_ARRAY, sizeof(int), compareInt);
    printf("\n");
    printf("Sorted Integer array -\n");
    for (int i = 0; i < SIZE_OF_ARRAY; i++) {
        printf("A[%d] = %d\t", i, arrayInt[i]);
    }
    printf("\n");
    char arrayChar[SIZE_OF_ARRAY] = {'y', 'r', 'a', 'c', 'z'};
    printf("Unsorted Character array -\n");
    for (int i = 0; i < SIZE_OF_ARRAY; i++) {
        printf("A[%d] = %c\t", i, arrayChar[i]);
    }
    printf("\n");
    genericBubbleSort(arrayChar, SIZE_OF_ARRAY, sizeof(char), compareChar);
    printf("Sorted Character array -\n");
    for (int i = 0; i < SIZE_OF_ARRAY; i++) {
        printf("A[%d] = %c\t", i, arrayChar[i]);
    }
    printf("\n");
    double arrayDouble[SIZE_OF_ARRAY] = {1.4, 6.7, 7.7, 8.9, 1.56};
    printf("Unsorted Double array -\n");
    for (int i = 0; i < SIZE_OF_ARRAY; i++) {
        printf("A[%d] = %lf\t", i, arrayDouble[i]);
    }
    printf("\n");
    genericBubbleSort(arrayDouble, SIZE_OF_ARRAY, sizeof(double), compareDouble);
    printf("Sorted Double array -\n");
    for (int i = 0; i < SIZE_OF_ARRAY; i++) {
        printf("A[%d] = %lf\t", i, arrayDouble[i]);
    }
    return 0;
}
