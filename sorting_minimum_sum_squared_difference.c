/*
Problem:
You are given two arrays nums1 and nums2 of equal length, and two integers k1 and k2. 
You can perform operations to decrease the difference of elements by 1 using k1 + k2 total operations. 
Return the minimum sum of squared differences between nums1 and nums2 after all operations.

Approach:
- Compute the absolute differences and count frequency.
- Start from the largest difference and greedily reduce it using available operations.
- Count squared sum of the resulting differences.

Example:
Input: nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0  
Output: 579
*/

#include <stdlib.h>

typedef long long ll;

int compare_desc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

long long minSumSquareDiff(int* nums1, int nums1Size, int* nums2, int nums2Size, int k1, int k2){
    int diff[100001] = {0};
    int maxDiff = 0;
    for (int i = 0; i < nums1Size; ++i) {
        int d = abs(nums1[i] - nums2[i]);
        diff[d]++;
        if (d > maxDiff) maxDiff = d;
    }

    long long k = (long long)k1 + (long long)k2;

    for (int i = maxDiff; i > 0 && k > 0; --i) {
        if (diff[i] == 0) continue;
        long long move = (k < diff[i]) ? k : diff[i];
        diff[i - 1] += move;
        diff[i] -= move;
        k -= move;
    }

    ll res = 0;
    for (int i = 0; i <= maxDiff; ++i) {
        res += (ll)i * i * diff[i];
    }
    return res;
}

/*
Output:
Input: nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
Output: 579
*/
