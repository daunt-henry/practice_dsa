/*
Problem:
Given an integer n, return all the structurally unique BSTs (binary search trees)
that store values from 1 to n.

Example:
Input: n = 3

Output: List of 5 unique BSTs (structurally distinct)

This program generates all such trees and prints their preorder traversal.

------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create a new TreeNode
struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Clone a tree (deep copy)
struct TreeNode* cloneTree(struct TreeNode* root) {
    if (!root) return NULL;
    struct TreeNode* newRoot = newNode(root->val);
    newRoot->left = cloneTree(root->left);
    newRoot->right = cloneTree(root->right);
    return newRoot;
}

// Generate all unique BSTs for range [start, end]
struct TreeNode** generateTreesRange(int start, int end, int* returnSize) {
    if (start > end) {
        struct TreeNode** base = malloc(sizeof(struct TreeNode*));
        base[0] = NULL;
        *returnSize = 1;
        return base;
    }

    int total = 0;
    struct TreeNode** result = NULL;

    for (int i = start; i <= end; i++) {
        int leftSize = 0, rightSize = 0;
        struct TreeNode** leftTrees = generateTreesRange(start, i - 1, &leftSize);
        struct TreeNode** rightTrees = generateTreesRange(i + 1, end, &rightSize);

        for (int l = 0; l < leftSize; l++) {
            for (int r = 0; r < rightSize; r++) {
                struct TreeNode* root = newNode(i);
                root->left = cloneTree(leftTrees[l]);
                root->right = cloneTree(rightTrees[r]);
                result = realloc(result, sizeof(struct TreeNode*) * (total + 1));
                result[total++] = root;
            }
        }

        free(leftTrees);
        free(rightTrees);
    }

    *returnSize = total;
    return result;
}

// Main generator
struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    return generateTreesRange(1, n, returnSize);
}

// Preorder traversal print
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
    int returnSize = 0;
    int n = 3;
    struct TreeNode** trees = generateTrees(n, &returnSize);

    printf("Total unique BSTs for n = %d: %d\n", n, returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("Tree %d (Preorder): ", i + 1);
        printPreorder(trees[i]);
        printf("\n");
        freeTree(trees[i]);
    }

    free(trees);
    return 0;
}
