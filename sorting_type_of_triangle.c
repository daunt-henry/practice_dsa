/*
Problem:
You are given an array `nums` of 3 positive integers representing the side lengths of a triangle.

Return the type of triangle as a string:
- "equilateral" if all sides are equal,
- "isosceles" if exactly two sides are equal,
- "scalene" if all three sides are different,
- "none" if the sides cannot form a valid triangle.

A triangle is valid if: a + b > c, a + c > b, and b + c > a.

Example Input 1:
nums = [3, 3, 3]
Output: "equilateral"

Example Input 2:
nums = [3, 4, 5]
Output: "scalene"

Example Input 3:
nums = [1, 2, 3]
Output: "none"
*/

#include <stdio.h>
#include <stdlib.h>

char* triangleType(int* nums, int numsSize) {
    int a = nums[0], b = nums[1], c = nums[2];
    if (a + b <= c || a + c <= b || b + c <= a) return "none";
    if (a == b && b == c) return "equilateral";
    if (a == b || b == c || a == c) return "isosceles";
    return "scalene";
}

int main() {
    int nums1[] = {3, 3, 3};
    int nums2[] = {3, 4, 5};
    int nums3[] = {1, 2, 3};

    printf("Triangle 1: %s\n", triangleType(nums1, 3)); // Output: equilateral
    printf("Triangle 2: %s\n", triangleType(nums2, 3)); // Output: scalene
    printf("Triangle 3: %s\n", triangleType(nums3, 3)); // Output: none

    return 0;
}
