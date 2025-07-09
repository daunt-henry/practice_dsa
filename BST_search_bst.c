/*
Problem:
You are given the root of a binary search tree (BST) and an integer val.
Return the subtree rooted at the node with value val.
If such a node does not exist, return NULL.

Approach:
- Use recursion or iteration to search the BST.
- At each step:
  - If node->val == val → return node.
  - If val < node->val → search left subtree.
  - If val > node->val → search right subtree.

Time Complexity: O(h), where h = height of tree
Space Complexity: O(h) due to recursion

-------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Tree node definition
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Search BST
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (!root) return NULL;

    if (val == root->val)
        return root;
    else if (val < root->val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

// ------- Helpers --------
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
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

// -------- Demo --------
int main() {
    /*
        Tree:
            4
           / \
          2   7
         / \
        1   3

        Search for val = 2
        Expected subtree: 2 → 1, 3
    */

    struct TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    int val = 2;
    struct TreeNode* result = searchBST(root, val);

    if (result) {
        printf("Subtree rooted at %d (In-order): ", val);
        inorder(result);  // Expected: 1 2 3
    } else {
        printf("Value %d not found in BST.\n", val);
    }
    printf("\n");

    freeTree(root);
    return 0;
}
