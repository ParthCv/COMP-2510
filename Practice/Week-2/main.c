#include <stdio.h>

void swap(int *firstPointer, int *secondPointer) {
  int temporary = *firstPointer;
  *firstPointer = *secondPointer;
  *secondPointer = temporary;
}

void mysteryFunction(int * firstPointer, int * secondPointer) {
    int * temp = firstPointer;
    firstPointer = secondPointer;
    secondPointer = temp;
    *temp = 3;
}

void incrementByOne(int * pointer) {
    *pointer += 1;
}

int main() {
//  int first = 1, second = 2;
//  int *p = &first;
//  swap(&first, &second);
//  printf("First %d, Second: %d\n", first, second);
//  printf("%d",&first);
//    printf("%d",*p);
//
//    printf("\n");
//
//    int number = 1;
//    int *pointerToNumber = &number;
//    printf("Variable value: %d, Variable address: %p\n", number, &number);
//    printf("Pointer value: %p, Pointer reference value: %d\n", pointerToNumber, *pointerToNumber);
//
//    int first = 1, second = 2;
//    mysteryFunction(&first, &second);
//    printf("First: %d, Second: %d\n", first, second);

    int one = 1;
    printf("%d\n",one);
    incrementByOne(&one);
    printf("%d\n",one);
    incrementByOne(&one);
    printf("%d\n",one);

    return 0;
}

