/*
Problem:
Wildcard Matching:
- '?' matches any single character
- '*' matches any sequence (including empty)

Approach:
Dynamic Programming

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(const char *s, const char *p) {
    int m = strlen(s), n = strlen(p);
    bool dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;

    // When string is empty but pattern has '*'
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    }

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }

    return dp[m][n];
}

// Demo
int main() {
    const char* s = "adceb";
    const char* p = "*a*b";
    bool result = isMatch(s, p);
    printf("Match result: %s\n", result ? "true" : "false");
    return 0;
}
