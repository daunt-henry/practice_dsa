/*
Problem:
Given the head of a singly linked list where elements are sorted in ascending order,
convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree where the depth of the two subtrees of every node never differs by more than one.

Example:
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Definition for binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Utility to create a new linked list node
struct ListNode* createListNode(int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Utility to create a new tree node
struct TreeNode* createTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Helper to find the middle node of the list
struct ListNode* findMiddle(struct ListNode* head, struct ListNode** prev) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    *prev = NULL;

    while (fast && fast->next) {
        *prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Main function to convert sorted list to BST
struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (!head) return NULL;
    if (!head->next) return createTreeNode(head->val);

    struct ListNode* prev = NULL;
    struct ListNode* mid = findMiddle(head, &prev);

    if (prev) prev->next = NULL;

    struct TreeNode* root = createTreeNode(mid->val);
    root->left = sortedListToBST(prev ? head : NULL);
    root->right = sortedListToBST(mid->next);

    return root;
}

// Utility to print tree in pre-order traversal
void printPreOrder(struct TreeNode* root) {
    if (!root) return;
    printf("%d ", root->val);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// Driver code
int main() {
    // Input: [-10,-3,0,5,9]
    struct ListNode* head = createListNode(-10);
    head->next = createListNode(-3);
    head->next->next = createListNode(0);
    head->next->next->next = createListNode(5);
    head->next->next->next->next = createListNode(9);

    struct TreeNode* bstRoot = sortedListToBST(head);
    printf("Pre-order of BST: ");
    printPreOrder(bstRoot);  // Example: 0 -10 -3 5 9

    return 0;
}
