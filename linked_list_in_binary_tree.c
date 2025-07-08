/*
Problem:
Given the head of a linked list and the root of a binary tree, return true if there exists a downward path in the tree such that
along the path, the nodes have the same value as the linked list.

The path must go downwards (can only move from parent to child nodes).

Example:
Input:
Linked List: [4,2,8]
Binary Tree:
        1
       / \
      4   4
     /     \
    2       2
   /         \
  1           8

Output: true

Explanation:
There is a path: 4 → 2 → 8 matching the linked list.

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper to match the list from a given tree node
bool match(struct ListNode* head, struct TreeNode* root) {
    if (!head) return true;
    if (!root) return false;
    if (root->val != head->val) return false;
    return match(head->next, root->left) || match(head->next, root->right);
}

// Traverse the tree and try to match from every node
bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    if (!root) return false;
    return match(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
}

// Demo helpers (for testing)
struct ListNode* createList(int* arr, int len) {
    if (len == 0) return NULL;
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    struct ListNode* curr = head;

    for (int i = 1; i < len; i++) {
        curr->next = malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = arr[i];
        curr->next = NULL;
    }
    return head;
}

struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Demo
int main() {
    int listArr[] = {4, 2, 8};
    struct ListNode* head = createList(listArr, 3);

    // Construct binary tree from example
    struct TreeNode* root = newNode(1);
    root->left = newNode(4);
    root->left->left = newNode(2);
    root->left->left->left = newNode(1);
    root->right = newNode(4);
    root->right->right = newNode(2);
    root->right->right->right = newNode(8);

    bool result = isSubPath(head, root);
    printf("Is Linked List a Subpath in Tree? %s\n", result ? "true" : "false");  // Output: true

    return 0;
}
