/*
Magnetic Force Between Two Balls

Problem:
- You are given an array `position` representing the positions of balls.
- Place `m` balls in the positions such that the minimum distance between any two balls is maximized.

Approach:
- Sort the positions.
- Use binary search on the answer:
  - Try placing the balls with minimum distance `mid`.
  - Use greedy placement to check if it's possible.

Time: O(n log n + n log(maxDist))
Space: O(1)

Example:
Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Balls placed at 1, 4, 7 → min distance = 3
*/

#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

bool isPossible(int* position, int positionSize, int m, int force) {
    int count = 1;
    int last_pos = position[0];

    for (int i = 1; i < positionSize; i++) {
        if (position[i] - last_pos >= force) {
            count++;
            last_pos = position[i];
        }
    }
    return count >= m;
}

int maxDistance(int* position, int positionSize, int m) {
    qsort(position, positionSize, sizeof(int), cmp);

    int low = 1;
    int high = position[positionSize - 1] - position[0];
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(position, positionSize, m, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}
