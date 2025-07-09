/*
Problem:
Given the root of a binary search tree and an integer k,
return the kth smallest value in the BST.

Since in-order traversal of a BST gives sorted order,
we can perform in-order traversal and count the elements until we reach k.

Time: O(h + k), Space: O(h), where h is the height of the tree.

Example:
Input: root = [3,1,4,null,2], k = 1
Output: 1

------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// In-order traversal to find kth smallest
void inorder(struct TreeNode* root, int k, int* count, int* result) {
    if (!root || *count >= k) return;

    inorder(root->left, k, count, result);

    (*count)++;
    if (*count == k) {
        *result = root->val;
        return;
    }

    inorder(root->right, k, count, result);
}

int kthSmallest(struct TreeNode* root, int k) {
    int count = 0;
    int result = -1;
    inorder(root, k, &count, &result);
    return result;
}

// ----- Demo + Helpers -----

// Create a new TreeNode
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
    /*
          3
         / \
        1   4
         \
          2
    */

    struct TreeNode* root = newNode(3);
    root->left = newNode(1);
    root->left->right = newNode(2);
    root->right = newNode(4);

    int k = 1;
    int value = kthSmallest(root, k);
    printf("The %dth smallest element is: %d\n", k, value);  // Output: 1

    freeTree(root);
    return 0;
}
