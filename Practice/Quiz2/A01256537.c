#include <stdio.h>
#include <stdbool.h>
/**
 * The bug was that code was not checking for the char 'z'. The map array didn't have enough
 * space to store the frequency of letter 'z'. And in the for loop in printMap function the
 * loop stopped before it could run for c='z'.
 *
 * Also even though the function says it only prints the alphabets, but it also prints the
 * characters between 'Z' and 'a'
 */

bool isAlphabet(char c){
    return (c >= 97 && c <= 122) || (c >= 65 && c <= 90);
}

void printMap(int *map) {
    for (int c = 'A'; c <= 'z'; c++) { //We should also run for c='z'
        if (map[c] && isAlphabet((char)c)) {//To see we only print the alphabets
            printf("%c: %d\n", c, map[c]);
        }
    }
}

void printLettersOfAlphabetFrequencyInString(char *input) {
    // Recall that characters have integer values.
    int map['z' + 1] = {0}; //size should be 1 greater, so we have space for 'z'

    while (*input) {
        map[*input]++;
        input++;
    }

    printMap(map);
}

int main() {
    printLettersOfAlphabetFrequencyInString("Seyed was here.");
    return 0;
}
