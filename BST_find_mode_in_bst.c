/*
Problem:
Given the root of a BST, return all the mode(s) (value(s) that appear most frequently).

Constraints:
- The BST may contain duplicate values.
- Return result in any order.
- O(n) time and ideally O(1) space (not counting output).

Approach:
- Do in-order traversal (left-root-right) to get sorted values.
- Track current value, current count, and max frequency.
- Use two passes: first to find max frequency, second to collect modes.

Time: O(n), Space: O(h) recursion stack + output array

------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// -------- TreeNode Definition --------
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// -------- Globals for Traversal --------
int currentVal;
int currentCount;
int maxCount;
int modeCount;
int* modes;

// -------- First and Second Pass Traversal --------
void inorder(struct TreeNode* root, int collect) {
    if (!root) return;

    inorder(root->left, collect);

    if (root->val != currentVal) {
        currentVal = root->val;
        currentCount = 1;
    } else {
        currentCount++;
    }

    if (currentCount > maxCount) {
        maxCount = currentCount;
        modeCount = 1;
        if (collect) modes[0] = currentVal;
    } else if (currentCount == maxCount) {
        if (collect) modes[modeCount] = currentVal;
        modeCount++;
    }

    inorder(root->right, collect);
}

// -------- Find Mode Function --------
int* findMode(struct TreeNode* root, int* returnSize) {
    currentVal = 0x7FFFFFFF;
    currentCount = 0;
    maxCount = 0;
    modeCount = 0;

    inorder(root, 0);  // First pass: get maxCount and modeCount

    modes = malloc(sizeof(int) * modeCount);
    modeCount = 0;
    currentVal = 0x7FFFFFFF;
    currentCount = 0;

    inorder(root, 1);  // Second pass: collect modes

    *returnSize = modeCount;
    return modes;
}

// -------- Tree Utilities --------
struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// -------- Demo Main --------
int main() {
    /*
         1
          \
           2
          /
         2
    */
    struct TreeNode* root = newNode(1);
    root->right = newNode(2);
    root->right->left = newNode(2);

    int size = 0;
    int* result = findMode(root, &size);

    printf("Modes: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    freeTree(root);
    return 0;
}
