/*
Problem:
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST means:
- All nodes on the left subtree are strictly less than the node.
- All nodes on the right subtree are strictly greater.
- This must be true recursively for all nodes.

Example:
Input: [2,1,3]
Output: true

Input: [5,1,4,null,null,3,6]
Output: false

------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Validate BST using range bounds
bool validate(struct TreeNode* root, long minVal, long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return validate(root->left, minVal, root->val) &&
           validate(root->right, root->val, maxVal);
}

bool isValidBST(struct TreeNode* root) {
    return validate(root, LONG_MIN, LONG_MAX);
}

// Tree builder helper
struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Free tree
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main demo
int main() {
    // Example 1: Valid BST (2,1,3)
    struct TreeNode* root1 = newNode(2);
    root1->left = newNode(1);
    root1->right = newNode(3);
    printf("Tree 1 is valid BST? %s\n", isValidBST(root1) ? "true" : "false"); // true
    freeTree(root1);

    // Example 2: Invalid BST (5,1,4,null,null,3,6)
    struct TreeNode* root2 = newNode(5);
    root2->left = newNode(1);
    root2->right = newNode(4);
    root2->right->left = newNode(3);
    root2->right->right = newNode(6);
    printf("Tree 2 is valid BST? %s\n", isValidBST(root2) ? "true" : "false"); // false
    freeTree(root2);

    return 0;
}
