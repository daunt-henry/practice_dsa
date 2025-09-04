/*
Problem: Open the Lock (LeetCode 752)
URL: https://leetcode.com/problems/open-the-lock/

We have a lock with 4 wheels (`0000` to `9999`). Each can rotate +1 or -1.
Given deadends (combinations to avoid) and a target, find the minimum number
of rotations (moves) needed to reach the target from "0000", or return -1 if impossible.

Approach: BFS (Breadth-First Search)
- Represent each state as a 4-digit number.
- Enqueue starting state `0000`.
- At each step, generate 8 neighbors (increment/decrement each digit).
- Avoid deadends and visited states.

Time Complexity: O(10^4) — manageable for brute BFS
Space Complexity: O(10^4)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STATE 10000
#define QUEUE_SIZE 20000

void inc(char* s, int i) {
    s[i] = (s[i] == '9') ? '0' : s[i] + 1;
}

void dec(char* s, int i) {
    s[i] = (s[i] == '0') ? '9' : s[i] - 1;
}

int openLock(char **deadends, int deadendsSize, char *target) {
    if (strcmp(target, "0000") == 0) return 0;

    bool dead[MAX_STATE] = {false}, seen[MAX_STATE] = {false};
    int code;
    for (int i = 0; i < deadendsSize; i++) {
        code = (deadends[i][0]-'0')*1000 + (deadends[i][1]-'0')*100 +
               (deadends[i][2]-'0')*10 + (deadends[i][3]-'0');
        dead[code] = true;
    }

    int targetCode = (target[0]-'0')*1000 + (target[1]-'0')*100 +
                     (target[2]-'0')*10 + (target[3]-'0');

    if (dead[0]) return -1;

    int queue[QUEUE_SIZE];
    int front = 0, back = 0;
    queue[back++] = 0;
    seen[0] = true;
    int steps = 0;

    char s[5], orig;

    while (front < back) {
        steps++;
        int sz = back - front;
        while (sz--) {
            int x = queue[front++];
            sprintf(s, "%04d", x);

            for (int i = 0; i < 4; i++) {
                orig = s[i];

                inc(s, i);
                code = (s[0]-'0')*1000 + (s[1]-'0')*100 +
                       (s[2]-'0')*10 + (s[3]-'0');
                if (!dead[code] && !seen[code]) {
                    if (code == targetCode) return steps;
                    seen[code] = true;
                    queue[back++] = code;
                }

                s[i] = orig;
                dec(s, i);
                code = (s[0]-'0')*1000 + (s[1]-'0')*100 +
                       (s[2]-'0')*10 + (s[3]-'0');
                if (!dead[code] && !seen[code]) {
                    if (code == targetCode) return steps;
                    seen[code] = true;
                    queue[back++] = code;
                }

                s[i] = orig;
            }
        }
    }

    return -1;
}

int main(void) {
    char* dead1[] = {"0201","0101","0102","1212","2002"};
    char target1[] = "0202";
    printf("Output: %d (expected: 6)\n",
           openLock(dead1, 5, target1));

    char* dead2[] = {"8888"};
    char target2[] = "0009";
    printf("Output: %d (expected: 1)\n",
           openLock(dead2, 1, target2));

    return 0;
}
