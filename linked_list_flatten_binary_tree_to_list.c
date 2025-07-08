/*
Problem:
Given the root of a binary tree, flatten the tree into a "linked list":

- The "linked list" should use the same TreeNode structure.
- The right child pointer should point to the next node in the list.
- The left child pointer should always be NULL.
- The "linked list" should be in the same order as a pre-order traversal.

Example:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Utility to create a new tree node
struct TreeNode* createTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Core logic to flatten the binary tree to linked list (in-place)
void flatten(struct TreeNode* root) {
    while (root) {
        if (root->left) {
            struct TreeNode* rightmost = root->left;
            while (rightmost->right) {
                rightmost = rightmost->right;
            }
            rightmost->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
    }
}

// Print flattened tree (linked list)
void printFlattened(struct TreeNode* root) {
    while (root) {
        printf("%d", root->val);
        if (root->right) printf(" -> ");
        root = root->right;
    }
    printf("\n");
}

// Driver code
int main() {
    // Input: [1,2,5,3,4,null,6]
    struct TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(5);
    root->left->left = createTreeNode(3);
    root->left->right = createTreeNode(4);
    root->right->right = createTreeNode(6);

    flatten(root);
    printf("Flattened tree (right-linked list): ");
    printFlattened(root);  // Expected: 1 -> 2 -> 3 -> 4 -> 5 -> 6

    return 0;
}
