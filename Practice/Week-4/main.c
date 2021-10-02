#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void removeCharA(char* input, char* output) {

    if(input[0] == 'A') {
        output = *input + 1;
        removeCharA(input++, output);
    }

    removeCharA(input++, output );
}

int maxInt(int x, int y)
{
    return x > y ? x : y;
}

int recursiveMaxEle(int* arr, int length)
{
    if (length == 1) {
        return arr[0];
    }
    return maxInt(recursiveMaxEle(arr, length - 1), arr[length - 1]);
}

bool hasRepeatedInteger(int* arr, int length) {
    if(length == 0 || length == 1) {
        return false;
    } else {
        int* tempArr = arr;
        for(int i = 0; i < length; i++) {
            if(arr[i] == arr[0]) {
                return true;
            } else {
                tempArr[i-1] = arr[i];
            }
        }
        int n = sizeof(tempArr)/sizeof(tempArr[0]);
        return hasRepeatedInteger(tempArr,n);
    }

}

int main() {
    printf("Hello, World!\n");
//    char input[10] = "";
//    char output[10];
//    removeCharA(input,output);
//    printf("%s",output);
    int arr[5] = {10,4,8,5,12};
    printf("%d",recursiveMaxEle(arr,5));

    int arr2[5] = {10,5,8,5,12};
    if(recursiveMaxEle(arr2,5)) {
        printf("worked");
    };

    return 0;
}
