/*
Maximum Number of Events That Can Be Attended II

Given a list of events where each event has a start time, end time, and value,
and an integer k, return the maximum value that can be obtained by attending at most k non-overlapping events.

Approach:
- Sort events by end time.
- Use dynamic programming where dp[i][j] represents the max value considering first i events and attending j.
- For each event, choose either:
    1. Skip the event → dp[i-1][j]
    2. Attend it → event value + dp of the latest non-overlapping event

Time Complexity: O(n * k * log n)

Example:
Input: events = [[1,3,4],[2,4,3],[10,11,2]], k = 2
Output: 6
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
    int value;
} Event;

int cmp(const void* a, const void* b) {
    Event* ea = (Event*)a;
    Event* eb = (Event*)b;
    return ea->end - eb->end;
}

int binarySearch(Event* events, int endIndex, int target) {
    int left = 0, right = endIndex - 1, res = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (events[mid].end < target) {
            res = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return res;
}

int maxValue(int** events, int eventsSize, int* eventsColSize, int k) {
    Event* evs = (Event*)malloc(sizeof(Event) * eventsSize);
    for (int i = 0; i < eventsSize; ++i) {
        evs[i].start = events[i][0];
        evs[i].end = events[i][1];
        evs[i].value = events[i][2];
    }

    qsort(evs, eventsSize, sizeof(Event), cmp);

    int** dp = (int**)malloc((eventsSize + 1) * sizeof(int*));
    for (int i = 0; i <= eventsSize; ++i)
        dp[i] = (int*)calloc(k + 1, sizeof(int));

    for (int i = 1; i <= eventsSize; ++i) {
        for (int j = 1; j <= k; ++j) {
            int prev = binarySearch(evs, i - 1, evs[i - 1].start);
            int valWith = evs[i - 1].value + (prev != -1 ? dp[prev + 1][j - 1] : 0);
            int valWithout = dp[i - 1][j];
            dp[i][j] = valWith > valWithout ? valWith : valWithout;
        }
    }

    int result = dp[eventsSize][k];
    for (int i = 0; i <= eventsSize; ++i)
        free(dp[i]);
    free(dp);
    free(evs);
    return result;
}
