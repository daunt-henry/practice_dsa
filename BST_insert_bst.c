/*
Problem:
Given the root of a binary search tree (BST) and a value to insert into the tree,
insert the value into the BST and return the root of the updated BST.
The new value must be inserted according to the BST property.

Assume there are no duplicate values in the BST.

Approach:
- Traverse the tree recursively.
- If val < node->val → go left
- If val > node->val → go right
- If NULL, create and return new node.

Time Complexity: O(h), where h = height of tree
Space Complexity: O(h) due to recursion

---------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Tree node definition
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Insert value into BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (!root) {
        struct TreeNode* node = malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = node->right = NULL;
        return node;
    }

    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);

    return root;
}

// --------- Helpers ---------
struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void inorder(struct TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// --------- Demo ---------
int main() {
    /*
        Original BST:
             4
            / \
           2   7
          / \
         1   3

        Insert value: 5

        Expected BST Inorder: 1 2 3 4 5 7
    */
    struct TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    int val = 5;
    root = insertIntoBST(root, val);

    printf("BST after insertion (In-order): ");
    inorder(root);  // Expected: 1 2 3 4 5 7
    printf("\n");

    freeTree(root);
    return 0;
}
