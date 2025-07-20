/*
Title: Number of People Aware of a Secret

Description:
On day 1, one person discovers a secret. Each person can share the secret after `delay` days
and forgets it after `forget` days.

Return the number of people who remember the secret on day `n`.

Example:
Input: n = 6, delay = 2, forget = 4
Output: 5

Explanation:
- Day 1: [1] knows the secret.
- Day 2: [1]
- Day 3: [1,2] (1 shares)
- Day 4: [1,2,3]
- Day 5: [2,3,4] (1 forgets)
- Day 6: [2,3,4,5,6] → 5 people know the secret.

Constraints:
- 1 <= n <= 1000
- 1 <= delay < forget <= n
*/

#include <stdio.h>

#define MOD 1000000007

int peopleAwareOfSecret(int n, int delay, int forget) {
    long dp[1001] = {0};
    dp[1] = 1;
    long sum = 0;

    for (int i = 2; i <= n; i++) {
        int start = i - forget;
        int end = i - delay;

        if (end >= 1)
            for (int j = start + 1; j <= end; j++)
                if (j > 0)
                    dp[i] = (dp[i] + dp[j]) % MOD;
    }

    for (int i = n - forget + 1; i <= n; i++)
        if (i > 0)
            sum = (sum + dp[i]) % MOD;

    return (int)sum;
}

// Sample test
int main() {
    int n = 6, delay = 2, forget = 4;
    int result = peopleAwareOfSecret(n, delay, forget);
    printf("People who remember the secret on day %d: %d\n", n, result);  // Output: 5
    return 0;
}
