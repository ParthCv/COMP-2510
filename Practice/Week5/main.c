#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES_IN_FILE 200
#define MAX_CHARACTERS_IN_NAME 50

//void topStudents(char * fileName){
//    FILE * file = fopen(fileName,"r");
//    if(file == NULL) printf("Could not open file!");
//    char studentName[MAX_LINES_IN_FILE];
//    int studentScore[MAX_LINES_IN_FILE];
//    int line = 0;
//    while(fscanf(file,"%s %d",studentName[line],studentScore[line]) > 0){
//
//    }
//}

void swap(int * firstNum, int * secondNum) {
    int temp = *firstNum;
    *firstNum = *secondNum;
    *secondNum = temp;
}

void reverseArrayRecursively(int *array, int size) {
    if(size == 1){
        return;
    }
    if(size == 0){
        return;
    } else {
        swap(array,array+(size-1));
        reverseArrayRecursively(array+1,size-2);
    }

}

int main() {
    printf("Hello, World!\n");
//    char * fileName = "students.txt";
//    topStudents(fileName);
    int arr[] = {1,2,3,4};
    reverseArrayRecursively(arr,4);
    for (int i = 0; i < 4; i++) {
        printf("%d\t",arr[i]);
    }
    return 0;
}
