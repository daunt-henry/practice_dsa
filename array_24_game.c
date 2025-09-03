/*
24 Game
URL: https://leetcode.com/problems/24-game/

You are given an integer array cards of length 4. You should return true if you can get 24 
by applying the following operations on the numbers in any order:
    - Addition (+)
    - Subtraction (-)
    - Multiplication (*)
    - Division (/)

Each number must be used exactly once. You may use floating-point division.

Example 1:
Input: cards = [4,1,8,7]
Output: true
Explanation: (8 - 4) * (7 - 1) = 24

Example 2:
Input: cards = [1,2,1,2]
Output: false
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Recursive helper
bool dfs(double* nums, int size) {
    if (size == 1) {
        return fabs(nums[0] - 24.0) < 1e-6;
    }
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            double a = nums[i], b = nums[j];
            double next[6];
            int ops = 0;

            // Generate all possible results of combining a and b
            next[ops++] = a + b;
            next[ops++] = a - b;
            next[ops++] = b - a;
            next[ops++] = a * b;
            if (fabs(b) > 1e-6) next[ops++] = a / b;
            if (fabs(a) > 1e-6) next[ops++] = b / a;

            // Collect remaining numbers
            double rest[4];
            int idx = 0;
            for (int k = 0; k < size; ++k) {
                if (k != i && k != j) rest[idx++] = nums[k];
            }

            // Try each operation result
            for (int op = 0; op < ops; op++) {
                double nxtNums[5];  // FIX: allow one extra slot safely
                for (int k = 0; k < idx; k++) nxtNums[k] = rest[k];
                nxtNums[idx] = next[op];
                if (dfs(nxtNums, idx + 1)) return true;
            }
        }
    }
    return false;
}

bool judgePoint24(int* cards, int cardsSize) {
    double nums[4];
    for (int i = 0; i < cardsSize; ++i) nums[i] = cards[i];
    return dfs(nums, cardsSize);
}

// Driver for showcase
int main() {
    int cards1[] = {4, 1, 8, 7};
    int cards2[] = {1, 2, 1, 2};

    printf("Example 1: %s\n", judgePoint24(cards1, 4) ? "true" : "false");
    printf("Example 2: %s\n", judgePoint24(cards2, 4) ? "true" : "false");

    return 0;
}

/*
Expected Output:
Example 1: true
Example 2: false
*/
