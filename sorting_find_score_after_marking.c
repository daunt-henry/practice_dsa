#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Question:
// You are given an array nums. You repeatedly pick the smallest unmarked element,
// mark it, and also mark its adjacent elements. Add the picked value to the score.
// Return the total score after all elements are marked.

// Output: 8 (example)

typedef struct {
    int val;
    int idx;
} Pair;

int cmp(const void* a, const void* b) {
    Pair* p1 = (Pair*)a;
    Pair* p2 = (Pair*)b;
    if (p1->val == p2->val) return p1->idx - p2->idx;
    return p1->val - p2->val;
}

long long findScore(int* nums, int numsSize) {
    Pair* arr = malloc(sizeof(Pair) * numsSize);
    bool* marked = calloc(numsSize, sizeof(bool));
    long long score = 0;

    for (int i = 0; i < numsSize; ++i) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    qsort(arr, numsSize, sizeof(Pair), cmp);

    for (int i = 0; i < numsSize; ++i) {
        int idx = arr[i].idx;
        if (marked[idx]) continue;
        score += arr[i].val;
        marked[idx] = true;
        if (idx > 0) marked[idx - 1] = true;
        if (idx + 1 < numsSize) marked[idx + 1] = true;
    }

    free(arr);
    free(marked);
    return score;
}

// ----------- Main / Test Code -----------
int main() {
    int nums[] = {2, 1, 3, 4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    long long result = findScore(nums, numsSize);
    printf("%lld\n", result); // Output: 8

    return 0;
}
