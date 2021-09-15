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

}

int main() {
    printf("Hello, World!\n");
    printMultiplicationTable();
    return 0;
}
