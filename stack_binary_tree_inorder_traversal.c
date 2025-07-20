/*
Title: Binary Tree Inorder Traversal

Description:
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example:
Input: root = [1,null,2,3]
Output: [1,3,2]
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Inorder traversal using iterative approach with a stack
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(1000 * sizeof(int));
    struct TreeNode* stack[1000];
    int top = -1;
    *returnSize = 0;

    while (root || top != -1) {
        while (root) {
            stack[++top] = root;
            root = root->left;
        }
        root = stack[top--];
        result[(*returnSize)++] = root->val;
        root = root->right;
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
    int* result = inorderTraversal(root, &size);

    printf("Inorder Traversal: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
