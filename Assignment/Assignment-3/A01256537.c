#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CORRECT_NUMBER_OF_ARGUMENTS 2
#define WRONG_NUMBER_OF_ARGUMENTS_ERROR 1
#define FILE_NOT_FOUND_ERROR 2
#define MEMORY_NOT_ALLOCATED_ERROR 3
#define INITIAL_SIZE 10
#define MAX_LENGTH 50
#define GPA_THRESHOLD 3.9f

/**
 * The structure to hold student data.
 * name - String to store student's name.
 * gpa - float to store student's GPA.
 */

struct Student {
    char *name;
    float gpa;
};

/**
 * Checks if memory allocation was successful or not.
 *
 * @param students dynamically allocated Student array
 */

void checkMemoryAllocation(struct Student *students) {
    if (students == NULL) {
        perror("Error reallocating memory!");
        exit(MEMORY_NOT_ALLOCATED_ERROR);
    }
}

/**
 * Resizes a dynamically allocated array if length is bigger than the initial size.
 *
 * @param students - array of Students
 * @param usedLength - used length of the allocated memory
 * @param arraySize - current allocated size of the array
 * @return reallocated array with twice the size
 */

struct Student *resizeArrayIfNeeded(struct Student *students, int usedLength, int *arraySize) {
    if (usedLength <= *arraySize) {
        return students;
    }
    *arraySize *= 2;
    struct Student *resizedStudents = (struct Student *) realloc(students, *arraySize * sizeof(struct Student));
    checkMemoryAllocation(resizedStudents);
    return resizedStudents;
}

/**
 * Reads the file and stores its data in a Student array
 *
 * @param file - pointer to file with student data
 * @return student array with data
 */

struct Student *readAndStoreFileData(FILE *file) {
    int size = INITIAL_SIZE;
    struct Student *students = (struct Student *) calloc(size, size * sizeof(struct Student));
    checkMemoryAllocation(students);
    int numberOfStudents = 0;
    float tempGpa = 0;
    char tempName[MAX_LENGTH] = {0};
    struct Student tempStudent;
    while (fscanf(file,"%s %f",tempName,&tempGpa) == 2) {
        numberOfStudents++;
        students = resizeArrayIfNeeded(students, numberOfStudents, &size);
        tempStudent.gpa = tempGpa;
        tempStudent.name = strdup(tempName);
        students[numberOfStudents-1] = tempStudent;
    }
    return students;
}

/**
 * Sorts the array using the bubble sort method.
 *
 * @param students array with all the students
 * @param size the number of students in the stu
 */

struct Student *sortTheArray(struct Student *students, int size) {
    struct Student *tempStudents = students;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (tempStudents[j].gpa > tempStudents[j + 1].gpa) {
                struct Student temp = tempStudents[j];
                tempStudents[j] = tempStudents[j + 1];
                tempStudents[j + 1] = temp;
            }
        }
    }
    return tempStudents;
}

/**
 * returns the number of students in array.
 *
 * @param students array with all students
 * @return the number of students
 */

int arraySize(struct Student *students) {
    int numOfStudents = 0;
    while (students[numOfStudents].gpa != 0 && students[numOfStudents].name != NULL) numOfStudents++;
    return numOfStudents;
}

/**
 * Prints the Students with a GPA higher than 3.9
 *
 * @param students array with all students
 */

void printStudentData(struct Student *students) {
    int index = 0;
    while (students[index].gpa != 0 && students[index].name != NULL) {
        if (students[index].gpa > GPA_THRESHOLD)
            printf("%s %lf\n", students[index].name, students[index].gpa);
        index++;
    }
}

/**
 * Checks if file was successfully found.
 *
 * @param file pointer to the file.
 */

FILE *openFile(char *filename){
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("File could not be opened!");
        exit(FILE_NOT_FOUND_ERROR);
    }
    return file;
}

/**
 * Opens the file and processes it's data.
 *
 * @param filename name of the file to process
 */

void processFile(char *filename) {
    FILE *file = openFile(filename);
    struct Student *students = readAndStoreFileData(file);
    students = sortTheArray(students, arraySize(students));
    printStudentData(students);
    free(students);
    fclose(file);
}

/**
 * Checks if correct number of command line arguments were provided.
 *
 * @param argc count of command line arguments
 */

void correctNumberOfArguments(int argc){
    if (argc != CORRECT_NUMBER_OF_ARGUMENTS) {
        perror("Wrong number of arguments!");
        exit(WRONG_NUMBER_OF_ARGUMENTS_ERROR);
    }
}

int main(int argc, char *argv[]) {
    correctNumberOfArguments(argc);
    processFile(argv[1]);
    return 0;
}