/*
Problem:
There are `n` meeting rooms, all initially free.
You are given `meetings`, where each meeting has a start and end time.

Rule:
- A meeting takes the smallest indexed free room at its start.
- If no room is available at the meeting start, wait until the earliest one frees up, and then assign it.
- Meetings are scheduled in the given order.

Return the index of the room that held the most meetings.

Example Input:
n = 2
meetings = [[0,10],[1,5],[2,7],[3,4]]

Expected Output:
0
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long ll;

int cmpMeetings(const void* a, const void* b) {
    int* m1 = *(int**)a;
    int* m2 = *(int**)b;
    return m1[0] - m2[0];
}

int mostBooked(int n, int** meetings, int meetingsSize, int* meetingsColSize) {
    int* roomCount = calloc(n, sizeof(int));
    ll* endTime = calloc(n, sizeof(ll));

    qsort(meetings, meetingsSize, sizeof(int*), cmpMeetings);

    for (int i = 0; i < meetingsSize; ++i) {
        int start = meetings[i][0];
        int end = meetings[i][1];
        int duration = end - start;

        int roomFound = -1;
        ll earliest = LLONG_MAX;

        for (int j = 0; j < n; ++j) {
            if (endTime[j] <= start) {
                roomFound = j;
                break;
            }
            if (endTime[j] < earliest) {
                earliest = endTime[j];
                roomFound = j;
            }
        }

        if (endTime[roomFound] <= start)
            endTime[roomFound] = end;
        else
            endTime[roomFound] += duration;

        roomCount[roomFound]++;
    }

    int maxRoom = 0;
    for (int i = 1; i < n; ++i) {
        if (roomCount[i] > roomCount[maxRoom])
            maxRoom = i;
    }

    free(roomCount);
    free(endTime);
    return maxRoom;
}

int main() {
    int n = 2;
    int m0[] = {0, 10};
    int m1[] = {1, 5};
    int m2[] = {2, 7};
    int m3[] = {3, 4};
    int* meetings[] = {m0, m1, m2, m3};
    int meetingsColSize[] = {2, 2, 2, 2};

    int result = mostBooked(n, meetings, 4, meetingsColSize);
    printf("Room with most meetings: %d\n", result);

    return 0;
}
