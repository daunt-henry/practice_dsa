/*
Problem:
Given an array representing the preorder traversal of a BST,
construct the corresponding binary search tree.

Approach:
- Use recursion with upper bounds to simulate preorder traversal.
- At each step, insert node if within bounds and recurse for left and right.

Time Complexity: O(n)
Space Complexity: O(n) for recursion stack

------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// TreeNode structure
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Recursive builder function
struct TreeNode* build(int* preorder, int* index, int bound, int size) {
    if (*index >= size || preorder[*index] > bound)
        return NULL;

    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = preorder[*index];
    root->left = root->right = NULL;
    (*index)++;

    root->left = build(preorder, index, root->val, size);
    root->right = build(preorder, index, bound, size);

    return root;
}

// Main entry function
struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) {
    int index = 0;
    return build(preorder, &index, INT_MAX, preorderSize);
}

// Inorder print to verify BST
void printInorder(struct TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

// Helper to free tree
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Demo
int main() {
    /*
        Input: preorder = [8,5,1,7,10,12]

        Expected BST:
                 8
               /   \
              5    10
             / \     \
            1   7     12

        Inorder Output: 1 5 7 8 10 12
    */

    int preorder[] = {8, 5, 1, 7, 10, 12};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    struct TreeNode* root = bstFromPreorder(preorder, n);
    printf("Inorder Traversal: ");
    printInorder(root);  // Output: 1 5 7 8 10 12
    printf("\n");

    freeTree(root);
    return 0;
}
