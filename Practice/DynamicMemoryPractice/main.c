#include <stdio.h>
#include <stdlib.h>

#define ERROR_ALLOCATING_MEMORY 2

int *integerFun(int *input, int size) {
    int sizeOfResult = 0;
    for (int i = 0; i < size; i++) {
        sizeOfResult += input[i];
    }
    printf("size = %d\n", sizeOfResult);
    int *result = (int *) malloc(sizeOfResult * sizeof(int));
    int *tempPointer = result;
    if (result == NULL) {
        perror("Error Reallocating Memory");
        exit(ERROR_ALLOCATING_MEMORY);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < input[i]; j++) {
            result[j] = input[i];
        }
    }
    return tempPointer;
}

int main() {
    printf("Hello, World!\n");
    int arr[] = {1, 2, 3};
    int *res = integerFun(arr, 3);
    for (int i = 0; i < 6; i++) {
        printf("%d\n", res[i]);
    }
    free(res);
    return 0;
}
