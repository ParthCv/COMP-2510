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

/**
 * checks if memory allocation was successful.
 *
 * @param link the dynamically allocated Node.
 */

void checkMemoryAllocation(Link link) {
    if (!link) {
        perror("Memory Allocation Error!!");
        exit(MEMORY_ALLOCATION_ERROR);
    }
}

/**
 * adds a new node with all the fields.
 *
 * @param data data of the Node
 * @param base start index of Node
 * @param limit size of the block
 * @param isHole is the node a hole or a process
 * @param next the next process or hole it points to
 * @return pointer to a Node with all the information and a next node
 */

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

/**
 *  pushes a newly allocated node to the list.
 *
 * @param data data of the Node
 * @param base start index of Node
 * @param limit size of the block
 * @param isHole is the node a hole or a process
 * @param next the next process or hole it points to
 * @return pointer to a Node with all the information and a next node
 */

void push(int data, int base, int limit, bool isHole, Link *head) {
    Link link = createNodeWithNext(data, base, limit, isHole, *head);
    *head = link;
}

/**
 * checks if the node is a hole or a process.
 *
 * @param link a Node in the list
 * @return true if hole and false if a process
 */

bool isHole(Link link) {
    return link->isHole;
}

/**
 * Frees up the allocated memory linked list.
 *
 * @param head a pointer to the linked list
 */

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

/**
 * Merges The two adjacent holes
 *
 * @param hole a pointer to the linked list
 */

void mergeAdjacentHoles(Link *hole) {
    Link thisHole = *hole;
    Link nextHole = (*hole)->next;
    thisHole->limit += nextHole->limit;
    thisHole->next = nextHole->next;
    free(nextHole);
}

/**
 * Merges All consecutive holes in the whole memory.
 *
 * @param head a pointer to the linked list
 */

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

/**
 * Separates the hole and processes into two separates list.
 *
 * @param head a pointer to the linked list
 * @param holes a pointer to the linked list with all the holes
 * @param process a pointer to the linked list with all the processes
 */

void separateHoleAndProcesses(Link *head, Link *holes, Link *process) {
    Link temp = *head;
    while (temp) {
        if (isHole(temp)) {
            push(temp->data, temp->base, temp->limit, temp->isHole, *&holes);
        } else {
            push(temp->data, temp->base, temp->limit, temp->isHole, *&process);
        }
        temp = temp->next;
    }
}

/**
 * Copies the nodes form a list into another list.
 *
 * @param target a pointer to the linked list to which Nodes will be added.
 * @param list a pointer to the linked list that will be added to the list.
 */

void addNodesToListFromList(Link *target, Link *list) {
    while (*list) {
        push((*list)->data, (*list)->base, (*list)->limit, (*list)->isHole, target);
        Link next = (*list)->next;
        free(*list);
        *list = next;
    }
}

/**
 * Sorts the memory to have all processes in the start and all holes at the end.
 *
 * @param head a pointer to the linked list
 */

void compaction(Link *head) {
    Link holes = NULL;
    Link process = NULL;
    separateHoleAndProcesses(head, &holes, &process);
    destroy(&*head);
    *head = NULL;
    addNodesToListFromList(head, &holes);
    addNodesToListFromList(head, &process);
}

/**
 * Changes the bases to correct value based on the limit and base of previous node.
 *
 * @param head a pointer to the linked list
 */

void correctBases(Link *head) {
    Link temp = *head;
    while (temp->next) {
        Link next = temp->next;
        next->base = temp->base + temp->limit;
        temp = next;
    }
}

/**
 * Performs compaction on the memory.
 *
 * @param head a pointer to the linked list
 */

void compactMemory(Link *head) {
    compaction(head);
    correctBases(head);
    mergeFreeBlock(head);
}

/**
 * Prints all the holes and process in the memory with the data of each process.
 *
 * @param head the head of the linked list
 */

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

    printf("\n----------Compaction of the memory----------\n\n");
    compactMemory(&head);
    printMemory(head);

    destroy(&head);
    return 0;
}
