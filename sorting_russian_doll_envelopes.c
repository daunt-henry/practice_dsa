/*
Problem: Russian Doll Envelopes

Description:
Given envelopes with dimensions [width, height], find the maximum number
of envelopes you can Russian-doll (i.e., nest).

Approach:
1. Sort envelopes by:
   - Width ascending
   - Height descending (for equal widths)
2. Find Longest Increasing Subsequence (LIS) on heights

Time: O(n log n)
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int* e1 = *(int**)a;
    int* e2 = *(int**)b;
    if (e1[0] != e2[0]) return e1[0] - e2[0];
    return e2[1] - e1[1]; // height descending
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize) {
    qsort(envelopes, envelopesSize, sizeof(int*), cmp);

    int* dp = malloc(sizeof(int) * envelopesSize);
    int len = 0;

    for (int i = 0; i < envelopesSize; i++) {
        int h = envelopes[i][1];

        int left = 0, right = len;
        while (left < right) {
            int mid = (left + right) / 2;
            if (dp[mid] < h)
                left = mid + 1;
            else
                right = mid;
        }

        dp[left] = h;
        if (left == len) len++;
    }

    free(dp);
    return len;
}

// Test
int main() {
    int input[][2] = {{5,4}, {6,4}, {6,7}, {2,3}};
    int size = sizeof(input) / sizeof(input[0]);

    // Convert to array of pointers for qsort
    int** envelopes = malloc(sizeof(int*) * size);
    int* colSizes = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        envelopes[i] = malloc(sizeof(int) * 2);
        envelopes[i][0] = input[i][0];
        envelopes[i][1] = input[i][1];
        colSizes[i] = 2;
    }

    int result = maxEnvelopes(envelopes, size, colSizes);
    printf("Maximum number of envelopes: %d\n", result);

    for (int i = 0; i < size; i++) free(envelopes[i]);
    free(envelopes);
    free(colSizes);
    return 0;
}

/*
========= OUTPUT =========
Maximum number of envelopes: 3
==========================
*/
