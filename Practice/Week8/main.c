#include <stdio.h>
#include <stdbool.h>

#define UPPER_BOUND 1001

int turnOnFirstAndThirdBit(int n){
    int mask = 5;
    return (n | mask);
}

int turnOnSecondAndThirdBit(int n){
    int mask = 6;
    return (n | mask);
}

int turnOffFourthBit(int n){
    int mask = 23;
    return n & mask;
}

int bitFun(int n){
    int secondAndThirdBit = turnOnSecondAndThirdBit(n);
    return turnOffFourthBit(secondAndThirdBit);
}

bool checkForAnagram(const int arr1[], const int arr2[], size_t size1, size_t size2){
    if(size1 != size2){
        return false;
    }
    int mapForArray1[UPPER_BOUND]={0};
    int mapForArray2[UPPER_BOUND]={0};
    for(int i = 0; i< size1; i++){
        mapForArray1[arr1[i]]++;
        mapForArray2[arr2[i]]++;
    }
    for(int i = 0; i < UPPER_BOUND; i++){
        if(mapForArray1[i] != mapForArray2[i]){
            return false;
        }
    }
    return true;
}

int main() {
    int arr1[4] = {1,2,2,2};
    int arr2[4] = {2,1,2,2};
    if(checkForAnagram(arr1,arr2,4,4)){
        printf("They are anagrams");
    } else {
        printf("Not Anagrams");
    }
    return 0;
}
