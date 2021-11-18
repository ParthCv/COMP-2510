#include <stdio.h>
#include <stdbool.h>

//Easy

void oddOrEven(int x) {
    if (x % 2 == 0) {
        printf("%d is an even number\n", x);
    } else {
        printf("%d is a odd number\n", x);
    }
}

void function(int x, void(*functionPointer)(int)) {
    printf("calling the function on %d\n", x);
    functionPointer(x);
}

//Medium

bool compareInteger(void *integerOne, void *integerTwo) {
    int *argOne = (int *) integerOne;
    int *argTwo = (int *) integerTwo;
    return *argOne > *argTwo;
}

bool compareFloat(void *floatOne, void *floatTwo) {
    float *argOne = (float *) floatOne;
    float *argTwo = (float *) floatTwo;
    return *argOne > *argTwo;
}

int largestOfThree(void *first, void *second, void *third, bool(*compare)(void *, void *)) {
    if (compare(first, second)) {
        if (compare(first, third)) {
            return 1;
        }
        return 3;
    }
    return 2;
}

int main() {
    printf("Hello, World!\n");
    function(6, oddOrEven);
    int a = 6;
    int b = 7;
    int c = 4;
    float af = 10.90f;
    float bf = 17.089f;
    float cf = 9.89f;
    printf("largest out of a,b and c is - %d\n", largestOfThree(&a, &b, &c, compareInteger));
    printf("largest float out of a,b and c is - %d\n", largestOfThree(&af, &bf, &cf, compareFloat));
    return 0;
}
