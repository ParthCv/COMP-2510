#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define THRESHOLD 5.0f

struct Node {
    float data;
    struct Node *next;
};

typedef struct Node *Link;

void printLinkedListRecursive(Link head) {
    if (!head) {
        printf("->NULL\n");
        return;
    }
    printf("%lf", head->data);
    if (head->next) {
        printf("->");
    }
    printLinkedListRecursive(head->next);
}

Link createNode(float data) {
    Link link = (Link) malloc(sizeof(struct Node));
    if (!link) {
        perror("Memory Allocation Error!");
        exit(1);
    }
    link->data = data;
    link->next = NULL;
    return link;
}

Link createNodeWithNext(float data, Link next) {
    Link link = createNode(data);
    link->next = next;
    return link;
}

void push(float data, Link *head) {
    Link link = createNodeWithNext(data, *head);
    *head = link;
}

void deleteNodeAtPosition(Link *head, int position) {
    if(!*head) {
        perror("Empty lis is passed to pop");
        exit(3);
    }
    Link currentPosition = *head;
    for(int i = 1; i < position-1; i++){
        currentPosition = currentPosition->next;
    }
    Link newLink = currentPosition->next->next;
    currentPosition->next = newLink;
    free(currentPosition->next);
}

void filter(Link *head, bool(*isValid)(float)) {
    Link currentNode = *head;
    int position = 1;
    while (currentNode->next) {
        if(!isValid(currentNode->data)){
            deleteNodeAtPosition(head,position);
        }
        position++;
        currentNode = currentNode->next;
    }
}

bool isGreaterThanThreshold(float data) {
    return data < THRESHOLD;
}

int main() {
//    Link head = NULL;
//    push(4.76f, &head);
//    push(8.30f, &head);
//    push(5.76f, &head);
//    push(3.66f, &head);
//    push(9.55f, &head);
//    push(7.80f, &head);
//    printLinkedListRecursive(head);
//    filter(&head,isGreaterThanThreshold);
//    printLinkedListRecursive(head);



    return 0;
}
