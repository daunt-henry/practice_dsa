/*
Title: Minimum Additions to Make Valid String

You can only append characters to the end of the string.
A valid string consists of repeated "abc" substrings.

Example:
Input: word = "b"
Output: 2
Explanation: Add "a" and "c" to form "abc".

Approach:
- Traverse the input string in chunks, trying to match "abc".
- Count the number of characters needed to complete missing parts of "abc".

Time Complexity: O(n)
*/

#include <stdio.h>
#include <string.h>

int addMinimum(char* word) {
    int n = strlen(word), count = 0;

    for (int i = 0; i < n;) {
        if (word[i] == 'a') {
            if (i + 1 < n && word[i + 1] == 'b') {
                if (i + 2 < n && word[i + 2] == 'c') {
                    i += 3;
                } else {
                    i += 2;
                    count += 1; // missing 'c'
                }
            } else if (i + 1 < n && word[i + 1] == 'c') {
                i += 2;
                count += 1; // missing 'b'
            } else {
                i += 1;
                count += 2; // only 'a'
            }
        } else if (word[i] == 'b') {
            if (i + 1 < n && word[i + 1] == 'c') {
                i += 2;
                count += 1; // missing 'a'
            } else {
                i += 1;
                count += 2; // only 'b'
            }
        } else if (word[i] == 'c') {
            i += 1;
            count += 2; // only 'c'
        }
    }

    return count;
}

int main() {
    char word1[] = "b";
    printf("Input: \"%s\"\nOutput: %d\n", word1, addMinimum(word1)); // Output: 2

    char word2[] = "aaa";
    printf("Input: \"%s\"\nOutput: %d\n", word2, addMinimum(word2)); // Output: 6

    char word3[] = "abcabc";
    printf("Input: \"%s\"\nOutput: %d\n", word3, addMinimum(word3)); // Output: 0

    return 0;
}
