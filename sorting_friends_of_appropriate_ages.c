/*
Problem: Friends of Appropriate Ages (LeetCode 825)

Given a list of people's ages, count how many friend requests would be made
under these rules:
1. age[B] <= age[A]
2. age[B] > 0.5 * age[A] + 7

Approach:
- Count frequency of each age (1 to 120)
- For each pair (ageA, ageB), apply rules
- Avoid self-friend request counting

Time: O(1) since age ranges from 1–120 (constant space & time)
*/

#include <stdio.h>

int numFriendRequests(int* ages, int agesSize) {
    int count[121] = {0};

    for (int i = 0; i < agesSize; i++) {
        count[ages[i]]++;
    }

    int total = 0;

    for (int ageA = 1; ageA <= 120; ageA++) {
        if (count[ageA] == 0) continue;

        for (int ageB = 1; ageB <= 120; ageB++) {
            if (count[ageB] == 0) continue;

            if (ageB <= ageA && ageB > (0.5 * ageA + 7)) {
                if (ageA == ageB) {
                    total += count[ageA] * (count[ageA] - 1);
                } else {
                    total += count[ageA] * count[ageB];
                }
            }
        }
    }

    return total;
}

// Test
int main() {
    int ages[] = {16, 17, 18};
    int size = sizeof(ages) / sizeof(ages[0]);

    int result = numFriendRequests(ages, size);
    printf("Output: %d\n", result);  // Expected: 2

    return 0;
}

/*
========= OUTPUT =========
Output: 2
==========================
*/
