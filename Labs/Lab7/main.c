#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define BAD_INPUT_ERROR_CODE 1

bool mystery(int x) {
    if (x <= 0) {
        perror("x needs to be at least 1.");
        exit(BAD_INPUT_ERROR_CODE);
    }
    return ((x - 1) & x) == 0;
}

int midpoint_bad(int x, int y) {
    return (x + y) / 2;
}

int midpoint_better(int x, int y) {
    return x + ((y - x) / 2);
}

int midpoint_knuth(int x, int y) {
    return (x & y) + ((x ^ y) >> 1);
}

int main() {
    printf("Hello, World!\n");
    if(mystery(1))printf("true\n");
    else printf("false\n");
    int x = 2147483647;
    int y = 2147483647;
    printf("The mid point of %d and %d is %d by midpoint_bad(x,y)\n",x,y, midpoint_bad(x,y));
    printf("The mid point of %d and %d is %d by midpoint_better(x,y)\n",x,y, midpoint_better(x,y));
    printf("The mid point of %d and %d is %d by midpoint_knuth(x,y)\n",x,y, midpoint_knuth(x,y));
    return 0;
}
