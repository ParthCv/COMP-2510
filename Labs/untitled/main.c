#include <stdio.h>
#include <stdlib.h>

#define MEMORY_ALLOCATION_ERROR 1

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node *Link;

/**
 * checks if memory allocation was successful.
 */

void checkMemoryAllocation(Link link) {
    if (!link) {
        perror("Memory Allocation Error!");
        exit(MEMORY_ALLOCATION_ERROR);
    }
}

/**
 * dynamically creates a node.
 */

Link createNode(int data) {
    Link link = (Link) malloc(sizeof(struct Node));
    checkMemoryAllocation(link);
    link->data = data;
    link->next = NULL;
    return link;
}

/**
 * dynamically creates a node with next.
 */

Link createNodeWithNext(int data, Link next) {
    Link link = createNode(data);
    link->next = next;
    return link;
}

/**
 * pushes nodes in the the list.
 */

void push(int data, Link *head) {
    Link link = createNodeWithNext(data, *head);
    *head = link;
}

/**
 * prints the linked list.
 */

void printLinkedList(Link head) {
    if (!head) {
        printf("\n");
        return;
    }
    printf("%d", head->data);
    if (head->next) {
        printf("->");
    }
    printLinkedList(head->next);
}

/**
 * creates a copy of the linked list.
 */

Link copyList(Link head) {
    if (!head) {
        return NULL;
    }
    Link newNode = createNodeWithNext(head->data, copyList(head->next));
    return newNode;
}

/**
 * creates a reverse copy of the list.
 */

Link reverseCopyList(Link head) {
    Link reverseCopy = NULL;
    Link tempHead = head;
    while (tempHead) {
        push(tempHead->data, &reverseCopy);
        tempHead = tempHead->next;
    }
    free(tempHead);
    return reverseCopy;
}

/**
 * frees up the heap memory for a linked list.
 */

void destroyList(Link* head) {
    if (!*head) {
        return;
    } else {
        Link nextNode = *head;
        *head = (*head)->next;
        free(nextNode);
        nextNode = *head;
        *head = NULL;
        destroyList(&nextNode);
    }
}

int main() {
    Link head = NULL;
    push(4, &head);
    push(3, &head);
    push(2, &head);
    push(1, &head);
    printf("Original List ->\n");
    printLinkedList(head);
    printf("------------------------------------------\n");
    Link copy = copyList(head);
    printf("Copied List ->\n");
    printLinkedList(copy);
    printf("Original List after copy ->\n");
    printLinkedList(head);
    printf("------------------------------------------\n");
    Link reverseCopy = reverseCopyList(head);
    printf("Reverse Copied List ->\n");
    printLinkedList(reverseCopy);
    printf("Original List after copy ->\n");
    printLinkedList(head);
    destroyList(&head);
    destroyList(&copy);
    destroyList(&reverseCopy);
    return 0;
}
