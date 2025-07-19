/*
Title: Stamping the Sequence


You are given two strings stamp and target. You need to return an array of the sequence of moves to stamp the entire target with '?'
A move is defined by placing the `stamp` over a substring of `target` and replacing those characters with '?'
You can return the moves in reverse order.

Example:
Input: stamp = "abc", target = "ababc"
Output: [0, 2]

Explanation:
- Stamp at index 0 -> "abc??"
- Stamp at index 2 -> "?????"

Constraints:
- 1 <= stamp.length <= target.length <= 1000
- stamp and target consist of lowercase English letters only
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isStamp(char *stamp, char *target, int pos, int slen, int tlen) {
    int stamped = 0;
    for (int i = 0; i < slen; i++) {
        if (target[pos + i] == '?') continue;
        if (stamp[i] != target[pos + i]) return 0;
        stamped = 1;
    }
    return stamped;
}

int doStamp(char *target, int pos, int slen) {
    int count = 0;
    for (int i = 0; i < slen; i++) {
        if (target[pos + i] != '?') {
            target[pos + i] = '?';
            count++;
        }
    }
    return count;
}

int* movesToStamp(char *stamp, char *target, int* returnSize) {
    int slen = strlen(stamp), tlen = strlen(target);
    int *res = malloc(sizeof(int) * tlen);
    int resIndex = 0, changed = 1, total = 0;
    int visited[tlen];
    memset(visited, 0, sizeof(visited));

    while (total < tlen) {
        changed = 0;
        for (int i = 0; i <= tlen - slen; i++) {
            if (!visited[i] && isStamp(stamp, target, i, slen, tlen)) {
                int count = doStamp(target, i, slen);
                if (count > 0) {
                    visited[i] = 1;
                    res[resIndex++] = i;
                    total += count;
                    changed = 1;
                }
            }
        }
        if (!changed) {
            *returnSize = 0;
            return NULL;
        }
    }

    // Reverse result
    for (int i = 0; i < resIndex / 2; i++) {
        int temp = res[i];
        res[i] = res[resIndex - i - 1];
        res[resIndex - i - 1] = temp;
    }

    *returnSize = resIndex;
    return res;
}

int main() {
    char stamp[] = "abc";
    char target[] = "ababc";
    int returnSize;
    int* result = movesToStamp(stamp, target, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i != returnSize - 1) printf(", ");
    }
    printf("]\n");

    free(result);
    return 0;
}
