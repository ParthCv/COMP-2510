#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

void printNum(int n) {
    printf("%d ",n);
    if (n > 0) {

        printNum(n-1);
    }
}

int sumTillN(int n) {
    int sum = 0;
    if(n==1) {
        return 1;
    } else {
        sum = n + sumTillN(n-1);
    }
    return sum;
}

int Fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    } else
        return (Fibonacci(n-1) + Fibonacci(n-2));
}

void printArray(int arr[], int l, int index) {
    if (l == 0) {

    } else if (index >= l) {

    } else {
        printf("%d ", arr[index]);
        printArray(arr,l,index+1);
    }
}

int NumOfDigits(int n) {
    if (n == 0) {
        return 0;
    } else {
        return 1 + NumOfDigits(n/10);
    }
}

int sumOfDigits(int n) {
    if (n == 0) {
        return 0;
    } else {
        return ((n%10) + sumOfDigits(n/10));
    }
}

int gcd(int x, int y) {
    if(x == 0) {
        return y;
    }
    if(y == 0) {
        return x;
    }

    if(x > y) {
        return gcd(x % y, y);
    } else {
        return gcd(x, y % x);
    }
}

int largestInArray(int *arr, int size, int lrg) {
    if(size < 0){
        return lrg;
    } else {
        if(*arr > lrg) {
            lrg = *arr;
        }
        largestInArray(arr+1,size-1,lrg);
    }
}

void reverseString(char *str, int start, int end) {
    if(start > end){
        return;
    } else {
        char temp = *(str + start);
        *(str + start) = *(str + end);
        *(str + end) = temp;

        reverseString(str, start+1, end-1);
    }
}

int factorial(int n) {
    if (n ==0){
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int toBinary(int n) {
    if (n == 0) {
        return 0;
    } else {
        return ((n%2)+ 10 * toBinary(n/2));
    }
}

bool checkForPrime(int n, int i) {
    if(n<=2){
       return n==2 ? true : false;
    } else if (n % i == 0) {
        return false;
    } else if (i*i > n) {
        return true;
    }
    return checkForPrime(n, i+1);
}

int lcm(int a, int b) {
    return ((a*b)/gcd(a,b));
}

void printEven(int cur, int limit) {
    if(cur > limit){
        return;
    } else {
        printf("%d, ",cur);
        printEven(cur+2,limit);
    }
}

void multiplyMatrix(int amat[MAX][MAX], int bmat[MAX][MAX]){

}

bool isPalindrome(char str[], int start, int end) {
    if (start == end) {
        return true;
    } else if (str[start] != str[end]) {
        return false;
    } else if (str[start] == str[end]){
        return isPalindrome(str, start + 1, end - 1);
    }
    return false;
}

int power(int base, int n) {
    if(n != 0) {
        return (base * power(base, n - 1));
    } else {
        return 1;
    }
}

int hailstonevalue(int num){
    if(num%2==0) return num/2;
    else return num*3+1;
}

void hailstone(int num){
    if(num == 1){
        printf("1");
    } else {
        printf("%d ",num);
        hailstone(hailstonevalue(num));
    }
}

void copyStr(char * str1, char * str2) {
    if(*str1 == '\0'){
        *str2 = '\0';
        return;
    } else{
        *str2 = *str1;
        copyStr(++str1,++str2);
    }
}

char firstCapitalChar(char * str) {
    if (*str == '\0') {
        return 1;
    } else if(*str >= 'A' && *str <= 'Z') {
        return *str;
    } else {
        firstCapitalChar(++str);
    }
}

int binarySearch(int arr[], int start, int last, int n) {
    if(last <= 0){
        return -1;
    } else {
        int middle = (start - last)/2 + 1;

        if(arr[middle] == n){
            return middle;
        } else if (arr[middle] > n){
            return binarySearch(arr,start,middle - 1, n);
        } else {
            return binarySearch(arr, middle + 1, last, n);
        }
    }
}

int main() {
    //printNum(50);

    //printf("Sum of numer 1 - 5 = %d", sumTillN(5));

    for(int i = 0; i < 10; i++) {
        printf("%d\n", Fibonacci(i));
    }

//    int arr[5] = {1,2,3,4,5};
//    printArray(arr,5,0);

//    printf("Num of digit in 100 are -> %d", NumOfDigits(100));

//    printf("Sum of digit in 25 are -> %d", sumOfDigits(25));

//    printf("GCD of 336 and 360 = %d",gcd(336,360));

//    int arr[] = {5,10,25,20,15};
//    printf("Largest in array is %d", largestInArray(arr,5,arr[0]));

//    char str[] = "Hello World";
//    reverseString(str,0, strlen(str)-1);
//    printf("%s",str);

//    printf("factorial of 5 is = %d", factorial(5));

//    printf("8 to binary is -> %d", toBinary(8));

//    printf("LCM of 15 and 20 = %d", lcm(15,20));

//    printEven(10,40);

//    bool temp = isPalindrome("MOM",0, strlen("MOM") - 1);
//    printf("%d",temp);

//    printf("3 to the power 4 = %d", power(3,4));

//    hailstone(13);

//    char str1[] = "Hello World";
//    char str2[MAX];
//    copyStr(str1,str2);
//    printf("%s",str2);

//    char str[] = "testString";
//    printf("the first capital letter in string is -> %c", firstCapitalChar(str));

//    int arr[] = {1,2,4,7,10};
//    printf("Found at index => %d", binarySearch(arr,0,4,7));
}

