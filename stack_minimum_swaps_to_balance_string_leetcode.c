/*
Title: Minimum Number of Swaps to Make the String Balanced

Description:
  You are given a string s of even length, consisting of '[' and ']'.
  A string is balanced if the number of opening and closing brackets is equal
  and every prefix has at least as many opening brackets as closing ones.

  You can swap any two characters at most once in each operation.
  Return the minimum number of swaps needed to balance the string.

Example:
  Input: s = "][]["
  Output: 1

  Input: s = "]]][[["
  Output: 2

Approach:
  - Traverse the string and track the balance of brackets.
  - Keep count of imbalance when closing brackets exceed openings.
  - The number of swaps required is (max imbalance + 1) / 2.

Constraints:
  - 1 <= s.length <= 10^5
  - s.length is even
  - s[i] is either '[' or ']'
*/

#include <stdio.h>

int minSwaps(char* s) {
    int open = 0, maxImbalance = 0;

    for (int i = 0; s[i]; ++i) {
        if (s[i] == '[') {
            open++;
        } else {
            open--;
        }

        if (open < 0) {
            if (-open > maxImbalance) {
                maxImbalance = -open;
            }
        }
    }

    return (maxImbalance + 1) / 2;
}

int main() {
    char s1[] = "][][";
    char s2[] = "]]][[[";

    printf("Input: \"%s\" -> Minimum Swaps: %d\n", s1, minSwaps(s1)); // Output: 1
    printf("Input: \"%s\" -> Minimum Swaps: %d\n", s2, minSwaps(s2)); // Output: 2

    return 0;
}
