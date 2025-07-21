/*
N-ary Tree Preorder Traversal

Perform a preorder traversal on an N-ary tree. 
Preorder traversal visits root node first, then recursively visits all its children from left to right.

Input:        Output:
      1           [1, 3, 5, 6, 2, 4]
    / | \
   3  2  4
  / \
 5   6

The tree structure is simulated using Node structs where each node has:
- val (int)
- numChildren (int)
- children (array of Node*)
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
    result[(*returnSize)++] = root->val;
    for (int i = 0; i < root->numChildren; ++i) {
        dfs(root->children[i], result, returnSize);
    }
}

int* preorder(Node* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 10000);
    *returnSize = 0;
    dfs(root, result, returnSize);
    return result;
}

// Example usage (manual tree creation)
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
    int* result = preorder(&node1, &returnSize);

    printf("Preorder traversal: ");
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
