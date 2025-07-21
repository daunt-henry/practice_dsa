/*
Title: Online Stock Span

Description:
  Implement a class `StockSpanner` that collects daily price quotes for some stock,
  and returns the span of that stock's price for the current day.

  The span of the stock's price today is defined as the maximum number of consecutive days
  (starting from today and going backward) for which the price was less than or equal to today's price.

Example Input:
  next(100) → 1
  next(80)  → 1
  next(60)  → 1
  next(70)  → 2
  next(60)  → 1
  next(75)  → 4
  next(85)  → 6

Example Output:
  1 1 1 2 1 4 6
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_DAYS 10000

typedef struct {
    int prices[MAX_DAYS];
    int spans[MAX_DAYS];
    int top;
} StockSpanner;

StockSpanner* stockSpannerCreate() {
    StockSpanner* obj = (StockSpanner*)malloc(sizeof(StockSpanner));
    obj->top = -1;
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int span = 1;
    while (obj->top >= 0 && obj->prices[obj->top] <= price) {
        span += obj->spans[obj->top];
        obj->top--;
    }
    obj->top++;
    obj->prices[obj->top] = price;
    obj->spans[obj->top] = span;
    return span;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj);
}

int main() {
    StockSpanner* ss = stockSpannerCreate();
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(prices[0]);

    printf("Spans: ");
    for (int i = 0; i < n; ++i) {
        int span = stockSpannerNext(ss, prices[i]);
        printf("%d ", span);
    }
    printf("\n");

    stockSpannerFree(ss);
    return 0;
}
