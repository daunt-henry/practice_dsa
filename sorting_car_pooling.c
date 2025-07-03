/*
Problem:
You are given trips as {numPassengers, from, to} and a car with a fixed capacity.
Determine if you can complete all the trips without exceeding the capacity at any point.

Approach:
- Use a "difference array" (timeline) to track passengers getting in/out.
- Traverse from 0 to 1000 to simulate the timeline.

Time: O(n + 1000)
Space: O(1000)
*/

#include <stdio.h>
#include <stdbool.h>

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity) {
    int timeline[1001] = {0};

    for (int i = 0; i < tripsSize; i++) {
        int num = trips[i][0];
        int from = trips[i][1];
        int to = trips[i][2];

        timeline[from] += num;
        timeline[to] -= num;
    }

    int curr = 0;
    for (int i = 0; i <= 1000; i++) {
        curr += timeline[i];
        if (curr > capacity) return false;
    }

    return true;
}

// Helper function for dynamic input allocation
int** createTrips(int arr[][3], int size) {
    int** trips = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        trips[i] = (int*)malloc(3 * sizeof(int));
        for (int j = 0; j < 3; j++) {
            trips[i][j] = arr[i][j];
        }
    }
    return trips;
}

// Test
int main() {
    int data[][3] = {{2, 1, 5}, {3, 3, 7}};
    int size = sizeof(data) / sizeof(data[0]);
    int* colSizes = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) colSizes[i] = 3;

    int** trips = createTrips(data, size);

    bool result = carPooling(trips, size, colSizes, 4);
    printf("Can car pool all trips? %s\n", result ? "Yes" : "No");  // Expected: No

    for (int i = 0; i < size; i++) free(trips[i]);
    free(trips);
    free(colSizes);

    return 0;
}

/*
========= OUTPUT =========
Can car pool all trips? No
==========================
*/
