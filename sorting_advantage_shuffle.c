/*
Problem: Advantage Shuffle (LeetCode 870)

Given two arrays A and B, rearrange A to maximize the number of indices where A[i] > B[i].

Approach:
- Sort A
- Sort B with original indices
- Greedy assign:
    - if A can beat B[i], use largest A
    - else, sacrifice smallest A

Time: O(n log n)
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Pair;

int compare(const void* a, const void* b) {
    return ((Pair*)a)->value - ((Pair*)b)->value;
}

int* advantageCount(int* A, int ASize, int* B, int BSize, int* returnSize) {
    qsort(A, ASize, sizeof(int), compare);

    Pair* Bpair = malloc(sizeof(Pair) * BSize);
    for (int i = 0; i < BSize; i++) {
        Bpair[i].value = B[i];
        Bpair[i].index = i;
    }
    qsort(Bpair, BSize, sizeof(Pair), compare);

    int* res = malloc(sizeof(int) * ASize);
    int low = 0, high = ASize - 1;

    for (int i = BSize - 1; i >= 0; i--) {
        int b = Bpair[i].value;
        int idx = Bpair[i].index;

        if (A[high] > b) {
            res[idx] = A[high--];
        } else {
            res[idx] = A[low++];
        }
    }

    *returnSize = ASize;
    free(Bpair);
    return res;
}

// Test
int main() {
    int A[] = {2,7,11,15};
    int B[] = {1,10,4,11};
    int size = sizeof(A)/sizeof(A[0]);
    int returnSize;

    int* result = advantageCount(A, size, B, size, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    free(result);
    return 0;
}

/*
========= OUTPUT =========
Output: [2,11,7,15]
==========================
*/
