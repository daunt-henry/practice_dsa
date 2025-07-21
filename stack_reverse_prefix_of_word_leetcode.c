/*
Title: Reverse Prefix of Word

Description:
  Given a 0-indexed string `word` and a character `ch`, reverse the segment
  of `word` that starts at the beginning and ends at the first occurrence of `ch`
  (inclusive). If the character `ch` does not exist in `word`, return the original string.

Examples:
  Input: word = "abcdefd", ch = 'd'
  Output: "dcbaefd"

  Input: word = "xyxzxe", ch = 'z'
  Output: "zxyxxe"

  Input: word = "abcd", ch = 'z'
  Output: "abcd"

Approach:
  - Find the index of first occurrence of `ch`.
  - Reverse the substring from index 0 to that index in-place.
  - If `ch` not found, return word as is.

Constraints:
  - 1 <= word.length <= 250
  - word consists of lowercase English letters
  - ch is a lowercase English letter
*/

#include <stdio.h>
#include <string.h>

char* reversePrefix(char* word, char ch) {
    int i = 0;
    while (word[i] && word[i] != ch) {
        i++;
    }

    if (!word[i]) return word; // ch not found

    int left = 0, right = i;
    while (left < right) {
        char temp = word[left];
        word[left] = word[right];
        word[right] = temp;
        left++;
        right--;
    }

    return word;
}

int main() {
    char word1[] = "abcdefd";
    char word2[] = "xyxzxe";
    char word3[] = "abcd";

    printf("Input: \"%s\", ch = 'd' -> Output: \"%s\"\n", word1, reversePrefix(word1, 'd'));
    printf("Input: \"%s\", ch = 'z' -> Output: \"%s\"\n", word2, reversePrefix(word2, 'z'));
    printf("Input: \"%s\", ch = 'z' -> Output: \"%s\"\n", word3, reversePrefix(word3, 'z'));

    return 0;
}
