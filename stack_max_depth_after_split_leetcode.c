/*
Title: Maximum Nesting Depth of Two Valid Parentheses Strings

Description:
  Given a valid parentheses string seq, split it into two disjoint subsequences A and B,
  such that both A and B are valid parentheses strings and the maximum nesting depth
  of both A and B is minimized.

  Return an array where the i-th element indicates whether the i-th character in seq
  belongs to group A (0) or group B (1).

Example Input:
  seq = "(()())"

Example Output:
  [0,1,1,1,1,0]

Explanation:
  Split the sequence such that both groups have balanced parentheses and their nesting
  depth is as low as possible.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* maxDepthAfterSplit(char* seq, int* returnSize) {
    int n = strlen(seq);
    int* ans = (int*)malloc(n * sizeof(int));
    *returnSize = n;

    int depth = 0;
    for (int i = 0; i < n; ++i) {
        if (seq[i] == '(') {
            depth++;
            ans[i] = depth % 2;
        } else {
            ans[i] = depth % 2;
            depth--;
        }
    }
    return ans;
}

void printArray(int* arr, int n) {
    printf("[");
    for (int i = 0; i < n; ++i) {
        if (i > 0) printf(",");
        printf("%d", arr[i]);
    }
    printf("]\n");
}

int main() {
    char seq[] = "(()())";
    int size;
    int* result = maxDepthAfterSplit(seq, &size);

    printf("Input: %s\n", seq);
    printf("Output: ");
    printArray(result, size);  // Expected: [0,1,1,1,1,0]

    free(result);
    return 0;
}
