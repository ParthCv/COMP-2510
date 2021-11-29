#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    char data;
    struct Node * next;
};

typedef struct Node* Link;

bool DigitInList(Link head, int *number) {
    if (!head) {
        return true;
    }
    if (head->data > '9' || head->data < '0') {
        return false;
    }
    *number *= 10;
    *number += (head->data - '0');
    return DigitInList(head->next, number);
}

Link createNode(char data) {
    Link link = (Link) malloc(sizeof(struct Node));
    if (!link) {
        perror("Memory Allocation Error!");
        exit(1);
    }
    link->data = data;
    link->next = NULL;
    return link;
}

Link createNodeWithNext(char data, Link next) {
    Link link = createNode(data);
    link->next = next;
    return link;
}

void push(char data, Link *head) {
    Link link = createNodeWithNext(data, *head);
    *head = link;
}

void printLinkedListRecursive(Link head) {
    if (!head) {
        printf("\n");
        return;
    }
    printf("%c", head->data);
    if (head->next) {
        printf("->");
    }
    printLinkedListRecursive(head->next);
}

int main() {

    /**
     * so the mystery function should be named digitsInList.
     *
     * the parameters are the head of the list and an int with value zero
     *
     * the return value it true if all chars are digits and false for the first non-digit char
     *
     * The function changes the value of number to the the integer with merged digits until the first character
     *          for ex - 3->7>m->8->3  this list will return the 37 i.e 3 * 10 + 7
     *
     * The possible bug could be that it only merges until the first non-digit char but its possible there
     * are other digit chars in the list. Otherwise no bug
     *
     */

    int num = 0;
    Link head = NULL;
    push('1',&head);
    push('7',&head);
    push('m',&head);
    push('9',&head);
    push('6',&head);
    printLinkedListRecursive(head);
    printf("\n");
    if(DigitInList(head, &num)){
        printf("the value is true\n");
    } else {
        printf("the value is false\n");
    }
    printf("num = %d",num);
    printf("\n");
    printLinkedListRecursive(head);
    return 0;
}
