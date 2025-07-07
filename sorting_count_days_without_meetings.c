/*
Problem:
You're given:
- `days`: total number of days.
- `meetings`: a list of intervals where each meeting occupies a range of days.

Return the **number of days** that are not covered by any meeting.

Example Input:
days = 10  
meetings = [[1,2], [4,5], [7,10]]

Expected Output:
2

Explanation:
Meetings cover days: 1-2, 4-5, 7-10  
Free days: 3 and 6 → total = 2
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

int countDays(int days, int** meetings, int meetingsSize, int* meetingsColSize) {
    qsort(meetings, meetingsSize, sizeof(int*), cmp);

    int freeDays = 0;
    int prevEnd = 0;

    for (int i = 0; i < meetingsSize; ++i) {
        int start = meetings[i][0];
        int end = meetings[i][1];

        if (start > prevEnd + 1)
            freeDays += (start - prevEnd - 1);

        if (end > prevEnd)
            prevEnd = end;
    }

    if (prevEnd < days)
        freeDays += (days - prevEnd);

    return freeDays;
}

int main() {
    int m1[] = {1, 2}, m2[] = {4, 5}, m3[] = {7, 10};
    int* meetings[] = {m1, m2, m3};
    int cols[] = {2, 2, 2};
    int days = 10;

    int result = countDays(days, meetings, 3, cols);
    printf("Free days without meetings: %d\n", result);  // Output: 2
    return 0;
}
