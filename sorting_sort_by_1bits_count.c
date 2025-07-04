/*
Sort Integers by The Number of 1 Bits

Problem:
Sort array by:
1. Number of 1's in binary (ascending)
2. If tie, by actual number (ascending)

Approach:
- Custom comparator using bit-count
- Use qsort in C

Time Complexity: O(n log n)
Space: O(1)

Example:
Input: [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
*/

#include <stdlib.h>

// Count 1's in binary
int countBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// Compare by bit count then value
int compare(const void* a, const void* b) {
    int bitA = countBits(*(int*)a);
    int bitB = countBits(*(int*)b);
    if (bitA == bitB)
        return *(int*)a - *(int*)b;
    return bitA - bitB;
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    qsort(arr, arrSize, sizeof(int), compare);
    *returnSize = arrSize;
    return arr;
}
