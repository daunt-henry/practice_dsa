/*
Problem:
Implement an iterator over a binary search tree (BST).
Your BSTIterator object will be initialized with the root node of a BST.
Calling `next()` will return the next smallest number in the BST.

Functions to implement:
- BSTIterator* bSTIteratorCreate(struct TreeNode* root)
- int bSTIteratorNext(BSTIterator* obj)
- bool bSTIteratorHasNext(BSTIterator* obj)
- void bSTIteratorFree(BSTIterator* obj)

Constraints:
- You must use O(h) memory, where h is the height of the tree.
- `next()` and `hasNext()` must run in average O(1) time.

------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// TreeNode definition
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Stack capacity
#define STACK_CAPACITY 100

// BST Iterator struct
typedef struct {
    struct TreeNode* stack[STACK_CAPACITY];
    int top;
} BSTIterator;

// Push all left nodes into stack
void pushLeft(BSTIterator* obj, struct TreeNode* node) {
    while (node) {
        obj->stack[++(obj->top)] = node;
        node = node->left;
    }
}

// Create iterator
BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* obj = malloc(sizeof(BSTIterator));
    obj->top = -1;
    pushLeft(obj, root);
    return obj;
}

// Return next smallest element
int bSTIteratorNext(BSTIterator* obj) {
    struct TreeNode* node = obj->stack[(obj->top)--];
    if (node->right) {
        pushLeft(obj, node->right);
    }
    return node->val;
}

// Check if there are more elements
bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->top != -1;
}

// Free memory
void bSTIteratorFree(BSTIterator* obj) {
    free(obj);
}

// -----------------------------
// Demo helpers

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
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
           7
          / \
         3   15
             / \
            9  20
    */

    struct TreeNode* root = newNode(7);
    root->left = newNode(3);
    root->right = newNode(15);
    root->right->left = newNode(9);
    root->right->right = newNode(20);

    BSTIterator* iterator = bSTIteratorCreate(root);
    while (bSTIteratorHasNext(iterator)) {
        printf("%d ", bSTIteratorNext(iterator));
    }
    printf("\n");  // Expected Output: 3 7 9 15 20

    bSTIteratorFree(iterator);
    freeTree(root);
    return 0;
}
