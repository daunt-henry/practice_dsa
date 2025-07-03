/*
Problem:
Given an array representing the heights of students, determine how many
students are not standing in the right position compared to a non-decreasing sorted order.

Approach:
- Copy the heights to a new array.
- Sort the new array.
- Compare original and sorted arrays to count mismatches.

Time: O(n log n)
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int heightChecker(int* heights, int heightsSize) {
    int* expected = (int*)malloc(sizeof(int) * heightsSize);
    memcpy(expected, heights, sizeof(int) * heightsSize);

    qsort(expected, heightsSize, sizeof(int), cmp);

    int count = 0;
    for (int i = 0; i < heightsSize; i++) {
        if (heights[i] != expected[i]) {
            count++;
        }
    }

    free(expected);
    return count;
}

// Test
int main() {
    int heights[] = {1, 1, 4, 2, 1, 3};
    int size = sizeof(heights) / sizeof(heights[0]);

    int result = heightChecker(heights, size);
    printf("Number of mismatched positions: %d\n", result);  // Expected: 3

    return 0;
}

/*
========= OUTPUT =========
Number of mismatched positions: 3
==========================
*/
