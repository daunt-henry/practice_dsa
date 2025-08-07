/*
Problem: H-Index II

Given a sorted array of citation counts for a researcher's papers (ascending order),
find the researcher's h-index efficiently. The h-index is defined such that the
researcher has at least h papers with at least h citations each.

Example:
Input: citations = [0, 1, 3, 5, 6]
Output: 3

Explanation:
There are 5 papers in total. We look for the maximum h such that there are at least
h papers with at least h citations. Here, 3 papers have 3 or more citations,
hence h-index = 3.
*/

#include <stdio.h>

// Performs binary search to find the smallest index where citations[index] + index >= n
// The result is then h-index = n - index.
int hIndex(int* citations, int citationsSize) {
    int left = 0, right = citationsSize;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (citations[mid] + mid >= citationsSize)
            right = mid;
        else
            left = mid + 1;
    }
    return citationsSize - left;
}

int main() {
    int citations[] = {0, 1, 3, 5, 6};
    int size = sizeof(citations) / sizeof(citations[0]);

    int result = hIndex(citations, size);
    printf("H-index: %d\n", result);  // Expected output: H-index: 3

    return 0;
}
