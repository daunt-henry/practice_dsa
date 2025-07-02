/*
Problem: Valid Anagram

Description:
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An anagram is a word or phrase formed by rearranging the letters of another.

Example:
Input: s = "anagram", t = "nagaram"
Output: true
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if two strings are anagrams
bool isAnagram(char * s, char * t) {
    int count[26] = {0};

    if (strlen(s) != strlen(t)) return false;

    for (int i = 0; s[i]; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }

    return true;
}

// Main function to test
int main() {
    char s[] = "anagram";
    char t[] = "nagaram";

    if (isAnagram(s, t))
        printf("Valid Anagram: true\n");
    else
        printf("Valid Anagram: false\n");

    return 0;
}

/*
========= OUTPUT =========
Valid Anagram: true
==========================
*/
