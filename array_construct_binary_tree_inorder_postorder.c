/*
Construct Binary Tree from Inorder and Postorder Traversal

Given two integer arrays inorder and postorder where inorder is the inorder traversal 
of a binary tree and postorder is the postorder traversal of the same tree, 
construct and return the binary tree.

Example:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int findIndex(int* arr, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == val) return i;
    }
    return -1;
}

struct TreeNode* build(int* inorder, int inStart, int inEnd,
                       int* postorder, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return NULL;

    int rootVal = postorder[postEnd];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = root->right = NULL;

    int rootIndex = findIndex(inorder, inStart, inEnd, rootVal);
    int leftSize = rootIndex - inStart;

    root->left = build(inorder, inStart, rootIndex - 1,
                       postorder, postStart, postStart + leftSize - 1);
    root->right = build(inorder, rootIndex + 1, inEnd,
                        postorder, postStart + leftSize, postEnd - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    return build(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}

// Optional: test code
void printPreorder(struct TreeNode* root) {
    if (!root) return;
    printf("%d ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int n = sizeof(inorder) / sizeof(int);

    struct TreeNode* root = buildTree(inorder, n, postorder, n);
    printf("Preorder of constructed tree: ");
    printPreorder(root);
    printf("\n");
    return 0;
}

/*
Sample Output:
Preorder of constructed tree: 3 9 20 15 7
*/
