#include <stdio.h>
#include <stdbool.h>

void printMultiplicationTable(){
    printf("Multiplication for numbers upto 10\n");
    printf("------------------------------------------------\n\t*\t");
    for (int i = 1; i <= 10; i++) {
        printf("%3d\t",i);
    }
    printf("\n");
    printf("------------------------------------------------\n");
    for (int i = 1; i <= 10; i++) {
        printf("%3d | ", i);
        for (int j = 1; j <= 10; j++) {
            printf("%3d\t", i*j);
        }
        printf("\n");
    }
}

bool isPalindrome(const int elements[], int size) {
    for(int i = 0; i < size/2 && size != 0; i++) {
        if(elements[i] != elements[size-i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    printMultiplicationTable();

    printf("\n");

    //Test Cases for Palindrome function

    /* Empty array
     * expected result - true
     */

    int array1[] = {};
    int array1Size = 0;

    if (isPalindrome(array1,array1Size) == true) {
        printf("{} is a palindrome\n");
    }

    /* Array with 1 integer
     * expected result  - true
     */

    int array2[] = {1};
    int array2Size = 1;

    if (isPalindrome(array2,array2Size) == true) {
        printf("{1} is a palindrome\n");
    }

    /* Non Palindrome array
     * expected result - false
     */

    int array3[] = {1,2,3,4};
    int array3Size = 4;

    if (isPalindrome(array3,array3Size) == false) {
        printf("{1,2,3,4} is not a palindrome\n");
    }

    /* A Palindrome array
     * expected result - true
     */

    int array4[] = {1,2,3,3,2,1};
    int array4Size = 6;

    if (isPalindrome(array4,array4Size) == true) {
        printf("{1,2,3,3,2,1} is a palindrome\n");
    }

    /* A Palindrome array with an odd number size
     * expected result - true
     */

    int array5[] = {5,4,9,8,9,4,5};
    int array5Size = 7;

    if (isPalindrome(array5,array5Size) == true) {
        printf("{5,4,9,8,9,4,5} is a palindrome\n");
    }

    return 0;
}
