/*
Problem:
Given a binary tree (not necessarily perfect), connect each node's next pointer to its next right node.
If there is no next right node, the next pointer should be set to NULL.

You must do this in **constant extra space** (recursive stack is allowed).

Example:
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]

Explanation: The '#' indicates the end of each level.

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node with next pointer.
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

// Main function to connect next pointers (works for any binary tree)
struct Node* connect(struct Node* root) {
    if (!root) return NULL;

    struct Node* current = root;
    struct Node dummy;  // dummy head for next level
    struct Node* tail = &dummy;

    while (current) {
        if (current->left) {
            tail->next = current->left;
            tail = tail->next;
        }
        if (current->right) {
            tail->next = current->right;
            tail = tail->next;
        }

        current = current->next;

        if (!current) {
            current = dummy.next;
            dummy.next = NULL;
            tail = &dummy;
        }
    }

    return root;
}

// Print tree using next pointers (level-wise)
void printLevels(struct Node* root) {
    while (root) {
        struct Node* curr = root;
        while (curr) {
            printf("%d", curr->val);
            if (curr->next) printf(" -> ");
            curr = curr->next;
        }
        printf(" -> NULL\n");

        // Go to the first node of next level
        while (root && !root->left && !root->right)
            root = root->next;
        if (!root) break;
        root = root->left ? root->left : root->right;
    }
}

// Driver code
int main() {
    // Input: [1,2,3,4,5,null,7]
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(7);

    connect(root);
    printf("Level order with next pointers:\n");
    printLevels(root);  // Expected: 1 -> NULL, 2 -> 3 -> NULL, 4 -> 5 -> 7 -> NULL

    return 0;
}
