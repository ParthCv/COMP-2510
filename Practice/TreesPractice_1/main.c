#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node* TreeNode;

TreeNode createTreeNode(int data) {
    TreeNode treeNode = (TreeNode) malloc(sizeof(struct Node));
    if (treeNode == NULL) {
        perror("Memory error");
        exit(1);
    }
    treeNode->data = data;
    treeNode->left = NULL;
    treeNode->right = NULL;
    return treeNode;
}

TreeNode createTreeNodeWithChildren(int data, TreeNode left, TreeNode right) {
    TreeNode treeNode = createTreeNode(data);
    treeNode->left = left;
    treeNode->right = right;
    return treeNode;
}

void printTreeNode(TreeNode node) {
    if (!node) {
        printf("NULL\n");
        return;
    }
    if (node->left && node->right) {
        printf("Node:%d, left = %d, right = %d\n",
               node->data, node->left->data, node->right->data);
        return;
    }
    if (node->left) {
        printf("Node:%d, left = %d, right = NULL\n",
               node->data, node->left->data);
        return;
    }
    if (node->right) {
        printf("Node:%d, left = NULL, right = %d\n",
               node->data, node->right->data);
        return;
    }

    printf("Node:%d, left = NULL, right = NULL\n", node->data);
}

void printTree(TreeNode root) {
    if (!root) {
        return;
    }
    printTreeNode(root);
    printTree(root->left);
    printTree(root->right);
}

TreeNode findMaxNodeInBinaryTree(TreeNode root) {
    if(!root){
        return NULL;
    }
    if(!root->left && !root->right){
        return root;
    }
    if(root->left && !root->right){
        TreeNode leftSide = findMaxNodeInBinaryTree(root->left);
        return (root->data > leftSide->data) ? root : leftSide;
    }
    if(!root->left && root->right){
        TreeNode rightSide = findMaxNodeInBinaryTree(root->right);
        return (root->data > rightSide->data) ? root : rightSide;
    }
    TreeNode leftSide = findMaxNodeInBinaryTree(root->left);
    TreeNode rightSide = findMaxNodeInBinaryTree(root->right);
    TreeNode compare = (leftSide->data > rightSide->data) ? leftSide : rightSide;
    return (root->data > compare->data) ? root : compare;
}

int main() {
    TreeNode node1 = createTreeNode(1);
    TreeNode node4 = createTreeNode(4);
    TreeNode node6 = createTreeNode(6);
    TreeNode node9 = createTreeNode(9);
    TreeNode node3 = createTreeNodeWithChildren(3, node1, node4);
    TreeNode node8 = createTreeNodeWithChildren(8, node6, node9);
    TreeNode root = createTreeNodeWithChildren(5, node3, node8);

    printTree(root);

    TreeNode max = findMaxNodeInBinaryTree(root);
    printTreeNode(max);
    return 0;
}
