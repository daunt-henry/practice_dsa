/*
Problem:
Given the head of a singly linked list and dimensions `m` x `n`, fill a matrix of size m x n
with values from the list in spiral order. Fill unused cells with -1.

Example:
Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output:
[
 [3,0,2,6,8],
 [5,0,-1,-1,1],
 [5,2,4,9,7]
]

Explanation:
Values filled clockwise in spiral pattern using the linked list.

-------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

int** spiralMatrix(int m, int n, struct ListNode* head, int* returnSize, int** returnColumnSizes) {
    int** matrix = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    *returnSize = m;

    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) {
            matrix[i][j] = -1;
        }
    }

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (head && top <= bottom && left <= right) {
        for (int j = left; j <= right && head; j++) {
            matrix[top][j] = head->val;
            head = head->next;
        }
        top++;
        for (int i = top; i <= bottom && head; i++) {
            matrix[i][right] = head->val;
            head = head->next;
        }
        right--;
        for (int j = right; j >= left && head && top <= bottom; j--) {
            matrix[bottom][j] = head->val;
            head = head->next;
        }
        bottom--;
        for (int i = bottom; i >= top && head && left <= right; i--) {
            matrix[i][left] = head->val;
            head = head->next;
        }
        left++;
    }

    return matrix;
}

// Demo helpers
struct ListNode* createList(int* arr, int size) {
    struct ListNode* head = NULL, *tail = NULL;
    for (int i = 0; i < size; ++i) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

void printMatrix(int** matrix, int m, int* colSizes) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < colSizes[i]; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(int** matrix, int m) {
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int vals[] = {3,0,2,6,8,1,7,9,4,2,5,5,0};
    int m = 3, n = 5;
    struct ListNode* head = createList(vals, sizeof(vals)/sizeof(int));

    int returnSize;
    int* colSizes;
    int** matrix = spiralMatrix(m, n, head, &returnSize, &colSizes);

    printf("Spiral Filled Matrix:\n");
    printMatrix(matrix, returnSize, colSizes);

    freeList(head);
    freeMatrix(matrix, returnSize);
    free(colSizes);
    return 0;
}
