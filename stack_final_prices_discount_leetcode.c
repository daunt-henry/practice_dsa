/*
Title: Final Prices With a Special Discount in a Shop

Description:
  You are given an integer array prices where prices[i] is the price of the ith item in a shop.
  There is a special discount for items. If you buy the ith item, you will receive a discount for the next item j such that j > i and prices[j] <= prices[i].
  You get a discount equal to prices[j]. If there is no such j, you get no discount.

Example:
  Input: prices = [8, 4, 6, 2, 3]
  Output: [4, 2, 4, 2, 3]

Explanation:
  - For price 8, next smaller is 4 => 8 - 4 = 4
  - For price 4, next smaller is 2 => 4 - 2 = 2
  - For price 6, next smaller is 2 => 6 - 2 = 4
  - For price 2, no smaller => 2
  - For price 3, no smaller => 3
*/

#include <stdio.h>
#include <stdlib.h>

int* finalPrices(int* prices, int pricesSize, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * pricesSize);
    for (int i = 0; i < pricesSize; i++) {
        int discount = 0;
        for (int j = i + 1; j < pricesSize; j++) {
            if (prices[j] <= prices[i]) {
                discount = prices[j];
                break;
            }
        }
        res[i] = prices[i] - discount;
    }
    *returnSize = pricesSize;
    return res;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int prices[] = {8, 4, 6, 2, 3};
    int size = sizeof(prices) / sizeof(prices[0]);
    int returnSize;
    int* result = finalPrices(prices, size, &returnSize);
    printf("Final prices after discount:\n");
    printArray(result, returnSize);
    free(result);
    return 0;
}
