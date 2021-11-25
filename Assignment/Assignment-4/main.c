#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HOLE true
#define PROCESS false
#define MEMORY_ALLOCATION_ERROR 2

struct Node {
    int data;
    int base;
    int limit;
    bool isHole;
    struct Node *next;
};

typedef struct Node *Link;

void checkMemoryAllocation(Link link) {
    if (!link) {
        perror("Memory Allocation Error!!");
        exit(MEMORY_ALLOCATION_ERROR);
    }
}

Link createNodeWithNext(int data, int base, int limit, bool isHole, Link next) {
    Link link = (Link) malloc(sizeof(struct Node));
    checkMemoryAllocation(link);
    link->data = data;
    link->base = base;
    link->limit = limit;
    link->isHole = isHole;
    link->next = next;
    return link;
}

void push(int data, int base, int limit, bool isHole, Link *head) {
    Link link = createNodeWithNext(data, base, limit, isHole, *head);
    *head = link;
}

bool isHole(Link link) {
    return link->isHole;
}

void mergeAdjacentHoles(Link *hole) {
    Link thisHole = *hole;
    Link nextHole = (*hole)->next;
    thisHole->limit += nextHole->limit;
    thisHole->next = nextHole->next;
    free(nextHole);
}

void mergeFreeBlock(Link *head) {
    if (!head || !(*head)->next) {
        return;
    }
    if (isHole(*head) && isHole((*head)->next)) {
        mergeAdjacentHoles(head);
        mergeFreeBlock(&*head);
    } else {
        mergeFreeBlock(&(*head)->next);
    }
}


Link getPreviousNodeBeforeNextProcess(Link link) {
    Link prevLink = createNodeWithNext(link->data,link->base,link->limit,link->isHole,link->next);
    return prevLink;
}

void swapNextAndBase(Link nodeOne, Link nodeTwo) {
    int tempBase = nodeOne->base;
    Link tempNext = nodeOne->next;
    nodeOne->base = nodeTwo->base;
    nodeOne->next = nodeTwo->next;
    nodeTwo->base = tempBase;
    nodeTwo->next = tempNext;
}

void compaction(Link *head) {
    if (!*head) {
        return;
    }
    if ((*head)->isHole) {
        Link prevNodeProcess = getPreviousNodeBeforeNextProcess(*head);
        if (!prevNodeProcess) {
            return;
        }
        Link nodeProcess = prevNodeProcess->next;
        prevNodeProcess->next = *head;
        swapNextAndBase(*head, nodeProcess);
        *head = nodeProcess;
    }
    compaction(&(*head)->next);
}

void printMemory(Link head) {
    Link curNode = head;
    int nodeNumber = 1;
    while (curNode != NULL) {
        printf("Node %d: ", nodeNumber);
        if (isHole(curNode))printf("H (Hole), ");
        else printf("P%d, ", curNode->data);
        printf("base = %d, limit = %d\n", curNode->base, curNode->limit);
        curNode = curNode->next;
        nodeNumber++;
    }
}

void destroy(Link *head) {
    if (!*head) {
        return;
    } else {
        Link nextNode = *head;
        *head = (*head)->next;
        free(nextNode);
        nextNode = *head;
        *head = NULL;
        destroy(&nextNode);
    }
}

int main() {
    Link head = NULL;
    push(0, 26, 6, HOLE, &head);
    push(3, 16, 10, PROCESS, &head);
    push(0, 15, 1, HOLE, &head);
    push(0, 11, 4, HOLE, &head);
    push(0, 7, 4, HOLE, &head);
    push(17, 6, 1, PROCESS, &head);
    push(1, 0, 6, PROCESS, &head);
    printMemory(head);

    printf("\n----------Merging the free blocks----------\n\n");
    mergeFreeBlock(&head);
    printMemory(head);

//    printf("\n----------Compaction of the memory----------\n\n");
//    compaction(&head);
//    printMemory(head);

    destroy(&head);
    return 0;
}
