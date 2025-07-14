/*
Problem:
Return all elements from two binary search trees into a sorted list.

Approach:
1. Perform in-order traversal on both BSTs to collect sorted arrays.
2. Merge the two sorted arrays into one.

Time Complexity: O(n + m)
Space Complexity: O(n + m)

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

// In-order traversal
void inorder(struct TreeNode* root, int* arr, int* index) {
    if (!root) return;
    inorder(root->left, arr, index);
    arr[(*index)++] = root->val;
    inorder(root->right, arr, index);
}

// Merge two sorted arrays
void merge(int* a, int sizeA, int* b, int sizeB, int* result) {
    int i = 0, j = 0, k = 0;
    while (i < sizeA && j < sizeB) {
        if (a[i] < b[j]) result[k++] = a[i++];
        else result[k++] = b[j++];
    }
    while (i < sizeA) result[k++] = a[i++];
    while (j < sizeB) result[k++] = b[j++];
}

// Main function
int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize) {
    int* arr1 = malloc(5000 * sizeof(int));
    int* arr2 = malloc(5000 * sizeof(int));
    int index1 = 0, index2 = 0;

    inorder(root1, arr1, &index1);
    inorder(root2, arr2, &index2);

    int* result = malloc((index1 + index2) * sizeof(int));
    merge(arr1, index1, arr2, index2, result);

    *returnSize = index1 + index2;
    free(arr1);
    free(arr2);
    return result;
}

// Helper to create node
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

// Print array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Demo
int main() {
    /*
        Tree 1:      2
                   / \
                  1   4

        Tree 2:      1
                   / \
                  0   3

        Expected output: [0, 1, 1, 2, 3, 4]
    */

    struct TreeNode* root1 = newNode(2);
    root1->left = newNode(1);
    root1->right = newNode(4);

    struct TreeNode* root2 = newNode(1);
    root2->left = newNode(0);
    root2->right = newNode(3);

    int returnSize;
    int* result = getAllElements(root1, root2, &returnSize);
    printf("Merged Elements: ");
    printArray(result, returnSize);  // Output: 0 1 1 2 3 4

    free(result);
    freeTree(root1);
    freeTree(root2);
    return 0;
}
