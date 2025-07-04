/*
Diagonal Traverse II

Problem:
- You are given a list of lists `nums`, where `nums[i][j]` exists.
- Return all elements in diagonal order: each diagonal has constant sum (i + j),
  and elements should be processed top to bottom (reverse of row index within each diagonal).

Approach:
- Flatten all (i, j, val) into a list.
- Sort by (i + j) → ascending diagonal
- For same diagonal, sort by i descending (to ensure top-down order in original grid).
- Then extract values.

Time: O(N log N) for sorting
Space: O(N) for temporary list

Example:
Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]
*/

#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int val;
} Node;

int cmp(const void* a, const void* b) {
    Node* n1 = (Node*)a;
    Node* n2 = (Node*)b;
    int d1 = n1->row + n1->col;
    int d2 = n2->row + n2->col;
    if (d1 != d2)
        return d1 - d2;
    return n2->row - n1->row;
}

int* findDiagonalOrder(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    int cap = 100000, count = 0;
    Node* flat = malloc(sizeof(Node) * cap);

    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsColSize[i]; j++) {
            flat[count++] = (Node){i, j, nums[i][j]};
        }
    }

    qsort(flat, count, sizeof(Node), cmp);

    int* res = malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++)
        res[i] = flat[i].val;

    *returnSize = count;
    free(flat);
    return res;
}
