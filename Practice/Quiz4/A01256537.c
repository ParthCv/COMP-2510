#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define MEMORY_ALLOCATION_ERROR 1

//The main problem with this code was that we didn't allocate memory for the name properly.
//I used strdup() for the memory allocation and check if it was successful
// And we can't free() if memory wasn't dynamically allocated

struct NameStruct {
    char *name;
};

struct NameStruct *createNameStruct(char *message) {
    struct NameStruct *newNode = (struct NameStruct*) malloc(sizeof(struct NameStruct));
    if (!newNode) {
        perror("Out of memory.");
        exit(MEMORY_ALLOCATION_ERROR);
    }
    newNode->name = strdup(message); //we need to allocate memory for the char pointers to store the name.
    if(newNode->name == NULL){ // Check if memory allocation for name was successful
        perror("Out of memory.");
        exit(MEMORY_ALLOCATION_ERROR);
    }
    return newNode;
}

void destroy(struct NameStruct *node) {
   free(node->name); // we can only use free() only when we have dynamically allocated memory
                      // using malloc, calloc or realloc
    free(node);
    node = NULL;
    //free just marks the memory as unused, the struct data will be there until overwriting.

}

int main() {
    char message[] = "This is an easy question";
    struct NameStruct *element = createNameStruct(message);
    if (element) {
        printf("Name : %s\n", element->name);
        destroy(element);
    }
    return 0;
}
