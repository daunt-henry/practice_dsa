/*
Problem: Hand of Straights (LeetCode 846)

Given an array `hand[]` and group size, determine whether it can be rearranged into groups
of consecutive cards of length groupSize.

Approach:
- Sort hand
- Greedily try to form a group starting from each unused card

Time: O(n^2)
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int isNStraightHand(int* hand, int handSize, int groupSize) {
    if (handSize % groupSize != 0) return 0;

    qsort(hand, handSize, sizeof(int), cmp);

    int* used = (int*)calloc(handSize, sizeof(int));

    for (int i = 0; i < handSize; i++) {
        if (used[i]) continue;

        int start = hand[i];
        int count = 0;

        for (int j = 0; j < handSize && count < groupSize; j++) {
            if (!used[j] && hand[j] == start + count) {
                used[j] = 1;
                count++;
            }
        }

        if (count < groupSize) {
            free(used);
            return 0;
        }
    }

    free(used);
    return 1;
}

// Test
int main() {
    int hand[] = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int size = sizeof(hand) / sizeof(hand[0]);
    int groupSize = 3;

    int result = isNStraightHand(hand, size, groupSize);
    printf("Output: %s\n", result ? "true" : "false");  // Expected: true

    return 0;
}

/*
========= OUTPUT =========
Output: true
==========================
*/
