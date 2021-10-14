#include <stdio.h>

#define MAX_CHAR 500

/**
 * copyFile - Takes two file paths and copies the content of the first file path in the new one.
 *
 * @param file - file path of the existing file.
 * @param newFile - file path of the new file.
 */

void copyFile(char * file, char * newFile) {
    FILE * existingFile;
    FILE * copyFile;
    char line[MAX_CHAR];
    existingFile = fopen(file, "r");
    copyFile = fopen(newFile, "w");
    if(existingFile == NULL || copyFile == NULL) printf("Could not open file");
    while (fgets(line, MAX_CHAR, existingFile) != NULL) fputs(line, copyFile);
    printf("file copeid to -> %s", newFile);
}

int main(int argc, char * argv[]) {
    if(argc!=3) printf("Wrong number of arguments");
    copyFile(argv[1], argv[2]);
    return 0;
}
