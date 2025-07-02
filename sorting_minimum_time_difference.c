/*
Problem: Minimum Time Difference

Given a list of time points in "HH:MM" format,
return the minimum difference in minutes between any two time points.

Approach:
1. Convert each time to total minutes.
2. Sort the times.
3. Compare all consecutive pairs and also the wrap-around pair.
4. Return the minimum.

Time: O(n log n)
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int timeToMinutes(char* time) {
    int hour = (time[0] - '0') * 10 + (time[1] - '0');
    int minute = (time[3] - '0') * 10 + (time[4] - '0');
    return hour * 60 + minute;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findMinDifference(char** timePoints, int timePointsSize) {
    int* minutes = malloc(sizeof(int) * timePointsSize);
    for (int i = 0; i < timePointsSize; i++) {
        minutes[i] = timeToMinutes(timePoints[i]);
    }

    qsort(minutes, timePointsSize, sizeof(int), compare);

    int minDiff = 1440;
    for (int i = 1; i < timePointsSize; i++) {
        int diff = minutes[i] - minutes[i - 1];
        if (diff < minDiff) minDiff = diff;
    }

    // Check circular difference
    int wrapDiff = 1440 - minutes[timePointsSize - 1] + minutes[0];
    if (wrapDiff < minDiff) minDiff = wrapDiff;

    free(minutes);
    return minDiff;
}

// Test
int main() {
    char* timePoints[] = {"23:59", "00:00", "12:00"};
    int size = sizeof(timePoints) / sizeof(timePoints[0]);

    int result = findMinDifference(timePoints, size);
    printf("Minimum time difference: %d minutes\n", result);

    return 0;
}

/*
========= OUTPUT =========
Minimum time difference: 1 minutes
==========================
*/
