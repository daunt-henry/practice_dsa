/*
Problem:
Given a root node and a key, delete the node with the given key in the BST and return the new root.

Constraints:
- Maintain the BST property.
- If the node has two children, replace it with its inorder successor or predecessor.

Approach:
- Recursively traverse to find the node.
- If node has:
    - No child: free it.
    - One child: replace with the child.
    - Two children: find inorder successor, copy value, and delete successor.

Time: O(h), Space: O(h), where h = height of tree.

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

// Helper to find minimum node in subtree (in-order successor)
struct TreeNode* minNode(struct TreeNode* node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

// Delete node
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (!root) return NULL;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to delete found
        if (!root->left) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Two children: replace with inorder successor
        struct TreeNode* succ = minNode(root->right);
        root->val = succ->val;
        root->right = deleteNode(root->right, succ->val);
    }

    return root;
}

// --- Helpers and demo ---

// Create node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// In-order print
void inorder(struct TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Free tree
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main demo
int main() {
    /*
            5
           / \
          3   6
         / \    \
        2   4    7
    */

    struct TreeNode* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->right = newNode(7);

    printf("Original BST (Inorder): ");
    inorder(root);  // 2 3 4 5 6 7
    printf("\n");

    int key = 3;
    root = deleteNode(root, key);

    printf("After deleting %d (Inorder): ", key);
    inorder(root);  // Should not contain 3
    printf("\n");

    freeTree(root);
    return 0;
}
