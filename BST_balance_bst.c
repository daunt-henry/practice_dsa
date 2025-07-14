/*
Problem:
Given a BST, return a balanced version of the tree with the same node values.

Approach:
1. Perform inorder traversal to get sorted array of values.
2. Build a balanced BST from the sorted array using divide-and-conquer.

Time Complexity: O(n)
Space Complexity: O(n)

------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Inorder traversal to fill array
void inorder(struct TreeNode* root, int* arr, int* index) {
    if (!root) return;
    inorder(root->left, arr, index);
    arr[(*index)++] = root->val;
    inorder(root->right, arr, index);
}

// Build balanced BST from sorted array
struct TreeNode* buildBST(int* arr, int left, int right) {
    if (left > right) return NULL;

    int mid = (left + right) / 2;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = arr[mid];
    root->left = buildBST(arr, left, mid - 1);
    root->right = buildBST(arr, mid + 1, right);
    return root;
}

// Main function
struct TreeNode* balanceBST(struct TreeNode* root) {
    int* arr = malloc(10000 * sizeof(int));
    int index = 0;
    inorder(root, arr, &index);
    struct TreeNode* balanced = buildBST(arr, 0, index - 1);
    free(arr);
    return balanced;
}

// Helper: Create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Helper: Print inorder traversal
void printInorder(struct TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

// Helper: Free tree memory
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Demo
int main() {
    /*
        Skewed BST:
            1
             \
              2
               \
                3
                 \
                  4

        Expected balanced BST:
              2
             / \
            1   3
                 \
                  4
    */

    struct TreeNode* root = newNode(1);
    root->right = newNode(2);
    root->right->right = newNode(3);
    root->right->right->right = newNode(4);

    struct TreeNode* balanced = balanceBST(root);

    printf("Inorder of Balanced BST: ");
    printInorder(balanced);  // Output: 1 2 3 4
    printf("\n");

    freeTree(balanced);
    freeTree(root);
    return 0;
}
