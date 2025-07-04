/*
Check If String Is Transformable With Substring Sort Operations

Problem:
- You can perform an operation: pick any digit and move it to the left
  as long as it's greater than all digits to its left.
- Return true if s can be transformed to t using such operations.

Approach:
- Track the positions of each digit in s using queues.
- For each digit in t:
  - Check if it's available in s.
  - Ensure no smaller digit is ahead in the queue (i.e., blocking the move).

Time: O(n)
Space: O(n)

Example:
Input: s = "84532", t = "34852"
Output: true
*/

#include <stdbool.h>
#include <string.h>

int queue[10][100005], front[10], rear[10];

bool isTransformable(char* s, char* t) {
    int len = strlen(s);
    memset(front, 0, sizeof(front));
    memset(rear, 0, sizeof(rear));

    for (int i = 0; i < len; i++) {
        int d = s[i] - '0';
        queue[d][rear[d]++] = i;
    }

    for (int i = 0; i < len; i++) {
        int d = t[i] - '0';
        if (front[d] >= rear[d])
            return false;

        int idx = queue[d][front[d]++];

        for (int j = 0; j < d; j++) {
            if (front[j] < rear[j] && queue[j][front[j]] < idx)
                return false;
        }
    }
    return true;
}
