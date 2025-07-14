/*
Problem:
Given the root of a Binary Search Tree and two integers low and high,
return the sum of values of all nodes with a value in the inclusive range [low, high].

Approach:
- Use DFS traversal.
- Prune subtrees that are completely outside the range.
- Only explore left/right if needed based on current node value.

Time Complexity: O(n)
Space Complexity: O(h) for recursion (h = tree height)

------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Recursive range sum
int rangeSumBST(struct TreeNode* root, int low, int high) {
    if (!root) return 0;

    int sum = 0;

    if (root->val >= low && root->val <= high)
        sum += root->val;

    if (root->val > low)
        sum += rangeSumBST(root->left, low, high);

    if (root->val < high)
        sum += rangeSumBST(root->right, low, high);

    return sum;
}

// Helper to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Helper to free memory
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Demo
int main() {
    /*
        BST:
              10
             /  \
            5   15
           / \    \
          3   7   18

        Range: [7, 15]
        Expected sum: 7 + 10 + 15 = 32
    */

    struct TreeNode* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->right = newNode(18);

    int low = 7, high = 15;
    int result = rangeSumBST(root, low, high);
    printf("Range Sum [%d, %d]: %d\n", low, high, result);  // Output: 32

    freeTree(root);
    return 0;
}
