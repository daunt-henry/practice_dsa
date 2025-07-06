/*
Problem:
Given an integer `num`, swap its digits such that digits at even indices are swapped with other even digits and odd indices with other odd digits only.

Return the **largest possible number** after such parity-based swaps.

Approach:
1. Extract all digits.
2. Separate them into odd and even digits.
3. Sort both sets in descending order.
4. Rebuild number preserving original parity at each index.

Example:
Input: 1234
Output: 3412
Explanation:
- Digits at even places: 2, 4 → sort → 4, 2
- Digits at odd places: 1, 3 → sort → 3, 1
- Final: 3412
*/

#include <stdio.h>

int largestInteger(int num){
    int digits[10], odd[10], even[10];
    int i = 0, o = 0, e = 0, temp = num;

    // Split digits and categorize by parity
    while (temp > 0) {
        int d = temp % 10;
        digits[i++] = d;
        if (d % 2 == 0) even[e++] = d;
        else odd[o++] = d;
        temp /= 10;
    }

    // Sort even and odd digits in descending order
    for (int x = 0; x < e - 1; x++) {
        for (int y = x + 1; y < e; y++) {
            if (even[x] < even[y]) {
                int t = even[x]; even[x] = even[y]; even[y] = t;
            }
        }
    }
    for (int x = 0; x < o - 1; x++) {
        for (int y = x + 1; y < o; y++) {
            if (odd[x] < odd[y]) {
                int t = odd[x]; odd[x] = odd[y]; odd[y] = t;
            }
        }
    }

    // Reconstruct number with sorted parity groups
    int res = 0;
    int j = 0, k = 0;
    for (int x = i - 1; x >= 0; x--) {
        res *= 10;
        if (digits[x] % 2 == 0)
            res += even[j++];
        else
            res += odd[k++];
    }

    return res;
}

/*
Input: 1234
Output: 3412
*/
