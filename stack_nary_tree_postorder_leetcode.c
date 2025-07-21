/*
N-ary Tree Postorder Traversal

Perform postorder traversal on an N-ary tree.
Postorder traversal visits all children of a node first (from left to right), then the node itself.

Example:

Input Tree:
      1
    / | \
   3  2  4
  / \
 5   6

Output: [5, 6, 3, 2, 4, 1]
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    int numChildren;
    struct Node** children;
} Node;

void dfs(Node* root, int* result, int* returnSize) {
    if (!root) return;
    for (int i = 0; i < root->numChildren; ++i) {
        dfs(root->children[i], result, returnSize);
    }
    result[(*returnSize)++] = root->val;
}

int* postorder(Node* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 10000);
    *returnSize = 0;
    dfs(root, result, returnSize);
    return result;
}

// Example usage
int main() {
    Node node5 = {5, 0, NULL};
    Node node6 = {6, 0, NULL};
    Node* children3[] = {&node5, &node6};
    Node node3 = {3, 2, children3};

    Node node2 = {2, 0, NULL};
    Node node4 = {4, 0, NULL};
    Node* children1[] = {&node3, &node2, &node4};
    Node node1 = {1, 3, children1};

    int returnSize;
    int* result = postorder(&node1, &returnSize);

    printf("Postorder traversal: ");
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
