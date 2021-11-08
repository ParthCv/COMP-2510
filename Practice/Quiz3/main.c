#include <stdio.h>
#include <stdlib.h>

#define EMPTY_ARRAY_ERROR 2
#define MEMORY_ALLOCATION_ERROR 3

int* subtractArray(int* firstArray, int* secondArray, int size){
    if(size == 0){
        perror("Empty array");
        exit(EMPTY_ARRAY_ERROR);
    }
    int *subtractArray = (int *)malloc(size * sizeof(int));
    if(subtractArray == NULL) {
        perror("Error allocating memory!");
        exit(MEMORY_ALLOCATION_ERROR);
    }
    for(int i = 0; i < size; i++){
        subtractArray[i] = firstArray[i] - secondArray[i];
    }
    return subtractArray;
}

int main() {
    printf("Hello, World!\n");
    int firstArray[] = {1,2,3,4,5};
    int secondArray[] = {4,3,2,1,5};
    int *result = subtractArray(firstArray,secondArray,5);
    for(int i=0; i<5; i++)
        printf("%d\n",result[i]);
    free(result);
    return 0;
}
