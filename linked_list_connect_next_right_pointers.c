/*
Problem:
You are given a perfect binary tree where all leaves are on the same level,
and every parent has two children. Populate each next pointer to point to its next right node.
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Example:
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: The '#' indicates the end of each level.

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a Node with next pointer
struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

// Utility to create a new node
struct Node* createNode(int val) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;
    return node;
}

// Main function to connect next pointers
struct Node* connect(struct Node* root) {
    if (!root) return NULL;

    struct Node* level_start = root;

    while (level_start->left) {
        struct Node* current = level_start;
        while (current) {
            current->left->next = current->right;
            if (current->next) {
                current->right->next = current->next->left;
            }
            current = current->next;
        }
        level_start = level_start->left;
    }

    return root;
}

// Print tree using level order traversal with next pointers
void printLevels(struct Node* root) {
    while (root) {
        struct Node* curr = root;
        while (curr) {
            printf("%d", curr->val);
            if (curr->next) printf(" -> ");
            curr = curr->next;
        }
        printf(" -> NULL\n");
        root = root->left;
    }
}

// Driver code
int main() {
    // Input: [1,2,3,4,5,6,7]
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    connect(root);
    printf("Level order with next pointers:\n");
    printLevels(root);  // Expected output: 1 -> NULL, 2 -> 3 -> NULL, 4 -> 5 -> 6 -> 7 -> NULL

    return 0;
}
