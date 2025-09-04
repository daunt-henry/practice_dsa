/*
 Minimum Swaps To Make Sequences Increasing

 Problem:
 You are given two integer arrays nums1 and nums2 of the same length.
 In one operation, you can swap nums1[i] with nums2[i].
 Return the minimum number of swaps to make both sequences strictly increasing.

 Example:
 Input:
 nums1 = [1,3,5,4]
 nums2 = [1,2,3,7]
 Output: 1
 Explanation:
 Swap at index 3 → nums1 = [1,3,5,7], nums2 = [1,2,3,4]
 Both sequences are strictly increasing.
*/

#include <stdio.h>
#include <limits.h>

int minSwap(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int keep = 0, swap = 1;

    for (int i = 1; i < nums1Size; i++) {
        int prevKeep = keep, prevSwap = swap;
        keep = swap = INT_MAX;

        if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
            if (prevKeep < keep) keep = prevKeep;
            if (prevSwap + 1 < swap) swap = prevSwap + 1;
        }

        if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
            if (prevSwap < keep) keep = prevSwap;
            if (prevKeep + 1 < swap) swap = prevKeep + 1;
        }
    }

    return keep < swap ? keep : swap;
}

int main() {
    int nums1[] = {1, 3, 5, 4};
    int nums2[] = {1, 2, 3, 7};
    int size = 4;

    int result = minSwap(nums1, size, nums2, size);
    printf("Minimum swaps needed: %d\n", result);

    return 0;
}
