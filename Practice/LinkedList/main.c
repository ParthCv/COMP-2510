#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node *Link;

void printLinkedList(struct Node *head) {
    struct Node *currentNode = head;
    while (currentNode != NULL) {
        printf("%d", currentNode->data);
        currentNode = currentNode->next;
        if (currentNode != NULL) {
            printf("->");
        }
    }
    printf("\n");
}

void printLinkedListRecursive(Link head) {
    if (!head) {
        printf("\n");
        return;
    }
    printf("%d", head->data);
    if (head->next) {
        printf("->");
    }
    printLinkedListRecursive(head->next);
}

Link createNode(int data) {
    Link link = (Link) malloc(sizeof(struct Node));
    if (!link) {
        perror("Memory Allocation Error!");
        exit(1);
    }
    link->data = data;
    link->next = NULL;
    return link;
}

Link createNodeWithNext(int data, Link next) {
    Link link = createNode(data);
    link->next = next;
    return link;
}

int getLengthOfLinkedList(Link head) {
    int length = 0;
    Link cur = head;
    while (cur) {
        ++length;
        cur = cur->next;
    }
    return length;
}

int getLengthOfLinkedListRecursive(Link head) {
    if (!head) {
        return 0;
    }
    return 1 + getLengthOfLinkedListRecursive(head->next);
}

void push(int data, Link *head) {
    Link link = createNodeWithNext(data, *head);
    *head = link;
}

Link getTail(Link head) {
    if (!head) {
        return NULL;
    }
    if (!head->next) {
        return head;
    }
    return getTail(head->next);
}

void addLast(Link *head, int data) {
    Link newTail = createNode(data);
    if (!*head) {
        *head = newTail;
        return;
    }
    Link currentTail = getTail(*head);
    currentTail->next = newTail;
}

int removeTail(Link *head){
    if(!*head){
        perror("Empty List is passes to the removeTail Function");
        exit(2);
    }

    Link currentNode = *head;
    if(!currentNode->next){
        *head = NULL;
        int data = currentNode->data;
        free(currentNode);
        return data;
    }

    while (currentNode->next->next) {
        currentNode = currentNode->next;
    }

    int tailData = currentNode->next->data;
    free(currentNode->next);
    currentNode->next = NULL;
    return tailData;
}

int pop(Link *head) {
    if(!*head) {
        perror("Empty lis is passed to pop");
        exit(3);
    }
    int data = (*head)->data;
    Link oldHead = *head;
    *head = (*head)->next;
    free(oldHead);
    return data;
}

int addElementAfterPosition(Link head, int data, int position){

}

int deleteNodeAtPosition(Link *head, int position) {
    if(!*head) {
        perror("Empty lis is passed to pop");
        exit(3);
    }
    Link currentPosition = *head;
    for(int i = 1; i < position-1; i++){
        currentPosition = currentPosition->next;
    }
    Link newLink = currentPosition->next->next;
    int deletedData = currentPosition->next->data;
    currentPosition->next = newLink;
    free(currentPosition->next);
    return deletedData;
}

int main() {
    //4->20->10->NULL
//    Link node3 = createNode(10);
//    Link node2 = createNodeWithNext(20, node3);
//    Link node1 = createNodeWithNext(4, node2);
//    //printLinkedList(&node1);
//    printLinkedListRecursive(node1);
//    push(50, &node1);
//    printLinkedListRecursive(node1);
//    Link tail = getTail(node1);
//    printf("Tail's data - %d\n", tail->data);
//    printf("length of list is - %d\n", getLengthOfLinkedListRecursive(node1));
//    addLast(&node1,45);
//    printLinkedListRecursive(node1);

    Link head = NULL;
    push(10,&head);
    push(97,&head);
    push(69,&head);
    push(20,&head);
    push(4,&head);
    printLinkedListRecursive(head);

    int tailData = removeTail(&head);
    printf("Removed tail data - %d\n",tailData);
    printLinkedListRecursive(head);

    int headata = pop(&head);
    printf("Removed head data - %d\n",headata);
    printLinkedListRecursive(head);

    int deleteData = deleteNodeAtPosition(&head,2);
    printf("Removed head data - %d\n",deleteData);
    printLinkedListRecursive(head);
    return 0;
}
