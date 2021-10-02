#include <stdio.h>
#include <string.h>

/**
 * findMinDistance() - finds the repeated character in the string with the minimum
 * distance between two consecutive occurrences.
 *
 * @param inputString - the string to find repeated characters.
 */

void findMinDistance(char* inputString) {
    int indexOfLetter = 0;
    int minDistance = strlen(inputString);

    for(int i = 0; i < strlen(inputString); i++) {
        for (int j = i + 1; j < strlen(inputString) ; j++) {
            if(inputString[i] == inputString[j] && minDistance > (j-i)) {
                indexOfLetter = i;
                minDistance = j - i - 1;
            }
        }
    }

    if (minDistance == strlen(inputString)) {
        printf("No repeats found!\n");
    } else {
        printf("Repeated char = %c, min distance = %d\n", inputString[indexOfLetter], minDistance);
    }
}

int main() {

    //Test Cases

    findMinDistance("123");
    findMinDistance("Hi there, how is it going?");
    findMinDistance("Hello there, how is it going?");

    return 0;
}
