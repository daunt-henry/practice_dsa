/*
Problem:
Convert a Binary Search Tree (BST) so that every node's new value is the sum of all values greater than or equal to it.

Example:
Input BST (in-order):   2 5 13
Output BST (in-order):  20 18 13

Approach:
- Traverse the tree in reverse in-order (right-root-left).
- Maintain a running sum of values visited so far.
- Update each node's value during traversal.

Time: O(n)
Space: O(h) for recursion stack (h = tree height)

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

// Global sum tracker
int runningSum = 0;

// Reverse in-order traversal
void reverseInorder(struct TreeNode* root) {
    if (!root) return;
    reverseInorder(root->right);
    runningSum += root->val;
    root->val = runningSum;
    reverseInorder(root->left);
}

// Convert BST to Greater Tree
struct TreeNode* convertBST(struct TreeNode* root) {
    runningSum = 0;
    reverseInorder(root);
    return root;
}

// ------- Helper Functions -------

// Create new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Inorder print for result
void inorder(struct TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Free tree memory
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// ------- Demo Main -------
int main() {
    /*
          5
         / \
        2   13

    After conversion:
          18
         /  \
       20    13
    */

    struct TreeNode* root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(13);

    root = convertBST(root);

    printf("Greater Tree Inorder: ");
    inorder(root);  // Output: 20 18 13
    printf("\n");

    freeTree(root);
    return 0;
}
