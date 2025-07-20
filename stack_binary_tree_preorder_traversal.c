/*
Title: Binary Tree Preorder Traversal

Description:
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example:
Input: root = [1,null,2,3]
Output: [1,2,3]
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Preorder traversal using iterative approach with a stack
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(1000 * sizeof(int));
    struct TreeNode* stack[1000];
    int top = -1;
    *returnSize = 0;

    if (root) stack[++top] = root;

    while (top != -1) {
        struct TreeNode* node = stack[top--];
        result[(*returnSize)++] = node->val;

        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }

    return result;
}

// Helper to create a new TreeNode
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Sample usage
int main() {
    // Construct the tree: [1,null,2,3]
    struct TreeNode* root = newNode(1);
    root->right = newNode(2);
    root->right->left = newNode(3);

    int size;
    int* result = preorderTraversal(root, &size);

    printf("Preorder Traversal: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
