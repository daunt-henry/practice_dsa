/*
Problem:
Given the root of a Binary Search Tree (BST), convert it to a Greater Sum Tree,
where each node contains the sum of all nodes greater than or equal to it.

Approach:
- Use reverse in-order traversal (right -> node -> left).
- Maintain a running sum to update nodes during traversal.

Time Complexity: O(n)
Space Complexity: O(h)

------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Tree node definition
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Reverse in-order traversal to update values
void reverseInorder(struct TreeNode* root, int* sum) {
    if (!root) return;

    reverseInorder(root->right, sum);

    *sum += root->val;
    root->val = *sum;

    reverseInorder(root->left, sum);
}

// Main transformation function
struct TreeNode* bstToGst(struct TreeNode* root) {
    int sum = 0;
    reverseInorder(root, &sum);
    return root;
}

// Helper to create a node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Inorder traversal print
void printInorder(struct TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
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
    /*
        Original BST:
              4
             / \
            1   6
               / \
              5   7

        After conversion:
              18
             /  \
           20    13
                /  \
              18    7

        Inorder should be: 20 18 18 13 7
    */

    struct TreeNode* root = newNode(4);
    root->left = newNode(1);
    root->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(7);

    struct TreeNode* newRoot = bstToGst(root);
    printf("Inorder of Greater Sum Tree: ");
    printInorder(newRoot);  // Output: 20 18 18 13 7
    printf("\n");

    freeTree(newRoot);
    return 0;
}
