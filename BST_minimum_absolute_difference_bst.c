/*
Problem:
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes.

Constraints:
- The BST property helps ensure in-order traversal gives a sorted sequence.
- The smallest difference will be between two consecutive elements in that traversal.

Approach:
- Use in-order traversal to get sorted values.
- Track previous node value and compute differences with current node.
- Keep updating the minimum difference found.

Time: O(n), Space: O(h) where h is the height of the tree.

------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// TreeNode definition
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Globals for traversal
int prev = -1;
int minDiff = INT_MAX;

// In-order traversal
void inorder(struct TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    if (prev != -1) {
        int diff = root->val - prev;
        if (diff < minDiff)
            minDiff = diff;
    }
    prev = root->val;
    inorder(root->right);
}

// Main function
int getMinimumDifference(struct TreeNode* root) {
    prev = -1;
    minDiff = INT_MAX;
    inorder(root);
    return minDiff;
}

// --- Helpers and Demo ---

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Free tree memory
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    /*
         4
        / \
       2   6
      / \
     1   3
    */
    struct TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    int ret = getMinimumDifference(root);
    printf("Minimum Absolute Difference: %d\n", ret);  // Output: 1

    freeTree(root);
    return 0;
}
