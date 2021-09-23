#include <stdio.h>
#include <string.h>

/**
 * Author - Parth Chaturvedi
 * Version - 23/09/21
 */

void printTokens(char* inputString) {

    /*
     * To get rid of trailing whitespaces.
     */

    int lastChar = strlen(inputString) - 1;
    while (lastChar > 0) {
        if(inputString[lastChar] == ' ' || inputString[lastChar] == '\n' || inputString[lastChar] == '\t'){
            lastChar--;
        } else {
            break;
        }
    }

    inputString[lastChar + 1] = '\0';

    /*
     * To get rid of leading whitespace.
     */

    int whitespaceCount = 0;

    while (inputString[whitespaceCount] == ' ' || inputString[whitespaceCount] == '\n'
            || inputString[whitespaceCount] == '\t') {
        whitespaceCount++;
    }

    if (whitespaceCount != 0) {
        int i = 0;
        while (inputString[i + whitespaceCount] != '\0') {
            inputString[i] = inputString[whitespaceCount + i];
            i++;
        }
        inputString[i] = '\0';
    }

    int k = 0;

    while (inputString[k]) {
        if (inputString[k] == ' ' || inputString[k] == '\t' || inputString[k] == '\n') {
            if (inputString[k - 1] == ' ' || inputString[k - 1] == '\t' || inputString[k - 1] == '\n') {
            } else {
                printf("\n");
            }
        } else {
            printf("%c",inputString[k]);

        }
        k++;
    }

}

void printOrignal(char* str) {
    printf("%s", str);
}

int main() {
    char str1[] = " \n   hi  i AM     \tPARTH\n\n\t";
    char str2[] = "  C is \n not easy    ";
    printf("Orignal String:- \n");
    printOrignal(str1);
    printf("\nTokenised String:- \n");
    printTokens(str1);
    printf("\n");
    printf("\nOrignal String:- \n");
    printOrignal(str2);
    printf("\nTokenised String:- \n");
    printTokens(str2);

    return 0;
}
