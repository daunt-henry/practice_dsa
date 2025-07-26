/*
Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The algorithm must run in O(log (m+n)) time.

Examples:
Input: nums1 = [1, 3], nums2 = [2]
Output: 2.00000

Input: nums1 = [1, 2], nums2 = [3, 4]
Output: 2.50000

Filename: median_of_two_sorted_arrays.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if(nums1Size > nums2Size)
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);

    int low = 0, high = nums1Size, halfLen = (nums1Size + nums2Size + 1) / 2;

    while (low <= high) {
        int i = (low + high) / 2;
        int j = halfLen - i;

        int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int minRight1 = (i == nums1Size) ? INT_MAX : nums1[i];

        int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int minRight2 = (j == nums2Size) ? INT_MAX : nums2[j];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((nums1Size + nums2Size) % 2 == 0)
                return (fmax(maxLeft1, maxLeft2) + fmin(minRight1, minRight2)) / 2.0;
            else
                return fmax(maxLeft1, maxLeft2);
        } else if (maxLeft1 > minRight2) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }

    return 0.0; // Should never reach here
}

// Sample test
int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};

    double median = findMedianSortedArrays(nums1, 2, nums2, 1);
    printf("Median: %.5f\n", median);  // Output: 2.00000

    int nums3[] = {1, 2};
    int nums4[] = {3, 4};
    median = findMedianSortedArrays(nums3, 2, nums4, 2);
    printf("Median: %.5f\n", median);  // Output: 2.50000

    return 0;
}
