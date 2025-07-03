/*
Problem:
You can play a token face up by spending power and gain score.
You can play a token face down by spending score and gain power.
Goal: Maximize final score.

Approach:
- Sort tokens.
- Use two pointers: spend small tokens for score, reclaim power using big tokens.
- Stop when neither move is possible.

Time: O(n log n)
Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int bagOfTokensScore(int* tokens, int tokensSize, int power) {
    qsort(tokens, tokensSize, sizeof(int), cmp);
    
    int left = 0, right = tokensSize - 1;
    int score = 0, maxScore = 0;

    while (left <= right) {
        if (power >= tokens[left]) {
            power -= tokens[left++];
            score++;
            if (score > maxScore) maxScore = score;
        } else if (score > 0) {
            power += tokens[right--];
            score--;
        } else {
            break;
        }
    }

    return maxScore;
}

// Test
int main() {
    int tokens[] = {100, 200, 300, 400};
    int power = 200;
    int size = sizeof(tokens) / sizeof(tokens[0]);

    int result = bagOfTokensScore(tokens, size, power);
    printf("Output: %d\n", result);  // Expected: 2

    return 0;
}

/*
========= OUTPUT =========
Output: 2
==========================
*/
