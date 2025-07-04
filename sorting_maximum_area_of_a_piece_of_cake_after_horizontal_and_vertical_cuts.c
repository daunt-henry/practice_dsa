/*
Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts

Problem:
- Given height `h` and width `w` of a cake and arrays of horizontal and vertical cuts,
  find the maximum area of a piece of cake after making all cuts.

Approach:
- Sort the horizontal and vertical cuts.
- Find the largest gap between consecutive cuts (including edges).
- Maximum area = max horizontal gap × max vertical gap.

Time: O(n log n + m log m)
Space: O(1) extra

Example:
Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Sorted: horz = [1,2,4], vert = [1,3]
Gaps: maxH = 2 (from 2 to 4), maxW = 2 (from 1 to 3)
Area: 2 × 2 = 4

Output: 4
*/

#include <stdlib.h>

#define MOD 1000000007

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxArea(int h, int w, int* horizontalCuts, int horizontalCutsSize, int* verticalCuts, int verticalCutsSize) {
    qsort(horizontalCuts, horizontalCutsSize, sizeof(int), cmp);
    qsort(verticalCuts, verticalCutsSize, sizeof(int), cmp);

    long maxH = horizontalCuts[0];
    for (int i = 1; i < horizontalCutsSize; i++) {
        int diff = horizontalCuts[i] - horizontalCuts[i - 1];
        if (diff > maxH) maxH = diff;
    }
    if (h - horizontalCuts[horizontalCutsSize - 1] > maxH)
        maxH = h - horizontalCuts[horizontalCutsSize - 1];

    long maxW = verticalCuts[0];
    for (int i = 1; i < verticalCutsSize; i++) {
        int diff = verticalCuts[i] - verticalCuts[i - 1];
        if (diff > maxW) maxW = diff;
    }
    if (w - verticalCuts[verticalCutsSize - 1] > maxW)
        maxW = w - verticalCuts[verticalCutsSize - 1];

    return (int)((maxH * maxW) % MOD);
}
