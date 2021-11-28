#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node *TreeNode;

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

int getNumberOfNodesInTHeLongestPath(TreeNode root) {
    if (!root) {
        return 0;
    }
    int left = getNumberOfNodesInTHeLongestPath(root->left);
    int right = getNumberOfNodesInTHeLongestPath(root->right);
    int max = (left > right) ? left : right;
    return max + 1;
}

int getTreeHeight(TreeNode root) {
    if (!root) {
        perror("Root is NULL");
        exit(2);
    }
    return getNumberOfNodesInTHeLongestPath(root) - 1;
}

TreeNode findNodeWithData(TreeNode root, int targetData) {
    if (!root) {
        return NULL;
    }
    if (root->data == targetData) {
        return root;
    }
    if (root->data > targetData) {
        return findNodeWithData(root->left, targetData);
    }
    return findNodeWithData(root->right, targetData);
}

TreeNode insert(TreeNode root, int data) {
    if (!root) {
        return createTreeNode(data);
    }
    if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void printInOrder(TreeNode root) {
    if (!root) {
        return;
    }
    printInOrder(root->left);
    printf(" %d", root->data);
    printInOrder(root->right);
}

void printPreOrder(TreeNode root) {
    if (!root) {
        return;
    }
    printf(" %d", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printPostOrder(TreeNode root) {
    if (!root) {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf(" %d", root->data);
}

int main() {
    /*
            5
           / \
          /   \
         3     8
        / \   / \
       /   \ /   \
      1    4 6    9
     */

    TreeNode node1 = createTreeNode(1);
    TreeNode node4 = createTreeNode(4);
    TreeNode node6 = createTreeNode(6);
    TreeNode node9 = createTreeNode(9);
    TreeNode node3 = createTreeNodeWithChildren(3, node1, node4);
    TreeNode node8 = createTreeNodeWithChildren(8, node6, node9);
    TreeNode root = createTreeNodeWithChildren(5, node3, node8);

    //root = insert(root, 10);

    printTree(root);

//    int height = getTreeHeight(root);
//    printf("Tree height = %d\n", height);
//
//    TreeNode node = findNodeWithData(root, 9);
//    printTreeNode(node);
    printf("\n");
    printInOrder(root);
    printf("\n");
    printPreOrder(root);
    printf("\n");
    printPostOrder(root);
    printf("\n");

    return 0;
}
