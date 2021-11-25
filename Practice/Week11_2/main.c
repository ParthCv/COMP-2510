#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node* Link;

void printList(Link head){
    if(!head){
        printf("->NULL\n");
        return;
    }
    printf("%d",head->data);
    if (head->next){
        printf("->");
    }
    printList(head->next);
}

Link createNode(int data){
    Link link = (Link) malloc(sizeof (struct Node));
    if(!link){
        perror("Memory allocation failed");
        exit(1);
    }
    link->data = data;
    link->next = NULL;
    return link;
}

Link createNodeWithNext(int data, Link next){
    Link link = createNode(data);
    link->next = next;
    return link;
}

void push(Link *head, int data){
    Link newNode = createNodeWithNext(data,*head);
    *head = newNode;
}

void sortedAddToList(Link *head, int data){
    if(!*head || (*head)->data > data){
        push(head,data);
        return;
    }

    sortedAddToList(&(*head)->next, data);
}

Link getPrevious(Link head,Link link) {

}

int main() {

    Link head = NULL;
    push(&head,10);
    push(&head,7);
    push(&head,3);
    push(&head,2);
    printList(head);
    sortedAddToList(&head,5);
    printList(head);
    printf("%p",head->next);
    return 0;
}
