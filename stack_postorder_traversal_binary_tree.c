/*
🧩 Problem:
Given the root of a binary tree, return the postorder traversal of its nodes' values.

📘 Postorder Traversal Order: Left -> Right -> Root

🧪 Examples:
Input: root = [1, null, 2, 3]
Output: [3, 2, 1]

Input: root = []
Output: []

Input: root = [1]
Output: [1]

🛠️ Constraints:
- Tree has up to 100 nodes
- Node values range from -100 to 100
*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(1000 * sizeof(int));
    struct TreeNode* stack[1000];
    struct TreeNode* prev = NULL;
    int top = -1, idx = 0;
    *returnSize = 0;

    while (root || top != -1) {
        while (root) {
            stack[++top] = root;
            root = root->left;
        }
        root = stack[top];
        if (!root->right || root->right == prev) {
            result[idx++] = root->val;
            prev = root;
            top--;
            root = NULL;
        } else {
            root = root->right;
        }
    }

    *returnSize = idx;
    return result;
}

/* 🔽 Sample driver code for demonstration
int main() {
    // Example tree: 1 -> (null, 2 -> 3)
    struct TreeNode node3 = {3, NULL, NULL};
    struct TreeNode node2 = {2, &node3, NULL};
    struct TreeNode node1 = {1, NULL, &node2};

    int returnSize;
    int* result = postorderTraversal(&node1, &returnSize);
    
    printf("Postorder Traversal: ");
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
*/
