#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_ALLOCATION_ERROR 2

struct Node {
    void *data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node *TreeNode;

void freeNodes(TreeNode root) {
    if (!root) {
        return;
    }
    freeNodes(root->left);
    freeNodes(root->right);
    free(root);
}

TreeNode createTreeNode(void *data) {
    TreeNode treeNode = (TreeNode) malloc(sizeof(struct Node));
    if (treeNode == NULL) {
        perror("Memory Error!");
        exit(MEMORY_ALLOCATION_ERROR);
    }
    treeNode->data = data;
    treeNode->left = NULL;
    treeNode->right = NULL;
    return treeNode;
}

TreeNode insertNode(TreeNode root, void *data, bool compare(void *, void *)) {
    if (!root) {
        return createTreeNode(data);
    }
    if (compare(root->data, data)) {
        root->left = insertNode(root->left, data, compare);
    } else {
        root->right = insertNode(root->right, data, compare);
    }
    return root;
}

void *getElementAtIndex(void *elements, size_t sizeOfEachElement, int index) {
    return (char *) elements + index * sizeOfEachElement;
}

void printInOrder(TreeNode root, void printFunction(void *)) {
    if (!root) {
        return;
    }
    printInOrder(root->left, printFunction);
    printFunction(root->data);
    printInOrder(root->right, printFunction);
}

TreeNode insertBTS(void *elements, size_t length, size_t sizeOfEachElement, bool compare(void *, void *)) {
    TreeNode root = NULL;
    for (int index = 0; index < length; index++) {
        void *element = getElementAtIndex(elements, sizeOfEachElement, index);
        root = insertNode(root, element, compare);
    }
    return root;
}

void sortArray(void *elements, size_t length, size_t sizeOfEachElement, bool compare(void *, void *), void printFunction(void *)) {
    TreeNode root = insertBTS(elements, length, sizeOfEachElement, compare);
    printInOrder(root, printFunction);
    printf("\n");
    freeNodes(root);
}

bool compareInteger(void *firstElement, void *secondElement) {
    int *firstInteger = (int *) firstElement;
    int *secondInteger = (int *) secondElement;
    return *firstInteger > *secondInteger;
}

void printBTSIntegerElement(void *element) {
    int *result = (int *) element;
    printf("%d ", *result);
}

bool compareString(void *firstElement, void *secondElement) {
    char *firstString = *(char **) firstElement;
    char *secondString = *(char **) secondElement;
    return strcmp(firstString, secondString) > 0;
}

void printFunction(void *element) {
    char *string = *(char **) element;
    printf("%s ", string);
}

bool compareDouble(void *firstElement, void *secondElement) {
    double *firstDouble = (double *) firstElement;
    double *secondDouble = (double *) secondElement;
    return *firstDouble > *secondDouble;
}

void printBTSDoubleElement(void *element) {
    double *result = (double *) element;
    printf("%.2f ", *result);
}

void destroy(TreeNode *head) {
    if (!*head) {
        return;
    } else {
        TreeNode left = (*head)->left;
        TreeNode right = (*head)->right;
        free(head);
        destroy(&left);
        destroy(&right);
    }
}

int main() {
    printf("\n--- For Integer ---\n");
    int arrayOfInteger[] = {5, 8, 9, 4, 6, 7, 3};
    printf("Before:\n");
    for (int i = 0; i < 7; i++) {
        printf("%d ", arrayOfInteger[i]);
    }
    printf("\nAfter:\n");
    sortArray(arrayOfInteger, 7, sizeof(int), compareInteger, printBTSIntegerElement);

    printf("\n--- For String ---\n");
    char *arrayOfString[] = {"Parth", "Eric", "Maggie", "Jae", "Victor", "Jhon", "Ray"};
    printf("Before:\n");
    for (int i = 0; i < 7; i++) {
        printf("%s ", arrayOfString[i]);
    }
    printf("\nAfter:\n");
    sortArray(arrayOfString, 7, sizeof(char *), compareString, printFunction);

    printf("\n--- For Double ---\n");
    double arrayOfDouble[] = {2.5, 45.5, 0.5, 10.75, 10.2, 0.5, 3.15};
    printf("Before:\n");
    for (int i = 0; i < 7; i++) {
        printf("%.2f ", arrayOfDouble[i]);
    }
    printf("\nAfter:\n");
    sortArray(arrayOfDouble, 7, sizeof(double), compareDouble, printBTSDoubleElement);

    return 0;
}