/*
 * Problem: Number of Lines To Write String (LeetCode 806)
 *
 * Given:
 * - widths[]: array of length 26 where widths[0] → width of 'a', ..., widths[25] → width of 'z'
 * - s: lowercase string
 *
 * Goal:
 * Write s across multiple lines (max width = 100 pixels per line).
 * Return an array of two ints:
 *   [ number of lines used, width used on last line ].
 *
 * Approach:
 * - Initialize lines = 1, currWidth = 0
 * - For each character:
 *     - Fetch its width w
 *     - If (currWidth + w) ≤ 100: add to current line
 *     - Else: start new line (lines++), currWidth = w
 */

#include <stdio.h>
#include <stdlib.h>

int* numberOfLines(int* widths, int widthsSize, char* s, int* returnSize) {
    int lines = 1, currWidth = 0;
    for (char* p = s; *p; ++p) {
        int w = widths[*p - 'a'];
        if (currWidth + w <= 100) {
            currWidth += w;
        } else {
            lines++;
            currWidth = w;
        }
    }
    int* res = malloc(2 * sizeof(int));
    res[0] = lines;
    res[1] = currWidth;
    *returnSize = 2;
    return res;
}

int main(void) {
    int widths1[26] = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    char s1[] = "abcdefghijklmnopqrstuvwxyz";
    int retSize1;
    int* res1 = numberOfLines(widths1, 26, s1, &retSize1);
    printf("Lines: %d, Last line width: %d (expected: 3, 60)\n", res1[0], res1[1]);
    free(res1);

    int widths2[26];
    for (int i = 0; i < 26; i++) widths2[i] = 4;
    char s2[] = "bbbcccdddaaa";
    int retSize2;
    int* res2 = numberOfLines(widths2, 26, s2, &retSize2);
    printf("Lines: %d, Last line width: %d (expected: 2, 4)\n", res2[0], res2[1]);
    free(res2);

    return 0;
}
