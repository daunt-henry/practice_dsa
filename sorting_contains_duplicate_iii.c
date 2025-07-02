/*
Problem: Contains Duplicate III

Description:
Return true if there exist two indices i and j such that:
  - |i - j| <= k
  - |nums[i] - nums[j]| <= t

Use sliding window + bucket hashing to solve in O(n) time.

Example:
Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;

ll getBucketId(ll num, ll size) {
    return num < 0 ? (num + 1LL) / size - 1 : num / size;
}

bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t) {
    if (t < 0 || k <= 0 || numsSize < 2) return false;

    int bucketSize = t + 1;
    int hashSize = numsSize;
    ll* mapKeys = malloc(sizeof(ll) * hashSize);
    ll* mapVals = malloc(sizeof(ll) * hashSize);
    int mapLen = 0;

    for (int i = 0; i < numsSize; i++) {
        ll num = (ll)nums[i];
        ll bucketId = getBucketId(num, bucketSize);

        for (int j = 0; j < mapLen; j++) {
            if (mapKeys[j] == bucketId || mapKeys[j] == bucketId - 1 || mapKeys[j] == bucketId + 1) {
                if (llabs(mapVals[j] - num) <= t) {
                    free(mapKeys);
                    free(mapVals);
                    return true;
                }
            }
        }

        mapKeys[mapLen] = bucketId;
        mapVals[mapLen] = num;
        mapLen++;

        if (i >= k) {
            ll oldBucket = getBucketId((ll)nums[i - k], bucketSize);
            for (int j = 0; j < mapLen; j++) {
                if (mapKeys[j] == oldBucket) {
                    mapKeys[j] = mapKeys[mapLen - 1];
                    mapVals[j] = mapVals[mapLen - 1];
                    mapLen--;
                    break;
                }
            }
        }
    }

    free(mapKeys);
    free(mapVals);
    return false;
}

// Test
int main() {
    int nums[] = {1, 2, 3, 1};
    int size = sizeof(nums) / sizeof(nums[0]);
    int k = 3, t = 0;

    if (containsNearbyAlmostDuplicate(nums, size, k, t))
        printf("Contains Nearby Almost Duplicate: true\n");
    else
        printf("Contains Nearby Almost Duplicate: false\n");

    return 0;
}

/*
========= OUTPUT =========
Contains Nearby Almost Duplicate: true
==========================
*/
