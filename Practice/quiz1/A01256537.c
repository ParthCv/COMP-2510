#include <stdio.h>
#include <stdbool.h>

bool createFile(char *fileName, char *content) {
    FILE *file;file = fopen(fileName, "w");
    if (file == NULL) {printf("Could not open file for writing.");
        return false;
    }
    fprintf(file, "%s", content);
    fclose(file);
    return true;
}

int main() {

    bool succeeded = createFile("test_file.txt", "This is my first file!\nThis is the second line");
    printf("Succeeded: %s\n", succeeded ? "True" : "False");
    return 0;
}