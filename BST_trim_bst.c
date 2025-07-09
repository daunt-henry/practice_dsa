/*
Problem:
Given the root of a binary search tree and two integers low and high, 
trim the tree so that all its elements lie in [low, high].
The resulting tree should still be a valid BST.

Approach:
- If node->val < low → discard left subtree and recur for right
- If node->val > high → discard right subtree and recur for left
- Else trim both subtrees and return node

Time: O(n), Space: O(h), where h is the height of the tree

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

// Main trimming logic
struct TreeNode* trimBST(struct TreeNode* root, int low, int high) {
    if (!root) return NULL;

    if (root->val < low)
        return trimBST(root->right, low, high);
    if (root->val > high)
        return trimBST(root->left, low, high);

    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}

// -------- Helpers --------

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Inorder print
void inorder(struct TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Free memory
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// -------- Demo --------
int main() {
    /*
         1
          \
           2
          /
         0
    Trim range: [1, 2]
    Expected output: 1 2
    */

    struct TreeNode* root = newNode(1);
    root->right = newNode(2);
    root->right->left = newNode(0);

    int low = 1, high = 2;
    root = trimBST(root, low, high);

    printf("Trimmed BST in-order: ");
    inorder(root);  // Expected: 1 2
    printf("\n");

    freeTree(root);
    return 0;
}
