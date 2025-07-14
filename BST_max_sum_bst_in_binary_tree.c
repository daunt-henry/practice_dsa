/*
Problem:
Return the maximum sum of keys of any subtree of the given binary tree which is also a BST.

Approach:
- Use post-order traversal (DFS).
- At each node, collect info from left and right subtrees.
- Check if the current subtree is a BST.
- If valid, compute and track maximum sum.

Time Complexity: O(n)
Space Complexity: O(h)

------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Tree node structure
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Info per subtree
struct Info {
    bool isBST;
    int sum;
    int minVal;
    int maxVal;
};

int maxSum = 0;

// DFS traversal
struct Info dfs(struct TreeNode* root) {
    if (!root) return (struct Info){true, 0, INT_MAX, INT_MIN};

    struct Info left = dfs(root->left);
    struct Info right = dfs(root->right);

    if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
        int currSum = left.sum + right.sum + root->val;
        if (currSum > maxSum) maxSum = currSum;

        return (struct Info){
            true,
            currSum,
            root->left ? left.minVal : root->val,
            root->right ? right.maxVal : root->val
        };
    }

    return (struct Info){false, 0, 0, 0};
}

// Main function
int maxSumBST(struct TreeNode* root) {
    maxSum = 0;
    dfs(root);
    return maxSum;
}

// Helpers
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

// Demo
int main() {
    /*
        Tree:
               1
              / \
             4   3
            / \
           2   4

        Subtree 4-2-4 is BST with sum 10
    */

    struct TreeNode* root = newNode(1);
    root->left = newNode(4);
    root->right = newNode(3);
    root->left->left = newNode(2);
    root->left->right = newNode(4);

    int result = maxSumBST(root);
    printf("Maximum Sum of BST Subtree: %d\n", result);  // Expected: 10

    freeTree(root);
    return 0;
}
