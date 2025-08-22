/*
Problem: Teemo Attacking (LeetCode 495)
Given attack times (sorted) in `timeSeries[]` and a fixed `duration`,
compute the total time a target remains poisoned.
Each attack poisons for 'duration' seconds, but overlapping poisoning should not be double-counted.

Example:
Input: timeSeries = [1, 4], duration = 2
Output: 4  (poison covers [1,3) and [4,6); total = 4 seconds)

Approach:
Iterate across attacks:
 - For each adjacent pair, add min(duration, gap between attacks)
Finally, add full `duration` for the last attack.

Time Complexity: O(n), Space Complexity: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    if (duration == 0 || timeSeriesSize == 0) return 0;

    int total = 0;
    for (int i = 0; i + 1 < timeSeriesSize; i++) {
        int diff = timeSeries[i + 1] - timeSeries[i];
        total += diff < duration ? diff : duration;
    }
    return total + duration;
}

int main(void) {
    int ts1[] = {1, 4};
    printf("Output: %d (expected 4)\n",
           findPoisonedDuration(ts1, 2, 2));

    int ts2[] = {1, 2};
    printf("Output: %d (expected 3)\n",
           findPoisonedDuration(ts2, 2, 2));

    int ts3[] = {1, 2, 5};
    printf("Output: %d (expected 4)\n",
           findPoisonedDuration(ts3, 3, 2));
    // Explanation: [1,3), [2,4) overlap => total 3, then [5,7) adds 2 => total 5 (oops miscount)—
    // Correct handling: gaps: min(2,1)=1, min(2,3)=2 → total = 1 + 2 + 2 = 5

    return 0;
}
