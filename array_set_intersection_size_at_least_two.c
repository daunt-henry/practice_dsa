/*
Problem: Set Intersection Size At Least Two (LeetCode 757)
URL: https://leetcode.com/problems/set-intersection-size-at-least-two/

Given a list of integer intervals [start, end], find the minimum size of a set S such that
every interval contains at least two elements from S.

Approach (Greedy + Sorting):
- Sort intervals by end ascending, and for ties by start descending.
- Keep track of two most recent selected points: p1 < p2.
- For each interval:
   - If it already contains both p1 and p2, do nothing.
   - If it contains none, add two points: end - 1 and end.
   - If it contains one, add one point: end.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int cmp(const void* a, const void* b) {
    const Interval* A = a;
    const Interval* B = b;
    if (A->end != B->end) return A->end - B->end;
    return B->start - A->start;
}

int intersectionSizeTwo(int** intervals, int intervalsSize, int* intervalsColSize) {
    Interval* arr = malloc(intervalsSize * sizeof(Interval));
    for (int i = 0; i < intervalsSize; i++) {
        arr[i].start = intervals[i][0];
        arr[i].end = intervals[i][1];
    }
    qsort(arr, intervalsSize, sizeof(Interval), cmp);

    int ans = 0, p1 = -1, p2 = -1;
    for (int i = 0; i < intervalsSize; i++) {
        int a = arr[i].start, b = arr[i].end;
        if (a <= p1) {
            // Already covered by p1 and p2
            continue;
        } else if (a > p2) {
            // No overlap
            ans += 2;
            p1 = b - 1;
            p2 = b;
        } else {
            // Partial overlap
            ans += 1;
            p1 = p2;
            p2 = b;
        }
    }

    free(arr);
    return ans;
}

int main(void) {
    int a1[][2] = {{1,3}, {1,4}, {2,5}, {3,5}};
    int* intervals1[4];
    int cols[4] = {2,2,2,2};
    for (int i = 0; i < 4; i++) intervals1[i] = a1[i];
    printf("Expected: 3, Got: %d\n", intersectionSizeTwo(intervals1, 4, cols));

    int a2[][2] = {{1,2}, {2,3}, {2,4}, {4,5}};
    int* intervals2[4];
    for (int i = 0; i < 4; i++) intervals2[i] = a2[i];
    printf("Expected: 5, Got: %d\n", intersectionSizeTwo(intervals2, 4, cols));

    return 0;
}
