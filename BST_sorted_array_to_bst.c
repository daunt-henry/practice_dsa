/*
Problem:
Given an integer array `nums` where the elements are sorted in ascending order,
convert it to a height-balanced binary search tree (BST).

A height-balanced BST is defined as a binary tree in which the depth of
the two subtrees of every node never differs by more than one.

Example:
Input: [-10,-3,0,5,9]
Output: A height-balanced BST

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

// Recursive helper to build BST
struct TreeNode* buildBST(int* nums, int left, int right) {
    if (left > right) return NULL;

    int mid = left + (right - left) / 2;
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    node->left = buildBST(nums, left, mid - 1);
    node->right = buildBST(nums, mid + 1, right);

    return node;
}

// Main function
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (!nums || numsSize == 0) return NULL;
    return buildBST(nums, 0, numsSize - 1);
}

// Preorder print
void printPreorder(struct TreeNode* root) {
    if (!root) {
        printf("null ");
        return;
    }
    printf("%d ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}

// Free memory
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Demo
int main() {
    int nums[] = {-10, -3, 0, 5, 9};
    int size = sizeof(nums) / sizeof(nums[0]);

    struct TreeNode* root = sortedArrayToBST(nums, size);

    printf("Preorder traversal of BST: ");
    printPreorder(root);  // Output varies, but should be height-balanced
    printf("\n");

    freeTree(root);
    return 0;
}
