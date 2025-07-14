/*
Problem:
Given the root of a binary search tree, rearrange the tree in increasing order 
so that the left child of every node is NULL and the right child contains the next node 
in the in-order traversal of the tree.

Approach:
- Perform in-order traversal.
- While traversing, link the visited node to the current tail of the new tree.

Time Complexity: O(n)
Space Complexity: O(h) due to recursion

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

struct TreeNode* newRoot = NULL;
struct TreeNode* curr = NULL;

void inorder(struct TreeNode* root) {
    if (!root) return;

    inorder(root->left);

    root->left = NULL;
    if (curr) {
        curr->right = root;
    } else {
        newRoot = root;
    }
    curr = root;

    inorder(root->right);
}

struct TreeNode* increasingBST(struct TreeNode* root) {
    newRoot = NULL;
    curr = NULL;
    inorder(root);
    return newRoot;
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

// Print right-skewed tree
void printIncreasing(struct TreeNode* root) {
    while (root) {
        printf("%d ", root->val);
        root = root->right;
    }
    printf("\n");
}

// Demo
int main() {
    /*
        Original Tree:
               5
              / \
             3   6
            / \   \
           2   4   8
          /       / \
         1       7   9

        Expected Output:
        1 2 3 4 5 6 7 8 9
    */
    struct TreeNode* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->left->left->left = newNode(1);
    root->right->right = newNode(8);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(9);

    struct TreeNode* result = increasingBST(root);
    printf("Increasing Order BST: ");
    printIncreasing(result);

    freeTree(result);
    return 0;
}
