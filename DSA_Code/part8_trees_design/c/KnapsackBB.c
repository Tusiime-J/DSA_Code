#include <stdio.h>

int value[3]  = {10, 7, 5};
int weight[3] = {4, 3, 2};
int capacity = 5;
int best = 0;                                   // best value found so far

void solve(int i, int w, int v, int remaining) {
    if (w > capacity) return;                   // too heavy: invalid
    if (v > best) best = v;                     // update the best answer
    if (i == 3) return;
    if (v + remaining <= best) return;          // BOUND: cannot beat best, prune

    solve(i + 1, w + weight[i], v + value[i], remaining - value[i]);   // branch: take item i
    solve(i + 1, w, v, remaining - value[i]);                          // branch: skip item i
}

int main() {
    solve(0, 0, 0, 22);                         // 22 = 10 + 7 + 5
    printf("Best value = %d\n", best);          // 12 (items 2 and 3)
    return 0;
}
