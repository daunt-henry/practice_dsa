/*
Maximum Binary Tree

Given an integer array with no duplicates. A maximum binary tree is constructed as follows:

1. The root is the maximum number in the array.
2. The left subtree is the maximum tree constructed from the left part subarray divided by the maximum number.
3. The right subtree is the maximum tree constructed from the right part subarray divided by the maximum number.

Example:
Input: [3,2,1,6,0,5]
Output: The constructed tree is:
       6
      / \
     3   5
      \  /
       2 0
        \
         1
*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    if (numsSize == 0) return NULL;

    int maxIndex = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[maxIndex]) maxIndex = i;
    }

    struct TreeNode* root = createNode(nums[maxIndex]);
    root->left = constructMaximumBinaryTree(nums, maxIndex);
    root->right = constructMaximumBinaryTree(nums + maxIndex + 1, numsSize - maxIndex - 1);

    return root;
}

// Helper to print preorder traversal
void printPreorder(struct TreeNode* root) {
    if (!root) return;
    printf("%d ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}

// Test
int main() {
    int nums[] = {3,2,1,6,0,5};
    int size = sizeof(nums) / sizeof(nums[0]);
    struct TreeNode* root = constructMaximumBinaryTree(nums, size);
    printf("Preorder of constructed Maximum Binary Tree: ");
    printPreorder(root);
    printf("\n");
    return 0;
}
