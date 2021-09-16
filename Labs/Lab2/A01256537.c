#include <stdio.h>
#include <stdbool.h>

void printMultiplicationTable(){
    printf("Multiplication for numbers upto 10\n");
    printf("-------------------------------------------------------------\n");
    for(int i = 1; i <= 10; i++) {
        printf("Table of %d\n", i);
        for(int j = 1; j <= 10; j++) {
            printf("\t%d x %d = %d\n", i, j, j*i);
        }
        printf("----------------------\n");
    }
}

bool isPalindrome(int elements[], int size) {
    for(int i = 0; i < size/2 && size != 0; i++) {
        if(elements[i] != elements[size-i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    printf("Hello, World!\n");
    printMultiplicationTable();

    int arr1[] = {1,2,3,4};
    int arr2[] = {1,2,3,2,1};
    int arr3[] = {1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1};
    int arr4[] = {1};
    int arr1Size = 4;
    int arr2Size = 5;
    int arr3Size = 20;
    int arr4Size = 1;

    if(isPalindrome(arr1,arr1Size)) {
        printf("Array 1 is a palindrome\n");
    } else {
        printf("Array 1 is not a palindrome\n");
    }

    if(isPalindrome(arr2,arr2Size)) {
        printf("Array 2 is a palindrome\n");
    } else {
        printf("Array 2 is not a palindrome\n");
    }

    if(isPalindrome(arr3,arr3Size)) {
        printf("Array 3 is a palindrome\n");
    } else {
        printf("Array 3 is not a palindrome\n");
    }

    if(isPalindrome(arr4,arr4Size)) {
        printf("Array 4 is a palindrome\n");
    } else {
        printf("Array 4 is not a palindrome\n");
    }

    return 0;
}
