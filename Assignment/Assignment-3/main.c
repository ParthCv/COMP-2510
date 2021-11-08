#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WRONG_NUMBER_OF_ARGUMENTS_ERROR 1
#define FILE_NOT_FOUND_ERROR 2
#define MEMORY_NOT_ALLOCATED_ERROR 3
#define INITIAL_SIZE 10

/**
 * The structure to hold student data.
 * name - String to store student's name.
 * gpa - float to store student's GPA.
 */

struct Student {
    char name[50];
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
 * @return reallocated array with bigger size
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
    while (!feof(file)) {
        numberOfStudents++;
        students = resizeArrayIfNeeded(students, numberOfStudents, &size);
        fscanf(file, "%s", &students[numberOfStudents - 1].name);
        fscanf(file, "%f", &students[numberOfStudents - 1].gpa);
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
    while ((strcmp(students[numOfStudents].name, " ") != 0) && students[numOfStudents].gpa != 0) numOfStudents++;
    return numOfStudents;
}

/**
 * Prints the Students with a GPA higher than 3.9
 *
 * @param students array with all students
 */

void printStudentData(struct Student *students) {
    int index = 0;
    while ((strcmp(students[index].name, " ") != 0) && students[index].gpa != 0) {
        if (students[index].gpa > 3.9f)
            printf("%s %0.2f\n", students[index].name, students[index].gpa);
        index++;
    }
}

/**
 * Checks if file was successfully found.
 *
 * @param file pointer to the file.
 */

void checkFile(FILE *file){
    if (file == NULL) {
        perror("File could not be opened!");
        exit(FILE_NOT_FOUND_ERROR);
    }
}

/**
 * Opens the file and processes it's data.
 *
 * @param filename name of the file to process
 */

void processFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    checkFile(file);
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
    if (argc != 2) {
        perror("Wrong number of arguments!");
        exit(WRONG_NUMBER_OF_ARGUMENTS_ERROR);
    }
}

int main(int argc, char *argv[]) {
    correctNumberOfArguments(argc);
    processFile(argv[1]);
    return 0;
}