/*
Problem: Find Smallest Letter Greater Than Target (LeetCode 744)
URL: https://leetcode.com/problems/find-smallest-letter-greater-than-target/

Given a sorted array of lowercase letters `letters[]`, find the smallest letter greater than `target`.
Wrap around to the start if needed.

Approach:
Use binary search to efficiently find the first letter > target:
- Search space is [0, lettersSize)
- If letters[mid] > target → continue searching left (hi = mid)
- Else → search right (lo = mid + 1)
- Final answer = letters[lo % lettersSize] to handle wrap-around.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <stdio.h>

char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int lo = 0, hi = lettersSize;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (letters[mid] > target) hi = mid;
        else lo = mid + 1;
    }
    return letters[lo % lettersSize];
}

int main(void) {
    char arr1[] = {'c', 'f', 'j'};
    printf("letters = [c,f,j], target = 'a' → %c (expected: c)\n",
           nextGreatestLetter(arr1, 3, 'a'));
    printf("letters = [c,f,j], target = 'c' → %c (expected: f)\n",
           nextGreatestLetter(arr1, 3, 'c'));
    printf("letters = [c,f,j], target = 'j' → %c (expected: c)\n",
           nextGreatestLetter(arr1, 3, 'j'));
    return 0;
}
