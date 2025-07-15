/*
Problem:
Implement regular expression matching with support for '.' and '*'.

'.' Matches any character.
'*' Matches zero or more of the preceding element.

Approach:
Dynamic Programming (Bottom-Up Tabulation)

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(const char* s, const char* p) {
    int m = strlen(s), n = strlen(p);
    bool dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;

    for (int j = 2; j <= n; j++) {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 2];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2];
                if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
    }

    return dp[m][n];
}

// Demo
int main() {
    const char* s = "aab";
    const char* p = "c*a*b";
    bool result = isMatch(s, p);
    printf("Match result: %s\n", result ? "true" : "false");
    return 0;
}
