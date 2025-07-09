/*
Problem:
Given a Binary Search Tree (BST), find the lowest common ancestor (LCA) of two given nodes p and q.

In a BST:
- The left subtree of a node contains nodes with values less than the node's value.
- The right subtree contains nodes with values greater.

Approach:
- If both p and q are smaller than current node, LCA lies in the left subtree.
- If both are greater, LCA lies in the right subtree.
- Otherwise, current node is the LCA.

Time: O(h), where h is the height of the tree

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

// Main function
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root) {
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        } else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        } else {
            return root;
        }
    }
    return NULL;
}

// --- Demo and helpers ---

// Create a new TreeNode
struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
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
           6
          / \
         2   8
        / \ / \
       0  4 7  9
         / \
        3   5
    */
    struct TreeNode* root = newNode(6);
    root->left = newNode(2);
    root->right = newNode(8);
    root->left->left = newNode(0);
    root->left->right = newNode(4);
    root->left->right->left = newNode(3);
    root->left->right->right = newNode(5);
    root->right->left = newNode(7);
    root->right->right = newNode(9);

    struct TreeNode* p = root->left;           // Node with val = 2
    struct TreeNode* q = root->left->right;    // Node with val = 4

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);
    printf("Lowest Common Ancestor of %d and %d is: %d\n", p->val, q->val, lca->val);  // Output: 2

    freeTree(root);
    return 0;
}
