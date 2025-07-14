/*
Problem:
Given the root of a Binary Search Tree (BST),
return the minimum difference between the values of any two different nodes in the tree.

Approach:
- Use in-order traversal to get values in sorted order.
- Track the previous node value and update minimum difference as you go.

Time Complexity: O(n)
Space Complexity: O(h), where h = height of tree

------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Tree node definition
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Global tracking variables
int minDiff = INT_MAX;
int previousVal = -1;

// In-order traversal
void inorder(struct TreeNode* root) {
    if (!root) return;

    inorder(root->left);

    if (previousVal != -1) {
        int diff = root->val - previousVal;
        if (diff < minDiff)
            minDiff = diff;
    }
    previousVal = root->val;

    inorder(root->right);
}

// Main function
int minDiffInBST(struct TreeNode* root) {
    minDiff = INT_MAX;
    previousVal = -1;
    inorder(root);
    return minDiff;
}

// Helpers
struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Demo
int main() {
    /*
        Tree:
             4
            / \
           2   6
          / \
         1   3

        Expected min difference: 1
    */

    struct TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    int result = minDiffInBST(root);
    printf("Minimum difference: %d\n", result);  // Output: 1

    freeTree(root);
    return 0;
}
