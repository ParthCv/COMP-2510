#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 5
#define MEMORY_ALLOCATION_ERROR 125

int *resizeArrayIfNeeded(int *array, int usedLength, int *arraySize) {
    if(usedLength <= *arraySize) {
        return array;
    }
    printf("Oops, need to resize!\n");
    *arraySize *= 2;
    int *newArray = (int *) realloc(array,*arraySize * sizeof(int));
    if(newArray == NULL){
        perror("Realloc didn't work");
        exit(MEMORY_ALLOCATION_ERROR);
    }
    return newArray;
}

int main() {
    int length = 0;
    int curNum = 0;
    int size = INITIAL_SIZE;
    int *array = (int *) calloc(size,size * sizeof(int));
    if(array == NULL){
        perror("Malloc didn't work");
        exit(MEMORY_ALLOCATION_ERROR);
    }
    printf("Enter the numbers. (negative number to stop)\n");
    scanf("%d",&curNum);
    while (curNum > 0) {
        length++;
        array = resizeArrayIfNeeded(array,length,&size);
        array[length-1] = curNum;
        scanf("%d",&curNum);
    }
    printf("The array has the elements -\n");
    for(int i = 0; i < size && array[i] != 0; i++){
        printf("A[%d] = %d\n",i,array[i]);
    }
    free(array);
    return 0;
}
